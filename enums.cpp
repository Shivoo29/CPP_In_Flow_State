#include <iostream>
using namespace std;

enum Example{
    a,b,c // enum is a user-defined data type that consists of integral constants. It is used to assign names to the integral constants which makes a program easy to read and maintain
};

int main (){
    Example value = b;
    if (value == b){
        cout << "Value of b is:" << b << endl;
    }
}