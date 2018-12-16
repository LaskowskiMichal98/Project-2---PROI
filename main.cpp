#include <iostream>
#include <string.h>
#include <vector>
#include "klasy.h"
using namespace std;

int main() {


    vector<rownanie>* lista = new vector<rownanie>;
    *lista=getData();

    for (int i = 0; i < 3; ++i) {
        (*lista)[i].printClass();
        cout << endl << endl;
    }
    return 0;
}