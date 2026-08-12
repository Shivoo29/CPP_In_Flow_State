#include <iostream>
using namespace std;

struct Entity{

    static int x,y;

    static void Print(){
        cout << x << "," << y << endl;
    }
};

 
int Entity::x;
int Entity::y;

int main(){

    Entity::x = 3;
    Entity::y = 4;
    Entity::Print();
}