#include <iostream>
using namespace std;

int main (){
    int example[5];
    example[0] = 2;
    example[4] = 4;
    // cout <<example[0] << endl;
    // cout <<example[4] << endl;
    
    for (int i = 0; i < 5; i++){
        example[i] = 2;
        cout << example[i] << endl;
    }

    int* ptr = example; // pointer to the first element of the array
    ptr[3] = 10; // change the value of the fourth element using pointer
    for (int i = 0; i < 5; i++){
        cout << example[i] << ", ";

    } cout << endl;

    example[4] = 20;
    *(ptr + 4) = 1;
    cout << example[4] << endl; 

    // heap implementation of array
    int* another = new int[5]; // this will not get deleted automatically, we need to delete it manually
    for (int i = 0; i < 5; i++){
        another[i] = i;
        cout << another[i] << ", ";
    }
    cout << endl;
    delete[] another; // free the memory allocated for the array
}