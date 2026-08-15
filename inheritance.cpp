// ============================================================
// INHERITANCE
// ------------------------------------------------------------
// "class Player : public Entity" means a Player IS AN Entity plus
// extra. Player gets every member of Entity for free, no copy-paste.
// The 'public' part controls how strictly: public inheritance keeps
// Entity's public members public, which is what makes a Player*
// usable anywhere an Entity* is expected.
// ============================================================

#include <iostream>
using namespace std;

// The BASE class (also called parent / superclass).
class Entity{
    public:
    float X,Y;

    void move(float xa, float ya){
        X += xa;
        Y += ya;
    }
};

// The DERIVED class (child / subclass): Entity's X, Y and move()
// plus its own Name and PrintName().
class Player : public Entity{
    public:
    const char* Name;

    void PrintName(){
        cout << Name << endl;
    }
};

int main(){
    Player player;
    player.move(5, 5);  // inherited from Entity -- Player never defined it
    player.X = 2;       // also inherited

    // Careful: X and Y were never initialized (no constructor), so
    // move() is adding 5 to garbage. Only the final assignment X = 2
    // gives X a known value.
}
