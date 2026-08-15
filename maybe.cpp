// ============================================================
// [[maybe_unused]] -- an ATTRIBUTE
// ------------------------------------------------------------
// Compilers warn about variables you declare but never use, because
// that usually means a typo or dead code. Sometimes it is deliberate
// though. [[maybe_unused]] tells the compiler "I know, stay quiet".
//
// Anything in [[double brackets]] is an attribute: extra information
// for the compiler that does not change what the program computes.
// ============================================================

#include <iostream>

int main()
{
    [[maybe_unused]] double pi { 3.14159 };  // Don't complain if pi is unused
    [[maybe_unused]] double gravity { 9.8 }; // Don't complain if gravity is unused
    [[maybe_unused]] double phi { 1.61803 }; // Don't complain if phi is unused

    std::cout << pi << '\n';
    std::cout << phi << '\n';

    // The compiler will no longer warn about gravity not being used
    // (pi and phi are used anyway, so the attribute is harmless there)

    // '\n' vs endl: both start a new line, but endl also flushes the
    // output buffer, which is slower. Prefer '\n' unless you need the
    // flush right away.

    return 0;
}
