// ============================================================
// FUNCTION DEFINITIONS (pairs with 05_headerFiles.h and 04_main.cpp)
// ------------------------------------------------------------
// 05_headerFiles.h DECLARES these two functions (signature only). This file
// DEFINES them (supplies the bodies). 04_main.cpp calls them.
//
// That split is how multi-file C++ works: each .cpp is compiled on its
// own into an object file, then the LINKER wires the calls in 04_main.cpp
// to the bodies here. Compile both together:
//     g++ 04_main.cpp 03_functions.cpp -o main
// Compiling 04_main.cpp alone gives an "undefined reference" link error.
// ============================================================

#include <iostream>
#include "05_headerFiles.h"

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
