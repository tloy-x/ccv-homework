//Filename: week5part2.cpp
//Author: Tanner Loy
//Date: 2/21/2020
//Description: A program that takes a two numbers from the user and outputs the first numbers to the power of the second.

#include <iostream>
using namespace std;

double num1;
int exp1;
double exponentCalc(double numPar, int expPar);
						 //^This variable likes to throw a warning sometimes when it thinks the "num" and "Par" are seperate. If it happens, it will work anyway.  
int main()
{
	cout << "Please enter a number and an integer exponent." << endl;  //USER INPUT SECTION START
	cin >> num1;
	while (cin.fail()) //Catching an invalid user input (characters or strings).
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid, only numbers are allowed." << endl;
		cout << "Please enter a number." << endl;
		cin >> num1;

	}

	cin >> exp1;
	while (cin.fail()) //Catching an invalid user input (Floats, characters, or strings.)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid, only integers are allowed." << endl;
		cout << "Please enter an exponent." << endl;
		cin >> exp1;

	}																   //USER INPUT SECTION END
	
	cout << "The answer is: " << exponentCalc(num1, exp1) << endl; //OUTPUT SECTION START

	cout << "Press RETURN to exit...";

	cin.get();
	cin.ignore();

	return 0;													     
}	        													   //OUTPUT SECTION END

double exponentCalc(double numPar, int expPar)  //FUNCTION SECTION START
{
	int count = 1;			// Declaring local variables.
	double answer = numPar;  

	while (count < expPar) //While the variable count is less than the number of times multiplication has happend, keep going.
	{
		answer = answer * numPar; //Multiplying the given number by itself.
		count++; //Incrementing the variable "count".
	}

	return answer;								//FUNCTION SECTION END														
} 