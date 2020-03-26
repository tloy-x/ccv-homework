//Author: Tanner Loy
//Date: 2/26/2020
//Filename: week6.cpp
//Description: A multipurpose calculator program made to demonstrate the use of a menu.

#include <iostream>
#include <algorithm> //Importing the algorithm library so I can use the sort function.
#include <string> //Importing the string library so I can declare string variables and functions.

using namespace std;

int i;
double highest(double numArr[]); //Declaring the highest function with an array.
string reverse(int myInt);
double parkCharge(double parkedTime);
char ans;

int main()
{
	do
	{
		int choice;
		cout << "--Multipurpose Calculator--" << endl; //User menu output.
		cout << "Select an option..." << endl;
		cout << "1 - Enter three numbers and determine the highest value." << endl;
		cout << "2 - Reverse an integer." << endl;
		cout << "3 - Calculate Parking Garage Charges." << endl;
		cout << "4 - Exit" << endl;

		cin >> choice; 

		switch (choice) //Switch statement for choosing menu options. This is more readable than a bunch of if-then statements (don't worry, there are some later).
		{
		case 1:
			double numbers[3]; //Declaring an array with 3 values
			cout << "You chose option 1. ";
			cout << "Please enter three numbers..." << endl;

			for (i = 0; i < 3; i++) //Getting 3 user inputs
			{
				cout << "Enter value " << i + 1 << ": ";
				cin >> numbers[i];
				while (cin.fail()) //Input cleaning.
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Invalid, only numbers are allowed";
					cout << "Enter value " << i + 1 << ": ";
					cin >> numbers[i];
				}
			}
			cout << "The greatest number is " << highest(numbers); //Calling highest function.
			break;

		case 2:
			int mynum; //Declaring a local variable.
			cout << "You chose option 2. ";
			cout << "Please enter an integer for reversing..." << endl;
			cin >> mynum;
			while (cin.fail()) //Input cleaning.
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid, non-integer entered, or integer too long.";
				cout << "\nEnter an integer :";
				cin >> mynum; 
			}

			cout << "Your new number is: " << reverse(mynum); //Calling the reverse function.
			break;

		case 3:
			double hours; //Declaring a local variable.
			cout << "You chose option 3. ";
			cout << "Please enter the total time in parked in the garage in hours..." << endl;
			cin >> hours;
			while (cin.fail()) //Input cleaning.
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid, only numbers are allowed";
				cout << "\nEnter the total time in parked in the garage in hours:";
				cin >> hours;
			}
			parkCharge(hours); //Calling the parkCharge function.
			break;

		case 4:
			cout << "You chose option 4. ";
			cout << "Exiting...";
			break;

		default: //Catching if he user inputs something invalid (not 1-4).
			cout << "Invalid response.";
		}

		if (choice != 4) //A little bit of code that gives consitent input based on whther or not the user inputted 4 (exit) as their choice.
		{
			cout << "\nWould you like to do it start over? y/n..." << endl;
			cin >> ans;

			while (true) //Simple while true loop. It's purpose is just to be a loop without a real condition.
			{
				if (ans == 'y' || ans == 'Y')
				{
					cout << endl;
					break; //Breaks for valid response.
				}
				else if (ans == 'n' || ans == 'N')
				{
					cout << "See you next time!";
					break; //Breaks for valid response.
				}
				else
				{
					cout << "Invalid response, try again." << endl;
					cin >> ans; //Asks for input if invalid response.
				}

			}
		}
		else
			ans = 'n';
	} while (ans == 'y' || ans == 'Y'); //Loops if the user enters yes to the question.

	cout << "\nPress RETURN to exit...";
	cin.get();
	cin.ignore();
	return 0;
}

double highest(double numArr[])
{
	sort(numArr, numArr + 3, greater<double>()); //Sorting the array into a descending order.
	return numArr[0]; //Returning the beginning of the list, since it is the largest when sorted.
}

string reverse(int myInt) //The way that this is coded makes it do funky stuff with negative numbers.
{
	string intStr = to_string(myInt); //Converts your number to a string.
	reverse(intStr.begin(), intStr.end()); //Reverse said string.
	return intStr; //Return reversed string.
}

double parkCharge(double parkedTime)
{

	cout.setf(ios::fixed); //Setting decimal precision.
	cout.setf(ios::showpoint); 
	cout.precision(2); 
	 
	double fee12, feeplus12, total;
	const double regRate = 3.75;
	const double plusRate = 5.00;
	if (parkedTime > 12 && parkedTime < 24) //Setting up if statements for the different edge cases.
	{
		fee12 = 12 * regRate; //Calculating the prices based on hourly rates.
		feeplus12 = (parkedTime - 12) * plusRate;
		total = fee12 + feeplus12;

		cout << "$" << fee12 << " For 12 hours at $3.75/hour." << endl; //Printing output from the function.
		cout << "$" << feeplus12 << " For " << parkedTime - 12 << " hours at $5.00/hour." << endl;
		cout << "Your total is $" << total << ". Have a nice day!";
	}
	else if (parkedTime <= 12) //Calculating the price for a 12 hour or less stay.
	{
		total = parkedTime * regRate;
		cout << "$" << total << " For " << parkedTime << " hours at $3.75/hour." << endl;
		cout << "Your total is $" << total << ". Have a nice day!";
	}
	else if (parkedTime <= 0) //Edge case for if no time was spent parked.
	{
		cout << "Invalid amount of hours.";
	}
	else if (parkedTime > 24) //Edge case for the maximum allowed time to be parked.
	{
		cout << "Time parked is too long.";
	}

	return 0;
}