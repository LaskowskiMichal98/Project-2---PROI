//
// Created by Michał Laskowski on 09/12/2018.
//

#include "klasy.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <cstdlib>

#define PATH "/users/michallaskowski/clionprojects/zadanie 2.7/test.txt"

using namespace std;

void rownanie:: printClass(){
    cout << "Rownanie:" << this->zawartosc << endl;
    cout << "Litera: " << this->litera << endl;
    cout << "Rowiazane?" << this->rozwiazane << endl;
    cout << "Wartosc: " << this->wartosc << endl;
}

vector<rownanie> getData(){

    vector<rownanie> rownania(10);
    fstream plik;
    plik.open(PATH,ios::in);

    if(!plik.good()){
        cout << "Blad otwarcia pliku" <<endl;
        exit(-1);
    }

    const char* wrong[26] = {",.<>?`~!@#$%&_[]{}|§£","++","--","**","//","^^","+-","-+","+*","*+","+/","/+","+^","^+","-*","*-","-/","/-","-^","^-",
                "*/","/*","*^","^*","/^","^/"};

    string temp;
    int count=0;
    while(!plik.eof()){

    getline(plik,temp);

    if((temp)[1]!='='){
        cout << "Plik zawiera bledne dane" << endl;
        exit (-1);
    }

    if(strpbrk((&temp[0]),wrong[0])!= nullptr){
        cout << "Plik zawiera bledne dane" << endl;
        exit (-1);
    };

    for (int i = 1; i < 27; ++i) {
        if(strstr((&temp[0]),wrong[i])!= nullptr){
            cout << "Plik zawiera bledne dane" << endl;
            exit (-1);
        }
    }

        for (int j = 0; j < temp.size()-1; ++j) {

            if(temp[j]=='/' && temp[j+1]=='0'){
                cout << "W danych wejsciowych wystepuje dzielenie przez 0" << endl;
                exit(1);
            }
            if (((int)temp[j] > 96 && (int)temp[j] < 123 && (int)temp[j+1] > 96 && (int)temp[j+1] < 123) ||
                    ((int)temp[j] > 96 && (int)temp[j] < 123 && (int)temp[j+1] > 47 && (int)temp[j+1] < 58) ||
                    ((int)temp[j] > 47 && (int)temp[j] < 58 && (int)temp[j+1] > 96 && (int)temp[j+1] < 123) ||
                    (temp[j]=='(' && (temp[j+1]=='+' || temp[j+1]=='-' || temp[j+1]=='*' || temp[j+1]=='/' || temp[j+1]=='^')) ||
                    (temp[j+1]==')' && (temp[j]=='+' || temp[j]=='-' || temp[j]=='*' || temp[j]=='/' || temp[j]=='^')) || (temp[strlen(&temp[0])-1]=='(')
                    || (temp[strlen(&temp[0])-1]=='=') || (temp[strlen(&temp[0])-1]=='+') || (temp[strlen(&temp[0])-1]=='*') || (temp[strlen(&temp[0])-1]=='/')
                    || (temp[strlen(&temp[0])-1]=='^') || (temp[strlen(&temp[0])-1]=='-')){
                cout << "Plik zawiera bledne dane" << endl;
                exit (-1);
            }
        }
        temp=getRidOfSpaces(temp);
        rownania[count].setZawartosc(temp);
        rownania[count].setRozwiazane(false);
        rownania[count].setLitera(temp[0]);

        count++;

    }
    plik.close();
    return rownania;
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

