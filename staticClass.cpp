// ============================================================
// static INSIDE A CLASS
// ------------------------------------------------------------
// A static member belongs to the CLASS, not to any object. There is
// exactly one copy shared by everything, and you reach it through the
// class name with :: (the scope resolution operator), no object needed.
//
// A static method likewise has no 'this' pointer, so it can only touch
// other static members -- there is no particular object for it to read.
//
// (Different meaning from 'static' at file scope -- see ternaryOperators.cpp.)
// ============================================================

#include <iostream>
using namespace std;

struct Entity{

    static int x,y;   // DECLARATION only: announces they exist,
                      // reserves no memory.

    static void Print(){
        cout << x << "," << y << endl;
    }
};


// DEFINITION: this is what actually allocates the two ints. Required
// once, outside the class, in exactly one .cpp file -- leave it out
// and you get a linker error, not a compiler error.
int Entity::x;
int Entity::y;

int main(){

    // No Entity object is ever created. None is needed.
    Entity::x = 3;
    Entity::y = 4;
    Entity::Print();
}
