// ============================================================
// VALUE-RETURNING FUNCTIONS
// ------------------------------------------------------------
// A function's return type is a contract: getValueFromUser() promises
// to hand back an int. 'return x;' fulfils it and hands control back
// to the caller.
// The point of pulling this out into its own function is reuse and
// naming -- the call site reads as what it does, not how it does it.
// ============================================================

#include <iostream>
using namespace std;

int getValueFromUser(){
    cout << "Enter any integer: ";
    int x {};      // empty braces = VALUE INITIALIZATION -> x starts at 0.
                   // Plain 'int x;' would leave garbage in it.
    cin >> x;      // reads from keyboard into x.
                   // (If the user types letters, cin fails and x stays 0.)
    return x;      // hands the value back to whoever called us
}

int main(){
    int num {};

    num = getValueFromUser();   // the call is replaced by its return value

    cout << num <<" double is: " << num * 2<< '\n';
    return 0;
}
