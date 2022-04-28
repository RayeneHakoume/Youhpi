#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>

#include "Pays.h"
using namespace std;

Pays::Pays()
{

}

Pays::Pays(int idPays, string nomPays, string infoPays)
{
    idP = idPays;
    nomP = nomPays;
    infoP = infoPays;

    ///Recuperation du nombre de monuments dans le pays d'identifiant idP
    int nbM = 0;
    ifstream fMonument;
    string ligneM;
    string stringidP = to_string(idP);
    fMonument.open("src/txt/Monument"+stringidP+".txt");
    while(getline(fMonument,ligneM))
    {
        nbM++;
    }
    fMonument.close();
    nbMonuments=nbM;
    //cout<<"le nb de monument dans le pays "<<idP<<"est: "<<nbMonuments<<endl;
    fMonument.open("src/txt/Monument"+stringidP+".txt");
    int idM;
    string nomM, infoM;
    for(int i=0; i< nbMonuments; i++)
    {
        fMonument>>idM;
        fMonument>>nomM;
        getline(fMonument,infoM);

        tabMonument[i] = new Monument(idM,nomM,infoM);

    }
    fMonument.close();
}

int Pays::getidP()
{
    return idP;
}

void Pays::setidP(int idPays)
{
    idP = idPays;
}

string Pays::getnomP()
{
    return nomP;
}

void Pays::setnomP(string nomPays)
{
    nomP = nomPays;
}

string Pays::getinfoP()
{
    return infoP;
}

void Pays::setinfoP(string infoPays)
{
    infoP = infoPays;
}

int Pays::getNbMonument()
{
    return nbMonuments;
}

void Pays::setNbMonument(int nbM)
{
    nbMonuments = nbM;
}


Pays::~Pays()
{
    for(int i=0; i<getNbMonument(); i++)
    {
        delete [] tabMonument[i];
    }
}

void Pays :: testRegressionPays()
{
    /// test du contructeur sans paramètre
    Pays pays1;
    /// test du contructeur avec paramètre

    string n = "Russie";
    string i = " beau Pays ou il fait froid...";
    Pays pays2 (1,n,i);
    /// test de l'acceseur getidP()
    pays2.getidP();
    cout<<pays2.getidP()<<endl;
    /// test du mutateur setidP
    pays2.setidP(3);
    cout<<pays2.getidP()<<endl;
    ///test de l'acceseur getnomP()
    pays2.getnomP();
    cout<<pays2.getnomP()<<endl;
    ///test du mutateur setnomP(thailande);
    string nom2="thailand";
    pays2.setnomP(nom2);
    cout<<pays2.getnomP()<<endl;
    ///test de l'accesseur getinfo
    pays2.getinfoP();
    cout<<pays2.getinfoP()<<endl;
    ///test du mutateur setinfo(strin infoP)
    string info="un des plus beau pays au monde";
    pays2.setinfoP(info);
    cout<<pays2.getinfoP()<<endl;
    cout<<"ok le test Regression de Pays"<<endl;
}

