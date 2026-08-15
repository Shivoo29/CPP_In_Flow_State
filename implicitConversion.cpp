// ============================================================
// IMPLICIT vs EXPLICIT CONSTRUCTORS
// ------------------------------------------------------------
// A constructor taking exactly ONE argument doubles as a silent
// conversion rule: C++ will use it on its own to turn that argument
// type into your type. Handy, but sometimes surprising -- 'explicit'
// switches that automatic behaviour off.
// ============================================================

#include <iostream>
#include <string>
using namespace std;

class Entity
{
    // 'private' = only code inside Entity can touch these.
    // m_ prefix is a convention meaning "member variable".
    private:
    string m_Name;
    int m_Age;
    float m_roll;

    public:
    // Single-argument constructor => also an implicit conversion
    // from string to Entity.
    Entity(const string& name) : m_Name(name), m_Age(-1)
    {
    }

    // Same deal for int: 'Entity b = 22;' would compile because of this.
    Entity(int age) : m_Name("Unknown"), m_Age(age)
    {
    }

    // 'explicit' kills the automatic conversion. You must name the
    // type yourself: Entity(21.09f). 'Entity c = 21.09f;' is rejected.
    explicit Entity(float roll) : m_roll(roll)
    {
    }
};

void printEntity (const Entity& entity){
    // some print function
}
int main()
{

    // Fails because it needs TWO conversions in a row:
    //   const char*  ->  std::string  ->  Entity
    // C++ allows at most ONE user-defined conversion implicitly.
    // printEntity("SKJ");

    // Fixed by doing one of the steps by hand.
    printEntity(Entity("SKJ"));

    Entity a = Entity("Shivam");
    Entity b (22); //Implicit Conversion

    Entity c = Entity(21.09f); // this is for explicit constructor because you have to call them
    // made this a float so that it only relates to explicit constructor
}
