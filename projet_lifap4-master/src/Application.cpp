#include <iostream>
#include <cassert>
#include <fstream>
#include <string.h>
#include <windows.h>
#include <time.h>

#include "Application.h"

using namespace std;

Application::Application() /// Constructeur par defaut
{
    /// Initialisation du nombre de pays au total et le nombre de monuments au total
    nbTotalPays = 0;
    nbTotalMonuments = 0;
    for(int i=0; i<nbContinent; i++)
        {
            for(int j=0; j<carte.tabCont[i]->getNbPays(); j++)
            {
                nbTotalPays++;
                for(int k=0; k<carte.tabCont[i]->tabPays[j]->getNbMonument(); k++)
                {
                    nbTotalMonuments++;
                }
            }
        }
    ///declaration de liens:
    Monument0="https://www.tripadvisor.fr/Attraction_Review-g190502-d10539988-Reviews-Sailor_s_Monument-Bergen_Hordaland_Western_Norway.html/";
    Monument1="https://www.sculpturenature.com/tjuvholmen-sculpture-park-oslo/";
    Monument2="https://www.connaissancedesarts.com/archi-jardin-et-patrimoine/la-mosquee-cathedrale-de-cordoue-une-foret-de-colonnes-11124216/";
    Monument3="https://barcelona-tourist-guide.com/fr/gaudi/sagrada-familia.html";
    Monument4="https://www.toureiffel.paris/fr/le-monument";
    Monument5="http://www.paris-arc-de-triomphe.fr/";
    Monument6="https://tripadvisor.fr/Attraction_Review-g1953908-d7047728-Reviews-Puputan_Klungkung_Monument-Klungkung_Bali.html";
    Monument7="https://www.indonesia.travel/gb/en/destinations/java/dki-jakarta/national-monument";
    Monument8="https://www.japanhoppers.com/fr/kanto/tokyo/kanko/364/";
    Monument9="https://www.vivrelejapon.com/ville-kyoto/kinkakuji";
    Monument10="https://www.petitfute.com/v41442-bangkok/c1173-visites-points-d-interet/c925-edifice-religieux/c932-temple/85454-wat-pho-temple-du-bouddha-couche.html?gclid=Cj0KCQjw17n1BRDEARIsAFDHFexqeCuC5E7TAxIfiHkFoTyBYLM_fyPh1gfLlrkkRFXfi3kkmlquqagaAldVEALw_wcB#xtor=SEC-386?pfpart=ADWbestoff#xtor=SEC-375";
    Monument11="https://www.thailandee.com/a-voir/wat-si-chum-sukhothai-41";
    Monument12="https://www.getyourguide.fr/le-cap-l103/cape-agulhas-tour-de-cape-town-t66895/";
    Monument13="https://capetownstadium.co.za/";
    Monument14="https://whc.unesco.org/fr/list/38/";
    Monument15="https://www.djerbahood.com/";
    Monument16="http://www.voyage-au-benin.com/letoile-rouge-de-cotonou/";
    Monument17="https://www.voyage-benin.com/guide-benin/attraction/ouidah";
    Monument18="http://septmerveillesdumonde.com/tourcn/";
    Monument19="https://www.jeparsaucanada.com/les-chutes-du-niagara/";
    Monument20="https://whc.unesco.org/fr/list/414/";
    Monument21="http://cdmxtravel.com/fr/lieux/monumento-a-la-revolucion.html";
    Monument22="https://www.merveilles-du-monde.com/Statue-de-la-Liberte/";
    Monument23="https://airfrance.fr/FR/fr/common/travel-guide/la-maison-blanche-l-adresse-la-plus-celebre-des-etats-unis.htm";
    Monument24="https://www.merveilles-du-monde.com/Christ-redempteur/";
    Monument25="https://www.planete3w.fr/decouvrir-les-chutes-iguazu-en-2-jours/";
    Monument26="https://www.voyageperou.info/sarcophages-de-karajia-et-quiocta/";
    Monument27="https://lesglobeblogueurs.com/chavin-de-huantar-perou/";
    Monument28="https://www.visiter-cuba.fr/la-habana-vieja/";
    Monument29="https://www.do-tours.com/guide/27873-el-capitolio.html";
    Monument30="http://mondedesphares.fr/?Phare-de-Castle-Point.html";
    Monument31="https://skycityauckland.co.nz/sky-tower/";
    Monument32="https://www.sydneyoperahouse.com/";
    Monument33="https://fr.visitmelbourne.com/regions/great-ocean-road/12-apostles";
    Monument34="https://viator.com/fr-FR/Nadi-attractions/Sri-Siva-Subramaniya-Temple/d4795-a24573";
    Monument35="https://www.airnewzealand.co.nz/destination-perth-coral-coast";

}


int Application::getnbTotalPays()
{
    return nbTotalPays;
}

void Application::setnbTotalPays(int nbTP)
{
    nbTotalPays = nbTP;
}


int Application::getnbTotalMonuments()
{
    return nbTotalMonuments;
}


void Application::setnbTotalMonuments(int nbTM)
{
    nbTotalMonuments = nbTM;
}

Application::~Application() /// Destructeur
{

}


void Application::afficherContinent()
{
    for (int i=0; i<nbContinent;i++)
    {
        cout<<endl<<" "<<carte.tabCont[i]->getidContinent()<<": ";
        cout<<carte.tabCont[i]->getNomC()<<endl;
    }
}


void Application::afficherPays(int idCont)
{
    for(int j=0; j<carte.tabCont[idCont]->getNbPays(); j++)
    {
       cout<<endl<<carte.tabCont[idCont]->tabPays[j]->getidP()<<": ";
       cout<<carte.tabCont[idCont]->tabPays[j]->getnomP()<<endl;
    }

}


void Application::afficherInfoPays(int idCont,int idPays)
{
    for(int i=0; i< carte.tabCont[idCont]->getNbPays(); i++)
    {
        if(carte.tabCont[idCont]->tabPays[i]->getidP() == idPays)
        {
            cout<<endl<<carte.tabCont[idCont]->tabPays[i]->getinfoP()<<endl;
        }
    }
}


void Application::afficherInfoMonument(int idCont,int idPays,int idMon)
{
    char rep;
    for(int i=0; i<carte.tabCont[idCont]->getNbPays(); i++)
    {
        if(carte.tabCont[idCont]->tabPays[i]->getidP() == idPays)
        {
            for(int j=0; j<carte.tabCont[idCont]->tabPays[i]->getNbMonument(); j++)
            {
                if(carte.tabCont[idCont]->tabPays[i]->tabMonument[j]->getidM() == idMon)
                {
                    cout<<"Nous vous proposons un lien vers une page Web pour en savoir davantage sur ce monument"<<endl;
                    cout<<"Voulez vous vister cette page? (y/n)"<<endl;
                    cin>>rep;
                    if(rep=='y')
                    {
                        lien(idMon);
                        cout<<endl<<carte.tabCont[idCont]->tabPays[i]->tabMonument[j]->getinfoM()<<endl;
                        cout<<endl<<"Nb de Like: ";
                        AfficherLike(idCont,i,j);
                        cout<<" Liker ce monument <3 (y/n)"<<endl;
                        cin>>rep;
                        if(rep =='y')
                        {
                            Liker(idCont,i,j);
                        }
                        if(rep =='n')
                        {
                            afficherPays(idCont);
                            parcoursPays(idCont,i);
                        }
                    }
                    if(rep=='n')
                    {
                        cout<<endl<<carte.tabCont[idCont]->tabPays[i]->tabMonument[j]->getinfoM()<<endl;
                        cout<<endl<<"Nb de Like: ";
                        AfficherLike(idCont,i,j);
                        cout<<" Liker ce monument <3 (y/n)"<<endl;
                        cin>>rep;
                        if(rep =='y')
                        {
                            Liker(idCont,i,j);
                        }
                        if(rep =='n')
                        {
                            afficherPays(idCont);
                            parcoursPays(idCont,i);
                        }
                    }
                }

            }
        }
    }
}

void Application::afficherMonument(int idCont, int idPays)
{
    for(int i=0; i<carte.tabCont[idCont]->getNbPays(); i++)
    {
        if(carte.tabCont[idCont]->tabPays[i]->getidP() == idPays)
        {
            for(int j=0; j<carte.tabCont[idCont]->tabPays[i]->getNbMonument(); j++)
            {
                cout<<endl<<carte.tabCont[idCont]->tabPays[i]->tabMonument[j]->getidM()<<": ";
                cout<<carte.tabCont[idCont]->tabPays[i]->tabMonument[j]->getnomM()<<endl;
            }
        }

    }

}

void Application::afficherMonumentLamba(int idCont, int idPays, int idM)
{
    for(int j=0; j<carte.tabCont[idCont]->tabPays[idPays]->getNbMonument(); j++)
        {
            if(carte.tabCont[idCont]->tabPays[idPays]->tabMonument[j]->getidM() == idM)
            {
                cout<<carte.tabCont[idCont]->tabPays[idPays]->tabMonument[j]->getnomM()<<endl;
                cout<<endl<<carte.tabCont[idCont]->tabPays[idPays]->tabMonument[j]->getinfoM()<<endl;
            }
        }
}


void Application::Menu()
{
    char choix;
    cout<<"____________________________________________________________________________________________________"<<endl;
    cout<<"                                             Menu"<<endl;
    cout<<"____________________________________________________________________________________________________"<<endl;
    cout<<"1. Pour voir nos superbes selections sur les differents monuments du monde a visiter !"<<endl;
    cout<<"2. Pour partager avec nous vos superbes decouvertes au sein d'un pays riche en culture!"<<endl;
    cout<<endl<<"Choix :";
    cin>>choix;

      switch(choix)
    {
    case '1':
        voirSelection();
        //Boucle();
        break;
    case '2':
        Boucle2();
        break;
    case '3':
        lien(0);
        break;
    default:
        cout<< "Veuillez saisir 1 ou 2 " << endl;
        Menu();
        break;
        }

}


void Application::Boucle()
{
    int kContinent, kPays;
    char reponse;
    cout<<"                    Welcome!                  "<<endl;
    parcoursContinent(kContinent);

    cout<< "   Pour consulter les Pays, taper p.       " <<endl;
    cout<< "   Pour revenir au Menu Principal, taper m.       " <<endl;
    cin>>reponse;

      switch(reponse)
    {
    case 'p':
       parcoursPays(kContinent,kPays);
        break;
    case 'm':
        Menu();
         break;
    default :
        cout << "Veuillez saisir 'p' ou 'm' " << endl;
        Boucle();
        break;

    }


}


void Application::Boucle2()
{
    int kContinent;
    char reponse;
    cout<<"   Veuillez entrer l'identifiant du continent dans lequel se trouve le monument que vous souhaitez ajouter:    "<<endl;
    parcoursContinent(kContinent);

    cout<< "   Pour ajouter un monument, taper p.       " <<endl;
    cout<< "   Pour retour au Menu Principal, taper m.       " <<endl;
    cin>>reponse;

      switch(reponse)
    {
    case 'p':
        ajouter(kContinent);
        break;
    case 'm':
        Menu();
         break;
    default :
        cout << "Veuillez saisir 'p' ou 'm' " << endl;
        Boucle2();
        break;

    }


}


void Application::parcoursContinent(int& idC)
{
    afficherContinent();
    cout<<"            Veuillez choisir un continent ^_^           "<<endl;
    cin>>idC;
    assert(idC>=0);
    assert(idC<6);

    cout<<" Voici les pays du continent "<<carte.tabCont[idC]->getNomC()<<" que nous avons repertories pour vous !"<<endl;
    afficherPays(idC);

}


void Application::parcoursPays(int idC,int idP)
{
    cout<<" Choisissez un pays pour voir les monuments que nous avons selectiones comme etant incontournable !"<<endl;
    cin>>idP;

    assert(idP>=0);
    assert(idP<getnbTotalPays());

    afficherInfoPays(idC,idP);
    afficherMonument(idC,idP);

    char reponse;
    cout<< "   Pour consulter un monument, taper p.       " <<endl;
    cout<<"    Pour retourner au menu precedent, taper m."<<endl;
    cout<<"    Pour retourner au menu principal, taper M."<<endl;
    cin>>reponse;
    switch(reponse)
    {
    case 'm':
        parcoursContinent(idC);
        break;
    case 'p':
        parcoursMonument(idC,idP);
        break;
    case 'M':
        Menu();
        break;
    default :
        cout<<"Desole, nous ne comprenons pas votre choix..."<<endl<<"Veuillez saisir soit 'p' ou 'm' ou 'M'" << endl;parcoursPays(idC,idP);
        break;
    }
}


void Application::parcoursMonument(int idC, int idP)
{
    int idM;
    cout<<" Veuillez saisir l'identifiant du monument dont vous vous voulez en connaître d'avantage: "<<endl;
    cin>>idM;

    assert(idM>=0);
    assert(idM<getnbTotalMonuments());

    afficherInfoMonument(idC,idP,idM);

    char reponse;
    cout<<"    Pour retourner au menu precedent, taper m."<<endl;
    cin>>reponse;

    if (reponse=='m') parcoursMonument(idC,idP);
    else {
        cout << "Veuillez saisir 'm'" << endl;
        parcoursMonument(idC,idP);
    }


}

void Application::ajouter(int idC)
{
    ///Declaration de variables:
    char reponse;
    int idPays;
    int indice = carte.tabCont[idC]->getNbPays()-1;

    cout<<"Est-ce que le monument que vous souhaitez ajouter se trouve dans l'un des pays precedents? (y/n/m) taper m pour un retour au menu precedent "<<endl;
    cin>>reponse;
    if(reponse == 'y')
    {
        cout<<"Veuillez saisir l'identifiant correspondant: "<<endl;
        cin>>idPays;
        //assert(idPays>=carte.tabCont[idC]->tabPays[0]->getidP());
        //assert(idPays<carte.tabCont[idC]->tabPays[indice]->getidP());
        ajouterMonument(idC,idPays);
        }
    if(reponse == 'n')
    {
        ajouterPays(idC);
    }

    if(reponse == 'm')
    {
        parcoursContinent(idC);
    }



}

void Application::ajouterPays(int idC)
{
    ///Declaration des variables
    string nomP;
    string infoP;
    string str;
    int newIdP, nb;
    string stringidC = to_string(idC);

    //Ouverture du fichier en écriture
    ofstream fContinent;
    fContinent.open("src/txt/Continent"+stringidC+".txt",ios::app);
    if(fContinent)
    {

        ///Ecriture de l'id du pays dans le fichier:
        newIdP = getnbTotalPays();                  //le nouvel idM correspond au nbtotal de Monuments
        setnbTotalPays(getnbTotalPays()+1);
        fContinent << '\n' << newIdP <<" ";

        cin.ignore();

        ///Saisie et Ecriture du nom du pays dans le fichier:
        cout<<endl<<"D'accord, veuillez saisir le nom du pays dans le lequel se situe le monument que vous souhaitez ajouter:"<<endl;
        getline(cin, nomP);
        str = stringtoChainetoString(nomP);
        fContinent << str <<" " ;

        ///Saisie et Ecriture de l'info du pays dans le fichier:
        cout<<endl<<"Super! En une ou deux phrases veuillez donner une description du pays..."<<endl;
        getline(cin, infoP);
        fContinent << infoP << endl;


        nb = carte.tabCont[idC]->getNbPays(); //on recupere le nombre de pays que l'on a sur ce continent
        carte.tabCont[idC]->setNbPays(nb+1);
        carte.tabCont[idC]->tabPays[nb]->setidP(newIdP);
        carte.tabCont[idC]->tabPays[nb]->setnomP(str);
        carte.tabCont[idC]->tabPays[nb]->setinfoP(infoP);


        fContinent.close();
        ajouterMonument(idC,newIdP);
    }else
    {
        cout<<"Erreur dans l'ouverture du fichier(Voir fontion ajouterMonument dans Application)"<<endl;
    }

}


void Application::ajouterMonument(int idC,int idP)
{
    ///Declaration des variables
    string nomM;
    string infoM;
    string str;
    int newIdM, nb;
    string stringidP = to_string(idP);

    //Ouverture du fichier en écriture
    ofstream fMonument;
    fMonument.open("src/txt/Monument"+stringidP+".txt",ios::app);
    if(fMonument)
    {

        ///Ecriture de l'id du monument dans le fichier:
        newIdM = getnbTotalMonuments();                  //le nouvel idM correspond au nbtotal de Monuments
        setnbTotalMonuments(getnbTotalMonuments()+1);
        fMonument << '\n' << newIdM <<" ";

        cin.ignore();

        ///Saisie et Ecriture du nom du monument dans le fichier:
        cout<<endl<<"D'accord, veuillez saisir le nom du monument dans le lequel se situe le monument que vous souhaitez ajouter:"<<endl;
        getline(cin, nomM);
        str = stringtoChainetoString(nomM);
        fMonument << str <<" " ;

        ///Saisie et Ecriture de l'info du monument dans le fichier:
        cout<<endl<<"Super! En une ou deux phrases veuillez donner une description du monument..."<<endl;
        getline(cin, infoM);
        fMonument << infoM << endl;

        fMonument.close();

        nb = carte.tabCont[idC]->tabPays[idP]->getNbMonument(); //on recupere le nombre de monuments que l'on a sur ce pays
        carte.tabCont[idC]->tabPays[idP]->setNbMonument(nb+1);
        carte.tabCont[idC]->tabPays[idP]->tabMonument[nb]->setidM(newIdM);
        carte.tabCont[idC]->tabPays[idP]->tabMonument[nb]->setnomM(str);
        carte.tabCont[idC]->tabPays[idP]->tabMonument[nb]->setinfoM(infoM);
    }else
    {
        cout<<"Erreur dans l'ouverture du fichier(Voir fontion ajouterMonument dans Application)"<<endl;
    }

}

string Application::stringtoChainetoString(string str)
{
    ///Declaration des variables:
    int i=0;
    char c;
    size_t size = str.size() + 1;
    char * buffer = new char[ size ];
    char newc[size];
    // copier la chaîne
    strncpy( buffer, str.c_str(), size );
    ///On va donc remplacer les espaces par des traits du huit
    while (buffer[i])
    {
        c=buffer[i];
        if (isspace(c)) c='_';
        newc[i]=c;
        i++;
    }
    delete [] buffer;
    return newc;
}

void Application::Liker(int idC,int idP, int idM)
{
    carte.tabCont[idC]->tabPays[idP]->tabMonument[idM]->tabLike.ajouterElement(1);
    carte.tabCont[idC]->tabPays[idP]->tabMonument[idM]->setnbLike(carte.tabCont[idC]->tabPays[idP]->tabMonument[idM]->tabLike.taille_utilisee);
}

void Application::AfficherLike(int idC, int idP, int idM)
{
    cout<<carte.tabCont[idC]->tabPays[idP]->tabMonument[idM]->getnbLike();
}

void Application:: Selection()
{
     const char* mois;
     char rep;
     mois = moisAnnee();


     if(mois == "Janvier" || mois == "Février" || mois == "Mars")
     {
         cout<<"C'est la periode ideal pour visiter: "<< endl;
         afficherMonumentLamba(4,0,24);
     }

     if(mois == "Avril" || mois == "Mai" || mois == "Juin")
     {
         cout<<"C'est la periode ideal pour visiter: "<< endl;
         afficherMonumentLamba(5,2,35);
     }

     if(mois == "Juillet" || mois == "Aout" || mois == "Septembre")
     {
         cout<<"C'est la periode ideal pour visiter: "<< endl;
         afficherMonumentLamba(3,2,22);
     }

     if(mois == "Octobre" || mois == "Novembre" || mois == "Décembre")
     {
         cout<<"C'est la periode ideal pour visiter: "<< endl;
         afficherMonumentLamba(1,0,6);
     }


     cout<<"m: menu principal     v: Visiter la totalite les monuments que nous avons repertorie"<<endl;
     cin>>rep;
     if(rep == 'm') Menu();
     if(rep == 'v') Boucle();

}

const char * Application::moisAnnee()
{
     const char * months[] = {
        "Janvier", "Février", "Mars", "Avril", "Mai", "Juin", "Juillet",
        "Août", "Septembre", "Octobre", "Novembre", "Décembre"
        };

    time_t timestamp = time( NULL );
    struct tm * now = localtime( & timestamp );

    printf( "%4d-%02d-%02d %02d:%02d\n",
    now->tm_year+1900, now->tm_mon+1, now->tm_mday,
    now->tm_hour, now->tm_min, now->tm_sec );

    return months[now->tm_mon];
}

void  Application::voirSelection()
{
    char rep, rep2;
    cout<<" Souhaitez-vous voir notre selection de monuments a visiter pour la saison en cours? (y/n)"<<endl;
    cin>>rep;

    if(rep =='y')Selection();

    if(rep =='n')
    {
        cout<<"m: menu principal     v: Visiter la totalite les monuments que nous avons repertorie"<<endl;
        cin>>rep2;
        if(rep2 == 'm') Menu();
        if(rep2 == 'v') Boucle();
    }
}

void Application::lien(int idM)
{
   /* ///On convertit le int en char* pour pouvoir concatener:
    char* indice = (char*)idM;
    char* M = "Monument";
    char* name = strcat(M,indice);
    cout<<"je suis un test"<<name;
    ///On redirige vers le lien web:
   // ShellExecute(NULL, NULL, name, NULL, NULL, SW_SHOWNORMAL);*/

    if(idM==0) ShellExecute(NULL, NULL, Monument0, NULL, NULL, SW_SHOWNORMAL);
    if(idM==1) ShellExecute(NULL, NULL, Monument1, NULL, NULL, SW_SHOWNORMAL);
    if(idM==2) ShellExecute(NULL, NULL, Monument2, NULL, NULL, SW_SHOWNORMAL);
    if(idM==3) ShellExecute(NULL, NULL, Monument3, NULL, NULL, SW_SHOWNORMAL);
    if(idM==4) ShellExecute(NULL, NULL, Monument4, NULL, NULL, SW_SHOWNORMAL);
    if(idM==5) ShellExecute(NULL, NULL, Monument5, NULL, NULL, SW_SHOWNORMAL);
    if(idM==6) ShellExecute(NULL, NULL, Monument6, NULL, NULL, SW_SHOWNORMAL);
    if(idM==7) ShellExecute(NULL, NULL, Monument7, NULL, NULL, SW_SHOWNORMAL);
    if(idM==8) ShellExecute(NULL, NULL, Monument8, NULL, NULL, SW_SHOWNORMAL);
    if(idM==9) ShellExecute(NULL, NULL, Monument9, NULL, NULL, SW_SHOWNORMAL);
    if(idM==10) ShellExecute(NULL, NULL, Monument10, NULL, NULL, SW_SHOWNORMAL);
    if(idM==11) ShellExecute(NULL, NULL, Monument11, NULL, NULL, SW_SHOWNORMAL);
    if(idM==12) ShellExecute(NULL, NULL, Monument12, NULL, NULL, SW_SHOWNORMAL);
    if(idM==13) ShellExecute(NULL, NULL, Monument13, NULL, NULL, SW_SHOWNORMAL);
    if(idM==14) ShellExecute(NULL, NULL, Monument14, NULL, NULL, SW_SHOWNORMAL);
    if(idM==15) ShellExecute(NULL, NULL, Monument15, NULL, NULL, SW_SHOWNORMAL);
    if(idM==16) ShellExecute(NULL, NULL, Monument16, NULL, NULL, SW_SHOWNORMAL);
    if(idM==17) ShellExecute(NULL, NULL, Monument17, NULL, NULL, SW_SHOWNORMAL);
    if(idM==18) ShellExecute(NULL, NULL, Monument18, NULL, NULL, SW_SHOWNORMAL);
    if(idM==19) ShellExecute(NULL, NULL, Monument19, NULL, NULL, SW_SHOWNORMAL);
    if(idM==20) ShellExecute(NULL, NULL, Monument20, NULL, NULL, SW_SHOWNORMAL);
    if(idM==21) ShellExecute(NULL, NULL, Monument21, NULL, NULL, SW_SHOWNORMAL);
    if(idM==22) ShellExecute(NULL, NULL, Monument22, NULL, NULL, SW_SHOWNORMAL);
    if(idM==23) ShellExecute(NULL, NULL, Monument23, NULL, NULL, SW_SHOWNORMAL);
    if(idM==24) ShellExecute(NULL, NULL, Monument24, NULL, NULL, SW_SHOWNORMAL);
    if(idM==25) ShellExecute(NULL, NULL, Monument25, NULL, NULL, SW_SHOWNORMAL);
    if(idM==26) ShellExecute(NULL, NULL, Monument26, NULL, NULL, SW_SHOWNORMAL);
    if(idM==27) ShellExecute(NULL, NULL, Monument27, NULL, NULL, SW_SHOWNORMAL);
    if(idM==28) ShellExecute(NULL, NULL, Monument28, NULL, NULL, SW_SHOWNORMAL);
    if(idM==29) ShellExecute(NULL, NULL, Monument29, NULL, NULL, SW_SHOWNORMAL);
    if(idM==30) ShellExecute(NULL, NULL, Monument30, NULL, NULL, SW_SHOWNORMAL);
    if(idM==31) ShellExecute(NULL, NULL, Monument31, NULL, NULL, SW_SHOWNORMAL);
    if(idM==32) ShellExecute(NULL, NULL, Monument32, NULL, NULL, SW_SHOWNORMAL);
    if(idM==33) ShellExecute(NULL, NULL, Monument33, NULL, NULL, SW_SHOWNORMAL);
    if(idM==34) ShellExecute(NULL, NULL, Monument34, NULL, NULL, SW_SHOWNORMAL);
    if(idM==35) ShellExecute(NULL, NULL, Monument35, NULL, NULL, SW_SHOWNORMAL);
}
