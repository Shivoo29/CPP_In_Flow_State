// ============================================================
// MEMBER INITIALIZER LISTS
// ------------------------------------------------------------
// Members are ALWAYS constructed before the constructor body runs.
// So assigning inside the body means: build the member once (default
// constructor), then throw that away and assign over it.
// The ': a(x), b(y)' list builds them correctly the first time.
// This file proves it by printing from Example's constructors.
// ============================================================

#include <iostream>
#include <string>
using namespace std;

class Example{
    public:
    // Default constructor: takes no arguments.
    Example()
    {
        cout << "constructor created Sucesfully!!" << endl;
    }
    // Overloaded constructor: same name, different parameters.
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
    // Using the list: Example(8) is built directly. One construction,
    // one line of output.
    Entity(): m_Name("unknown"), m_Score(0), m_example(8) // This is member initializar list
    {
        // If you did it this way instead, m_example would be built
        // TWICE: once by the default constructor before the body,
        // then discarded and overwritten here. Two lines of output.
        // m_example = Example(8);
    }
    // This overload skips the list, so m_Name is default-constructed
    // (empty string) and then assigned -- and m_Score is left as
    // uninitialized garbage. That is the bug the list prevents.
    Entity(const string& name)
    {
        m_Name = name;
    }
    // Returns const& so the caller can read the name without copying
    // the string and without being able to modify it.
    const string& GetName() const { return m_Name; }
};

int main(){
    Entity e0;
    cout << e0.GetName() << endl;

    Entity e1("SKJ");
    cout << e1.GetName() << endl;
}
