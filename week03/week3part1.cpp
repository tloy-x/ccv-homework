#include <iostream>
using namespace std;

int main() {
	double input1, input2, sum, diff, prod;
	int quot;

	cout << "Please enter two numbers." << endl;

	cout << "Number 1:";
	cin >> input1;
	while (cin.fail()) //Catching an input failure in the case of entering something that is not a number.
	{
		cin.clear(); //Clears input error
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Ignores the rest of the current line up to '\n'.
		cout << "Invalid response. Only numbers are allowed." << endl;
		cout << "PLease enter your first number: ";
		cin >> input1;
	}

	cout << "Number 2:";
	cin >> input2;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid response. Only numbers are allowed." << endl;
		cout << "Please enter a second number: ";
		cin >> input2;
	}
	if (input2 == 0) //Catches if the second number is 0. This would cause problems when dividing if it were not caught.
	{
		cout << "Invalid response. Zero is not allowed." << endl;
		cout << "Please enter a second number: ";
		cin >> input2;
	}

	sum = input1 + input2;

	diff = input1 - input2;
	if (diff < 0.00)
	{
		diff = diff * -1;
	}

	prod = input1 * input2;

	quot = input1 / input2;

	cout << "\nThe sum of " << input1 << " and " << input2 << " is: " << sum << endl;
	cout << "The difference between " << input1 << " and " << input2 << " is: " << diff << endl;
	cout << "The product of " << input1 << " and " << input2 << " is: " << prod << endl;
	cout << "The quotent of " << input1 << " and " << input2 << " is: " << quot << endl;

	cout << "\nPress ENTER to continue..." << endl;

	cin.ignore();
	cin.get();
}