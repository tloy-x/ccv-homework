//Theres a seemingly random bug that occurs sometimes that hangs
//the program idefinitely. idk bro

#include <ncurses.h>
#include <string>
#include <vector>

int cards[2][13] = 
{   //X = Card value, Y = count
    {1/*Ace*/, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11/*Jack*/, 12/*Queen*/, 13/*King*/} ,
    {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4} 
};

class Player
{
    public:
        bool pulled_ace = false;

        void blackjack_init()
        {
            hand.clear();
            total = 0;
        }

        int pull(int opt = 0)
        {
            int raw_pull, pos;

            raw_pull = cards[0][rand() % 13];

            if(opt != 0)
            {
                raw_pull = opt;
            }
            
            while(1)
            {
                pos = raw_pull - 1;
                if(cards[1][pos] == 0)
                {
                    raw_pull = cards[0][rand() % 13];
                }

                else
                {
                    cards[1][pos] = cards[1][pos] - 1;
                    break;
                }
            }

            int value;
            value = 0;

            if(raw_pull > 1 && raw_pull < 11)
            {
                value = raw_pull;
            }
            else if(raw_pull >= 11)
            {
                value = 10;
            }
            else if(raw_pull == 1)
            {
                pulled_ace = true;
            }

            total = total + value;

            if(raw_pull == 1)
            {}
            else if(raw_pull != 1 && raw_pull < 11)
            {
                last_pull = std::to_string(raw_pull);
            }
            else if(raw_pull >= 11)
            {
                if(raw_pull == 11)
                    last_pull = "Jack";
                else if(raw_pull == 12)
                    last_pull = "Queen";
                else if(raw_pull == 13)
                    last_pull = "King";
            }

            if(pulled_ace == false)
            {
            hand.push_back(last_pull);
            }
            else
            {}

            return value;
        }

        std::vector<std::string> hand;
        int total = 0;
        std::string last_pull;
};


int main(int argc, char* argv[])
{
    Player user;

    srand(time(0));
    //NCURSES START
    initscr();
    noecho();
    cbreak();

    int ymax, xmax;
    getmaxyx(stdscr, ymax, xmax);

    WINDOW * menuwin = newwin(5, 20, ymax-5, xmax/2 - 10);
    WINDOW * dialogwin = newwin(3, 12, ymax/2, (xmax/2)-6);
    WINDOW * acedialog = newwin(4, 20, ymax/2, (xmax/2)-10);
    refresh();

    //Allows for arrowkeys.
    keypad(menuwin, true);

    std::string actions[2] = {"Hit", "Exit"};
    std::string ace_opt[2] = {"1", "11"};
    std::string end[2] = {"Try Again", "Exit"};

    int highlight = 0;
    do
    {
        box(menuwin, 0, 0);
        wrefresh(menuwin);
        do
        {
            if(user.total == 21)
            {
                box(dialogwin, 0, 0);
                wattron(dialogwin, A_REVERSE);
                mvwprintw(dialogwin, 1, 1, "Blackjack!");
                wrefresh(dialogwin);
                wclear(dialogwin);
                wattroff(dialogwin, A_REVERSE);
                break;
            }

            else if(user.total > 21)
            {
                box(dialogwin, 0, 0);
                wattron(dialogwin, A_REVERSE);
                mvwprintw(dialogwin, 1, 3, "Bust!!");
                wrefresh(dialogwin);
                wclear(dialogwin);
                wattroff(dialogwin, A_REVERSE);
                break;
            }

            int action;
            //int choice;

            int x = 0, y = 0;
            while(1)
            {
                for(int i = 0; i < 2; i++)
                {
                    if(i == highlight)
                    {
                        wattron(menuwin, A_REVERSE);
                    }

                    mvwprintw(menuwin, i+1, 1, actions[i].c_str());
                    wattroff(menuwin, A_REVERSE);
                }

                action = wgetch(menuwin);

                switch(action)
                {
                    case KEY_UP:
                        highlight--;
                        if(highlight == -1)
                            highlight = 0;
                        break;
                    case KEY_DOWN:
                        highlight++;
                        if(highlight == 2)
                            highlight = 1;
                        break;
                    default:
                        break;
                }

                if(action == 10)
                    break;
            }

            if(actions[highlight] == "Hit")
            {
                user.pull();

                if(user.pulled_ace == true)
                {
                    box(acedialog, 0, 0);
                    wattron(acedialog, A_REVERSE);
                    mvwprintw(acedialog, 1, 1, "You pulled an Ace!");
                    mvwprintw(acedialog, 2, 6, "1 or 11?");
                    wrefresh(acedialog);
                    wclear(acedialog);
                    wattroff(acedialog, A_REVERSE);

                    wclear(menuwin);
                    box(menuwin, 0, 0);

                    wrefresh(menuwin);
                    
                    int acehighlight = 0;
                    while(1)
                    {
                        for(int i = 0; i < 2; i++)
                        {
                            if(i == acehighlight)
                            {
                                wattron(menuwin, A_REVERSE);
                            }

                            mvwprintw(menuwin, i+1, 1, ace_opt[i].c_str());
                            wattroff(menuwin, A_REVERSE);
                        }

                        int aceaction = wgetch(menuwin);

                        switch(aceaction)
                        {
                            case KEY_UP:
                                acehighlight--;
                                if(acehighlight == -1)
                                    acehighlight = 0;
                                break;
                            case KEY_DOWN:
                                acehighlight++;
                                if(acehighlight == 2)
                                    acehighlight = 1;
                                break;
                            default:
                                break;
                        }

                        if(aceaction == 10)
                            break;
                    }

                    if(ace_opt[acehighlight] == "1")
                    {
                        user.last_pull = "Ace (1)";
                        user.hand.push_back("Ace (1)");
                        user.total = user.total + 1;
                        user.pulled_ace = false;
                        wrefresh(acedialog);
                    }
                    else if(ace_opt[acehighlight] == "11")
                    {
                        user.last_pull = "Ace (11)";
                        user.hand.push_back("Ace (11)");
                        user.total = user.total + 11;
                        user.pulled_ace = false;
                        wrefresh(acedialog);
                    }

                }

                wmove(stdscr, 0, 0);
                clrtoeol();
                wrefresh(stdscr);
                mvwprintw(stdscr, 0, 0, "You pulled: %s", user.last_pull.c_str());
                mvwprintw(stdscr, 1, 0, "Total: %d", user.total);
                wmove(stdscr, 2, 0);
                printw("Hand: ");
                for(int i=0;i<user.hand.size();i++)
                {
                    if(i == user.hand.size() - 1)
                    {
                        addstr(user.hand[i].c_str());
                    }
                    else
                    {
                        addstr(user.hand[i].c_str());
                        addstr(", ");
                    }
                }
                wrefresh(stdscr);
            }

            else if(actions[highlight] == "Exit")
                goto EXIT;

        }while(1);

        do
        {
            int highlight = 0;
            if(actions[highlight] == "Exit")
                break;
            int action;

            while(1)
            {
                for(int i = 0; i < 2; i++)
                {
                    if(i == highlight)
                    {
                        wattron(menuwin, A_REVERSE);
                    }

                    mvwprintw(menuwin, i+1, 1, end[i].c_str());
                    wattroff(menuwin, A_REVERSE);
                }

                action = wgetch(menuwin);

                switch(action)
                {
                    case KEY_UP:
                        highlight--;
                        if(highlight == -1)
                            highlight = 0;
                        break;
                    case KEY_DOWN:
                        highlight++;
                        if(highlight == 2)
                            highlight = 1;
                        break;
                    default:
                        break;
                }

                if(action == 10)
                    break;
            }

            if(end[highlight] == "Try Again")
            {   
                int cards[2][13] = 
                {   //X = Card value, Y = count
                    {1/*Ace*/, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11/*Jack*/, 12/*Queen*/, 13/*King*/} ,
                    {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4} 
                }; 
                user.blackjack_init();
                wmove(stdscr, 0, 0);
                clrtoeol();
                wmove(stdscr, 1, 0);
                clrtoeol();
                wmove(stdscr, 2, 0);
                clrtoeol();
                wclear(menuwin);
                wrefresh(dialogwin);
                refresh();
                break;
            }
            else if(end[highlight] == "Exit")
                goto EXIT;;
        }while(1);
    }while(1);
    EXIT:
    endwin();
    //NCURSES END

    return 0;
}