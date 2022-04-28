#ifndef PIXEL_H_INCLUDED
#define PIXEL_H_INCLUDED

using namespace std;
/**
@brief Classe Pixel qui est un element d'une Image
@author 11503521 11706748 11706619
@file file\Pixel.h
@version finale
@date 20/02/2020
**/

class Pixel{

    private:
    /**@brief Donnees membres*/

        /**@brief Composante rouge du pixel: entier*/
        unsigned char r;

        /**@brief Composante verte du pixel: entier*/
        unsigned char g;

        /**@brief Composante bleue du pixel: entier*/
        unsigned char b;

    public:
    /**@brief fonctions membres*/

        /**
        @brief Constructeur par defaut
        */
        Pixel();

        /**
        @brief Constructeur avec parametres
        @param[in] composantes d'un pixel: entier
        */
        Pixel(unsigned char nr, unsigned char ng, unsigned char nb);

        /**
        @brief Destructeur par defaut
        */
        ~Pixel();

        /**
        @brief accesseur recuperant la composante rouge du pixel
        @return la composante rouge (entier)
        */
        unsigned char getRouge()const;

        /**
        @brief accesseur recuperant la composante verte du pixel
        @return la composante verte (entier)
        */
        unsigned char getVert()const;

        /**
        @brief accesseur recuperant la composante bleue du pixel
        @return la composante bleue (entier)
        */
        unsigned char getBleu()const;

        /**
        @brief mutateur permettant de modifier la composante rouge du pixel
        @param [in] nr(entier)
        */
        void setRouge(unsigned char nr);

         /**
        @brief mutateur permettant de modifier la composante verte du pixel
        @param [in] nv(entier)
        */
        void setVert(unsigned char nv);

         /**
        @brief mutateur permettant de modifier la composante bleue du pixel
        @param [in] nb(entier)
        */
        void setBleu(unsigned char nb);




};


#endif // PIXEL_H_INCLUDED
