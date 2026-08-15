// ============================================================
// FUNCTION DEFINITIONS (pairs with super.h and main.cpp)
// ------------------------------------------------------------
// super.h DECLARES these two functions (signature only). This file
// DEFINES them (supplies the bodies). main.cpp calls them.
//
// That split is how multi-file C++ works: each .cpp is compiled on its
// own into an object file, then the LINKER wires the calls in main.cpp
// to the bodies here. Compile both together:
//     g++ main.cpp function.cpp -o main
// Compiling main.cpp alone gives an "undefined reference" link error.
// ============================================================

#include <iostream>
#include "super.h"

using namespace std;

// Returns a value the caller can use.
int multiply(int x, int y) {
    return x * y;
}

// 'void' = returns nothing. This one does its work by printing.
void result(int x, int y) {
    cout << "The result of multiplication is: "
         << multiply(x, y) << endl;   // one function calling another
}
