// ============================================================
// OPERATOR OVERLOADING
// ------------------------------------------------------------
// An "operator" is just a symbol (+, *, <<, ==) that the compiler
// turns into a function call. C++ already knows what + means for
// int and float, but it has NO idea what + means for a type you
// invented. Operator overloading = you teaching it.
// ============================================================

#include <iostream>
#include <string>
using namespace std;

// struct vs class: identical in C++ except members of a struct are
// public by default. Used here because vector2 is plain data.
struct vector2{

    float X, Y;

    // Constructor. The part after the ':' is a MEMBER INITIALIZER LIST.
    // It builds X and Y directly from x and y instead of default-
    // constructing them first and assigning after. Cheaper, and the
    // only way to init const/reference members.
    vector2(float x, float y) : X(x), Y(y)
    {
    // some construct functionality
    }

    // 'const vector2& other'
    //   & = pass by reference, so no copy of the struct is made
    //   const = promise we will not modify what was handed to us
    // The trailing 'const' (after the parentheses) is a different
    // promise: this method will not modify *this* object either.
    // That is what lets you call Add() on a const vector2.
    vector2 Add(const vector2& other) const
    {
        return vector2(X + other.X, Y + other.Y);
    }

    vector2 Multiply(const vector2& other) const
    {
        return vector2(X * other.X, Y * other.Y);
    }

    // Operator overloading

    // Now 'a + b' becomes a call to a.operator+(b).
    // The left operand is the object the method is called on,
    // the right operand is the parameter. This is why + can be a
    // member function: its left side is always a vector2.
    vector2 operator+(const vector2& other) const
    {
        return Add(other);
    }

    vector2 operator*(const vector2& other) const
    {
        return Multiply(other);
    }

    // Printing needs operator<<, but its LEFT operand is cout (an
    // ostream), not a vector2 -- so it cannot be a member function.
    // It has to be a free function. 'friend' lets us write that free
    // function here inside the struct while still giving it access
    // to private members.
    //
    // Why return ostream& (a reference to the stream)?
    // So that chaining works:
    //     cout << v << endl;
    // is really  ((cout << v) << endl)  -- the inner call must hand
    // cout back so endl has something to attach to.


    /*
    friend ostream& operator<<(ostream& os, const vector2& v)
    {
        os << v.X << ", " << v.Y;
        return os;
    }
    */

    // Comparison operators return bool, not vector2 -- the question
    // "are these equal?" has a yes/no answer, not a vector one.
    // && is logical AND: both sides must be true.
    // (Comparing floats with == is exact and can surprise you: 0.1f+0.2f
    //  is not bit-identical to 0.3f. Real code compares within a tolerance.)
    bool operator==(const vector2& other) const
    {
        return X == other.X && Y == other.Y;
    }

    bool operator!=(const vector2& other) const
    {
        // The commented line is a genuine bug: && makes it "both
        // coordinates differ", so (1,5) != (1,9) would report false.
        // Correct is ||, but better still is the line below.
        //return X != other.X && Y != other.Y;

        // Define != as "not ==". One definition of equality, so the two
        // operators can never drift apart when you edit == later.
        // '*this' is the current object; the '!' flips the bool.
        return !(*this == other);
    }
};

// Free function version -- works without 'friend' because X and Y are
// public (this is a struct). You'd need friend only to reach private members.
ostream& operator<<(ostream& stream, const vector2& other){
    stream << other.X << ", " << other.Y;
    return stream;
}



int main(){
    vector2 position(3.0f, 4.5f);
    vector2 speed(0.3f, 1.5f);
    vector2 powerup(1.1f, 1.1f);

    // The verbose way: explicit method calls, read inside-out.
    vector2 result1 = position.Add(speed.Multiply(powerup));
    cout << result1 << endl;

    // The same math via operators. Note '*' binds tighter than '+'
    // (normal precedence rules still apply -- overloading changes
    // what an operator DOES, never its precedence or arity).
    vector2 result2 = position + speed * powerup;
    cout << result2 << endl;

    // Both results came from the same math, so operator== reports True.
    if (result1 == result2) { cout << "True" << '\n'; }
    else { cout << "False" << endl; }
    return 0;   // 0 tells the OS the program finished successfully
}
