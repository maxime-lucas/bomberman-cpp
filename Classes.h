#ifndef CLASSES_H_INCLUDED
#define CLASSES_H_INCLUDED

#include "Header.h"

class Shape
{
	protected:
		SDL_Rect dimCoordSprite; // Coordonn�es dans l'image
		SDL_Rect dimCoordEcran; // Coordonn�es dans l'�cran
		SDL_Surface *sprite; // Feuille de sprite stock�e ici
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


class Figure : public Shape /*classe figure m�re des classes personnages*/
{
public:
    Figure(); /*constructeur par d�faut*/
    virtual ~Figure(); /*destructeur*/
    Figure(SDL_Surface* , SDL_Rect , int); /*constructeur param�tr�*/
    void show(SDL_Surface*); /*m�thode d'affichage*/
    void MoveUp(); /*m�thodes de d�placement du sprite*/
    void MoveDown();
    void MoveLeft();
    void MoveRight();
    void resetSprite();
protected:
    int xVel , yVel; //taille du d�placement perso
    int speed; //vitesse de d�placement du personnage
    int direction; //North = 0 , South = 1 , East = 2 , West = 3
    void updateSprite();

};

class Bomber : public Figure /*classe du personnage Bomber d�riv�e de Figure*/
{
protected:

public:
    Bomber(); /*constructeur par d�faut*/
    ~Bomber(); /*destructeur*/
    void show (SDL_Surface*); /*m�thode d'affichage*/
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
