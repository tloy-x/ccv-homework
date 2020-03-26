//Date: 3/16/2020
//Author: Tanner Loy
//Filename: main.cpp
//Description: A multipurpose program that calclates labor costs for painting walls and ceilings, and replacing floors.

/*
Authors note: This code is very messy and weird. I spent a few days strugging to find an easy way to do
this, and I ended up with this. There are some clever bits, like the input VALIDATION, not cleaning.
I got so tired of writing this particular program, that I'm not going to add input cleaning into the line
count. So please don't enter strings instead of doubles. I'm begging you. If I DID work up the strength
to put input cleaning in, I'll put a smaller note under this one. Thanks for reading! ~Tanner
*/

/*
Fixed it! I'll leave the above comment in because I feel like it.
*/

#include <iostream> //cin, cout
#include <string> //string
#include <algorithm> //find()
#include <iterator> //begin(), end()
#include <vector> //vector
#include <numeric> //accumulate

using namespace std;

vector<string> choicesMain = { "EXIT", "PAINT", "FLOOR", "BOTH" }; //Using this technique throughout the program to determine if user input is valid.
bool checker(string& INSTRING, vector<string> INVEC); //Checks user input against a wordlist vector.
void cleaner(string& INSTRING); //Cleans user input by converting it to uppercase.
void initialize(int& count); //Initializing the program on start/restart.
void finalOut(double paintPrice, double floorPrice); //Makes my life easier.

double paint(double sqft, string choice); //Calculates painting charges for walls OR ceiling.
double paintBoth(double wallSQFT, double ceilSQFT); //Calculates charges for walls ANS ceiling.
double floor(double sqft, string floorchoice); //Calculates charges for replacing flooring.

bool yesBoth = false; //Boolean for use in the paint() function.
string ans;

int main()
{
	cout.setf(ios::fixed); //Setting decimal precision.
	cout.setf(ios::showpoint);
	cout.precision(2);

	int count = 0;
	do
	{
		string choice, choicePaint, choiceFloor; //USER INPUT START

		initialize(count); //Calls the initializer at program start/restart.
		cin >> choice;
		while (true)
		{
			if (checker(choice, choicesMain)) //Checks choice against choicesMain list.
			{
				break;
			}
			else
			{
				cout << "Invalid response, try again.\n"; //Catches invalid input.
				cin >> choice;
			}
		}

		if (choice == "PAINT") //Case for PAINT input path.
		{
			int i, wallcount;
			yesBoth = false;
			vector<double> walls; //Declaring a new vector. Vectors are cool for this purpose, since they are dynamially size, as opposed to arrays which are of static size.
			double sqft;

			vector<string> choicesPaint = { "WALL", "CEIL", "BOTH" }; //Local vector for the PAINT path.
			cout << "Are you painting WALLs, CEILings, or BOTH?\n";
			cin >> choicePaint;
			while (true)
			{
				if (checker(choicePaint, choicesPaint))
				{
					break;
				}
				else
				{
					cout << "Invalid response, try again.\n";
					cin >> choicePaint;
				}
			}

			if (choicePaint == "WALL") //Case for PAINT->WALL path.
			{
				walls.clear();
				cout << "How many rooms are your painting?\n";
				cin >> wallcount;
				while (cin.fail()) //Input cleaning.
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Invalid, only integers are allowed\n";
					cout << "How many rooms are your painting?\n";
					cin >> wallcount;
				}

				if (wallcount > 1)
				{
					double o;
					for (i = 1; i <= wallcount; i++)
					{
						cout << "Enter square footage of room " << i << endl;
						cin >> o;
						while (cin.fail()) //Input cleaning.
						{
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout << "Invalid, only numbers are allowed\n";
							cout << "Enter square footage of room " << i << endl;
							cin >> o;
						}
						walls.push_back(o);
					}

					sqft = accumulate(walls.begin(), walls.end(), 0.0);

				}
				else
				{
					cout << "Enter square footage\n";
					cin >> sqft;
					while (cin.fail()) //Input cleaning.
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Invalid, only numbers are allowed\n";
						cout << "Enter square footage\n";
						cin >> sqft;
					}
				}

				cout << "The total price of labor will be $" << paint(sqft, choicePaint) << " for " << sqft << " square feet of walls." << endl;
			}
			else if (choicePaint == "CEIL") //Case for PAINT->CEIL path.
			{
				cout << "Enter square footage\n";
				cin >> sqft;
				while (cin.fail()) //Input cleaning.
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Invalid, only numbers are allowed\n";
					cout << "Enter square footage\n";
					cin >> sqft;
				}
				cout << "The total price of labor will be $" << paint(sqft, choicePaint) << " for " << sqft << " square feet of ceilings." << endl;
			}

			else if (choicePaint == "BOTH") //Case for PAINT->BOTH path.
			{
				walls.clear();
				double wallsqft, ceilsqft;

				cout << "How many rooms are your painting?\n";
				cin >> wallcount;
				while (cin.fail()) //Input cleaning.
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Invalid, only integers are allowed\n";
					cout << "How many rooms are your painting?\n";
					cin >> wallcount;
				}

				if (wallcount > 1)
				{
					double o;
					for (i = 1; i <= wallcount; i++)
					{
						cout << "Enter wall square footage of room " << i << endl;
						cin >> o;
						while (cin.fail()) //Input cleaning.
						{
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout << "Invalid, only numbers are allowed\n";
							cout << "Enter square footage of room " << i << endl;
							cin >> o;
						}
						walls.push_back(o);
					}

					wallsqft = accumulate(walls.begin(), walls.end(), 0.0);
				}
				else
				{
					cout << "Enter square footage of walls\n";
					cin >> wallsqft;
					while (cin.fail()) //Input cleaning.
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Invalid, only numbers are allowed\n";
						cout << "Enter square footage of walls\n";
						cin >> wallsqft;
					}
				}

				cout << "Enter square footage of ceilings\n";
				cin >> ceilsqft;
				while (cin.fail()) //Input cleaning.
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Invalid, only numbers are allowed";
					cout << "Enter value.";
					cin >> ceilsqft;
				}

				cout << "The total price of labor will be $" << paintBoth(wallsqft, ceilsqft) << " for " << wallsqft << " square feet of walls and " << ceilsqft << " square feet of ceilings." << endl;

				cout << endl;

			}
		}
		else if (choice == "FLOOR") //Case for FLOOR path.
		{
			double sqft;
			vector<string> choicesFloor = { "WOOD", "TILE", "OTHER" };
			cout << "Are you installing WOOD, TILE, or OTHER flooring?\n";
			cin >> choiceFloor;
			while (true)
			{
				if (checker(choiceFloor, choicesFloor))
				{
					break;
				}
				else
				{
					cout << "Invalid response, try again.\n";
					cin >> choiceFloor;
				}
			}
			cout << "How many square feet of flooring are you replacing?\n";
			cin >> sqft;
			while (cin.fail()) //Input cleaning.
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid, only numbers are allowed\n";
				cout << "How many square feet of flooring are you replacing?\n";
				cin >> sqft;
			}

			cout << "The total price of labor will be $" << floor(sqft, choiceFloor); //Function takes user entered square footage and their flooring choice for calculating different rates.
			cout << " for " << sqft << " square feet of ";
			transform(choiceFloor.begin(), choiceFloor.end(), choiceFloor.begin(), ::tolower);
			cout << choiceFloor << " flooring.\n";
		}
		else if (choice == "BOTH") //Case for BOTH path.
		{
			double paintprice, floorprice;
			int i, wallcount;
			yesBoth = false;
			vector<double> walls;
			double wallsqft, ceilsqft;

			vector<string> choicesPaint = { "WALL", "CEIL", "BOTH" };
			cout << "Are you painting WALLs, CEILings, or BOTH?\n";
			cin >> choicePaint;
			while (true)
			{
				if (checker(choicePaint, choicesPaint))
				{
					break;
				}
				else
				{
					cout << "Invalid response, try again.\n";
					cin >> choicePaint;
				}
			}

			if (choicePaint == "WALL") //Case for BOTH->WALL path.
			{
				walls.clear();
				cout << "How many rooms are your painting?\n";
				cin >> wallcount;
				while (cin.fail()) //Input cleaning.
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Invalid, only integers are allowed\n";
					cout << "How many rooms are your painting?\n";
					cin >> wallcount;
				}

				if (wallcount > 1)
				{
					double o;
					for (i = 1; i <= wallcount; i++)
					{
						cout << "Enter square footage of room " << i << endl;
						cin >> o;
						while (cin.fail()) //Input cleaning.
						{
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout << "Invalid, only integers are allowed\n";
							cout << "How many rooms are your painting?\n";
							cin >> wallcount;
						}
						walls.push_back(o);
					}

					wallsqft = accumulate(walls.begin(), walls.end(), 0.0);

				}
				else
				{
					cout << "Enter square footage\n";
					cin >> wallsqft;
					while (cin.fail()) //Input cleaning.
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Invalid, only numbers are allowed\n";
						cout << "Enter square footage of walls\n";
						cin >> wallsqft;
					}
				}

				paintprice = paint(wallsqft, choicePaint);
			}
			else if (choicePaint == "CEIL")//Case for BOTH->CEIL path.
			{
				cout << "Enter square footage\n";
				cin >> ceilsqft;
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Invalid, only numbers are allowed";
					cout << "Enter value.";
					cin >> ceilsqft;
				}
				paintprice = paint(ceilsqft, choicePaint);

			}

			else if (choicePaint == "BOTH")//Case for BOTH->BOTH path.
			{
				walls.clear();
				cout << "How many rooms are your painting?\n";
				cin >> wallcount;
				while (cin.fail()) //Input cleaning.
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Invalid, only integers are allowed\n";
					cout << "How many rooms are your painting?\n";
					cin >> wallcount;
				}

				if (wallcount > 1)
				{
					double o;
					for (i = 1; i <= wallcount; i++)
					{
						cout << "Enter wall square footage of room " << i << endl;
						cin >> o;
						while (cin.fail()) //Input cleaning.
						{
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout << "Invalid, only numbers are allowed\n";
							cout << "Enter square footage of room " << i << endl;
							cin >> o;
						}
						walls.push_back(o);
					}

					wallsqft = accumulate(walls.begin(), walls.end(), 0.0);
				}
				else
				{
					cout << "Enter square footage of walls\n";
					cin >> wallsqft;
					while (cin.fail()) //Input cleaning.
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Invalid, only numbers are allowed\n";
						cout << "Enter square footage of walls\n";
						cin >> wallsqft;
					}
				}

				cout << "Enter square footage of ceilings\n";
				cin >> ceilsqft;
				while (cin.fail()) //Input cleaning.
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Invalid, only numbers are allowed";
					cout << "Enter value.";
					cin >> ceilsqft;
				}

				paintprice = paintBoth(wallsqft, ceilsqft);

				cout << endl;

			}

			double floorsqft;
			vector<string> choicesFloor = { "WOOD", "TILE", "OTHER" };
			cout << "Are you installing WOOD, TILE, or OTHER flooring?\n";
			cin >> choiceFloor;
			while (true)
			{
				if (checker(choiceFloor, choicesFloor))
				{
					break;
				}
				else
				{
					cout << "Invalid response, try again.\n";
					cin >> choiceFloor;
				}
			}
			cout << "How many square feet of flooring are you replacing?\n";
			cin >> floorsqft; 
			while (cin.fail()) //Input cleaning.
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid, only numbers are allowed\n";
				cout << "How many square feet of flooring are you replacing?\n";
				cin >> floorsqft;
			}//USER INPUT END

			floorprice = floor(floorsqft, choiceFloor);

			if (choicePaint == "WALL")
				cout << "The total price for wall paint is $" << paintprice << " for " << wallsqft << " square feet of walls." << endl; //OUTPUT START
			else if (choicePaint == "CEIL")
				cout << "The total price of ceiling paint is $" << paintprice << " for " << ceilsqft << " square feet of ceilings." << endl;
			else if (choicePaint == "BOTH")
				cout << "The total price of labor will be $" << paintprice << " for " << wallsqft << " square feet of walls and " << ceilsqft << " square feet of ceilings." << endl;


			cout << "The total price of floor labor is $" << floorprice;
			cout << " for " << floorsqft << " square feet of ";
			transform(choiceFloor.begin(), choiceFloor.end(), choiceFloor.begin(), ::tolower);
			cout << choiceFloor << " flooring.\n";

			finalOut(paintprice, floorprice); //OUTPUT END
		}
		else if (choice == "EXIT") //Exit condition.
		{
			cout << "Exiting...\n";
			cout << "Press RETURN to exit...";
			cin.get();
			cin.ignore();
			return 0;
		}
		else
		{
			cout << "error";
		}

		cout << "Would you like to make another calculation? y/n\n";
		cin >> ans;
		while (cin.fail()) //Input cleaning.
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid, only chars are allowed\n";
			cout << "Would you like to make another calculation ? y / n\n";
			cin >> ans;
		}
	}while (ans == "y");

	cout << "Press RETURN to exit...";
	cin.get();
	cin.ignore();
	return 0;
}

bool checker(string& INSTRING, vector<string> INVEC)
{
	transform(INSTRING.begin(), INSTRING.end(), INSTRING.begin(), ::toupper); //Transforms input to uppercase.
	bool exists = find(begin(INVEC), end(INVEC), INSTRING) != end(INVEC); //Checks input against inputted vector.
	return exists; //Returns boolean value.
}

void cleaner(string& INSTRING)
{
	transform(INSTRING.begin(), INSTRING.end(), INSTRING.begin(), ::toupper); //Cleans user input by converting to uppercase.
	return;
}

double paint(double sqft, string choice)
{
	const double wallTime = .0125; //Hours per sqft
	double wallPrice, ceilPrice, regPrice, discPrice, rate, ceilRate, discRate;
	const double ceilTime = .016; //Hours per sqft

	rate = .50; //$ per sqft (2.5hrs / 200sqft = .0125hrs per sqft, * $40 per hour = $.50 per sqft)
	ceilRate = .64; //$ per sqft (see above)
	discRate = rate - (rate * 0.15); //%15 discout to rate.
	if (choice == "WALL") //Usage of passing the choice argument.
	{
		if (sqft <= 1400.00) //Case for when the square footage of the walls are less than 1400.
		{
			wallPrice = sqft * rate;
			return wallPrice;
		}
		else if (sqft > 1400.00) //Case for when the square footage of the walls are more than or equal to 1400.
		{
			regPrice = 1400.00 * rate;
			discPrice = (sqft - 1400.00) * discRate;
			wallPrice = regPrice + discPrice;

			return wallPrice;
		}
		else if (sqft == 0)
			cout << "Square footage cannot be 0" << endl;
	}
	else if (choice == "CEIL") //Calculation for ceiling prices.
	{
		ceilPrice = sqft * ceilRate;
		return ceilPrice;
		
	}
	return 0;
}

double paintBoth(double wallSQFT, double ceilSQFT)
{
	double price, wallPrice, ceilPrice, regPrice, discPrice, rate, ceilRate, discRate;

	rate = .50; //$ per sqft (2.5hrs / 200sqft = .0125hrs per sqft, * $40 per hour = $.50 per sqft)
	ceilRate = .64; //$ per sqft (see above).
	discRate = rate - (rate * 0.15);
	if (wallSQFT <= 1400.00)
	{
		wallPrice = wallSQFT * rate;
	}
	else if (wallSQFT > 1400.00)
	{
		regPrice = 1400.00 * rate;
		discPrice = (wallSQFT - 1400.00) * discRate;
		wallPrice = regPrice + discPrice;
	
	}
	else if (wallSQFT == 0)
		cout << "Square footage cannot be 0" << endl;

	ceilPrice = ceilSQFT * ceilRate;
	
	price = ceilPrice + wallPrice;
	return price;
}

double floor(double sqft, string floorchoice)
{
	double floorprice, woodrate, tilerate, otherrate;

	woodrate = .96; //$ per sqft.
	tilerate = 1.46; //$ per sqft.
	otherrate = .51; //$ per sqft.

	if (floorchoice == "WOOD")
	{
		floorprice = sqft * woodrate;
		return floorprice;
	}
	else if (floorchoice == "TILE")
	{
		floorprice = sqft * tilerate;
		return floorprice;
	}
	else if (floorchoice == "OTHER")
	{
		floorprice = sqft * otherrate;
		return floorprice;
	}
	return 0;
}

void initialize(int& count)
{
	if (count == 0) //Checking if the function has been run yet.
	{
		cout << "--LABOR CALCULATOR--\n";
		cout << "Type EXIT at any time to exit!\n";
		cout << "Are you PAINTing the interior of a house, replacing FLOORing, or BOTH?\n";
		count++;
	}
	else
	{
		cout << "\n\n\n\n\n"; //Five newlines on a program restart.
		cout << "--LABOR CALCULATOR--\n";
		cout << "Type EXIT at any time to exit!\n";
		cout << "Are you PAINTing the interior of a house, replacing FLOORing, or BOTH?\n";
		count++;
	}
}

void finalOut(double paintPrice, double floorPrice)
{
	double total;
	total = paintPrice + floorPrice;
	cout << "The grand total of your order is $" << total << endl; //Makes my life easy.
}
