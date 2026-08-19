#include <iostream>

// Abstraction = hiding unnecessary data from outside a class
// getter = function that makes a private attribute READABLE
// setter = function that makes a private attribute WRITABLE

class Stove{
    /*public:
    int temperature = 0;*/
    private:
    int temperature = 0;
    public:

    int getTemperature(){
        return temperature;
    }

    void setTemperature(int temperature){
        if( temperature < 0 ) { this -> temperature = 0; }
        else if( temperature >= 100 ) { 
            this -> temperature = 100;
            std::cout << "temperature is maxed out!!" << '\n';
        }
        else {this -> temperature = temperature;}
    }
};

int main(){
    Stove stove;

    // stove.temperature = 1000000;
    stove.setTemperature(1000000);

    std::cout << "the temperature of the stove is " << stove.getTemperature() << '\n';
}