#include <iostream> //cout
#include <vector> //vector
#include <fstream> //ifstream, ofstream
#include <numeric> //accumulate
#include <string> //string
#include <sstream> //istringstream

//Excluding the using declaration so I can get used to using std:: instead.
//using namespace std; 

std::vector<double> scores;

void averager(std::vector<double> &outvec); //Gets data from the temp.dat file and outputs thm t a vector.

void usage(char* name[]); //Usage output.

int main(int argc, char* argv[])
{

    if (argc < 2 || argc > 3) //Catching too many or oo few arguments.
        usage(argv);

    if (std::string(argv[1]) == "-h") //Case for the help flag.
        usage(argv);
    
    bool verbose = false;

    if (argv[2])
    {
        if (std::string(argv[2]) == "-v") //Case for verbose flag.
        {
            std::cout << '\n'; //Adding newline before output.
            verbose = true; //If set, verbose = true.
        }
    }

    std::ifstream inFile; //Opening input filestream.
    std::ofstream temp; //Creating output filestream.

    inFile.open(argv[1]); //Opening input filestream based on the filename passed via arguments.
    temp.open("temp.dat"); //Oepening temp.dat file.

    char next;
    int count = 0;

    while (! inFile.eof()) //Isolating scores into temp.dat.
    {

        if (count < 2) //Checking for less than two spaces counted.
        {
            if (next == ' ') //Case based on if the loaded character is a space.
            {
                count++; //Couting number of spaces
                //cout << next;
                inFile.get(next); //Go to next character.
            }

            else //If character is not a space.
            {
                //cout << next;
                inFile.get(next); //Get next character
            }                                                                   
        }
        
        else //Caught if two spaces are counted.
        {
            temp << next; //Puts characters into temp.dat.
            inFile.get(next);
        }

        if (next == '\n') //Checking for the end of a line.
        {
            
            count = 0; //Resetting count value.
            temp << '\n'; //Adding newline to temp for seperation. 

            //temp << " " << 9999 << endl; //Old delimeter code
        }

    } //Loops while inFile is not at end of file.

    inFile.close(); //Closing my files.
    temp.close();

    averager(scores);

    remove("temp.dat"); //Deleting the temp.dat.

    std::ifstream input; //Declaring new clean input stream.
    input.open(std::string(argv[1])); //Opens same file as original input stream.

    std::ofstream outFile; //Declaring output file stream.
    outFile.open("average_" + std::string(argv[1])); //Crearting new output file. 

    count = 0;
    int i = 0;
    char next2; //Not "next two characters". This is just another variable called next.

    while (! input.eof()) //Loops while input is not at end of file.
    {
        input.get(next2); //Extracts cahracters from input,
        outFile << next2; //and inserts them into outFile.

        if (verbose == true) //Checking for verbosity.
            std::cout << next2;

        if (next2 == ' ') //Couting spaces.
            count++;
        
        if (count == 2) // If number of spaces is two, put in the averaged score according to the vector index.
        {
            outFile << scores[i];

            if (verbose == true) //Checking for verbosity.
                std::cout << scores[i];
            
            i++; //Counting line number for easy index addressing.

            while (next2 != '\n') //Ignoring the rest of the line up to newline
                input.get(next2);

            outFile << std::endl; //Ending outFile line.

            if (verbose == true) //Checking for verbosity.
                std::cout << std::endl;
                
            count = 0; //Resetting count.
        }
    }
   
    return 0;
}

void averager(std::vector<double> &outvec)
{
    std::ifstream temp2;
    std::vector<int> tempvec;
    double average;

    temp2.open("temp.dat");

    // This is the old metheod I was using. I had been putting the integer "9999" at the end of every line as a delimeter
    // to signal the end of a line for this function. I asked stackOverflow for help on this one. 
    // https://stackoverflow.com/questions/60909366/trouble-checking-for-newline-character-when-taking-integers-as-input

    // int num;

    // while (! temp2.eof())
    // {
    //     temp2 >> num;

    //     if (num != 9999)
    //         tempvec.push_back(num);

    //     else if (num == 9999)
    //     {
    //        average = accumulate(tempvec.begin(), tempvec.end(), 0.0) / tempvec.size();

    //        outvec.push_back(average);
    //        tempvec.clear();
    //     }
    // }

    std::string line;
    while (getline(temp2, line)) //Getting lines up to '\n' from the input stream.
    {
        std::istringstream temp2(line); //Parsing out integers.
        int temp;
        while ( temp2 >> temp)
        {
            tempvec.push_back(temp); //Placing integers into a temporary vector.
        }

        average = accumulate(tempvec.begin(), tempvec.end(), 0.0) / tempvec.size(); //Averaging the set of numbers on a line.
        outvec.push_back(average); //Adding the average to final vector. 
        tempvec.clear(); //Clearing temporary vector.
    }

    temp2.close(); //Closing the file for completeness.

    return;
}

void usage(char* name[]) //Had some fun making a usage message so this seemed like a real command line tool.
{
    std::cout << "Usage: " << std::string(name[0]) << " [FILENAME] <option>" << std::endl << std::endl
         << "  -v       Toggle verbose output." << '\n'
         << "  -h       Display this message." << '\n';

    exit(1); //End program.
    return;
}