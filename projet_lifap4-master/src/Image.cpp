#include <cassert>
#include <time.h>
#include "Image.h"

#include <iostream>
using namespace std;

const int TAILLE_SPRITE = 32;
unsigned int t=10;
float temps () {
    return float(SDL_GetTicks()) / CLOCKS_PER_SEC;  // conversion des ms en secondes en divisant par 1000
}

// ============= CLASS IMAGE =============== //

Image::Image () {
    surface = NULL;
    texture = NULL;
    has_changed = false;
}

void Image::loadFromFile (const char* filename, SDL_Renderer * renderer) {
    surface = IMG_Load(filename);
    if (surface == NULL) {
        string nfn = string("../") + filename;
        cout << "Error: cannot load "<< filename <<". Trying "<<nfn<<endl;
        surface = IMG_Load(nfn.c_str());
        if (surface == NULL) {
            nfn = string("../") + nfn;
            surface = IMG_Load(nfn.c_str());
        }
    }
    if (surface == NULL) {
        cout<<"Error: cannot load "<< filename <<endl;
        exit(1);
    }

    SDL_Surface * surfaceCorrectPixelFormat = SDL_ConvertSurfaceFormat(surface,SDL_PIXELFORMAT_ARGB8888,0);
    SDL_FreeSurface(surface);
    surface = surfaceCorrectPixelFormat;

    texture = SDL_CreateTextureFromSurface(renderer,surfaceCorrectPixelFormat);
    if (texture == NULL) {
        cout << "Error: problem to create the texture of "<< filename<< endl;
        exit(1);
    }
}

void Image::loadFromCurrentSurface (SDL_Renderer * renderer) {
    texture = SDL_CreateTextureFromSurface(renderer,surface);
    if (texture == NULL) {
        cout << "Error: problem to create the texture from surface " << endl;
        exit(1);
    }
}

void Image::draw (SDL_Renderer * renderer, int x, int y, int w, int h) {
    int ok;
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.w = (w<0)?surface->w:w;
    r.h = (h<0)?surface->h:h;

    if (has_changed) {
        ok = SDL_UpdateTexture(texture,NULL,surface->pixels,surface->pitch);
        assert(ok == 0);
        has_changed = false;
    }

    ok = SDL_RenderCopy(renderer,texture,NULL,&r);
    assert(ok == 0);
}

SDL_Texture * Image::getTexture() const {return texture;}

void Image::setTexture(SDL_Texture * text) {texture = text;}

SDL_Surface * Image::getSurface() const {return surface;}

void Image::setSurface(SDL_Surface * surf) {surface = surf;}







// ============= CLASS SDLAPP =============== //

sdlApp::sdlApp() : ap() {
    // Initialisation de la SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;SDL_Quit();exit(1);
    }

    if (TTF_Init() != 0) {
        cout << "Erreur lors de l'initialisation de la SDL_ttf : " << TTF_GetError() << endl;SDL_Quit();exit(1);
    }

    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if( !(IMG_Init(imgFlags) & imgFlags)) {
        cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;SDL_Quit();exit(1);
    }

	int dimx, dimy;
	dimx = 700;
	dimy = 600;

    // Creation de la fenetre
    window = SDL_CreateWindow("Youhpi", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, dimx, dimy, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window == NULL) {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl; SDL_Quit(); exit(1);
    }

    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

    // IMAGES
    etat = "accueil";
    im_accueil.loadFromFile("data/accueil.png",renderer);
    im_menu.loadFromFile("data/menu.png",renderer);

    // FONTS
    font = TTF_OpenFont("data/Magazine-Bold.ttf",50);
    if (font == NULL) {
            cout << "Failed to load DejaVuSansCondensed.ttf! SDL_TTF Error: " << TTF_GetError() << endl; SDL_Quit(); exit(1);
	}
	font_color.r = 255;font_color.g = 255;font_color.b = 255;
	font_im.setSurface(TTF_RenderText_Solid(font,"Cliquez  pour  acceder  a  l'application  !",font_color));
	font_im.loadFromCurrentSurface(renderer);
}

sdlApp::~sdlApp () {
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void sdlApp::sdlAff () {

	//Remplir l'Ecran de
    SDL_SetRenderDrawColor(renderer, 166, 206, 227, 255);
    SDL_RenderClear(renderer);
    if(etat == "accueil")
    {
        im_accueil.draw(renderer,0,0,700,600);
        SDL_Rect positionTitre;
        positionTitre.x = 200; positionTitre.y = 49; positionTitre.w = 300; positionTitre.h = 40;
        SDL_RenderCopy(renderer,font_im.getTexture(),NULL,&positionTitre);
    }

    if(etat == "menu")
    {

        im_menu.draw(renderer,0,0,700,600);

        ///Nous allons afficher le menu: 1er choix
        font_color ={255,255,255};
        sdlEcrireAvecRect(150,200,50,40,font_color.r,font_color.g,font_color.b,"1");
        sdlEcrire(250,200,150,80,font_color.r,font_color.g,font_color.b,"Visiter!");
        ///2e choix:
        font_color ={255,255,255};
        sdlEcrireAvecRect(150,300,50,40,font_color.r,font_color.g,font_color.b,"2");
        sdlEcrire(220,300,150,80,font_color.r,font_color.g,font_color.b,"Partager!");


    }
///
    if(etat == "afficherCont")
    {
        SDL_RenderClear(renderer);
        sdlAffCont();
    }
    ///
    if(etat == "afficherPays")  sdlAffPays(0);
    if(etat == "afficherPays1") sdlAffPays(1);
    if(etat == "afficherPays2") sdlAffPays(2);
    if(etat == "afficherPays3") sdlAffPays(3);

    if(etat == "afficherPays4") sdlAffPays(4);
    if(etat == "afficherPays5") sdlAffPays(5);

    if(etat =="afficherMonument0") sdlAffMonument(0,0,0);
    if(etat =="afficherMonument1") sdlAffMonument(0,1,2);
    if(etat =="afficherMonument2") sdlAffMonument(0,2,4);

    if(etat =="afficherMonument3") sdlAffMonument(1,3,6);
    if(etat =="afficherMonument4") sdlAffMonument(1,4,8);
    if(etat =="afficherMonument5") sdlAffMonument(1,5,10);

    if(etat =="afficherMonument6") sdlAffMonument(2,6,12);
    if(etat =="afficherMonument7") sdlAffMonument(2,7,14);
    if(etat =="afficherMonument8") sdlAffMonument(2,8,16);

     if(etat =="afficherMonument9") sdlAffMonument(3,9,18);
    if(etat =="afficherMonument10") sdlAffMonument(3,10,20);
    if(etat =="afficherMonument11") sdlAffMonument(3,11,22);

     if(etat =="afficherMonument12") sdlAffMonument(4,12,24);
    if(etat =="afficherMonument13") sdlAffMonument(4,13,26);
    if(etat =="afficherMonument14") sdlAffMonument(4,14,28);

     if(etat =="afficherMonument15") sdlAffMonument(5,15,30);
    if(etat =="afficherMonument16") sdlAffMonument(5,16,32);
    if(etat =="afficherMonument17") sdlAffMonument(5,17,34);
}


void sdlApp::sdlBoucle()
{
    SDL_Event events;
    bool quit = false;

    Uint32 t = SDL_GetTicks(), nt;
    // tant que ce n'est pas la fin ...
    while(!quit)
    {
        // tant qu'il y a des evenements  traiter (cette boucle n'est pas bloquante)
        while(SDL_PollEvent(&events))
        {
            switch(events.type)
            {
                case SDL_QUIT:
                    quit = true;
                    break;
                ///Lorsqu'on clique pour acceder a l'application:
                case SDL_MOUSEBUTTONDOWN:
                        if(200<=events.button.x && events.button.x<550 && 49<events.button.y && events.button.y<89)
                        {
                            etat = "menu";
                            break;
                        }

                default: break;
            }
            ///Lorsqu'on est dans le menu:
            if(etat == "menu")
            {
                switch(events.type)
                {
                    case SDL_MOUSEBUTTONDOWN:
                        ///1er choix: Visiter
                        if(150<=events.button.x && events.button.x<200 && 200<events.button.y && events.button.y<240)
                        {
                             etat = "afficherCont";
                             //break;
                        }else ///2nd choix: Partager
                        if(150<=events.button.x && events.button.x<200 && 300<events.button.y && events.button.y<340)
                        {
                            etat="Partager";
                            break;
                        }

                    default: break;
                }
            }

            if(etat == "afficherCont")
            {
                switch(events.type)
                {
                    case SDL_MOUSEBUTTONDOWN:
                        ///Lorsqu'on appuie sur le continent0:
                        if(20<=events.button.x && events.button.x<50 && 100<events.button.y && events.button.y<140)
                        {
                            etat = "afficherPays";
                            break;
                        }///Lorsqu'on appuie sur le continent1:
                        else if(20<=events.button.x && events.button.x<50 && 150<events.button.y && events.button.y<190)
                        {
                            etat = "afficherPays1";
                            break;
                        }///Lorsqu'on appuie sur le continent2:
                        else if(20<=events.button.x && events.button.x<50 && 200<events.button.y && events.button.y<230)
                        {
                            etat = "afficherPays2";
                            break;
                        }///Lorsqu'on appuie sur le continent3:
                        else if(20<=events.button.x && events.button.x<50 && 240<events.button.y && events.button.y<270)
                        {
                            etat = "afficherPays3";
                            break;
                        }///Lorsqu'on appuie sur le continent4:
                        else if(20<=events.button.x && events.button.x<50 && 280<events.button.y && events.button.y<310)
                        {
                            etat = "afficherPays4";
                            break;
                        }///Lorsqu'on appuie sur le continent5:
                        else if(20<=events.button.x && events.button.x<50 && 320<events.button.y && events.button.y<350)
                        {
                            etat = "afficherPays5";
                            break;
                        }
                    break;

                    default: break;
                }
            }
            ///Lorsq'on appuie sur le pays0:
            if(etat=="afficherPays")
            {
                switch(events.type)
                {
                    case SDL_MOUSEBUTTONDOWN:
                        if(50<=events.button.x && events.button.x<100 && 100<events.button.y && events.button.y<140)
                            {
                                etat= "afficherMonument0";
                                break;
                            }
                        else if(50<=events.button.x && events.button.x<100 && 150<events.button.y && events.button.y<190)
                            {
                                etat="afficherMonument1";
                                break;
                            }
                        else if(50<=events.button.x && events.button.x<100 && 200<events.button.y && events.button.y<230)
                            {
                                etat="afficherMonument2";
                                break;
                            }
                        break;

                    default: break;
                }
            }
            ///Lorsq'on appuie sur le pays1:
            if(etat=="afficherPays1")
            {
                switch(events.type)
                {
                    case SDL_MOUSEBUTTONDOWN:
                        if(50<=events.button.x && events.button.x<100 && 100<events.button.y && events.button.y<140)
                            {
                                etat= "afficherMonument3";
                                break;
                            }
                        else if(50<=events.button.x && events.button.x<100 && 150<events.button.y && events.button.y<190)
                            {
                                etat="afficherMonument4";
                                break;
                            }
                        else if(50<=events.button.x && events.button.x<100 && 200<events.button.y && events.button.y<230)
                            {
                                etat="afficherMonument5";
                                break;
                            }
                        break;

                    default: break;
                }
            }
            ///Lorsq'on appuie sur le pays2:
            if(etat=="afficherPays2")
            {
                switch(events.type)
                {
                    case SDL_MOUSEBUTTONDOWN:
                        if(50<=events.button.x && events.button.x<100 && 100<events.button.y && events.button.y<140)
                            {
                                etat= "afficherMonument6";
                                break;
                            }
                        else if(50<=events.button.x && events.button.x<100 && 150<events.button.y && events.button.y<190)
                            {
                                etat="afficherMonument7";
                                break;
                            }
                        else if(50<=events.button.x && events.button.x<100 && 200<events.button.y && events.button.y<230)
                            {
                                etat="afficherMonument8";
                                break;
                            }
                        break;

                    default: break;
                }
            }
            ///Lorsq'on appuie sur le pays3:
            if(etat=="afficherPays3")
            {
                switch(events.type)
                {
                    case SDL_MOUSEBUTTONDOWN:
                        if(50<=events.button.x && events.button.x<100 && 100<events.button.y && events.button.y<140)
                            {
                                etat= "afficherMonument9";
                                break;
                            }
                        else if(50<=events.button.x && events.button.x<100 && 150<events.button.y && events.button.y<190)
                            {
                                etat="afficherMonument10";
                                break;
                            }
                        else if(50<=events.button.x && events.button.x<100 && 200<events.button.y && events.button.y<230)
                            {
                                etat="afficherMonument11";
                                break;
                            }
                        break;

                    default: break;
                }
            }
            ///Lorsq'on appuie sur le pays4:
            if(etat=="afficherPays4")
            {
                switch(events.type)
                {
                    case SDL_MOUSEBUTTONDOWN:
                        if(50<=events.button.x && events.button.x<100 && 100<events.button.y && events.button.y<140)
                            {
                                etat= "afficherMonument12";
                                break;
                            }
                        else if(50<=events.button.x && events.button.x<100 && 150<events.button.y && events.button.y<190)
                            {
                                etat="afficherMonument13";
                                break;
                            }
                        else if(50<=events.button.x && events.button.x<100 && 200<events.button.y && events.button.y<230)
                            {
                                etat="afficherMonument14";
                                break;
                            }
                        break;

                    default: break;
                }
            }
            ///Lorsq'on appuie sur le pays5:
            if(etat=="afficherPays5")
            {
                switch(events.type)
                {
                    case SDL_MOUSEBUTTONDOWN:
                        if(50<=events.button.x && events.button.x<100 && 100<events.button.y && events.button.y<140)
                            {
                                etat= "afficherMonument15";
                                break;
                            }
                        else if(50<=events.button.x && events.button.x<100 && 150<events.button.y && events.button.y<190)
                            {
                                etat="afficherMonument16";
                                break;
                            }
                        else if(50<=events.button.x && events.button.x<100 && 200<events.button.y && events.button.y<230)
                            {
                                etat="afficherMonument17";
                                break;
                            }
                        break;

                    default: break;
                }
            }


        } ///fin du deuxieme while ouvert


        sdlAff();
        SDL_RenderPresent(renderer);
        SDL_ShowCursor(SDL_ENABLE);

    } ///fin du premier while ouvert
}




void sdlApp::sdlEcrireAvecRect(int x, int y, int w, int h,int r, int g, int b,const char* texte)
{
    SDL_Rect positionRect = {x,y,w,h};
    SDL_Color font_color ={r,g,b};
    SDL_SetRenderDrawColor(renderer,255,255,255,0);
    SDL_RenderDrawRect(renderer, &positionRect);
    font_im.setSurface(TTF_RenderText_Blended_Wrapped(font, texte, font_color, 100));
    font_im.setTexture(SDL_CreateTextureFromSurface(renderer,font_im.getSurface()));
    SDL_QueryTexture(font_im.getTexture(),NULL,NULL,&positionRect.w,&positionRect.h);
    SDL_RenderCopy(renderer,font_im.getTexture(),NULL,&positionRect);
}

void sdlApp::sdlEcrire(int x, int y, int w, int h,int r, int g, int b,const char* texte)
{
    SDL_Color font_color = {r,g,b};
    font_im.setSurface(TTF_RenderText_Blended_Wrapped(font, texte, font_color, 100));
    font_im.setTexture(SDL_CreateTextureFromSurface(renderer,font_im.getSurface()));
    SDL_Rect positionTexte = {x,y,w,h};
    SDL_QueryTexture(font_im.getTexture(),NULL,NULL,&positionTexte.w,&positionTexte.h);
    SDL_RenderCopy(renderer, font_im.getTexture(), NULL, &positionTexte);
}

void sdlApp::sdlAffCont()
{
    //image mise en fond: faire un sdl-draw_color pour une couleur de fond pour l'affichage de pays
    im_menu.draw(renderer,0,0,700,600);
    ///Declaration des variables:
    string nomC, nomCont, choix;
    const char * finalname, *finalchoix;
    int x = 200; int y = 100; int w = 250; int h = 40;
    int x1 = 20; int y1 = 100; int w1 = 50; int h1 = 40;
    for (int i=0; i<6; i++ )
    {
        nomC = ap.carte.tabCont[i]->getNomC();
        finalname = nomC.c_str();
        choix = to_string(i);
        finalchoix = choix.c_str();
        sdlEcrire(x,y,w,h,font_color.r,font_color.g,font_color.b,finalname);
        sdlEcrireAvecRect(x1,y1,w1,h1,font_color.r,font_color.g,font_color.b,finalchoix);
        y = y + 50;
        y1 = y1 + 50;
    }

}

void sdlApp:: sdlAffPays(int idCont)
{
    //im_menu.draw(renderer,0,0,700,600);
   //SDL_RenderClear(renderer);
    ///Declaration des variables:
    string stringidC = to_string(idCont);
    string name = "data/continent"+stringidC+".png";
    const char * filename = name.c_str();
    im_continent.loadFromFile(filename,renderer);
    im_continent.draw(renderer,150,350,300,300);
    string idP, choix, nomP;
    const char * finalname, *finalchoix;
    int x = 200; int y = 100; int w = 250; int h =40;
    int x1 = 50; int y1 = 100; int w1 = 50; int h1 = 40;

    for(int j=0; j<ap.carte.tabCont[idCont]->getNbPays(); j++)
    {
       nomP = ap.carte.tabCont[idCont]->tabPays[j]->getnomP();
       finalname = nomP.c_str();
       choix = to_string(j);
       finalchoix = choix.c_str();
       sdlEcrire(x,y,w,h,font_color.r,font_color.g,font_color.b,finalname);
       sdlEcrireAvecRect(x1,y1,w1,h1,font_color.r,font_color.g,font_color.b,finalchoix);
       y=y+50;
       y1=y1+50;
    }
}

void sdlApp:: sdlAffMonument(int idCont,int idPays,int idM)
{
    //SDL_RenderClear(renderer);
    //im_menu.draw(renderer,0,0,700,600);
    string stringidPays = to_string(idPays);
    string stringidM = to_string(idM);
    string stringidPidM = stringidPays+stringidM ;
    string name = "data/Monument"+stringidPidM +".png";

    int idM2 =idM+1;
    string stringidPays2 = to_string(idPays);
    string stringidM2 = to_string(idM2);
    string stringidPidM2 = stringidPays2+stringidM2 ;
    string name2 = "data/Monument"+stringidPidM2+".png";

    const char * filename2=name2.c_str();
    im_continent2.loadFromFile(filename2,renderer);
    im_continent2.draw(renderer,350,300,350,300);

    const char * filename=name.c_str();
    im_continent.loadFromFile(filename,renderer);
    im_continent.draw(renderer,0,300,350,300);

    string choix, nomM;
    const char * finalname, *finalchoix;
    int x = 100; int y = 100; int w = 200; int h =40;
    int x1 = 50; int y1 = 100; int w1 = 50; int h1 = 40;

    for(int j=0; j<ap.carte.tabCont[idCont]->tabPays[idPays]->getNbMonument(); j++)
    {
       nomM = ap.carte.tabCont[idCont]->tabPays[idPays]->tabMonument[j]->getnomM();
       finalname = nomM.c_str();
       choix = to_string(j);
       finalchoix = choix.c_str();
       sdlEcrire(x,y,w,h,font_color.r,font_color.g,font_color.b,finalname);
       sdlEcrireAvecRect(x1,y1,w1,h1,font_color.r,font_color.g,font_color.b,finalchoix);
       y=y+50;
       y1=y1+50;
    }


}


/*void sdlApp::sdlcin (int x, int y, int w, int h){
    SDL_StartTextInput();
    SDL_Event event;
    char* text;
    SDL_Rect Texte = {x,y,w,h};
    SDL_SetTextInputRect(&Texte);
    strcat(text, event.text.text);
    SDL_StopTextInput();
}*/
