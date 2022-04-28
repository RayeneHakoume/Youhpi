#include <iostream>

#include "Monument.h"
using namespace std;

Monument::Monument()
{

}

Monument::Monument(int idMonument, string nomMonument, string infoMonument)
{
    idM = idMonument;
    nomM = nomMonument;
    infoM = infoMonument;

    for (unsigned int i =0; i<tabLike.taille_utilisee; i++)
    {
        tabLike.ajouterElement(tabLike.valeurIemeElement(i));
    }
    nbLike = tabLike.taille_utilisee;

}

int Monument::getidM()
{
    return idM;
}

void Monument::setidM(int idMonument)
{
    idM = idMonument;
}

string Monument::getnomM()
{
    return nomM;
}

void Monument::setnomM(string nomMonument)
{
    nomM = nomMonument;
}

string Monument::getinfoM()
{
    return infoM;
}

void Monument::setinfoM(string infoMonument)
{
    infoM = infoMonument;
}

int Monument::getnbLike()
{
    return nbLike;
}

void Monument::setnbLike(int nbL)
{
    nbLike = nbL;
}

Monument::~Monument()
{

}

void Monument::testRegressionMonument()
{
    /// test du constructeur sans paramètre
    Monument monument1;
    /// test du constructeur avec des paramètre
    string mon="tour effeil";
    string info ="Monument historique de Paris";
    Monument monument2(1,mon, info);
    ///test de l'accesseur getidM()
    monument2.getidM();
    cout<<monument2.getidM()<<endl;
    ///test du mutateur setidM(idM)
    monument2.setidM(2);
    cout<<monument2.getidM()<<endl;
    ///test de l'accesseur getnomM()
    monument2.getnomM();
    cout<<monument2.getnomM()<<endl;
    /*test du mutateur setnomM(nomM)
    string nomM=" arc de triomphe";
    monument2.setnomM(nomM);
    cout<<monument2.getnomM();
    */
    cout<<"ok test regression de monument"<<endl;


}
