// ============================================================
// ARRAYS (and why they are really pointers)
// ------------------------------------------------------------
// An array is a block of same-typed values laid out back to back in
// memory. The array's name decays into a pointer to its first
// element, which is why example[i] and *(ptr + i) mean the same thing.
// C++ does NOT bounds-check: reading example[99] compiles fine and
// quietly reads someone else's memory.
// ============================================================

#include <iostream>
using namespace std;

int main (){
    int example[5];   // 5 ints on the stack, all uninitialized garbage.
                      // 'int example[5] = {};' would zero them.
    example[0] = 2;
    example[4] = 4;   // indices run 0..4. example[5] would be out of bounds.
                      // cout <<example[0] << endl;
                      // cout <<example[4] << endl;

    for (int i = 0; i < 5; i++){
        example[i] = 2;
        cout << example[i] << endl;
    }

    int* ptr = example; // pointer to the first element of the array
                        // (the array "decays" to &example[0] here)
    ptr[3] = 10;        // change the value of the fourth element using pointer
                        // ptr[3] is literally defined as *(ptr + 3)
    for (int i = 0; i < 5; i++){
        cout << example[i] << ", ";

    } cout << endl;

    example[4] = 20;
    // Pointer arithmetic: +4 moves 4 *ints* (16 bytes), not 4 bytes.
    // The compiler scales by the pointed-to type's size for you.
    *(ptr + 4) = 1;
    cout << example[4] << endl;   // prints 1 -- same memory as ptr+4

    // heap implementation of array
    // Needed when the size is only known at runtime, or when the
    // array must outlive this function.
    int* another = new int[5]; // this will not get deleted automatically, we need to delete it manually
    for (int i = 0; i < 5; i++){
        another[i] = i;
        cout << another[i] << ", ";
    }
    cout << endl;
    delete[] another; // free the memory allocated for the array
                      // delete[] (with brackets) for anything made
                      // with new[]. Plain delete here is undefined behaviour.
}
