#include <iostream>
using namespace std;

int main()
{
	double fat, protein; //Declared as doubles to allow for decimal numbers.
	bool b1; //Boolean value for later.
	char ans; //Char value for y/n user input

	do //Do-While statement so the loop happens at least once.
	{
		b1 = true; //Initializing the boolean "b1'.
		cout << "Enter a fat percentage: %";
		cin >> fat;

		while (cin.fail()) //Catching an input failure in the case of entering something that is not a number.
		{
			cin.clear(); //Clears input error
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Ignores the rest of the current line up to '\n'.
			cout << "Invalid response. Only numbers are allowed." << endl;
			cout << "Enter a fat percentage: % ";
			cin >> fat;
		}

		cout << "Enter a protein percentage: %";
		cin >> protein;

		while (cin.fail()) //Catching an input failure in the case of entering something that is not a number.
		{
			cin.clear(); //Clears input error
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Ignores the rest of the current line up to '\n'.
			cout << "Invalid response. Only numbers are allowed." << endl;
			cout << "Enter a protein percentage: % ";
			cin >> protein;
		}

		if (fat < 18 && protein > 23) { //All of these if statements use the "&&" operator to compare against multiple values.
			cout << "Your dog food is Super Premium!\n";
		}
		else if (18 <= fat && fat < 20 && 23 >= protein && protein > 20) {
			cout << "Your dog food is premium!\n";
		}
		else if (20 <= fat && fat < 25 && 20 >= protein && protein > 16) {
			cout << "Your dog food is of normal quality.\n";
		}
		else if (25 <= fat && fat < 40 && 16 >= protein && protein > 8) {
			cout << "Your dog food is of 'not so great' quality. Go to Petco!\n";
		}
		else if (fat >= 40) { //This is a failsafe for when the fat content does not fit in any category. 
			cout << "Fat content is too high for calculation.\n";
		}
		else if (protein <= 8) { //Same for this.
			cout << "Error. Protein content too low for calculation.\n";
		}
		else if (fat >= 40 && protein <= 8) { //And this one.
			cout << "Error. Protein and fat content too low for calculation.\n";
		}
		else { //Blanket else statement 
			cout << "Unable to do calculation: numbers do not fit into a specified range.";
		}

		while (b1 == true) //A while loop using the boolean "b1". The boolean is never really set to false, so the loop will keep going until it is broken.
		{
			cout << "Would you like do another calculation? y/n" << endl; //This is put at the head of the loop to make sure it is not recursive.
			cin >> ans;

			if (ans == 'y' || ans == 'Y') //Allows for lowercase and uppercase answers.
			{
				break; //Breaks out of the loop.
			}

			else if (ans == 'n' || ans == 'N') //Allows for lowercase and uppercase answers.
			{
				break; //Breaks out of the loop.
			}

			else //If an answer other than "y" or "n" is given, this exception is caught.
			{
				cout << "Invalid response. Try again." << endl; //This is the only option that doesn't break the loop. Instead, it repeats the loop by asking for the user input again.
			}
		}
	} while (ans == 'y' || ans == 'Y');

	cout << "Press RETURN to exit...";
	cin.ignore();
	cin.get();
	return 0;
}