#ifndef CLASSES_H_INCLUDED
#define CLASSES_H_INCLUDED

#include "Header.h"

class Shape /*classe abstraite dont seront dérivées toutes les autres classes*/
{
protected:
    SDL_Rect dimCoordSprite; //coordonnées dans l'image
    SDL_Rect dimCoordEcran; //coordonnées dans l'écran
    SDL_Surface *sprite; //feuille de sprites stockée ici
    int nbSprites; //nombre de sprites (pour perso)

public:
    Shape(); /*constructeur par défaut*/
    Shape(SDL_Surface* , SDL_Rect , int); /*constructeur avec arguments*/
    virtual ~Shape(); /*destructeur*/
    virtual void show(SDL_Surface*) = 0; /*méthode virtual rendant la classe abstraite*/
};

class Figure : public Shape /*classe figure mère des classes personnages*/
{
public:
    Figure(); /*constructeur par défaut*/
    virtual ~Figure(); /*destructeur*/
    Figure(SDL_Surface* , SDL_Rect , int); /*constructeur paramétré*/
    void show(SDL_Surface*); /*méthode d'affichage*/
protected:
    int xVel , yVel; //taille du déplacement perso
    int speed; //vitesse de déplacement du personnage
    int direction; //Noth = 0 , South = 1 , East = 2 , West = 3
};

class Bomber : public Figure /*classe du personnage Bomber dérivée de Figure*/
{
protected:

public:
    Bomber(); /*constructeur par défaut*/
    ~Bomber(); /*destructeur*/
    void show (SDL_Surface*); /*méthode d'affichage*/
};

class Button : public Shape /*classe bouton dérivée de Shape*/
{
protected:
public:
    Button(); /*constructeur par défaut*/
    Button(SDL_Surface*,SDL_Rect,int); /*constructeur paramétré*/
    ~Button(); /*destructeur*/
    void show(SDL_Surface*); /*méthode d'affichage*/
};

class Timer /*classe timer de gestion du temps*/
{
    private:
    //Le temps quand le timer est lancé
    int startTicks;

    //Les "ticks" enregistré quand le Timer a été mit en pause
    int pausedTicks;

    //Le status du Timer
    bool paused;
    bool started;

    public:
    //Initialise les variables
    Timer();

    //Les différentes actions du timer
    void start();
    void stop();
    void pause();
    void unpause();

    //recupére le nombre de ticks depuis que le timer a été lancé
    //ou récupére le nombre de ticks depuis que le timer a été mis en pause
    int get_ticks();

    //Fonctions de vérification du status du timer
    bool is_started();
    bool is_paused();
};

#endif // CLASSES_H_INCLUDED
