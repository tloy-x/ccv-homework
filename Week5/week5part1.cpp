//Author: Tanner Loy
//Date: 2/19/2020
//Filename: week5part1.cpp
//Description: A program that takes 5 user inputs, and outputs the average.

#include <iostream>
using namespace std;

double numbers[5]; //Decalring a list of five numbers.
double averageCalc(double valueList[]); //Declaring a function
int i;

int main()
{
	cout << "Please enter five values for averaging." << endl;												//USER INPUT SECTION START
	for (i = 0; i < 5; i++) //For statement to take 5 user inputs, and add each to an array.				 
	{
		cout << "Enter value " << i + 1 << ": ";
		cin >> numbers[i]; //Sets user input equal to an array index, and the increments the index value.
		while (cin.fail()) //Catching if the user input is not a number.
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid response. Only numbers are allowed." << endl;
			cout << "Enter value " << i + 1 << ": "; //Tells the user which input they are currenly inputing. The value is i + 1, because i starts at 0.
			cin >> numbers[i];
		}

	}																										//USER INPUT SECTION END

	cout << "The average of your numbers is: " << averageCalc(numbers) << endl;								//OOUTPUT SECTION START

	cout << "\nPress RETURN to exit...";

	cin.get();
	cin.ignore();

	return 0;
}																											//OUTPUT SECTION END

double averageCalc(double valueList[])																		//FUNCTION SECTION START
{
	double sum = 0, average; //Declaring two local doubles I will need for the function.

	for (i = 0; i < 5; i++) //For loop stating that while the index of the list is less than 5, increment i, and continue.
	{						//i is equal to 0 because arrays start at 0.
		sum = sum + valueList[i]; //Re-assigning sum to equal sum plus the next value in the array.
	}

	average = sum / 5; //Getting the average by dividing the sum by the size of the array.
		 
	return average; //Returning the value average.
}																											//FUNCTION SECTION END