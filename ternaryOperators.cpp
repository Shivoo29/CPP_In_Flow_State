// ============================================================
// THE TERNARY OPERATOR  ( condition ? a : b )
// ------------------------------------------------------------
// Read it as: "if condition then a else b".
// Unlike an if-statement, it is an EXPRESSION -- it produces a value,
// so it can sit on the right of '='. That is the whole point.
// Both branches must yield the same type.
// ============================================================

#include <iostream>
#include <string>

using namespace std;

// 'static' at file scope (outside any class) means something entirely
// different from static-in-a-class: it limits the name to THIS file,
// so another .cpp can define its own s_Level without a clash.
// s_ prefix is the convention for a static variable.
static int s_Level = 7;
static int s_Speed = 2;

int main(){
    // The if-version of the exact same logic, kept for comparison:
    //if (s_Level > 5) s_Speed = 10;
    //else s_Speed = 5;

    s_Speed = s_Level > 5 ? 10 : 5;   // 7 > 5 is true -> 10

    // Ternaries nest, but readability drops fast. This parses as:
    //   s_Level > 10 ? ( s_Speed >= 10 ? "Master" : "Noob" ) : "Normal"
    // s_Level is 7, so the outer condition is false -> "Normal".
    // Anything more nested than this deserves an if/else.
    string rank = s_Level > 10 ? s_Speed >=10 ? "Master" : "Noob" : "Normal";


    cout << s_Speed << endl;
    cout << rank << endl;
}
