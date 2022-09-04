/*

El programa generarà un fitxer .txt amb les linies cout necessàries per a
dibuixar les figures que necessiti mitjançant "cout".

La llibreria de gestió d'arxius que utlitzaré serà la ·fstream"

*/
#include "coutGenerator.h"

void coutGenerator::generarTop(ofstream &codiGenerat, char *top, int &amplada, int &numFigures)
{
    codiGenerat << "cout << \"";
    char *topAux = new char[numFigures * (amplada + 3) - 3];
    memcpy(topAux, top, sizeof(top));
    for (int i = 0; i < numFigures; i++)
    {
        topAux += '   ';
    }
    codiGenerat.write(top, amplada);
    codiGenerat << "\" << endl;\n";
}   

bool coutGenerator::generarFitxer(int amplada, int alcada, int numFigures)
{
    //Definició de les cantonades
    char *top, *side;
    top = new char[amplada];
    memset (top, '-', amplada);

    side = new char[amplada-2];
    memset (side, 32, amplada-2);

    ofstream codiGenerat;
    codiGenerat.open("codiGenerat.cpp", fstream::out);
    if (!codiGenerat.is_open())
    {
        cout << " [e] -> No s'ha obert el fitxer" << endl;
        return false;
    }
    codiGenerat.flush(); //Buida el fitxer de tot el contingut que pugui tenir

    codiGenerat << "#include <iostream>\nusing namespace std;";
    codiGenerat << "int main(){";
    
    generarTop(codiGenerat, top, amplada, numFigures);
    for (int i = 0; i < alcada; i++)
    {
        codiGenerat << "cout << \"|";
        codiGenerat.write(side, amplada-2);
        codiGenerat << "|\" << endl;\n";
    }
    generarTop(codiGenerat, top, amplada, numFigures);
    codiGenerat << "}";
    
    return true;
}

void coutGenerator::imprimirFigura()
{
    ifstream figura;
    figura.open("codiGenerat.cpp", fstream::in);

    int compilation, execution;
    compilation = system("g++ -o cg codiGenerat.cpp");
    if (compilation == 0) execution = system("cg.exe");
    else cout << " [e] -> Square compilation failed" << endl;
    if (execution == 0) system("del cg.exe");
    else cout << " [e] -> Square execution failed" << endl;

    return;
}