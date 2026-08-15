// ============================================================
// mutable -- it means two unrelated things
// ------------------------------------------------------------
// 1. On a class member: "this field can be modified even by const
//    methods". For bookkeeping that is not part of the object's
//    logical state -- caches, hit counters, lazily computed values.
// 2. On a lambda: "the by-value copies I captured are not const,
//    let me modify them". Different feature, same keyword.
// ============================================================

#include <iostream>
#include <string>
using namespace std;

class Entity{
    private:
    string m_Name;
    mutable int m_debugCounter = 0;   // usage counter, not real state
    public:
    // Marked const (promises not to modify the object), yet it still
    // bumps m_debugCounter -- allowed only because of 'mutable'.
    const string& GetName() const {
        m_debugCounter++;
        return m_Name; }
};

int main (){
    Entity e;
    e.GetName();

    int x = 8;
    // A LAMBDA is an anonymous function you can store in a variable.
    // The [] is the CAPTURE LIST -- what outside variables it can see:
    //   [=] copy them in,  [&] refer to the originals,  [] see nothing.
    // Captured-by-value copies are const by default; 'mutable' lifts that.
    auto f = [=]() mutable{ // this is a lamda function which is denoting value using "="
        x++;                 // modifies the lambda's own COPY of x
        cout << x << endl;   // prints 9
    };

    f();

    // x out here is still 8 -- the copy was incremented, not the original.
    // Capturing with [&] instead would have changed the real x.

}
