#include <iostream>
#include "super.h"

using namespace std;

int main() {
    cout << "Enter two numbers to multiply: ";

    int a{};
    cin >> a;

    int b{};
    cin >> b;

    result(a, b);

    for(int i=0; i<5; i++){
        log(i);
    }
    return 0;
}