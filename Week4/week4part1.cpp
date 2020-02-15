#include <iostream>
using namespace std;

int main()
{
	int mynum = 19; //Initializing the starting number.

	for (int n = 1; mynum <= 65; mynum = mynum + n) //For statement initializing the value 'n', the conditional "while mynum is less than or equal to 65", and the update action "add 1 to mynum".
		if (mynum == 46) //If mynum is equal to 46, skip the cout step.
			; //This is an empty statement. Equivilent of "do nothing". In Python, I would use the "pass" statement for the same effect.
		else
			cout << mynum << endl;

	cout << "Press RETURN to exit...";
	cin.get();
	
	return 0;
}