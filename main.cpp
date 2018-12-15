#include <iostream>
#include <string.h>
#include <vector>
#include "klasy.h"
using namespace std;

int main() {

    cout << "Hello, World!" << endl;

    vector<rownanie>* lista = new vector<rownanie>;
    *lista=getData();

    for (int i = 0; i < 3; ++i) {
        cout << (*lista)[i].getZawartosc() << endl;
    }
    getRidOfSpaces((*lista)[0].getZawartosc());

    return 0;
}