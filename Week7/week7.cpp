//Date: 3/5/2020
//Filename: week7.cpp
//Author: Tanner Loy
//Description: A program that generates random prompts and scenarios from a list of words.

#include <iostream>
#include <string>
#include <ctime> //time(), for seeding srand.
#include <random> //srand(), rand().

using namespace std;

string adjs[] = { "epic", "evil", "friendly", "cool", "lonely", "possessed" }; //The next four declarations are wordlist arrays. I'm sure there is a better way to do this with classes or something, but this works just fine for me.
string nouns[] = { "judge", "police officer", "gamer", "spider", "bird", "zombie", "pig", "soldier" }; //None of the arrays have declared lengths, so I am able to add more words as much as I want without having to change that.
string enemies[] = { "doctor", "ghost", "farmer", "warrior", "robot", "egg", "gun", "horse", "gorverner" };
string locales[] = { "forest", "office", "coffee shop", "garden", "factory", "restaurant", "house", "painting" };

string ans;

string sentence(string adjective, string noun, string enemy, string location);
/*This function is used to create a sentence using the random words 
selected from the list, while also using programmed logic with the 
help of the vowelCheck function.*/

bool vowelCheck(string word);
/*This function takes the first letter of a chosen word and 
compares it against a list of vowels, to determine grammatical
usages (a vs an).*/

int main()
{
	cout << "--SCENARIO GENERATOR--" << endl << "Type \"exit\" at any time to exit." << endl; //You can type exit at any time, try it out!
	do
	{
		string strNoun, strAdj, strEnemy, strLocale; //Declaring many cool input values.

		srand((unsigned)time(0)); //Generating a seed based on UNIX time. One downside to this, is if it is done quick enough (more than once in one second), the outputs will be the same.

		strAdj = adjs[rand() % (sizeof(adjs) / sizeof(*adjs))]; //The next four declarations are getting random words from their respective lists.
		strNoun = nouns[rand() % (sizeof(nouns) / sizeof(*nouns))];
		strEnemy = enemies[rand() % (sizeof(enemies) / sizeof(*enemies))];
		strLocale = locales[rand() % (sizeof(locales) / sizeof(*locales))];

		cout << sentence(strAdj, strNoun, strEnemy, strLocale) << endl; //Calling the sentence function to create sentances.
		cout << "Press RETURN to generate another scenario..." << endl;
		getline(cin, ans); //Using getline() to either get input, or a lack of input.
		if (ans.empty()) //If getline() is empty or not "exit", nothing happens and the do-while loop continues.
		{}

	} while (ans != "exit"); //If getline() is equal to the exit command, the loop stops.
	cout << endl << "Press RETURN to exit...";
	cin.get();
	return 0;
}

bool vowelCheck(string word) //Function that returns a boolean value based on whether or not the input word starts with a vowel. It is only called when neccesary, as oppossed to being used on every word choice.
{
	const char vowels[5] = { 'a', 'e', 'i', 'o', 'u' };
	int i;
	bool voweled; //A fun new adjective.

	for (i = 0; i < 5; i++)
	{
		if (word.front() == vowels[i]) //Loops through all of the vowels in the vowels list.
		{
			voweled = true;
			break; //Breaks if a vowel is found, as to not have to go through every one.
		}
		else
			voweled = false;
	}
	return voweled;
}

string sentence(string adjective, string noun, string enemy, string location)
{	
	string moreWords[] = { " battles ", " fights ", " hugs ", " bakes a cake with ", " runs from ", " watches a movie with " };

	if (vowelCheck(adjective) == true) //Calling the vowelCheck function for grammar logic. This is only called when the sentance is going to use a preposition like a or an.
		cout << "An ";
	else
		cout << "A ";
	cout << adjective << " " << noun;

	if (vowelCheck(enemy) == true) //Calling the vowelCheck function for grammar logic.
		cout << moreWords[rand() % (sizeof(moreWords) / sizeof(*moreWords))] << "an "; //Also calling the moreWords array for some more variety.
	else
		cout << moreWords[rand() % (sizeof(moreWords) / sizeof(*moreWords))] << "a ";

	cout << enemy;

	if (vowelCheck(location) == true) //Calling the vowelCheck function for grammar logic.
		cout << " in an ";
	else
		cout << " in a ";

	cout << location; //Sorry that the whole sentence compilation/stucture ,

	return "."; //Returning a period for the end of the sentence.
} 

/*Authors note - I love using arrays for this sort of thing. All the forums say I should be using vectors,
but I'm so used to using arrays/lists from my python days, that I hust find it more concise and comfortable.
Before I start my next project, I will be learning how to use vectors effectively, so I can be apart of 
the "Cool Kids of StackOverflow" club. Thanks for reading! ~Tanner*/