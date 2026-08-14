#include <iostream>
#include <string>
using namespace std;

// new is actually an operator

using String = string;

class Entity{
    private:
    String m_Name;

    public:
    Entity() : m_Name("unknown") {}
    Entity(const String& name) : m_Name(name) {}

    const String& GetName() const { return m_Name; }
};

int main(){
    int a = 3;
    int* b = new int;
    int* c = new int[50]; // 200 bytes of memory is needed

    // the new keyword doen't only call the Entity class it can also call
    // the constructor
    // Entity* e = new Entity[50];
    Entity* e = new Entity();

    cout << a <<','<< b <<','<< c <<','<< e << endl;

    delete(e,b,c); 

    return 0;
}
