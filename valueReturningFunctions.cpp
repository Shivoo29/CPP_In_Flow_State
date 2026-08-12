#include <iostream>
using namespace std;

int getValueFromUser(){
    cout << "Enter any integer: ";
    int x {};
    cin >> x;
    return x;
}

int main(){
    int num {};

    num = getValueFromUser();

    cout << num <<" double is: " << num * 2<< '\n';
    return 0;
}