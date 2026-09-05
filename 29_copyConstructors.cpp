#include <iostream>
#include <string>
#include <cstring>
using namespace std;

struct Vector2
{
    /* data */
    float x, y;
};

class String
{
private:
    char* m_Buffer;
    unsigned int m_Size;
public:
    String(const char* string)
    {
        m_Size = strlen(string);
        m_Buffer = new char[m_Size + 1];
        // for ( int i = 0; i < m_Size; i++)
        // {
        //     m_Buffer[i] = string[i];
        // }
        memcpy(m_Buffer, string, m_Size);
        m_Buffer[m_Size] = 0;
    }
};

int main(){
    Vector2 a = { 2, 3 };
    Vector2 b = a;
    b.x = 5;

    //Vector2* a = new Vector2();
    //Vector2* b = a;
    //b->a = 2;
}