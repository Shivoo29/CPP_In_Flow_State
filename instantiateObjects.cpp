#include <iostream>
#include <string>
using namespace std;

using String = string;

class Entity{

    private:
    String m_Name;
    
    public:
    Entity() : m_Name("unknown"){}
    Entity(const String& name): m_Name(name){}

    const String& GetName() const { return m_Name; }
};

int main(){
    // stack allocation
    Entity entity; // this will be calling the default constructor
    cout << entity.GetName() << '\n';
    
    Entity entity1 = Entity("SKJ");
    cout << entity1.GetName() << '\n';

    // heap allocation
    Entity* entity2 = new Entity("Shivam");
    cout << entity2->GetName() << endl;  
    delete entity2;
    return 0;
}

