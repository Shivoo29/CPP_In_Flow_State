#include <iostream>
using namespace std;

class Entity{
    public:
    float X,Y;

    Entity(){
        cout << "created Entity" << endl;
        X = 0.0f;
        Y = 0.0f;
    }

    ~Entity(){
        cout << "destroyed Entity" << endl;
    }

    void Print(){
        cout << X << "," << Y << endl;
    }
};

void Function(){
    Entity e;
    e.Print();
}

int main (){
    Function();
}