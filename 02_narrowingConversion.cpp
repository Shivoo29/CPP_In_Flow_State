// ============================================================
// NARROWING CONVERSIONS -- and why {} is the safer initializer
// ------------------------------------------------------------
// Putting a double into an int throws away the fractional part. That
// is a "narrowing conversion": the target type cannot hold every
// possible source value.
// The three initialization syntaxes react differently:
//   int a { 3.5 };   brace init  -> ERROR (or at minimum a warning)
//   int b ( 4.5 );   paren init  -> silently truncates to 4
//   int x = 5.5;     copy init   -> silently truncates to 5
// This is the reason modern C++ prefers {}: it refuses to lose data
// quietly. Truncation always chops toward zero, it does not round.
// ============================================================

#include <iostream>
using namespace std;

int main()
{
    int a { 3.5};   // rejected by a conforming compiler; if it builds, a is 3
    int b ( 4.5);   // 4  -- .5 discarded, no warning
    int x = 5.5;    // 5  -- .5 discarded, no warning
    cout << a << endl;
    cout << b << endl;
    cout << x << endl;
    return 0;
}
