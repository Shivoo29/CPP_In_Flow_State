#include <iostream>
#include <string>
#include <memory> // to get access to all the smart pointer
using namespace std;

// Smart Pointers: Generally when you create a pointer using new you also have to delete it to free up space form the memory
// smart pointers are basically a wrapper around a raw pointer 
// when you call a smart_PTR it will automatically call new and then after some time it will also call delete based on what pointer you have used.

// first pointer is unique Pointer, it is a scoped pointer, when this ptr gets out of scope it will get deleted.
// it is called a unique_ptr because you can't copy it. If you try to do so there will be 2 ptrs pointing to the same memory location
// so when one of them dies it frees the memory but now the 2nd pointer is pointing to a freed up space.

class Entity{
    public:
    Entity()
    {
        cout << "Created Sucesfully" << '\n';
    }
    ~Entity()
    {
        cout << "Destructed Sucessfully" << '\n';
    }

    void Print(){}
};

int main(){
    

    shared_ptr<Entity> e0;
    //weak_ptr<Entity> e0; this won't work because the counter is already 0 because the scope is ended.
    {
            //unique_ptr<Entity> entity = new Entity() // cant do this because the constructor is expliclit
            //unique_ptr<Entity> entity(new Entity); // can do this because this is explicit already
            unique_ptr<Entity> entity = make_unique<Entity>(); // prefered (exception saefty)
            //unique_ptr<Entity> e0 = entity; // can't copy

            // Sencond poitner is Shared Pointer 
            // under the hood it works by reference counting -- simply how many reference you have to your pointer
            // and when that reference count == 0 it gets deleted 
            shared_ptr<Entity> sharedEntity = make_shared<Entity>();
            //shared_ptr<Entity> sharedEntity(new Entity()); ths compiles fine but we still not going to do this because 
            //shared_ptr has to allocate another block of memory called "control block" where it stores that reference count
            //and if you create a new entity and then pass it to the shared_ptr, then that's 2 allocation
            //because you are constructing the entity first and then the shared_ptr has to construct its control block. 


            e0 = sharedEntity;

            //when you assign a shared_ptr to another shared_ptr then the reference count will increase
            //but when you assign a shared_ptr to a weak_ptr then the reference count doen't increase
            weak_ptr<Entity> weakEntity = sharedEntity;
            //shared_ptr<Entity> e0 = sharedEntity; // can copy this no one will complaint
            entity -> Print();
    }
}
