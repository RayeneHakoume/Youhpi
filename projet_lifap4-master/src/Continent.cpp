#include <iostream>
#include <cassert>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>

#include "Continent.h"
using namespace std;


Continent::Continent()
{

}

Continent::Continent(int idC)
{
        ///Initialisation du nombre de pays par continent et du nombre de monument par pays
        int nbP = 0;
        ifstream fContinent;
        string ligne;
        string stringidC = to_string(idC);
        fContinent.open("src/txt/Continent"+stringidC+".txt");
        while(getline(fContinent,ligne))
        {
            nbP++;
        }
        fContinent.close();
        nbPays=nbP-1;

        ///Initialisation et ouverture des fichiers texte
        fContinent.open("src/txt/Continent"+stringidC+".txt");
      //  fMonument.open("txt/Monuments.txt");

        ///Initialisation des autres donnees membres de Continent
        if(!fContinent.is_open())
                {
                    cout<<"Erreur dans l'ouverture( voir constructeur continent)"<<endl;
                }else
                {

                    idContinent = idC;
                    getline(fContinent,nomC);

                    int IdP;
                    string NomP,infoP;
                    for(int i=0; i<nbPays; i++) //j'ai mis 3 car pour l'intant il y a 3 pays par continent
                    {
                        fContinent>>IdP;
                        fContinent>>NomP;
                        getline(fContinent,infoP);

                        tabPays[i] = new Pays(IdP,NomP,infoP);

                    }

                    fContinent.close();
                }


}


Continent::~Continent()
{
    for(int i=0; i<nbPays; i++)
    {
        delete [] tabPays[i];
    }

}

int Continent::getidContinent()
{
    return idContinent;
}

void Continent::setidContinent(int idC)
{
     idContinent = idC;
}

int Continent:: getNbPays()
{
    return nbPays;
}

void Continent :: setNbPays(int nbP)
{
    nbPays = nbP;

}

string Continent::getNomC()
{
    return nomC;
}

void Continent::setNomC(string nomContinent)
{
    nomC = nomContinent;
}

void Continent:: testRegressionContinent()
{

/// test du constructeur par defaut
    Continent continent1;

/// test du constructeur avec parametres
    Continent continent2 (0) ;

/// test de l'accesseur getidContinent()
    continent2.getidContinent();
    cout<<continent2.getidContinent()<<endl;

/// test du mutateur setidcontinent(int idc)
    continent2.setidContinent(2) ;
    cout<<continent2.getidContinent()<<endl;

/// test de l'accesseur getnbPays()
    continent2.getNbPays();
    cout<<continent2.getNbPays()<<endl;

/// test du mutateur setnbPays(int nbP);
    continent2.setNbPays(5);
    cout<<continent2.getNbPays()<<endl;

/// test de l'accesseur de getnomC()
    continent2.getNomC();
    cout<<continent2.getNomC()<<endl;

/// test du mutateur de setnomC()
    string p="Asie";
    continent2.setNomC(p);
    cout<<continent2.getNomC()<<endl;
    cout<<"ok le test Regression de Continent"<<endl;
}


