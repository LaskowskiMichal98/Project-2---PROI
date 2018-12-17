
#ifndef ZADANIE_2_7_KLASY_H
#define ZADANIE_2_7_KLASY_H
#include<iostream>

using namespace std;
class equation {

    string forCalculation;
    bool completed;
    char letter;
    double value;

public:
    equation(string cal = "1", bool com = true, char let = 'a', int val = 1){
        forCalculation=cal;
        completed=com;
        letter = let;
        value = val;
    }

    string getCalculate() const{
        return this->forCalculation;
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
        this->forCalculation=temp;
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


vector<equation> getData();
string getRidOfSpaces(string);
double findValue(char,vector<equation>);
bool checkData(string);

#endif
