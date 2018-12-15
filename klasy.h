//
// Created by Michał Laskowski on 09/12/2018.
//

#ifndef ZADANIE_2_7_KLASY_H
#define ZADANIE_2_7_KLASY_H
#include<iostream>
#include <string.h>

using namespace std;
class rownanie {

    string zawartosc;
    bool rozwiazane;
    char litera;
    double wartosc;

public:
    rownanie(string sciezka = "a=1", bool czy = true, char lit = 'a', int war = 1){
        zawartosc=sciezka;
        rozwiazane=czy;
        litera = lit;
        wartosc = war;
    }

    string getZawartosc() const{
        return this->zawartosc;
    }

    friend vector<rownanie> getData();
    friend void getRidOfSpaces(string);
};

vector<rownanie> getData();
void getRidOfSpaces(string);

#endif //ZADANIE_2_7_KLASY_H
