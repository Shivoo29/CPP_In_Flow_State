#include <iostream>
#include <string>
using namespace std;

class Entity
{
    private:
    string m_Name;
    int m_Age;
    int m_roll;

    public:
    Entity(const string& name) : m_Name(name), m_Age(-1)
    {
    }

    Entity(int age) : m_Name("Unknown"), m_Age(age) 
    {
    }

    explicit Entity(int roll) : m_roll(roll)
    {
    }
};

void printEntity (const Entity& entity){
    // some print function
}
int main()
{

    // printEntity("SKJ"); // this wont work because there will be 2 conversion and only one is allowed

    printEntity(Entity("SKJ"));

    Entity a = Entity("Shivam");
    Entity b (22); //Implicit Conversion

    Entity c = Entity(21); // this is for explicit constructor because you have to call them

}