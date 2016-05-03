#ifndef CLASSES_H_INCLUDED
#define CLASSES_H_INCLUDED

#include "Header.h"

class Shape /*classe abstraite dont seront d�riv�es toutes les autres classes*/
{
protected:
    SDL_Rect dimCoordSprite; //coordonn�es dans l'image
    SDL_Rect dimCoordEcran; //coordonn�es dans l'�cran
    SDL_Surface *sprite; //feuille de sprites stock�e ici
    int nbSprites; //nombre de sprites (pour perso)

public:
    Shape(); /*constructeur par d�faut*/
    Shape(SDL_Surface* , SDL_Rect , int); /*constructeur avec arguments*/
    virtual ~Shape(); /*destructeur*/
    virtual void show(SDL_Surface*) = 0; /*m�thode virtual rendant la classe abstraite*/
};

class Figure : public Shape /*classe figure m�re des classes personnages*/
{
public:
    Figure(); /*constructeur par d�faut*/
    virtual ~Figure(); /*destructeur*/
    Figure(SDL_Surface* , SDL_Rect , int); /*constructeur param�tr�*/
    void show(SDL_Surface*); /*m�thode d'affichage*/
protected:
    int xVel , yVel; //taille du d�placement perso
    int speed; //vitesse de d�placement du personnage
    int direction; //Noth = 0 , South = 1 , East = 2 , West = 3
};

class Bomber : public Figure /*classe du personnage Bomber d�riv�e de Figure*/
{
protected:

public:
    Bomber(); /*constructeur par d�faut*/
    ~Bomber(); /*destructeur*/
    void show (SDL_Surface*); /*m�thode d'affichage*/
};

class Button : public Shape /*classe bouton d�riv�e de Shape*/
{
protected:
public:
    Button(); /*constructeur par d�faut*/
    Button(SDL_Surface*,SDL_Rect,int); /*constructeur param�tr�*/
    ~Button(); /*destructeur*/
    void show(SDL_Surface*); /*m�thode d'affichage*/
};

class Timer /*classe timer de gestion du temps*/
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
