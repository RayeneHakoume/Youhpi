#ifndef CONTINENT_H_INCLUDED
#define CONTINENT_H_INCLUDED

#include "Pays.h"
using namespace std;

/**
@brief Classe Image
@author 11503521 11706748 11706619
@file file\Image.h
@version 3
@date 28/03/2020
**/
const int nbContinent = 6;
class Continent{

    private:
    /**@brief Donnees membres*/

        /**@brief identifiant du continent*/
        int idContinent;

        /**@brief nom du continent*/
        string nomC;

        /**@brief  tableau de Pays*/
        //Pays * tabPays;

        /**@brief  nombre de Pays par continent*/
        int nbPays;

     public:

     /**@brief fonctions membres*/

        Pays *tabPays[MaxPays]; //A revoir pourquoi sommes-nous obligé de le mettre en public

        /** @brief Constructeur par defaut */
        Continent();

        /**
        @brief Constructeur avec  parametres
        @param[in] l'identifiant du Continent: entier
        */
        Continent(int idC);

        /**
        @brief Destructeur par defaut
        */
        ~Continent();

        /**
        @brief accesseur permettant de consulter l'identifiant du Continent
        @return l'identifiant du Continent (entier)
        */
        int getidContinent();

        /**
        @brief mutateur permettant de  modifier l'identifiant du Continent
        @param[in] l'identifiant du Continent: entier
        */
        void setidContinent(int idC);

        /**
        @brief accesseur permettant de consulter le nombre de pays par continent
        @return le nombre de Pays (entier)
        */
        int getNbPays();

        /**
        @brief mutateur permettant de  modifier le nombre de pays par continent
        @param[in] le nombre de Pays: entier
        */
        void setNbPays(int nbP);

       /**
        @brief accesseur permettant de consulter le nom du Continent
        @return le nom du continent (entier)
        */
        string getNomC();

        /**
        @brief mutateur permettant de  modifier le nom Continent
        @param[in] nom d'un Continent: entier
        */
        void setNomC(string nomContinent);

        /**
        @brief procedure permettant de tester les fonctions de la classe continent
        */
        void testRegressionContinent();






};






#endif // CONTINENT_H_INCLUDED
