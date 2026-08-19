#include <iostream>
#include <string>
using namespace std;

// Scope{} -- the variety of subjects that are being discussed or considered
// A stack based Enity gets deleted after the end of the scope from the memory
// But a Heap beased Entity doesn't till the termination of the program by the user
class Entity{
    public:
    Entity(){
        cout << "created Entity" << endl;
    }

    ~Entity(){
        cout << "Destroyed Entity" << endl;
    }
};

int* CreateArray(int* array){ // or we can do it like void CreateArray(int* array){}
    // int array[50];
    return array; // still a stack based array

    int* array = new int[50];// this is heap based, and will stick around till the end

}

class ScopedPtr{
    private:
    Entity* m_ptr;
    public:
    ScopedPtr(Entity* ptr): m_ptr(ptr){}
    ~ScopedPtr(){
        delete m_ptr;
    }

};


int main(){

    ScopedPtr e = new Entity(); // implicit conversion 
    // int* a = CreatArray();
    int array[50];
    CreateArray(array);

    Entity e;              //Stack based initilisation
    Entity* e = new Entity;//Heap based initialisation
}