// ============================================================
// COPY CONSTRUCTORS  --  UNFINISHED, ON PURPOSE. READ THIS FIRST.
// ------------------------------------------------------------
// STATUS: this file compiles, prints "Shivam" twice, then CRASHES with
//         "free(): double free detected in tcache 2".
//         That crash is not a mistake in the file -- it is the entire
//         point of the lesson. Run it and watch it die.
//
// THE QUESTION THIS FILE ASKS:
//     When you write  b = a  for your own class, what does C++ copy?
//
// THE ANSWER:
//     If you write no copy constructor, the compiler writes one for you.
//     The one it writes copies each member ONE BY ONE, as-is.
//     For an int or a float that is perfect.
//     For a POINTER it copies the ADDRESS -- not the thing pointed at.
//     So now two objects hold the same address and both think they own it.
//     That is called a SHALLOW COPY, and it is what breaks below.
//
// WHAT YOU STILL HAVE TO DO (the part you stopped at):
//     Write a copy constructor for String that allocates its own buffer.
//     Its shape is at the bottom of this file. Don't peek until you've
//     tried it.
// ============================================================

#include <iostream>
#include <string>
#include <cstring>   // for strlen and memcpy -- the old C string functions
using namespace std;

// A class holding ONLY plain values (no pointers, no owned memory).
// The compiler's free copy is completely correct here. Keep this in the
// file as the contrast case: this is what "copying just works" looks like.
struct Vector2
{
    /* data */
    float x, y;
};

// A class that OWNS heap memory. This is where the free copy betrays you.
class String
{
private:
    char* m_Buffer;        // an address, pointing at chars we allocated
    unsigned int m_Size;
public:
    String(const char* string)
    {
        m_Size = strlen(string);         // strlen counts characters, NOT counting
                                         // the terminating '\0'. So "Shivam" -> 6.

        m_Buffer = new char[m_Size + 1]; // +1 makes room for that '\0'.
                                         // Forget the +1 and you overflow by one byte.

        // The hand-written version of the copy, kept for reference.
        // memcpy below does exactly this, just faster.
        // for ( int i = 0; i < m_Size; i++)
        // {
        //     m_Buffer[i] = string[i];
        // }

        memcpy(m_Buffer, string, m_Size); // copy m_Size bytes from string into m_Buffer
        m_Buffer[m_Size] = 0;             // write the '\0' terminator by hand.
                                          // cout needs it to know where to stop.
    }

    // Destructor: we called new[], so we owe a delete[]. Runs automatically
    // when a String dies.
    //
    // *** THIS IS WHERE THE PROGRAM CRASHES. ***
    // Not because this code is wrong -- it is correct -- but because it
    // runs TWICE on the SAME address. See the note in main().
    ~String()
    {
        delete[] m_Buffer;
    }

    // Declared as a friend so it can read the private m_Buffer.
    // (See 25_operatorOverloading.cpp -- operator<< can't be a member
    //  because its left operand is the stream, not a String.)
    friend ostream& operator<<(ostream& stream, const String& string);
};

ostream& operator<<(ostream& stream, const String& string)
{
    stream << string.m_Buffer;   // relies on that '\0' we wrote above
    return stream;
}

int main(){
    // ---- CASE 1: copying is harmless ----------------------------------
    Vector2 a = { 2, 3 };
    Vector2 b = a;   // compiler-generated copy: copies the floats themselves.
    b.x = 5;         // b has its own x. a.x is still 2. No connection between them.

    // The pointer version of the same idea, for contrast:
    // here b and a would be two names for ONE object, and changing
    // b->x WOULD change a->x, because only the address got copied.
    //Vector2* a = new Vector2();
    //Vector2* b = a;
    //b->a = 2;

    // ---- CASE 2: copying is fatal -------------------------------------
    String string = "Shivam";   // allocates a buffer at, say, address 0xAAAA

    String second = string;     // <-- THE BUG LIVES ON THIS LINE.
                                // No copy constructor exists, so the compiler
                                // uses its own: it copies m_Size (fine) and
                                // copies m_Buffer (an address!).
                                // Now second.m_Buffer == string.m_Buffer == 0xAAAA.
                                // ONE buffer, TWO objects that each believe they own it.

    cout << string << endl;     // prints Shivam -- both read the same memory,
    cout << second << endl;     // so both look correct. The damage is invisible so far.

}   // <-- AND HERE IS WHERE IT DETONATES.
    // End of main, both Strings die, destructors run in reverse order:
    //    ~second  ->  delete[] 0xAAAA      ok, memory returned to the system
    //    ~string  ->  delete[] 0xAAAA      SAME ADDRESS, ALREADY FREED
    // Freeing the same block twice corrupts the allocator's bookkeeping.
    // glibc catches it and aborts: "free(): double free detected in tcache 2".
    //
    // Even if it hadn't crashed, this design is broken: modify one String
    // and the other silently changes too, because there is only one buffer.


// ============================================================
// THE FIX YOU HAVE YET TO WRITE  --  try it yourself before reading
// ------------------------------------------------------------
// A COPY CONSTRUCTOR is the constructor that runs when an object is built
// from another object of the same type. Its signature is always:
//
//     String(const String& other)
//
//   const  -- we are not modifying the thing we copy from
//   &      -- MUST be a reference. Take it by value and constructing the
//             parameter would itself require a copy, which would call this
//             constructor again... forever. The compiler rejects it.
//
// A DEEP COPY means: don't copy the address, copy the CONTENTS into
// memory of your own. Roughly:
//
//     String(const String& other)
//         : m_Size(other.m_Size)
//     {
//         m_Buffer = new char[m_Size + 1];              // our own allocation
//         memcpy(m_Buffer, other.m_Buffer, m_Size + 1); // +1 grabs the '\0' too
//     }
//
// With that in place, 'second' owns a different block, each destructor
// frees its own, and the crash is gone.
//
// Worth knowing once the above makes sense:
//   - The compiler silently gives every class a copy constructor, a copy
//     assignment operator (b = a on an EXISTING b) and a destructor. Once
//     you need to write one of those three by hand, you almost always need
//     all three. That's the "rule of three".
//   - Pass big objects as const& to avoid triggering copies you didn't want.
//     Add a print statement inside your copy constructor and you'll see
//     exactly how often copies really happen.
// ============================================================
