#include <iostream>
#include <string>
using namespace std;

class Entity
{
    private:
    string m_Name;
    int m_Age;

    public:
    Entity(const string& name) : m_Name(name), m_Age(-1)
    {
    }

    Entity(int age) : m_Name("Unknown"), m_Age(age) 
    {
    }
};

int main()
{
    Entity a = Entity("Shivam");
    Entity b = Entity(22); //Implicit Conversion
       
}