// ============================================================
// main() -- where every C++ program starts
// ------------------------------------------------------------
// Exactly one main() per program. The OS calls it; when it returns,
// the program ends. Returning 0 means success.
//
// This file uses functions declared in super.h and defined in
// function.cpp, so build both together:
//     g++ main.cpp function.cpp -o main
// ============================================================

#include <iostream>
#include "super.h"    // quotes = look next to this file
                      // angle brackets = look in the system/standard headers

using namespace std;  // lets you write cout instead of std::cout.
                      // Convenient here; avoided in big projects and in
                      // headers because it dumps every std name into scope.

int main() {
    cout << "Enter two numbers to multiply: ";

    int a{};      // {} initializes to 0, so a is never garbage
    cin >> a;     // '>>' is the EXTRACTION operator: pull from input into a

    int b{};
    cin >> b;

    result(a, b);  // declared in super.h, body lives in function.cpp

    // A basic for loop, three parts separated by ';' :
    //   int i=0  run once at the start
    //   i<5      checked before each pass; loop stops when false
    //   i++      run after each pass
    for(int i=0; i<5; i++){
        log(i);   // log() is defined inline in super.h
    }
    return 0;
}
