#include <iostream>
using namespace std;

int i;
double numbers[4], sum, mean;
int length = sizeof(numbers) / sizeof(double);

int main()
{
	for (i = 0; i < 4; i++) //For statement to take four (4) user inputs, and add them to an array.
	{
		cout << "Enter a value: ";
		cin >> numbers[i]; //Sets user input equal to an array index, and the increments teh index value.
	}

	for (i = 0; i <= 4; i++) //Same as the above statement, except for the use of "i <= 4". This makes sure it adds all 4 values together.  
	{						 //If I used "i < 4", I would only get values up to index 4, and the calculation would stop.
		sum = sum + i; //Sets "sum" equal to sum plus whatever is in index i.
	}
	cout << endl << "The sum is: " << sum;

	
 
	mean = sum / 4; //Takes sum divied by 4 to get the average of the four numbers. I can also use "length = sizeof(numbers) / sizeof(double);" if I dont know how long the array is to begin with.
	cout << endl << "The mean is: " << mean << endl;


	cout << "Press RETURN to exit...";
	cin.get();
	cin.ignore();
	return 0;
}