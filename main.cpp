#include <iostream>
#include "coutGenerator.h"

using namespace std;

int main()
{
    cout << "Generador de 'cout' per a dibuixar figures.\nAmplada de la figura: ";
    int alcada, amplada;
    cin >> amplada;

    cout << "Alcada: ";
    cin >> alcada;

    cout << "Quantes figures vols per fila? ";
    int quantitat;
    //cin >> quantitat; // Pendent d'actualització
    // Control d'error
    if (quantitat < 0)
    {
        cout << " [e] -> " << quantitat << " no és una quantitat vàlida" << endl;
        return -1;
    }
    cout << "[i] -> Generant fitxer..." << endl;


    coutGenerator coutGen;

    if (!coutGen.generarFitxer(amplada, alcada, 1)) // Treballant en el numero de figures que podem fer en paral·lel
    {
        cout << " [e] -> No s'ha pogut generar el fitxer" << endl;
        return -1;
    }
    cout << "[i] -> El fitxer s'ha generat correctment" << endl;

    coutGen.imprimirFigura();

    return 0;
}