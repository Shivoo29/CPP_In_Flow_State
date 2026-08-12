#include <iostream>
using namespace std;

class Entity{
    private:
    mutable int m_X, m_Y;
    public:
    int GetX() const{
        m_X = 4;
        return m_X;
    }
    void SetX(int x){
        m_X = x;
    }
};

void PrintEntity(const Entity& e){
    cout << e.GetX() << endl;
}


int main(){

    Entity e;
    e.GetX();

    const int MAX_AGE = 99;

    int* a = new int;
    *a = 3;
    cout << *a << endl;  
}