/*
Author: Tanner Loy
Date: 1/21/20
Description: Program that prints some values.
*/

#include <iostream>
using namespace std;

int main()
{
    cout << 15 + 35; //This is simple addition, nothing wacky going on here.
    putchar('\n');

    cout << 5 + 10 * 3; //Here's where it gets a little weird if you're nor paying attention. Using Order of operations, we know to do the multiplication first, and this gives us 35.
    putchar('\n');

    cout << 5 * 10 + 3; //This one is also using order of operations, but it looks normal since it can be done from left to right regularly.
    putchar('\n');

    cout << "5 * 10 + 3"; //This is a string. No math is being done.
    putchar('\n');
    
    cout << "Press any key to continue."; //Program stop, for easy reading.
    cin.get();
    return 0;
}
