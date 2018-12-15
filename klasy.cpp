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

        for (int j = 0; j < strlen(&temp[0])-1; ++j) {
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
        rownania[count].zawartosc=temp;
        count++;

    }
    plik.close();
    return rownania;
}

void getRidOfSpaces(string object){

    char temp1[100];
    strcpy(temp1,(&object[0]));
    cout << temp1 << endl;
    cout << strlen(temp1) << endl;
    for (int i = 0; i < strlen(temp1); ++i) {
        if((temp1)[i]==' '){
            for (int j = i; j < strlen(temp1)-1; ++j) {
                temp1[j]=temp1[j+1];
            }
            object[strlen(temp1)]='X';
        }
    }

    cout << temp1 << endl;
    cout << strlen(temp1) << endl;
};