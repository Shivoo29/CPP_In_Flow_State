// ============================================================
// STRINGS -- the C way and the C++ way
// ------------------------------------------------------------
// C style: const char* -- a pointer to the first character of a
//   block of chars, ending in a hidden '\0' (null terminator). That
//   terminator is how cout knows where to stop; nothing stores a length.
// C++ style: std::string -- knows its own length, manages its own
//   memory, can grow. Use this one unless you have a reason not to.
// ============================================================

#include <iostream>
#include <string>
using namespace std;

int main(){
    // Points at read-only memory holding "shivam\0". const because
    // writing through it is undefined behaviour.
    const char* name = "shivam";
    cout << name << endl;

    // BUG worth studying: "shivam" is 6 letters, so a 6-char array has
    // no room for the '\0'. cout keeps reading past the end until it
    // stumbles onto a zero byte -- garbage output, or a crash.
    // char name2[7] = "shivam";  would size it correctly.
    char name2[6] = {'s','h','i','v','a','m'};
    cout << name2 << endl;

    string name3 = "shivam";   // knows name3.size() == 6, no terminator worries
    cout << name3 << endl;

    // RAW STRING LITERAL: R"( ... )" takes everything literally --
    // newlines, quotes and backslashes need no escaping. Handy for
    // regexes and Windows paths.
    const char* name4 = R"(shivam
    "kumar
    "jha)";

    // Adjacent string literals are glued together by the compiler,
    // so this is one string "shivam\nkumar\njha". Just a way to spread
    // a long literal across lines. \n is an escape for newline.
    const char* name5 = "shivam\n"
    "kumar\n"
    "jha";
}
