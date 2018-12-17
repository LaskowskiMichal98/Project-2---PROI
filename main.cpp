#include <iostream>
#include <string.h>
#include <vector>
#include "klasy.h"
using namespace std;

int main() {

    vector<equation> list;
    list=getData();

    for (int i = 0; i < list.size(); ++i) {
        list[i].printClass();
    }
    return 0;
}