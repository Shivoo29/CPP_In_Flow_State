#include <iostream>
#include <string>

using namespace std;

static int s_Level = 7;
static int s_Speed = 2;

int main(){
    //if (s_Level > 5) s_Speed = 10;
    //else s_Speed = 5;

    s_Speed = s_Level > 5 ? 10 : 5;
    string rank = s_Level > 10 ? s_Speed >=10 ? "Master" : "Noob" : "Normal";
    

    cout << s_Speed << endl;
    cout << rank << endl;
}