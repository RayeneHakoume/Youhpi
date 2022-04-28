#ifndef CARTE_H_INCLUDED
#define CARTE_H_INCLUDED
#include "Continent.h"
using namespace std;

/**
@brief Classe Carte
@author 11503521 11706748 11706619
@file file\Carte.h
@version 3
@date 29/03/2020
**/
class Carte{
    private:
    /**@brief Donnees membres*/

        /**@brief un pointeur de tableau sur Continent*/
       // Continent * tabCont[nbContinent];

     public:
        /**@brief fonctions membres*/

        Continent *tabCont[nbContinent];

        /**
        @brief Constructeur par defaut
        */
        Carte();

        /**
        @brief Destructeur par defaut
        */
        ~Carte();



};


#endif // CARTE_H_INCLUDED

