// ============================================================
// ENUMS (enumerations)
// ------------------------------------------------------------
// A set of named integer constants. Instead of remembering that
// "state 2 means paused", you write Paused. Same speed as an int at
// runtime -- the names exist only for the compiler and for you.
// ============================================================

#include <iostream>
using namespace std;

enum Example{
    a,b,c // enum is a user-defined data type that consists of integral constants. It is used to assign names to the integral constants which makes a program easy to read and maintain
          // Values auto-number from 0: a=0, b=1, c=2. You can set them
          // yourself too (a=5, b, c gives 5, 6, 7).
};

int main (){
    Example value = b;
    if (value == b){
        // Printing an enum prints its underlying number, so this
        // shows 1, not "b". C++ has no built-in name lookup for enums.
        cout << "Value of b is:" << b << endl;
    }
}

// Worth knowing: 'enum class Example { a, b, c };' is the modern,
// safer form. Its names are scoped (Example::a) so they cannot collide
// with other enums, and it will not silently convert to int.
