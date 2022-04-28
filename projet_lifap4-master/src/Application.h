#ifndef APPLICATION_H_INCLUDED
#define APPLICATION_H_INCLUDED

//#include "Image.h"
#include "Carte.h"
using namespace std;

/**
@brief Classe Application
@author 11503521 11706748 11706619
@file file\Application.h
@version 3
@date 29/03/2020
**/
const int maxPaysTotal = nbContinent * MaxPays;
const int maxMonumentTotal = maxPaysTotal * MaxMonuments;
class Application{

    private:
    /**@brief Donnees membres*/


        /**@brief le nombre de pays total*/
        int nbTotalPays;

        /**@brief le nombre de monuments total*/
        int nbTotalMonuments;

        char* Monument0,* Monument1,* Monument2,* Monument3,* Monument4,* Monument5;
        char* Monument6,* Monument7,* Monument8,* Monument9,* Monument10,* Monument11;
        char* Monument12,* Monument13,* Monument14,* Monument15,* Monument16,* Monument17;
        char* Monument18,* Monument19,* Monument20,* Monument21,* Monument22,* Monument23;
        char* Monument24,* Monument25,* Monument26,* Monument27,* Monument28,* Monument29;
        char* Monument30,* Monument31,* Monument32,* Monument33,* Monument34,* Monument35;


        char* tabUrl[maxMonumentTotal];


        public:
        /**@brief fonctions membres*/

        /**@brief une Carte*/
        Carte carte;

        /**
        @brief Constructeur par defaut
        */
        Application();

        /**
        @brief Destructeur par defaut
        */
        ~Application();

        /**
        @brief accesseur permettant de consulter le nombre total de pays
        @return le nombre total de pays (entier)
        */
        int getnbTotalPays();

        /**
        @brief mutateur permettant de modifier le nombre total de pays
        @param[in] le nombre total de pays: entier
        */
        void setnbTotalPays(int nbTP);

        /**
        @brief accesseur permettant de consulter le nombre total de monuments
        @return le nombre total de pays (entier)
        */
        int getnbTotalMonuments();

        /**
        @brief mutateur permettant de modifier le nombre total de monuments
        @param[in] le nombre total de monuments: entier
        */
        void setnbTotalMonuments(int nbTM);

        /**
        @brief Procedure qui permet de choisir un Continent
        @param[in] idC: entier
        */
        void choixContinent(int idC);

        /**
        @brief Procedure qui permet de choisir un Pays
        */
        void choixPays();

        /**
        @brief Procedure qui permet d'afficher tous les continents
        */
        void afficherContinent();

        /**
        @brief Procedure qui permet d'afficher les pays du continent choisi
        @param[in] idCont: entier
        */
        void afficherPays(int idCont);


        /**
        @brief Procedure qui permet d'afficher une breve description du pays choisi
        @param[in] idPays: entier
        */
        void afficherInfoPays(int idCont,int idPays);

        /**
        @brief Procedure qui permet d'afficher une breve description du monument choisi
        @param[in] idPays, idMon: entiers
        */
        void afficherInfoMonument(int idCont,int idPays,int idMon);


        /**
        @brief Procedure qui permet d'afficher les monuments repertories du pays choisi
        @param[in] idCont, idPays: entiers
        */
        void afficherMonument(int idCont,int idPays);


        /**
        @brief Procedure qui permet de gerer un menu
        */
        void Menu();


        /**
        @brief Procedure qui contient une boucle evenementielle pour visiter nos monuments
        */
        void Boucle();

        /**
        @brief Procedure qui contient une boucle evenementielle pour ajouter un monument
        */
        void Boucle2();

        /**
        @brief Procedure pour la saisie du continent
        @param[in] idC: entier
        */
        void parcoursContinent(int& idC);

        /**
        @brief Procedure pour la saisie du pays
        @param[in] idP, idC: entiers
        */
        void parcoursPays(int idC, int idP);

        /**
        @brief Procedure pour la saisie du monument
        */
        void parcoursMonument(int idC, int idP);

        /**
        @brief Procedure permettant d'ajouter un Pays
        @param[in] idCont: entier
        */
        void ajouterPays(int idCont);

        /**
        @brief Procedure permettant d'ajouter un monument
        @param[in] idPays: entier
        */
        void ajouterMonument(int idC, int idPays);

        /**
        @brief Procedure permettant d'ajouter un monument ou un pays non repertories
        @param[in] idContinent: entier
        */
        void ajouter(int idC);

        /**
        @brief Fonction permettant de transformer un string un chaine de caracteres
        @param[in] str: string
        */
        string stringtoChainetoString(string str);

         /**
        @brief Procedure permettant de Liker
        @param[in] idContinent, idPays, idMonuments: entier
        */
        void Liker(int idC,int idP,int idM);

         /**
        @brief Procedure permettant d'afficher les likes
        @param[in] idContinent, idPays, idMonuments: entier
        */
        void AfficherLike(int idC,int idP,int idM);

         /**
        @brief Procedure permettant de se rediriger vers une page Web
        @param[in] idMonuments: entier
        */
        void lien(int idM);

          /**
        @brief Fonction qui retourne le mois et l'annee
        */
        const char * moisAnnee();

         /**
        @brief Procedure qui selectionne des monuments à visiter selon les saisons
        */
        void Selection();


         /**
        @brief Procedure qui suggere a l'utilisateur des monuments à visiter selon les saisons
        */
        void voirSelection();

         /**
        @brief Procedure qui affiche un monument lambda selon les identifiants
        @param[in] idContinent, idPays, idMonuments: entier
        */
        void afficherMonumentLamba(int idCont, int idPays, int idM);





};
#endif // APPLICATION_H_INCLUDED
