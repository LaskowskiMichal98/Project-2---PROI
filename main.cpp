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
    HandleCalculations* FoundError = new Error;

    Plus->setNextHandler(Minus);
    Minus->setNextHandler(Star);
    Star->setNextHandler(Slash);
    Slash->setNextHandler(Exp);
    Exp->setNextHandler(Brackets);
    Brackets->setNextHandler(FoundError);

    for (int i = 0; i < list.size(); ++i) {
        list[i].printClass();
    }

    return 0;
}