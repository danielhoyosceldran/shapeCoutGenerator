/*

El programa generarà un fitxer .txt amb les linies cout necessàries per a
dibuixar les figures que necessiti mitjançant "cout".

La llibreria de gestió d'arxius que utlitzaré serà la ·fstream"

*/
#include "coutGenerator.h"

void coutGenerator::generarTop(ofstream &codiGenerat, string &top, int &amplada, int &numFigures)
{
    // Generates the top and bottom sides
    codiGenerat << "cout << \"";
    string auxTop;
    auxTop.assign(top);
    for (int i = 1; i < numFigures; i++)
    {
        auxTop.append("   ");
        auxTop.append(top);
    }
    codiGenerat << auxTop;
    codiGenerat << "\" << endl;\n";
}   

bool coutGenerator::generarFitxer(int amplada, int alcada, int numFigures)
{
    // Error control for non valid number of squares
    if (numFigures < 1)
    {
        cout << " [e] -> " << numFigures << " no és una quantitat valida" << endl;
        return false;
    }

    //D Defining the sides of the square
    string top, side;
    top.assign(amplada, '-');
    side.assign(amplada - 2, ' ');

    // Creating file
    ofstream codiGenerat;
    codiGenerat.open("codiGenerat.cpp", fstream::out);
    if (!codiGenerat.is_open())
    {
        cout << " [e] -> No s'ha obert el fitxer" << endl;
        return false;
    }
    codiGenerat.flush(); //Buida el fitxer de tot el contingut que pugui tenir

    codiGenerat << "#include <iostream>\nusing namespace std;";
    codiGenerat << "int main(){\n";
    
    generarTop(codiGenerat, top, amplada, numFigures);
    for (int i = 0; i < alcada; i++)
    {
        codiGenerat << "cout << \"|";
        string auxSide;
        auxSide.assign(side);
        for (int j = 1; j < numFigures; j++)
        {
            auxSide.append("|   |");
            auxSide.append(side);
        }
        codiGenerat << auxSide;
        codiGenerat << "|\" << endl;\n";
    }
    generarTop(codiGenerat, top, amplada, numFigures);
    codiGenerat << "}";
    
    return true;
}

void coutGenerator::imprimirFigura() // Compile and run the program that contains the squares. Print the squares
{
    ifstream figura;
    figura.open("codiGenerat.cpp", fstream::in);

    int compilation, execution;
    compilation = system("g++ -o cg codiGenerat.cpp");
    
    if (compilation == 0)   execution = system("cg.exe");
    else                    cout << " [e] -> Square compilation failed" << endl;
    
    if (execution == 0)     system("del cg.exe");
    else                    cout << " [e] -> Square execution failed" << endl;

    return;
}