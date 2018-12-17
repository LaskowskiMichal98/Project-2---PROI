//
// Created by Michał Laskowski on 17/12/2018.
//

#include "Handlers.h"
#include <iostream>

using namespace std;

double HandlePlus::calculation(string calculate) {

}

double HandleMinus::calculation(string calculate) {

}

double HandleStar::calculation(string calculate) {

}

double HandleSlash::calculation(string calculate) {

}

double HandleExp::calculation(string calculate) {

}

double HandleBrackets::calculation(string calculate) {

}

double Error::calculation(string calculate) {
    cout << "Wystapil blad podczas obliczania :" << calculate << endl;
    exit(3);
}