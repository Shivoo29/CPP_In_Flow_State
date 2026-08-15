// ============================================================
// CONSTRUCTORS AND DESTRUCTORS
// ------------------------------------------------------------
// Constructor: runs automatically when an object is created. Its job
//   is to leave the object in a valid state (uninitialized members
//   otherwise hold garbage).
// Destructor (~Name): runs automatically when the object dies -- end
//   of scope for stack objects, or on delete for heap ones. Its job
//   is cleanup: free memory, close files, release locks.
// You never call either one by hand. That automatic pairing is the
// core of C++ resource management (called RAII).
// ============================================================

#include <iostream>
using namespace std;

class Entity{
    public:
    float X,Y;

    // Same name as the class, no return type at all => constructor.
    Entity(){
        cout << "created Entity" << endl;
        X = 0.0f;
        Y = 0.0f;
    }

    // Class name with a leading ~ => destructor. Never takes arguments.
    ~Entity(){
        cout << "destroyed Entity" << endl;
    }

    void Print(){
        cout << X << "," << Y << endl;
    }
};

void Function(){
    Entity e;   // constructor fires here
    e.Print();
}               // e goes out of scope -> destructor fires here, automatically

int main (){
    // Output order proves the lifetime:
    //   created Entity / 0,0 / destroyed Entity
    Function();
}
