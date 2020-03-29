/*
Author: Tanner Loy
Date: 1/21/20
Description: CLI tool for converting tempretures from Farenheit to Celsius.
*/

#include <iostream>
using namespace std;
void main()
{
	int choice;
	float fheit, celc; //Float values to allow for decimal.

	cout << "Press 1 for Farenheit to Celsius\n";
	cout << "Press 2 for Celsius to Farenheit\n";
	cin >> choice; //Input for user's choice. Not sure if there is a better way to do this (boolean or what have you).

	if (choice == 1) {
		cout << "Please enter a Farenheit value.\n";
		cin >> fheit;
		celc = (fheit - 32.0) / 1.8000; //Farenheit to Celsius conversion.
		cout << "The tempreture ";
		cout << fheit;
		cout << " degrees Farenheit is: ";
		cout << celc;
		cout << " degrees Celsius.\n";
	}

	else if (choice == 2) {
		cout << "Please enter a Celsius value\n";
		cin >> celc;
		fheit = (celc * 1.8000) + 32.0; //Celsius to Farenheit conversion.
		cout << "The tempreture ";
		cout << celc;
		cout << " degrees Celsius is: ";
		cout << fheit;
		cout << " degrees Farenheit.\n";
	}

	else {
		cout << "Invalid choice. Exiting.\n"; //Exception catch in case the user inputs an option that doesn't exist.
	}

	cout << "Press any key to continue."; //Program stop.
	cin.ignore();
	cin.get();
}