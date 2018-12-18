#include <iostream>
#include <string.h>
#include <vector>
#include <math.h>
#include "klasy.h"
#include "Handlers.h"
using namespace std;

void Calculations(vector<equation>, HandleCalculations*);

int main() {

    vector<equation> list;
    list=getData();
    string change;
    int found = 0;

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

    Calculations(list,Plus);

    cout << endl << endl;

    cout << "Podaj wartosc od ktorej uzaleznic dalsze obliczenia np. a=15" << endl;
    cin >> change;

    for (int i = 0; i < list.size(); ++i) {
        list[i].setCompleted(false);
        if(change[0]==list[i].getLetter()){
            found=1;
            list[i].setCompleted(true);
            list[i].setValue(stof(change.substr(2)));
        }
    }
    if(found!=1){
        cout << "Nie znaleziono zadanej litery" << endl;
        exit(6);
    }

    Calculations(list,Plus);

    return 0;
}


void Calculations(vector<equation> list, HandleCalculations* Plus){
    for (int i = 0; i < list.size(); ++i) {
        if(!list[i].getComplete()) {
            list[i].setValue(Plus->calculation(list[i].getCalculate(), Plus,list));
            list[i].setCompleted(true);
        }
        if(isinf(list[i].getValue())){
            cout << "W obliczeniach wystapilo dzielenie przez 0" << endl;
            exit(5);
        }
        printResult(list[i]);
    }
}