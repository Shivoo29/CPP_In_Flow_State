#include <iostream>
#include <string>
#include <memory> // to get access to all the smart pointer
using namespace std;

// Smart Pointers: Generally when you create a pointer using new you also have to delete it to free up space form the memory
// smart pointers are basically a wrapper around a raw pointer 
// when you call a smart_PTR it will automatically call new and then after some time it will also call delete based on what pointer you have used.

// first pointer is unique Pointer, it is a scoped pointer, when this ptr gets out of scope it will get deleted.
// it is called a unique_ptr because you can't copy it. If copying were allowed you would end up with 2 ptrs
// owning the same memory location, so when one of them dies it frees the memory and the 2nd pointer is left
// pointing at freed space (a dangling pointer). Forbidding the copy is what makes that impossible.

class Entity{
    private:
    string m_Name;   // just a label so we can tell the two objects apart in the output

    public:
    // Taking a name here means make_unique<Entity>("...") forwards that
    // argument straight to this constructor.
    Entity(const string& name) : m_Name(name)
    {
        cout << "Created Sucesfully   -> " << m_Name << '\n';
    }
    ~Entity()
    {
        cout << "Destructed Sucessfully -> " << m_Name << '\n';
    }

    void Print(){}
};

int main(){
    

    shared_ptr<Entity> e0;
    //weak_ptr<Entity> e0; this would still COMPILE, but it would be useless here:
    //a weak_ptr does not own anything, so nothing would keep the object alive past the block.
    //You would have to call e0.lock() afterwards and it would come back empty (expired).
    {
            //unique_ptr<Entity> entity = new Entity("unique") // can't do this: unique_ptr's constructor
            //                                                    from a raw pointer is explicit, and '=' is
            //                                                    copy-initialization, which explicit forbids.
            //unique_ptr<Entity> entity(new Entity("unique")); // this form works -- parentheses are
            //                                                    direct-initialization, which explicit allows
            unique_ptr<Entity> entity = make_unique<Entity>("unique"); // prefered (exception saefty)
            //unique_ptr<Entity> e0 = entity; // can't copy

            // Sencond poitner is Shared Pointer 
            // under the hood it works by reference counting -- simply how many reference you have to your pointer
            // and when that reference count == 0 it gets deleted 
            shared_ptr<Entity> sharedEntity = make_shared<Entity>("shared");
            //shared_ptr<Entity> sharedEntity(new Entity("shared")); ths compiles fine but we still not going to do this because 
            //shared_ptr has to allocate another block of memory called "control block" where it stores that reference count
            //and if you create a new entity and then pass it to the shared_ptr, then that's 2 allocation
            //because you are constructing the entity first and then the shared_ptr has to construct its control block. 


            e0 = sharedEntity;   // ref count for the "shared" object goes 1 -> 2

            //when you assign a shared_ptr to another shared_ptr then the reference count will increase
            //but when you assign a shared_ptr to a weak_ptr then the reference count doen't increase
            weak_ptr<Entity> weakEntity = sharedEntity;
            //shared_ptr<Entity> e0 = sharedEntity; // can copy this no one will complaint
            entity -> Print();
    }   // end of block. Locals die in REVERSE order of declaration:
        //   weakEntity   -> owns nothing, no effect on the count
        //   sharedEntity -> count 2 -> 1. Still not zero (e0 holds one), so NO destructor yet
        //   entity       -> unique_ptr is the sole owner, so "unique" is destroyed HERE

    cout << "-- block ended, still alive: " << e0.use_count() << " owner of shared --\n";

}   // end of main: e0 dies, count 1 -> 0, so "shared" is destroyed HERE.
    // That is why the shared object outlives the scope it was created in.
