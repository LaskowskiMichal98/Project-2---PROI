

#include "Handlers.h"
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include "equation.h"

using namespace std;

double HandlePlus::calculation(string calculate,HandleCalculations* beg,vector<equation> list) {

    int openBracket=0;
    int closeBracket=0;
    int pos = -1;
    string split = "0";
    for (int i = 0; i < calculate.size(); ++i) {                        // Pomijam nawiasy, ponieważ te mają być policzone w pierwszej kolejności
        if(calculate[i]=='('){
            openBracket++;
        }
        else if (calculate[i]==')'){
            closeBracket++;
        }
        else if(calculate[i]=='+' && openBracket==closeBracket){       // Szukam znaku + w stringu i jeżeli takowy się znajduje, dzielę ten string na dwa osobne i
            pos=i;                                                     // zwracam sumę wywołań tej funkcji dla tych dwóch stringów
            break;
        }
    }

    if(pos==-1){
        return next->calculation(calculate,beg,list);                 // Jeżeli w stringu nie znajduje się żaden znak + , przekazuję go do kolejnej funkcji
    }                                                                 // Postępuję tak samo w funkcjach dla znków: - , * , / , ^
    else {
        split = calculate.substr(pos + 1);
        calculate.erase(pos);
        return (this->calculation(calculate,beg,list) + this->calculation(split,beg,list));
    }
}

double HandleMinus::calculation(string calculate,HandleCalculations* beg,vector<equation> list) {
    int openBracket=0;
    int closeBracket=0;
    int pos = -1;

    for (int i = 0; i < calculate.size(); ++i) {
        if(calculate[i]=='('){
            openBracket++;
        }
        else if (calculate[i]==')'){
            closeBracket++;
        }
        else if(calculate[i]=='-' && openBracket==closeBracket){
            pos=i;
            break;
        }
    }

    if(pos==-1){
        return next->calculation(calculate,beg,list);
    }
    else {
        string split = calculate.substr(pos + 1);
        calculate.erase(pos);

        return (this->calculation(calculate, beg,list) - this->calculation(split, beg,list));
    }
}

double HandleStar::calculation(string calculate,HandleCalculations* beg,vector<equation> list) {
    int openBracket=0;
    int closeBracket=0;
    int pos = -1;

    for (int i = 0; i < calculate.size(); ++i) {
        if(calculate[i]=='('){
            openBracket++;
        }
        else if (calculate[i]==')'){
            closeBracket++;
        }
        else if(calculate[i]=='*' && openBracket==closeBracket){
            pos=i;
            break;
        }
    }

    if(pos==-1){
      return  next->calculation(calculate,beg,list);
    }
    else {
        string split = calculate.substr(pos + 1);
        calculate.erase(pos);

        return (this->calculation(calculate, beg,list) * this->calculation(split, beg,list));
    }
}

double HandleSlash::calculation(string calculate,HandleCalculations* beg,vector<equation> list) {
    int openBracket=0;
    int closeBracket=0;
    int pos = -1;

    for (int i = 0; i < calculate.size(); ++i) {
        if(calculate[i]=='('){
            openBracket++;
        }
        else if (calculate[i]==')'){
            closeBracket++;
        }
        else if(calculate[i]=='/' && openBracket==closeBracket){
            pos=i;
            break;
        }
    }

    if(pos==-1){
        return next->calculation(calculate,beg,list);
    }
    else {
        string split = calculate.substr(pos + 1);
        calculate.erase(pos);

        return (this->calculation(calculate, beg,list) / this->calculation(split, beg,list));
    }
}

double HandleExp::calculation(string calculate,HandleCalculations* beg,vector<equation> list) {
    int openBracket=0;
    int closeBracket=0;
    int pos = -1;

    for (int i = 0; i < calculate.size(); ++i) {
        if(calculate[i]=='('){
            openBracket++;
        }
        else if (calculate[i]==')'){
            closeBracket++;
        }
        else if(calculate[i]=='^' && openBracket==closeBracket){
            pos=i;
            break;
        }
    }

    if(pos==-1){
        return next->calculation(calculate,beg,list);
    }
    else {
        string split = calculate.substr(pos + 1);
        calculate.erase(pos);

        return pow(this->calculation(calculate,beg,list), this->calculation(split,beg,list));
    }
}

double HandleBrackets::calculation(string calculate,HandleCalculations* beg,vector<equation> list) {
    int openPos=calculate.find_last_of("(");                                    // W wejściowym stringu szukam "najgłębszego" nawiasu i  dla jego zawartości wywołuję
    int closePos=calculate.find_first_of(")",openPos);                          // cały proces obliczania
    if(closePos!=-1 && openPos!=-1) {
        string split = calculate.substr(openPos+1, (closePos - openPos)-1);
        return(beg->calculation(split, beg,list));
    } else
        return next->calculation(calculate,beg,list);

}


double HandleNumber::calculation(string calculate, HandleCalculations * beg, vector<equation> list) {
    int found = 0;

    if ((int) calculate[0] > 60 && (int) calculate[0] < 123) {                  // Ostatni etap - wejściowy string składa się jedynie z liczby rzeczywistej bądź
        for (int i = 0; i < list.size(); ++i) {                                 // litery. Jeżeli jest to liczba rzeczywista - zwracam ją jako double.
            if (list[i].getLetter() == calculate[0]) {                          // Jeżeli jest to litera - sprawdzam czy jest ona obliczona - jeśli tak to zwracam
                found++;                                                        // jej wartość, jeśli nie - wywołuję wszystkie obliczenia dla równania tej litery.
                if(list[i].getComplete()) {
                    return list[i].getValue();
                }
                else{
                    list[i].setValue(beg->calculation(list[i].getCalculate(),beg,list));
                    list[i].setCompleted(true);
                    return list[i].getValue();
                }
            }
        }
        if(found==0){
            cout << "Nie znaleziono rownania dla litery: " << calculate << endl;
            exit (4);
        }
    }

    return stof(calculate);

}