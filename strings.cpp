#include <iostream>
#include <string>
using namespace std;

int main(){
    const char* name = "shivam";
    cout << name << endl;

    char name2[6] = {'s','h','i','v','a','m'};
    cout << name2 << endl;
    
    string name3 = "shivam";
    cout << name3 << endl;

    const char* name4 = R"(shivam
    "kumar
    "jha)";

    const char* name5 = "shivam\n"
    "kumar\n"
    "jha";
}