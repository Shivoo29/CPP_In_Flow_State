// ============================================================
// THE this POINTER
// ------------------------------------------------------------
// only accessable to us via a member function (a function that belongs to a class)
// "this" is a pointer to current object instence that the method belongs to
//
// The idea: when you call e.getX(), how does getX know WHICH Entity to
// read? The compiler secretly passes the object's address as a hidden
// first argument. 'this' is the name of that hidden argument.
//
//     e.getX()        is really    getX(&e)
//     inside getX,    this          is    &e
//
// So 'this' is always a POINTER (an address), never the object itself.
// That is why you reach members with '->' and not '.'.
//
// Two forms you will see:
//     this->x     the pointer, arrow to get at a member
//     *this       dereference it: the actual object, usable as Entity&
// ============================================================

#include <iostream>
#include <string>
using namespace std;

// A forward declaration: "a class called Entity exists, details later".
// Needed because printEntity below mentions Entity before the class body
// is written. Without this line the compiler hits 'Entity' as an unknown
// word and stops.
class Entity;

//void printEntity(Entity* e);
void printEntity(const Entity& e);   // declaration only; body is at the bottom

class Entity{
    public:
    int x,y;

    // The parameters are also named x and y, so inside this constructor
    // the plain name 'x' means the PARAMETER -- it shadows the member.
    // 'this->x' is how you say "the member x, not the parameter".
    Entity(int x,int y){ //I can use member initiliser like :x(x), y(y)
                         // (and with a member init list the names cannot
                         //  collide, which is why it is usually preferred)

        // These three commented lines are all the same operation,
        // written three ways:
        // Enitiy* e = this;   // 'this' is just a pointer, copyable like any other
        // e -> x=x;           // reach the member through the pointer
        // *this.x=x           // BROKEN: '.' binds tighter than '*', so this
                               // parses as *(this.x). Correct is (*this).x = x,
                               // and '->' is exactly shorthand for that.

        this -> x=x;   // member x  =  parameter x
        this -> y=y;

        // *this dereferences the pointer to get the object itself, which
        // can then bind to a reference. e is now another name for this object.
        Entity& e = *this;

        //printEntity(this);   // would need printEntity(Entity*) -- passing an address
        printEntity(*this);    // passes the object (bound to a const Entity&)
                               // Careful: the object is still half-built here.
                               // Calling out to other code from a constructor
                               // before the object is finished is risky.
    }

    // Trailing const = "this method does not modify the object".
    // It changes the type of 'this' from Entity* to const Entity*,
    // which is what makes the write below illegal.
    int getX() const
    {
        // const Entity* e = this;
        // e -> x = 4; this is wrong
        //             ^ correct: through a pointer-to-const you may read
        //               members but never assign to them. The compiler
        //               enforces the promise made by that trailing const.

        const Entity& e = *this;   // same object, reference form, still read-only
        return x;                  // bare 'x' means this->x -- the -> is implied
                                   // whenever there is no local of that name

    }


};

// The definition. Its signature has to match the declaration above
// (const Entity&), or the linker finds no body for what was declared.
void printEntity(const Entity& e){

    // some printing function
}

int main(){
    Entity a(2, 3);
    cout << a.getX() << endl;
}
