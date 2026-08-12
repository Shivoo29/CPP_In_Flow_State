#include <iostream>
#include <string>
using namespace std;

class Example{
    public:
    Example()
    {
        cout << "constructor created Sucesfully!!" << endl;
    }
    Example(int x){
        cout << "Created Entity with " << x << endl;
    }

};

class Entity{
    private:
    string m_Name; //m_ denotes this is a member variable 
    int m_Score;
    Example m_example;
    public:
    Entity(): m_Name("unknown"), m_Score(0), m_example(8) // This is member initializar list
    {
        // m_example = Example(8);
    }
    Entity(const string& name)
    {
        m_Name = name;
    }
    const string& GetName() const { return m_Name; }
};

int main(){
    Entity e0;
    cout << e0.GetName() << endl;

    Entity e1("SKJ");
    cout << e1.GetName() << endl;
}