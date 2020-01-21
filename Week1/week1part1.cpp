#include <iostream>
using namespace std;
int main()
{
	int choice;
	float fheit, celc;
	cout << "Press 0 for Farenheit to Celsius\n";
	cout << "Press 1 for Celsius to Farenheit\n";
	cin >> choice;
	if (choice == 1) {
		cout << "Please enter a Farenheit value.\n";
		cin >> fheit;
		celc = (fheit - 32.0) / 1.8000;
		cout << "The tempreture ";
		cout << fheit;
		cout << " degrees Farenheit is: ";
		cout << celc;
		cout << " degrees Celsius.";
		return 0;
	}

	else if (choice == 2) {
		cout << "Please enter a Celsius value\n";
		cin >> celc;
		fheit = (celc * 1.8000) + 32.0;
		cout << "The tempreture ";
		cout << celc;
		cout << " degrees Celsius is: ";
		cout << fheit;
		cout << " degrees Farenheit.";
		return 0;
	}

	else {
		cout << "Invalid choice. Exiting.";
		return 0;
	}
}