#include <iostream>
using namespace std;

// A stack-based Entity is destroyed automatically
// when it reaches the end of its scope.
//
// A heap-based Entity remains alive until it is
// explicitly deleted.

class Entity {
public:
    Entity() {
        cout << "Created Entity" << endl;
    }

    ~Entity() {
        cout << "Destroyed Entity" << endl;
    }
};


// --------------------------------------------------
// Option 1: Use an array supplied by the caller
// --------------------------------------------------
void CreateArray(int* array) {

    for (int i = 0; i < 50; i++) {
        array[i] = i;
    }
}


// --------------------------------------------------
// Option 2: Create an array on the heap
// --------------------------------------------------
int* CreateHeapArray() {

    int* array = new int[50];

    for (int i = 0; i < 50; i++) {
        array[i] = i;
    }

    return array;
}


// --------------------------------------------------
// A simple smart-pointer-like class
// --------------------------------------------------
class ScopedPtr {
private:
    Entity* m_ptr;

public:
    ScopedPtr(Entity* ptr)
        : m_ptr(ptr) {}

    ~ScopedPtr() {
        delete m_ptr;
    }
};


int main() {

    // ----------------------------------------------
    // STACK OBJECT
    // ----------------------------------------------
    {
        Entity stackEntity;
    } // stackEntity is automatically destroyed here


    // ----------------------------------------------
    // HEAP OBJECT
    // ----------------------------------------------
    {
        Entity* heapEntity = new Entity;

        delete heapEntity;
    } // heapEntity was deleted above


    // ----------------------------------------------
    // ScopedPtr / RAII
    // ----------------------------------------------
    {
        ScopedPtr scopedEntity = new Entity();
    } // ScopedPtr destructor deletes Entity automatically


    // ----------------------------------------------
    // STACK ARRAY
    // ----------------------------------------------
    int array[50];

    CreateArray(array);

    cout << "array[0] = " << array[0] << endl;
    cout << "array[49] = " << array[49] << endl;


    // ----------------------------------------------
    // HEAP ARRAY
    // ----------------------------------------------
    int* heapArray = CreateHeapArray();

    cout << "heapArray[0] = " << heapArray[0] << endl;
    cout << "heapArray[49] = " << heapArray[49] << endl;

    delete[] heapArray;

    return 0;
}