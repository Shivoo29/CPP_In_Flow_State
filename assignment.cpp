// ============================================================
// VARIABLES AND ASSIGNMENT
// ------------------------------------------------------------
// Declaring a variable reserves a named box in memory of a fixed type.
// '=' is copy assignment: put a value in the box, replacing whatever
// was there. Reading a box you never wrote to gives you garbage.
//
// This file uses std:: instead of 'using namespace std;'. Both work.
// The explicit std:: is what larger projects prefer -- it says exactly
// where cout comes from and avoids name collisions.
// ============================================================

#include <iostream>

int main()
{
	int width; // define a variable named width
	           // no value yet -- reading it right now would be garbage
	width = 5; // copy assignment of value 5 into variable width

	std::cout << width; // prints 5

	width = 7; // change value stored in variable width to 7
	           // the old 5 is simply overwritten and gone

	std::cout << width; // prints 7

	// Note: no endl anywhere, so the output runs together as "57".
	return 0;   // 0 tells the OS the program succeeded
}
