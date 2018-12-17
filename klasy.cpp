//
// Created by Michał Laskowski on 09/12/2018.
//

#include "klasy.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

#define PATH "/users/michallaskowski/clionprojects/zadanie 2.7/test.txt"

using namespace std;


void equation:: printClass(){
    cout << "Rownanie:" << this->forCalculation << endl;
    cout << "Litera: " << this->letter << endl;
    cout << "Rowiazane?" << this->completed << endl;
    cout << "Wartosc: " << this->value << endl;
}


vector<equation> getData(){

    vector<equation> fileEquations;
    fstream plik;
    plik.open(PATH,ios::in);

    if(!plik.good()){
        cout << "Blad otwarcia pliku" <<endl;
        exit(-1);
    }

    string temp;
    string calc;
    equation add;

    while(!plik.eof()){

    getline(plik,temp);

    temp=getRidOfSpaces(temp);

    if(!checkData(temp)){
        cout << "Plik zawiera niewlasciwe dane." << endl;
        exit (1);
    }
    calc=temp.substr(2);
    add.setCalculate(calc);
    add.setCompleted(false);
    add.setLetter(temp[0]);
    fileEquations.push_back(add);
    }

    plik.close();
    return fileEquations;
}


string getRidOfSpaces(string object){

    for (int i = 0; i < object.size(); ++i) {
        if((object)[i]==' '){
            for (int j = i; j < object.size()-1; ++j) {
                object[j]=object[j+1];
            }
            object.erase(object.size()-1);
        }
    }

    return object;
};


double findValue(char X, vector<equation> equations){

    for (int i = 0; i < equations.size(); ++i) {
        if(X==equations[i].getLetter()){
            if(equations[i].getComplete())
            return equations[i].getValue();
            else{
                return 3.14159265;
            }
        }
    }
    cout << "W rownaniu wystepuje litera, ktorej wartosc nie moze byc obliczona" << endl;
    exit(2);
}


bool checkData(string check){

    const string wrong[26] = {",.<>?`~!@#$%&_[]{}|§£","++","--","**","//","^^","+-","-+","+*","*+","+/","/+","+^","^+","-*","*-","-/","/-","-^","^-",
                             "*/","/*","*^","^*","/^","^/"};

    if((check)[1]!='='){
        return false;
    }

    if(check.find_first_of(wrong[0])!=string::npos){
        return false;
    }

    for (int i = 1; i < 26; ++i) {
        if(check.find(wrong[i])!=string::npos){
            return false;
        }
    }
    for (int k = 0; k < check.size()-1; ++k) {

        if (((int) check[k] > 96 && (int) check[k] < 123 && (int) check[k + 1] > 96 && (int) check[k + 1] < 123) ||
            ((int) check[k] > 96 && (int) check[k] < 123 && (int) check[k + 1] > 47 && (int) check[k + 1] < 58) ||
            ((int) check[k] > 47 && (int) check[k] < 58 && (int) check[k + 1] > 96 && (int) check[k + 1] < 123) ||
            (check[k] == '(' && (check[k + 1] == '+' || check[k + 1] == '-' || check[k + 1] == '*' || check[k + 1] == '/' || check[k + 1] == '^')) ||
            (check[k + 1] == ')' && (check[k] == '+' || check[k] == '-' || check[k] == '*' || check[k] == '/' || check[k] == '^')) ||
            (check[check.size()-1] == '(') ||
            (check[check.size()-1] == '=') ||
            (check[check.size()-1] == '+') ||
            (check[check.size()-1] == '*') ||
            (check[check.size()-1] == '/') ||
            (check[check.size()-1] == '^') ||
            (check[check.size()-1] == '-')) {
            return false;
        }
    }
    for (int j = 0; j < check.size()-1; ++j) {
        if (check[j] == '/' && check[j + 1] == '0') {
            return false;
        }
    }
    return true;
}
