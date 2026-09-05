// ============================================================
// VIRTUAL FUNCTIONS / POLYMORPHISM
// ------------------------------------------------------------
// Problem: if you hold a Player through an Entity* pointer, which
// GetName() runs -- Entity's or Player's?
// Without 'virtual': whatever the POINTER type says (Entity).
// With 'virtual': whatever the OBJECT really is (Player).
// That runtime lookup is called dynamic dispatch, done through a
// hidden per-class table of function pointers (the "vtable").
// ============================================================

#include <iostream>
using namespace std;

// A class with a pure virtual function is ABSTRACT: it cannot be
// instantiated, it only defines an interface others must fulfil.
class Printable{
    public:
    virtual string GetClassName() = 0; // pure virtual function
                                       // "= 0" means: no body here,
                                       // every child MUST supply one.
};

class Entity : public Printable{
    public:
    virtual string GetName(){ // virtual function
                              // children may replace this
        return "Entity";
    }
    string GetClassName() override { // override the pure virtual function
                                     // 'override' is a safety check: the
                                     // compiler errors if no matching
                                     // virtual exists in the base class
                                     // (catches typos and signature drift).
        return "Entity";
    }
};

class Player : public Entity{
    private:
    string m_Name;
    public:
    Player(const string& name)
        : m_Name(name) {}

    string GetName() override { return m_Name; } // override the virtual function
    string GetClassName() override {
        return "Player";
    }
};

class A: public Printable{
    public:
    string GetClassName() override {
        return "A";
    }
};

// This is the payoff: one function works for EVERY current and future
// Printable, without knowing any of their names.
void Print(Printable* obj){ // function that takes a Printable pointer
    cout << obj->GetClassName() << endl;
}

int main(){

    Entity* e = new Entity(); // create an Entity object
    cout << e->GetName() << endl;

    Player* p = new Player("SKJ"); // create a Player object
    cout << p->GetName() << endl;

    // UPCASTING: a Player IS an Entity, so this needs no cast.
    // Prints "SKJ", not "Entity" -- proof that virtual is working.
    // Drop 'virtual' from GetName and this line prints "Entity".
    Entity* e2 = p;                 // upcasting Player to Entity
    cout << e2->GetName() << endl;

    A* a = new A();                 // create an A object
    Print(a);

    // Note: everything made with 'new' here is leaked -- no delete.
    // Fine for a scratch file, not fine in real code. Also, a base
    // class meant for inheritance should declare a virtual destructor
    // so 'delete basePointer' cleans up the derived part too.
}
