
#ifndef ZADANIE_2_7_HANDLERS_H
#define ZADANIE_2_7_HANDLERS_H

#include <iostream>
#include "equation.h"
using namespace std;


class HandleCalculations {                      // Klasy składowe algorytmu do obliczeń, korzystając z wzorca projektowego "Chain of Responsibility"
public:
    HandleCalculations* next;

    HandleCalculations(){
        next = nullptr;
    }

    virtual double calculation(string,HandleCalculations*,vector<equation>) = 0;

    void setNextHandler(HandleCalculations* nextOne){
        next = nextOne;
    }
};

class HandlePlus : public HandleCalculations{
public:
    double calculation(string,HandleCalculations*,vector<equation>);
};


class HandleMinus : public HandleCalculations{
public:
    double calculation(string,HandleCalculations*,vector<equation>);
};

class HandleStar : public HandleCalculations{
public:
    double calculation(string,HandleCalculations*,vector<equation>);
};

class HandleSlash : public HandleCalculations{
public:
    double calculation(string,HandleCalculations*,vector<equation>);
};

class HandleExp : public HandleCalculations{
public:
    double calculation(string,HandleCalculations*,vector<equation>);
};

class HandleBrackets : public HandleCalculations{
public:
    double calculation(string,HandleCalculations*,vector<equation>);
};

class HandleNumber : public HandleCalculations{
public:
    double calculation(string,HandleCalculations*,vector<equation>);
};

#endif //ZADANIE_2_7_HANDLERS_H
