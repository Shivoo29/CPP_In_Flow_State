// ============================================================
// THE new OPERATOR (heap allocation)
// ------------------------------------------------------------
// Stack memory dies automatically at the end of its scope.
// 'new' asks for HEAP memory, which lives until you 'delete' it.
// You get back a POINTER, and you own the cleanup. Forget it and
// the memory leaks.
// ============================================================

#include <iostream>
#include <string>
using namespace std;

// new is actually an operator

// Type alias: 'String' now means std::string. Purely a nickname,
// no new type is created.
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
    int a = 3;            // stack: freed automatically at end of main
    int* b = new int;     // heap: one int, value uninitialized
    int* c = new int[50]; // 200 bytes of memory is needed
                          // (50 ints x 4 bytes each)

    // the new keyword doen't only call the Entity class it can also call
    // the constructor
    // Entity* e = new Entity[50];
    Entity* e = new Entity();   // allocates AND runs the constructor

    // Printing a pointer prints the ADDRESS, not the value it points
    // at. To see the value you would write *b instead of b.
    cout << a <<','<< b <<','<< c <<','<< e << endl;

    // CAREFUL: this is not three deletes. The commas here are the
    // comma OPERATOR, which evaluates e, then b, then yields c --
    // so only c is passed to delete. b and e leak, and c was made
    // with new[] so it needs delete[]. The correct form is:
    //     delete e;
    //     delete b;
    //     delete[] c;
    // Rule: new pairs with delete, new[] pairs with delete[].
    delete(e,b,c);

    return 0;
}
