#include <iostream>
#include "super.h"

using namespace std;

int multiply(int x, int y) {
    return x * y;
}

void result(int x, int y) {
    cout << "The result of multiplication is: "
         << multiply(x, y) << endl;
}