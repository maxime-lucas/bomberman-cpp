#ifndef CLASSES_H_INCLUDED
#define CLASSES_H_INCLUDED

#include "Header.h"

class Shape
{
	protected:
		SDL_Rect dimCoordSprite; // Coordonnées dans l'image
		SDL_Rect dimCoordEcran; // Coordonnées dans l'écran
		SDL_Surface *sprite; // Feuille de sprite stockée ici
		int nbSprites; // Nombre de sprites (surtout pour les personnages)

	public:
		Shape();
		Shape(SDL_Surface*,SDL_Rect,int);
		virtual ~Shape();
		virtual void show(SDL_Surface*) = 0;

		void setDimCoordEcranX(int);
		void setDimCoordEcranY(int);
		void setDimCoordEcranW(int);
		void setDimCoordEcranH(int);
		int getDimCoordEcranX();
		int getDimCoordEcranY();
		int getDimCoordEcranW();
		int getDimCoordEcranH();

		void setDimCoordSpriteX(int);
		void setDimCoordSpriteY(int);
		void setDimCoordSpriteW(int);
		void setDimCoordSpriteH(int);
		int getDimCoordSpriteX();
		int getDimCoordSpriteY();
		int getDimCoordSpriteW();
		int getDimCoordSpriteH();
};


class Figure : public Shape /*classe figure mère des classes personnages*/
{
public:
    Figure(); /*constructeur par défaut*/
    virtual ~Figure(); /*destructeur*/
    Figure(SDL_Surface* , SDL_Rect , int); /*constructeur paramétré*/
    void show(SDL_Surface*); /*méthode d'affichage*/
    void MoveUp(); /*méthodes de déplacement du sprite*/
    void MoveDown();
    void MoveLeft();
    void MoveRight();
    void resetSprite();
protected:
    int xVel , yVel; //taille du déplacement perso
    int speed; //vitesse de déplacement du personnage
    int direction; //North = 0 , South = 1 , East = 2 , West = 3
    void updateSprite();

};

class Bomber : public Figure /*classe du personnage Bomber dérivée de Figure*/
{
protected:

public:
    Bomber(); /*constructeur par défaut*/
    ~Bomber(); /*destructeur*/
    void show (SDL_Surface*); /*méthode d'affichage*/
};

class Button : public Shape
{
	protected :
		bool hovered;

	public :
		Button();
		Button(SDL_Surface*, SDL_Rect, int);
		~Button();
		void show(SDL_Surface*);
		void setHovered();
		void unsetHovered();
		bool isHovered(int, int);
		void toString();
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
