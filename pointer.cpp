// ============================================================
// POINTERS AND REFERENCES
// ------------------------------------------------------------
// A pointer holds an ADDRESS. Two symbols do the work:
//     &x  = "address of x"          (gives you the address)
//     *p  = "value at address p"    (dereference, follows it)
// A reference (int& r) is an alias: another name for an existing
// variable. Same effect as a pointer, but no address juggling, it
// can never be null, and it can never be re-pointed elsewhere.
// ============================================================

#include <iostream>
#include "super.h"
using namespace std;


// Takes an address. Caller must write incriment(&a), and inside we
// must dereference to reach the actual variable.
void incriment(int* value){
    (*value)++; // dereferencing the pointer and
                //incrementing the value it points to
                // NOTE the parentheses: *value++ would increment the
                // POINTER, not the number it points at.
}

// Same job via reference. Caller just writes incriment(a) and it
// still modifies the original. This is OVERLOADING: same name, the
// compiler picks by argument type.
void incriment(int& value){
    value++;
}

int main(){

    int var {4};        // {} is brace init: warns on narrowing (see conversion.cpp)
    int* ptr {&var};    // ptr holds the address of var
    *ptr = 10;          // write through the pointer...
    cout << var << endl;// ...and var itself changed. Prints 10.

    int a {3};
    int& b {a};         // b is not a copy, it IS a. Changing b changes a.
    log(b);
    incriment(&a);      // pointer version: pass the address explicitly
    incriment(a);       // reference version: looks like a normal call
    log(a);             // 3 + 1 + 1 = 5

}


