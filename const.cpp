// ============================================================
// const (and the mutable escape hatch)
// ------------------------------------------------------------
// const is a promise enforced by the compiler, not a runtime feature.
// It shows up in three different positions, meaning three things:
//   const int MAX = 99;              -> the value cannot change
//   int GetX() const { }             -> this METHOD won't modify the object
//   void f(const Entity& e)          -> f won't modify what it was given
// 'mutable' on a member says: this one field may change even inside
// a const method. Meant for caches/counters that are not part of the
// object's visible state.
// ============================================================

#include <iostream>
using namespace std;

class Entity{
    private:
    mutable int m_X, m_Y;   // mutable => writable even from const methods
    public:
    // The trailing const promises "I do not modify this object".
    // Assigning m_X here would normally be a compile error -- it only
    // works because m_X is mutable. (Doing real work like this in a
    // getter is bad practice; here it is just demonstrating the rule.)
    int GetX() const{
        m_X = 4;
        return m_X;
    }
    // No trailing const: this method is allowed to modify the object,
    // and therefore cannot be called on a const Entity.
    void SetX(int x){
        m_X = x;
    }
};

// e is a const reference, so only const methods may be called on it.
// GetX() qualifies; SetX() would not compile here.
void PrintEntity(const Entity& e){
    cout << e.GetX() << endl;
}


int main(){

    Entity e;
    e.GetX();

    const int MAX_AGE = 99;   // must be initialized here; can never be reassigned

    int* a = new int;
    *a = 3;
    cout << *a << endl;
    // (leaked -- 'delete a;' belongs here)
}
