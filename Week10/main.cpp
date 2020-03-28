#include <iostream> //cout
#include <vector> //vector
#include <fstream> //ifstream, ofstream
#include <numeric> //accumulate
#include <string> //string

using namespace std;

vector<double> scores;

char df[] = {'f'};

void averager(vector<double> &outvec);
void usage(char* name[]);

int main(int argc, char* argv[])
{

    if (argc < 2)
        usage(argv);

    if (string(argv[1]) == "-h")
        usage(argv);
    
    bool verbose = false;
    if (argv[2])
    {
        if (string(argv[2]) == "-v")
        {
            verbose = true;
        }
    }

    ifstream inFile;
    ofstream temp;

    inFile.open(argv[1]);
    temp.open("temp.dat");

    char next;
    int count = 0;

    while (! inFile.eof()) //Making temp file wiht isolated scores.
    {
        do 
        {
            if (count < 2) //skipping fist two words (name).
            {
                if (next == ' ')
                {
                    count++;
                    //cout << next;
                    inFile.get(next);
                }

                else
                {
                    //cout << next;
                    inFile.get(next);
                }                                                                   
            }
            
            else
            {
                temp << next;
                inFile.get(next);
            }

            if (next == '\n')
            {
               
                count = 0;
                temp << " " << 9999 << endl; //adding delimeter.
                
            }


        }while (next != '\n');
    }

    inFile.close();
    temp.close();

    averager(scores);
    remove("temp.dat");

    ifstream input;
    input.open(string(argv[1]));
    ofstream outFile;

    outFile.open("average_" + string(argv[1]));
    count = 0;
    int i = 0;
    char next2;

    while (! input.eof())
    {
        input.get(next2);
        outFile << next2;

        if (verbose == true)
            cout << next2;

        if (next2 == ' ')
            count++;
        
        if (count == 2)
        {
            outFile << scores[i];
            if (verbose == true)
                cout << scores[i];
            i++;

            while (next2 != '\n')
                input.get(next2);

            outFile << endl;
            if (verbose == true)
                cout << endl;
                
            count = 0;
        }
    }
   
    return 0;
}

void averager(vector<double> &outvec)
{
    ifstream temp2;
    vector<int> tempvec;
    double average;

    temp2.open("temp.dat");

    int num, numline;

    while (! temp2.eof())
    {
        temp2 >> num;
        if (num != 9999)
            tempvec.push_back(num);

        else if (num == 9999)
        {
           average = accumulate(tempvec.begin(), tempvec.end(), 0.0) / tempvec.size();

            outvec.push_back(average);
           tempvec.clear();
        }
    }

    temp2.close();

    return;
}

void usage(char* name[])
{
    cout << "Usage: " << string(name[0]) << " [FILENAME] <option>" << endl << endl
         << "  -v       Toggle verbose output." << endl
         << "  -h       Display this message." << endl;

    exit(1);
    return;
}