// ============================================================
// A CLASS -- the bare minimum
// ------------------------------------------------------------
// A class is a blueprint: it describes what an object holds and what
// it can do. Nothing exists in memory until you create an INSTANCE
// (an object) from it, as main does below.
//
// class vs struct: identical, except a class's members are private by
// default and a struct's are public. Hence the explicit 'public:' here.
// ============================================================

#include <iostream>
#include "super.h"
using namespace std;

class Player{
    public:          // everything after this is reachable from outside
    int x, y;
    int speed;
};                   // the semicolon after a class body is required

int main(){
    Player player;   // one Player object on the stack.
                     // No constructor defined, so x/y/speed hold garbage.
    player.x = 10;   // '.' reaches a member of an object you hold directly
                     // (use '->' when you hold a pointer instead)
}
