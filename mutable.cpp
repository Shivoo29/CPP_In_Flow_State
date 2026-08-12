#include <iostream>
#include <string>
using namespace std;

class Entity{
    private:
    string m_Name;
    mutable int m_debugCounter = 0;
    public:
    const string& GetName() const {
        m_debugCounter++;
        return m_Name; }
};

int main (){
    Entity e;
    e.GetName();

    int x = 8;
    auto f = [=]() mutable{ // this is a lamda function which is denoting value using "="
        x++;
        cout << x << endl;
    };

    f();

}