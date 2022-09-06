#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <string.h>

using namespace std;

class coutGenerator
{
private:
    void generarTop(ofstream &, string &, int &, int &);
public:
    bool generarFitxer(int, int, int);
    void imprimirFigura();
};