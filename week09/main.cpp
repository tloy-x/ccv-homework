//Usage: week9.exe [input filename], or: week9.exe

//Date: 3/21/2020
//Filename: main.cpp, week9.exe
//Author: Tanner Loy
//Description: A program that takes four numbers and calculates the variance and standard deviation.
//It can take input from a file and output to a file, or be run stand-alone in terminal.

#include <iostream> //cin, cout
#include <vector> //vector
#include <fstream> //ifstream, ofstream
#include <cmath> //sqrt, pow
#include <numeric> //accumulate
#include <stdlib.h> //exit

using namespace std;

vector<double> numbers;

double varicalc(vector<double> invec);

int main(int argc, char* argv[])
{
	ifstream inFile; //Declaring an input stream.

	if (argc == 2) //Checking if the program was run in console or not.
	{
		inFile.open(argv[1]); //Setting input filename equal to the second argument of the invocation in terminal.
		if (inFile.fail())
		{
			cout << "Failure opening input file, exiting"; //Catching open error.
			exit(1);
		}

		double value;
		int i;
		for (i = 0; i < 4; i++)
		{
			inFile >> value; //Setting value equal to one lines of inFile at a time, using the extract operator.
			while (inFile.fail()) //Checking if the values entered by file are valid.
			{
				inFile.clear();
				inFile.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Error, value number " << i + 1 << " is invalid or missing. Exiting";
				exit(1); //If not, exit.
			}
			numbers.push_back(value); //Putting the values at the end of a vector, vector style.
		}

		ofstream outFile; //Declaring an output stream

		outFile.open("output_" + string(argv[1]));
		if (outFile.fail()) //Catching open error.
		{
			cout << "Failure opening output file, exiting.";
			exit(1);
		}

		outFile << "Variance is: " << varicalc(numbers) << endl
			<< "Standard Deviation is: " << sqrt(varicalc(numbers));

		inFile.close(); //Be kind! Please close files.
		outFile.close();

		cout << "Done.";
	}

	else if (argc == 1) //Checking if the program was run in console or not.
	{
		vector<double> nums(4); //Declaring a vectoir with a size of 4.
		cout << "Enter 4 numbers for calculation.\n";

		int i;
		for (i = 0; i < 4; i++) //Taking 4 numbers as input.
		{
			cin >> nums[i]; //Putting the values at the end of a vector, array style.
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid, only numbers are allowed.\n";
				cout << "Enter number " << i + 1 << ": ";
				cin >> nums[i];
			}
		}

		cout << "Variance is: " << varicalc(nums) << ".\n" //Output to screen.
			<< "Standard Deviation is: " << sqrt(varicalc(nums)) << ".\n"; //Output to screen.

		cout << "Press RETURN to exit.";
		cin.ignore();
		cin.get();
	}

	else if (argc > 2) //Catching if there are too many arguments
	{
		cout << "Error, too many arguments.";
		exit(1);
	}
		
	else //Catching all other errors.
	{
		cout << "Unknown error, exiting.";
		exit(1);
	}

	return 0;
}

double varicalc(vector<double> invec) //Oh boy oh boy, here comes the meat and potatoes of this program. 
{
	double average, variance;
	vector<double> temp(4); //Declaring a temporary vector with a size of 4.

	average = accumulate(invec.begin(), invec.end(), 0.0) / 4; //Getting the average of the input vector.

	for (int i = 0; i < 4; i++) //Subtracting the average from each value in the input vector, adding them to temp, array style.
	{
		temp[i] = invec[i] - average; //Sum of temp = 0.
	}

	for (int i = 0; i < 4; i++)
	{
		temp[i] = pow(temp[i], 2); //Squaring each value in temp.
	}

	variance = accumulate(temp.begin(), temp.end(), 0.0) / 4; //Calculating variance by getting the average of the new vector.

	return variance; //Returning variance for usage in output. Standard deviation is calculated by taking the square root of of this value.
}