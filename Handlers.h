//
// Created by Michał Laskowski on 17/12/2018.
//

#ifndef ZADANIE_2_7_HANDLERS_H
#define ZADANIE_2_7_HANDLERS_H

#include <iostream>
using namespace std;


class HandleCalculations {
public:
    HandleCalculations* next;

    HandleCalculations(){
        next = nullptr;
    }

    virtual double calculation(string) = 0;

    void setNextHandler(HandleCalculations* nextOne){
        next = nextOne;
    }
};

class HandlePlus : public HandleCalculations{
public:
    double calculation(string);
};


class HandleMinus : public HandleCalculations{
public:
    double calculation(string);
};

class HandleStar : public HandleCalculations{
public:
    double calculation(string);
};

class HandleSlash : public HandleCalculations{
public:
    double calculation(string);
};

class HandleExp : public HandleCalculations{
public:
    double calculation(string);
};

class HandleBrackets : public HandleCalculations{
public:
    double calculation(string);
};

class Error : public HandleCalculations{
public:
    double calculation(string);
};

#endif //ZADANIE_2_7_HANDLERS_H
