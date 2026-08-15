// ============================================================
// A HEADER FILE (.h)
// ------------------------------------------------------------
// Headers hold DECLARATIONS -- promises that a function exists
// somewhere. #include literally pastes this file's text into the .cpp
// that includes it, so the compiler knows multiply() exists while
// compiling main.cpp, even though its body lives in function.cpp.
// The linker matches them up afterwards.
// ============================================================

#pragma once // it basically helps to aboide multiple inclusions of the same header file in a single compilation unit
             // Without it, including this header twice would declare
             // everything twice -- an error for definitions like log().

// DECLARATIONS: signature only, no body. "This exists, defined elsewhere."
int multiply(int x, int y);
void result(int x, int y);

// A DEFINITION (has a body) in a header. It works here only because
// #pragma once keeps it to one copy per .cpp file -- but if two
// different .cpp files include this header, each gets its own copy and
// the linker complains about a duplicate symbol. The usual fixes are
// to mark it 'inline', or move the body into a .cpp.
// Note this also relies on whoever includes it having already
// included <iostream>, which is fragile -- a header should include
// what it uses.
void log(int x){
    std::cout << "The value is: " << x << std::endl;

}

/*
older version of the header file with include guards
-- the portable, pre-#pragma-once way of doing the same job:
   the first include defines SUPER_H, so a second include finds the
   symbol already defined and skips the whole body.

#ifndef SUPER_H
#define SUPER_H

int multiply(int x, int y);
void result(int x, int y);

#endif // SUPER_H
*/
