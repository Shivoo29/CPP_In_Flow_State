#pragma once // it basically helps to aboide multiple inclusions of the same header file in a single compilation unit

int multiply(int x, int y);
void result(int x, int y);

void log(int x){
    std::cout << "The value is: " << x << std::endl;

}

/*
older version of the header file with include guards
#ifndef SUPER_H
#define SUPER_H

int multiply(int x, int y);
void result(int x, int y);

#endif // SUPER_H
*/