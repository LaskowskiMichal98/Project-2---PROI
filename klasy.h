//
// Created by Michał Laskowski on 09/12/2018.
//

#ifndef ZADANIE_2_7_KLASY_H
#define ZADANIE_2_7_KLASY_H
#include<iostream>

using namespace std;
class equation {

    string calculate;
    bool completed;
    char letter;
    double value;

public:
    equation(string cal = "1", bool com = true, char let = 'a', int val = 1){
        calculate=cal;
        completed=com;
        letter = let;
        value = val;
    }

    string getCalculate() const{
        return this->calculate;
    }
    char getLetter() const{
        return this->letter;
    }
    double getValue() const{
        return this->value;
    }
    bool getComplete() const{
        return this ->completed;
    }
    void setCalculate(string temp){
        this->calculate=temp;
    }
    void setCompleted(bool temp){
        this->completed=temp;
    }
    void setLetter(char temp){
        this->letter=temp;
    }
    void setValue(double temp){
        this->value=temp;
    }

    void printClass();
};


class HandleCalc{
public:
    HandleCalc* next;
    
};
vector<equation> getData();
string getRidOfSpaces(string);
double findValue(char,vector<equation>);
bool checkData(string);

#endif //ZADANIE_2_7_KLASY_H
