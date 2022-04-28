#ifndef IMAGE_H_INCLUDED
#define IMAGE_H_INCLUDED
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

#include "Application.h"
//#include "TableauDynamique.h"


class Image {

private:

    SDL_Surface * surface;
    SDL_Texture * texture;
    bool has_changed;

public:
    Image () ;
    void loadFromFile (const char* filename, SDL_Renderer * renderer);
    void loadFromCurrentSurface (SDL_Renderer * renderer);
    void draw (SDL_Renderer * renderer, int x, int y, int w=-1, int h=-1);
    SDL_Texture * getTexture() const;
    void setTexture(SDL_Texture * text);
    SDL_Surface * getSurface() const;
    void setSurface(SDL_Surface * surf);
};



/**
    La classe grant le jeu avec un affichage SDL
*/
class sdlApp {

private :

    SDL_Window * window;
    SDL_Renderer * renderer;

    TTF_Font * font;
    Image font_im;
    SDL_Color font_color;

    Mix_Chunk * sound;
    bool withSound;

    Image im_accueil;
    Image im_menu;
    Image im_continent;
    Image im_continent2;
    string etat;
    string sousetat;

    bool souris;
    bool touche;
public :
    /**@brief fonctions membres*/

    /**@brief une Application*/
    Application ap;

    /**
        @brief Constructeur par defaut
        */
    sdlApp ();


     /**
        @brief Constructeur par defaut
        */
    ~sdlApp ();


    /**
        @brief une procedure qui gere la boucle evenementielle
        */
    void sdlBoucle ();

    /** @brief une procedure qui gere l'affichage des differents etats
        */
    void sdlAff ();

    /** @brief une procedure qui gere l'affichage des Pays
        @param[in] iD du contient: entier
        */
    void sdlAffPays(int idCont);

    /** @brief une procedure qui gere l'affichage des Monuments
        @param[in] iD du contient, du pays et du monument: entier
        */

    void sdlAffMonument(int idCont, int idPays,int idM);


    /** @brief une procedure qui gere l'affichage des Monuments
                */

    void sdlAffCont();
    /**
    @brief procedure permettant d'ecrire du texte aux coordonnees: x,y,w,h et de la couleur: r,g,b sur la fenetre sdl
    @param[in] x,y,w,h, r,g,b: entiers ; texte: chaine de caractere
    */
    void sdlEcrire (int x, int y, int w, int h, int r, int g, int b, const char* texte);

     /**
    @brief procedure permettant d'ecrire du texte aux coordonnees: x,y,w,h et de la couleur: r,g,b sur la fenetre sdl et de dessiner un rectangle
    @param[in] x,y,w,h, r,g,b: entiers ; texte: chaine de caractere
    */

    void sdlEcrireAvecRect(int x, int y, int w, int h, int r, int g, int b, const char* texte);


};


#endif // IMAGE_H_INCLUDED
