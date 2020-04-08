//Date: 4/5/2020
//Filename: main.cpp
//Author: Tanner Loy

//Description: A simple blackjack game writtn for terminal. It's only one player at the moment, and
//it only involves hitting or going above 21. The next version will feature playing against the dealer,
//and deck logic (number of each card in the deck).

#include <iostream> //cin, cout
#include <random> //rand()
#include <algorithm> //accumulate() 
#include <ctime> //time()
#include <string> //string
#include <vector> //vector

int total = 0;

std::vector<std::string> hand; //Declaring the player's hand.

void blackjack_init(); //Intializer.

int main()
{
    srand(time(0)); //Seeding rand().

    std::string ans, cardname;

    int card, cardvalue, val, i;

    bool bust; //Boolean for checking if the user busted.

    total;

    int cards[2][13] = { //X = Card value, Y = count
        {1/*Ace*/, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11/*Jack*/, 12/*Queen*/, 13/*King*/} ,
        {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4} 
    };

    std::cout << "Type \"hit\" to hit.\n";
    std::cout << "Type \"quit\" to quit.\n";

    std::cout << "";

    do 
    {
        val = cards[0][rand() % 13]; //Pulling a card. There are 13 cards (A, 2-10, J, Q, K)

        std::cout << "Action: ";
        std::cin >> ans;

        if (ans == "hit")
        {
            if (1 < val && val < 11) //Checking the value of the user's pull.
            {
                cardvalue = val;

                cardname = std::to_string(cardvalue); //If the user's pull is a number card, the value is equal to the number.

                hand.push_back(cardname); //Adding the card's name (value) to the hand vector.

                std::cout << "You pulled a " << cardname << "!\n"; //Telling the user what they pulled.
            }

            else if (val >= 11) //Checking if the pull was a facecard.
            {
                cardvalue = 10; //Setting value to 10.

                if (val == 11)
                    cardname = "Jack";
                else if (val == 12)
                    cardname = "Queen";
                else if (val == 13)
                    cardname = "King";

                hand.push_back(cardname);

                std::cout << "You pulled a " << cardname << "!\n"; //Telling the user what they pulled.
            }

            else if (val = 1) //Checks if the user pulled an Ace.
            {
                int aceval;

                std::cout << "You pulled an Ace! 1 or 11?\n"; //Asking the user what they want their Ace to equal.

                std::cin >> aceval;

                while (true)
                {
                    if (aceval == 1) //If user entered '1'.
                    {
                        cardvalue = aceval;

                        cardname = "Ace (" + std::to_string(aceval) + ")"; //Setting the card's name to Ace(value).

                        hand.push_back(cardname);

                        break;

                    }
                    else if (aceval == 11) //If user entered '11'.
                    {
                        cardvalue = aceval;

                        cardname = "Ace (" + std::to_string(aceval) + ")"; //Setting the card's name to Ace(value).

                        hand.push_back(cardname);
                        
                        break;
                    }
                    else //Catching if the user inputted something invalid.
                    {
                        std::cout << "Invalid. Try again.\n";
                        std::cin >> aceval;
                    }
                }
            }
        }

        total = total + cardvalue; //Adding up the user's total after every pull.

        std::cout << "\nTotal: " << total << std::endl; //User total output.

        if (hand.size() == 1) //Grammar for hand output.
        {
            std::cout << "Hand: " << hand[0] << std::endl;
        }

        else //Hand output.
        {
            std::cout << "Hand: " << hand[0];

            for (i = 1; i < hand.size(); i++)
            {
                std::cout << ", " << hand[i];
            }

            std::cout << std::endl;           
        }
        
        if (total > 21) //Checking total against lose condition after every pull.
        {
            std::cout << "\nBust!";
            std::cout << "\nTry again? y/n: ";
            std::cin >> ans;

            if (ans == "n")
                break; //Ends the game.
            else
                blackjack_init(); //Calls initializer. 
        }

        if (total == 21) //Checking total against win condition after every pull.
        {
            std::cout << "\nBlackjack!";
            std::cout << "\nPlay again? y/n: ";
            std::cin >> ans;

            if (ans == "n")
                break; //Ends the game.
            else
                blackjack_init(); //Calls initializer. 
        }

    }while (ans != "quit");

    return 0;
}

void blackjack_init()
{
    hand.clear(); //Clears the hand vector.
    total = 0; //Resets total.
    std::cout << "Type \"hit\" to hit.\n";
    std::cout << "Type \"quit\" to quit.\n";
    std::cout << '\n'; //Outputs a newline.

    return; 
}