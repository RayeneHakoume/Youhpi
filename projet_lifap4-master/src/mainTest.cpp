#include <iostream>
#include <fstream>

using namespace std;
#include "Continent.h"
#include"Carte.h"
#include"Pays.h"

int main()
{
    /*Carte carte1;
    carte1.testRegressionCarte();
    */

    Continent continent1;
    continent1.testRegressionContinent();
    Pays pays1;
    pays1.testRegressionPays();
    Monument monument1;
    monument1.testRegressionMonument();



    return 0;
}
