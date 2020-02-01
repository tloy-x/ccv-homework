//Filename: Week2Homework.cpp
//Author: Tanner Loy
//Date: 1/30/2020
//Description: Calculates an employee's salary based on a sonstant pay increase.

#include <iostream> //Include directive for the iostream library. This allows for use of "cin" and "cout".
using namespace std; //Use directive for the standard namespace.

int main() //Declaring the main function.
{
	double const PAYINCREASE = 0.076; //Declaration of the constant variable PAYINCREASE. It being a constant variable means the value cannot be reassigned within the porgram without throwing errors.
	double annualSalary, retroactiveSalary, newAnnualSalary, newMonthlySalary; //I'm decalring these as doubles because they are going to represent dollar amounts, which use deciaml.
	char ans;
	bool b1; //Boolean value for later use in an input loop.

	do 
	{
		b1 = true; //Initializing the boolean "b1" to be true.
		cout << "Please enter your annual salary. $";
		cin >> annualSalary;
		while (cin.fail()) //Catching an input failure in the case of entering something that is not a number.
		{
			cin.clear(); //Clears input error
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Ignores the rest of the current line up to '\n'.
			cout << "Invalid response. Only numbers are allowed." << endl;
			cout << "Please enter your annual salary. $";
			cin >> annualSalary;
		}
		
		cout.setf(ios::fixed); //Setting precision for values with decimal points. Lifted from page 55 of Savitch.
		cout.setf(ios::showpoint);
		cout.precision(2);

		newAnnualSalary = annualSalary * PAYINCREASE + annualSalary; //Calculating the new annual salary by multiplying it by the pay increase to get the difference, then adding that to the current salary.
		retroactiveSalary = (annualSalary * PAYINCREASE) / 2; //Calculating the retroactive salary by taking the difference between the old annual salary and the new annual salary, and dividing it by 2 since it is only 6 months worth of wage. 
		newMonthlySalary = newAnnualSalary / 12; //Calculating the new monthly salary by taking the new annual salary and dividing it by 12 months.

		cout << "Previous annual salary is: $" << annualSalary << endl; //Adding "endl" to the ends of the declaration instead of "\n" because it looks cleaner.
		cout << "New annual salary is: $" << newAnnualSalary << endl;
		cout << "Retroactive salary due is: $" << retroactiveSalary << endl;
		
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
	} while (ans == 'y' || ans == 'Y'); //Breaks out of the do-while loop if the user answers yes to the question.

	cout << "Press RETURN to exit."; //Program stop. This is so the program doesn't just close instantly.
	cin.ignore();
	cin.get();
	return 0;
}
