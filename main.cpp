#include <iostream>
#include <string.h>
#include <vector>
#include "klasy.h"
#include "Handlers.h"
using namespace std;

int main() {

    vector<equation> list;
    list=getData();

    HandleCalculations* Plus = new HandlePlus;
    HandleCalculations* Minus = new HandleMinus;
    HandleCalculations* Star = new HandleStar;
    HandleCalculations* Slash = new HandleSlash;
    HandleCalculations* Exp = new HandleExp;
    HandleCalculations* Brackets = new HandleBrackets;
    HandleCalculations* Number = new HandleNumber;

    Plus->setNextHandler(Minus);
    Minus->setNextHandler(Star);
    Star->setNextHandler(Slash);
    Slash->setNextHandler(Exp);
    Exp->setNextHandler(Brackets);
    Brackets->setNextHandler(Number);

    for (int i = 0; i < list.size(); ++i) {
        if(!list[i].getComplete()) {
            list[i].setValue(Plus->calculation(list[i].getCalculate(), Plus,list));
                list[i].setCompleted(true);
            }

        printResult(list[i]);
    }

    return 0;
}