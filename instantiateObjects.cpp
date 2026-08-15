// ============================================================
// STACK vs HEAP: two ways to create an object
// ------------------------------------------------------------
// Stack: fast, automatic cleanup, but the object dies when its
//        scope ends and the space is limited (~1-8 MB).
// Heap:  you control the lifetime, size limited only by RAM, but
//        slower and YOU must delete it.
// Default to the stack. Use the heap only when you need the object
// to outlive its scope or it is too big for the stack.
// ============================================================

#include <iostream>
#include <string>
using namespace std;

using String = string;

class Entity{

    private:
    String m_Name;

    public:
    Entity() : m_Name("unknown"){}          // default constructor
    Entity(const String& name): m_Name(name){}

    const String& GetName() const { return m_Name; }
};

int main(){
    // stack allocation
    Entity entity; // this will be calling the default constructor
                   // NOTE: no parentheses. 'Entity entity();' would
                   // declare a FUNCTION returning Entity, not an object.
    cout << entity.GetName() << '\n';

    Entity entity1 = Entity("SKJ");
    cout << entity1.GetName() << '\n';

    // heap allocation
    Entity* entity2 = new Entity("Shivam");  // entity2 holds an address
    // '->' is shorthand for (*entity2).GetName() : follow the pointer,
    // then access the member.
    cout << entity2->GetName() << endl;
    delete entity2;   // mandatory, or the memory leaks
    return 0;
}

