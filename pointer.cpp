#include <iostream>
#include "super.h"
using namespace std;


void incriment(int* value){
    (*value)++; // dereferencing the pointer and 
                //incrementing the value it points to
}

void incriment(int& value){
    value++;
}

int main(){

    int var {4};
    int* ptr {&var};
    *ptr = 10;
    cout << var << endl;

    int a {3};
    int& b {a};
    log(b);
    incriment(&a);
    incriment(a);
    log(a);

}


