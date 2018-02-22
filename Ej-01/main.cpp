#include <iostream>
#include "../ArbolBinario/ArbolBinario.h"

using namespace std;

int const cant = 30;

int main() {
    ArbolBinario<int> arbolito;
    int staticArray[cant];

    srand(time(NULL));
    for (int i = 0; i < cant; ++i) {
        staticArray[i] = rand() % 401 + 100;
    }

    int cont = cant;
    for (int j = 0; j < cant; ++j) {
        try {
            arbolito.put(staticArray[j]);
        } catch (int e) {
            cont--;
        }
    }

    arbolito.print();
    cout << "El arbol tiene " << cont << " hojas distintas\n";
    return 0;
}