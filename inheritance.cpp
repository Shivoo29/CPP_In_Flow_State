#include <iostream>
using namespace std;

class Entity{
    public:
    float X,Y;
    
    void move(float xa, float ya){
        X += xa;
        Y += ya;
    }
};

class Player : public Entity{
    public:
    const char* Name;

    void PrintName(){
        cout << Name << endl;
    }
};

int main(){
    Player player;
    player.move(5, 5);
    player.X = 2;
}