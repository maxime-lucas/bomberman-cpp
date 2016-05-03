#ifndef CLASSES_H_INCLUDED
#define CLASSES_H_INCLUDED

#include "Header.h"

class Shape
{
protected:
    SDL_Rect dimCoordSprite; //coordonn�es dans l'image
    SDL_Rect dimCoordShape; //coordonn�es dans l'�cran
    SDL_Surface *sprite; //feuille de sprites stock�e ici
    int nbSprites; //nombre de sprites (pour perso)

public:
    Shape();
    Shape(SDL_Surface* , SDL_Rect , int);
    virtual ~Shape();
    virtual void show(SDL_Surface*) = 0;
};

class Figure : public Shape
{
public:
    Figure();
    virtual ~Figure();
    Figure(SDL_Surface* , SDL_Rect , int);
    void show(SDL_Surface*);
protected:
    int xVel , yVel; //taille du d�placement perso
    int speed; //
    int direction; //Noth = 0 , South = 1 , East = 2 , West = 3
};

class Bomber : public Figure
{
protected:

public:
    Bomber();
    ~Bomber();
    void show (SDL_Surface*);
};

class Timer
{
    private:
    //Le temps quand le timer est lanc�
    int startTicks;

    //Les "ticks" enregistr� quand le Timer a �t� mit en pause
    int pausedTicks;

    //Le status du Timer
    bool paused;
    bool started;

    public:
    //Initialise les variables
    Timer();

    //Les diff�rentes actions du timer
    void start();
    void stop();
    void pause();
    void unpause();

    //recup�re le nombre de ticks depuis que le timer a �t� lanc�
    //ou r�cup�re le nombre de ticks depuis que le timer a �t� mis en pause
    int get_ticks();

    //Fonctions de v�rification du status du timer
    bool is_started();
    bool is_paused();
};

#endif // CLASSES_H_INCLUDED
