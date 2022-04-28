#ifndef PAYS_H_INCLUDED
#define PAYS_H_INCLUDED

#include "Monument.h"
using namespace std;


/**
@brief Classe Pays
@author p1503521
@file file\Pays.h
@version 3
@date 29/03/2020
**/
const int MaxPays=6;
class Pays {

    private:
    /**@brief Donnees membres*/

        /**@brief Identifiant du pays*/
        int idP;

        /**@brief Nom du pays*/
        string nomP;

        /**@brief Information breve de presentation du pays */
        string infoP;

        /**@brief Le nombre de monuments par pays*/
        int nbMonuments;

    public:
    /**@brief fonctions membres*/

        /**
        @brief Constructeur par defaut
        */
        Pays();

        Monument *tabMonument[MaxMonuments];

        /**
        @brief Constructeur par copie
        */
        Pays(int idPays,string nomPays,string infoPays);

        /**
        @brief accesseur permettant de consulter l'identifiant du Pays
        @return l'identifiant du pays (entier)
         */
        int getidP();

        /**
        @brief mutateur permettant de  modifier l'identifiant du Pays
        @param[in] l'identifiant du Pays: entier
        */
        void setidP(int idPays);

        /**
        @brief accesseur permettant de consulter le nom du Pays
        @return le nom du Pays (chaine de caracteres)
        */
        string getnomP();

        /**
        @brief mutateur permettant de  modifier le nom Pays
        @param[in] nom d'un Pays: chaine de caracteres
        */
        void setnomP(string nomPays);

        /**
        @brief accesseur permettant de consulter la description d'un Pays
        @return l'info du Pays (chaine de caracteres)
        */
        string getinfoP();

        /**
        @brief mutateur permettant de  modifier la description du Pays
        @param[in] info d'un Pays: chaine de caracteres
        */
        void setinfoP(string infoPays);

        /**
        @brief accesseur permettant de consulter le nombre de monuments par pays
        @return le nombre de monuments (entier)
        */
        int getNbMonument();

        /**
        @brief mutateur permettant de  modifier le nombre de monument par pays
        @param[in] le nombre de monuments: entier
        */
        void setNbMonument(int nbM);

        /**
        @brief Destructeur
        */
        ~Pays();

        /**
        @brief test de la classe carte
        **/
        void testRegressionPays();

};

#endif // PAYS_H_INCLUDED
