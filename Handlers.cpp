//
// Created by Michał Laskowski on 17/12/2018.
//

#include "Handlers.h"
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include "klasy.h"

using namespace std;

double HandlePlus::calculation(string calculate,HandleCalculations* beg,vector<equation> list) {

    int openBracket=0;
    int closeBracket=0;
    int pos = -1;
    string split = "0";
    for (int i = 0; i < calculate.size(); ++i) {
        if(calculate[i]=='('){
            openBracket++;
        }
        else if (calculate[i]==')'){
            closeBracket++;
        }
        else if(calculate[i]=='+' && openBracket==closeBracket){
            pos=i;
            break;
        }
    }

    if(pos==-1){
        return next->calculation(calculate,beg,list);
    }
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
    int openPos=calculate.find_last_of("(");
    int closePos=calculate.find_first_of(")",openPos);
    if(closePos!=-1 && openPos!=-1) {
        string split = calculate.substr(openPos+1, (closePos - openPos)-1);
        return(beg->calculation(split, beg,list));
    } else
        return next->calculation(calculate,beg,list);

}


double HandleNumber::calculation(string calculate, HandleCalculations * beg, vector<equation> list) {
    int found = 0;

    if ((int) calculate[0] > 60 && (int) calculate[0] < 123) {
        for (int i = 0; i < list.size(); ++i) {
            if (list[i].getLetter() == calculate[0]) {
                found++;
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