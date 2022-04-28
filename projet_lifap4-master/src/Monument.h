#ifndef MONUMENT_H_INCLUDED
#define MONUMENT_H_INCLUDED
#include <string>
#include <string.h>


#include "TableauDynamique.h"

using namespace std;

/**
@brief Classe Monument
@author 11503521 11706748 11706619
@file file\Monument.h
@version 3
@date 29/03/2020
**/
const int MaxMonuments = 4;
class Monument {

    private:
        /**@brief Donnees membres*/

        /**@brief Identifiant du monument*/
        int idM;

        /**@brief Nom du monument*/
        string nomM;

        /**@brief Information breve de presentation du pays */
        string infoM;

        int nbLike;

    public:
        /**@brief fonctions membres*/

        /**@brief constructeur*/
        Monument();

        /**@brief constructeur par copie*/
        Monument(int idMonument,string nomMonument, string infoM);

        TableauDynamique tabLike;

        /**@brief destructeur*/
        ~Monument();


        /**
        @brief accesseur
        @return l'identifiant du Monument
        */
        int getidM();

        /**
        @brief mutateur
        @param[in] l'identifiant du Monument
        */
        void setidM(int idMonument);

        /**
        @brief accesseur
        @return le nom du Monument
        */
        string getnomM();

        /**
        @brief mutateur
        @param[in] l'identifiant du Monument
        */
        void setnomM(string nomMonument);

        /**
        @brief permettant de consulter la description d'un Monument
        @return l'info du Monument
        */
        string getinfoM();

        /**
        @brief mutateur permettant de  modifier la description du Monument
        @param[in] info d'un Monument
        */
        void setinfoM(string infoMonument);

        int getnbLike();
        void setnbLike(int nbL);

        /**
        @brief test de la classe monument
        */
        void testRegressionMonument();


};





#endif // MONUMENT_H_INCLUDED
