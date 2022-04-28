#include <iostream>

#include "Carte.h"
using namespace std;

Carte::Carte() ///Constructeur
{
    for(int i=0; i<nbContinent ; i++)
        {
            tabCont[i] = new Continent(i);
        }

}
Carte::~Carte() ///Destructeur
{
    for(int i=0; i<nbContinent; i++)
        {
            delete [] tabCont[i];
        }

}
