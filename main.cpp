#include <iostream>
#include <string.h>
#include <vector>
#include <math.h>
#include "equation.h"
#include "Handlers.h"
using namespace std;

void StartCalculations(vector<equation>, HandleCalculations*);

int main() {

    string path;
    cout << "Podaj sciezke do pliku / nazwe pliku, z ktorego wczytane zostana dane" << endl;
    getline(cin,path);

    vector<equation> list;
    list=getData(path);
    string change;
    int found = 0;

    HandleCalculations* Plus = new HandlePlus;                  // Tworzę elementy łańcucha zobowiązań i łączę je ze sobą
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

    StartCalculations(list,Plus);

    cout << endl << endl;

    cout << "Podaj wartosc od ktorej uzaleznic dalsze obliczenia np. a=15" << endl;
    getline(cin,change);
    change=getRidOfSpaces(change);

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

    StartCalculations(list,Plus);

    return 0;
}


void StartCalculations(vector<equation> list, HandleCalculations* Plus){
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