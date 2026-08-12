#include <iostream>
using namespace std;

class Printable{
    public:
    virtual string GetClassName() = 0; // pure virtual function
};

class Entity : public Printable{
    public:
    virtual string GetName(){ // virtual function
        return "Entity";
    }
    string GetClassName() override { // override the pure virtual function
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

void Print(Printable* obj){ // function that takes a Printable pointer
    cout << obj->GetClassName() << endl;
}

int main(){

    Entity* e = new Entity(); // create an Entity object
    cout << e->GetName() << endl; 

    Player* p = new Player("SKJ"); // create a Player object
    cout << p->GetName() << endl;

    Entity* e2 = p;                 // upcasting Player to Entity
    cout << e2->GetName() << endl;

    A* a = new A();                 // create an A object 
    Print(a);
}