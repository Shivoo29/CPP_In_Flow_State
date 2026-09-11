// ============================================================
// THE ARROW OPERATOR  ->
// ------------------------------------------------------------
// Two separate lessons live in this file.
//
// 1. WHAT -> ACTUALLY IS
//    For a raw pointer, ptr->print() is pure shorthand for
//    (*ptr).print() : dereference the pointer, then use '.' on the object.
//    The parentheses are needed in the long form because '.' binds tighter
//    than '*', so *ptr.print() would parse as *(ptr.print()).
//
// 2. YOU CAN OVERLOAD IT
//    -> is an operator, so your own class can define it. That is exactly
//    how smart pointers (unique_ptr, shared_ptr -- see 28_smartPointers)
//    let you write ptr->print() even though they are not pointers.
//    ScopedPtr below is a hand-rolled unique_ptr that shows the trick.
//
// Plus, at the end of main, a party trick that abuses -> to compute
// where each member sits inside a struct.
// ============================================================

#include <iostream>
#include <string>
using namespace std;

class Entity{
    public:
    // Marked const so it can be called through a const Entity* too --
    // which matters for ptr3 at the bottom.
    void print() const {cout << "Hello" << endl;}
    int x;
};

// A minimal stand-in for unique_ptr: it holds a raw pointer, and deletes
// it automatically when the ScopedPtr itself goes out of scope. "Scoped"
// because the object's lifetime is tied to this wrapper's scope.
class ScopedPtr{
    private:
    Entity* m_Obj;
    public:
    // Takes ownership of the raw pointer handed to it.
    ScopedPtr(Entity* obj) : m_Obj(obj){}

    // The whole point: you can never forget the delete, because the
    // destructor runs on its own at the end of the scope.
    ~ScopedPtr(){delete m_Obj;}

    // *** THE OVERLOAD ***
    // Return a pointer, and the compiler does the rest: when you write
    // ptr2->print(), it calls this, gets back an Entity*, and then applies
    // -> AGAIN to that. It keeps chaining -> until it reaches a raw
    // pointer. That is why you write ptr2->print() and not
    // ptr2->->print() or ptr2.operator->()->print().
    Entity* operator->(){return m_Obj;}

    // A second version for when the ScopedPtr itself is const.
    // Overloading on constness: the compiler picks this one for a const
    // object, the one above for a non-const object.
    // It returns const Entity*, so through it you may only call const
    // methods -- print() qualifies, assigning to x would not.
    const Entity* operator->() const {
        return m_Obj;
    }
};

// Plain data, three floats laid out back to back. Used for the offset
// trick below.
struct Vector3{
    
    float x, y, z;

};


int main (){

    // ---- Party trick: find each member's byte offset in the struct ----
    // The offset trick: pretend address 0 holds a Vector3, ask for the
    // address of one member, and since the object "starts" at 0 the
    // address you get back IS the member's offset in bytes.
    // Nothing is ever read here -- '&' only computes an address.
    //
    // Cast to size_t, NOT int: a pointer is 8 bytes on 64-bit, an int is 4,
    // so (int) would chop the top half off. That is the "loses precision"
    // error -- it is a COMPILE error, not a runtime one.
    size_t offset_x = (size_t)&((Vector3*)nullptr)->x;
    size_t offset_y = (size_t)&((Vector3*)nullptr)->y;
    size_t offset_z = (size_t)&((Vector3*)nullptr)->z;
    // floats are 4 bytes each, so this prints 0, 4, 8.
    //
    // Worth knowing: this is technically undefined behaviour (you are
    // forming a member address on a null object). It works everywhere in
    // practice, but the sanctioned version is offsetof from <cstddef>:
    //     offsetof(Vector3, y)   -- same answer, fully legal
    cout << "offset_x: " << offset_x << endl;
    cout << "offset_y: " << offset_y << endl;
    cout << "offset_z: " << offset_z << endl;

    // ---- Case 1: you hold the object directly -> use '.' ----
    Entity e;
    e.print();

    // ---- Case 2: you hold a pointer -> use '->' ----
    Entity* ptr = &e;        // &e is the address of e
    //Entity& entity = *ptr; // a reference: yet another name for e, uses '.'
    //(*ptr).print();        // the long form -- identical to ptr->print()

    ptr->print();            // shorthand for (*ptr).print()
    ptr->x = 2;              // -> works for data members too, not just methods

    // ---- Case 3: you hold a wrapper that OVERLOADS '->' ----
    ScopedPtr ptr2(new Entity());
    ptr2->print();           // calls ScopedPtr::operator->() to get the
                             // Entity*, then -> again to reach print()
                             // No delete needed: ~ScopedPtr handles it.

    // Same, but the wrapper is const, so the const overload is chosen and
    // you get a const Entity* back. print() is const, so this is fine.
    const ScopedPtr ptr3(new Entity());
    ptr3->print();

}   // ptr3 and ptr2 die here (reverse order), each destructor deleting its
    // Entity. 'e' was on the stack and needed no delete at all.
