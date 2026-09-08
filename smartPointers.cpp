#include <iostream>
#include <strings>
#include <memory>
using namespace std;

// Smart Pointers : when you create a pointer you are explicitly giving a variable a memory address.
// New allocates a memory space for you on the heap 
// and Delete basically deletes it for you 
// Smart pointer basically automates this process for you   

// UniquePointer: it is a scoped pointer which means that when it goes out of scoped it automatically deletes itself.
// you cant copy a uniquePointer because when any one of them reaches the end of the scope it frees the memory and in the mean time
//the copied pointer is still pointing the location which is freed already.

class Entity{
    public:
    Entity()
    {
        cout << "created Entity" << '\n';
    }

    ~Entity()
    {
        cout << "Destroyed Entity" << '\n';
    }

    void print(){}
};

int main()
{
    {
        // empty scope
        // unique_ptr<Entity> entity(new Entity()); // not the standard way to initialize this!!!
        unique_ptr<Entity> entity = make_unique<Entity>();
        entity -> print(); 
    }
}