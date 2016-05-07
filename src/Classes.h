#ifndef CLASSES_H_INCLUDED
#define CLASSES_H_INCLUDED

#include "Header.h"
////////////////////////////////////	SHAPE	////////////////////////////////////////////////
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
		
		void setSprite(SDL_Surface *s) { sprite = s; };
};

////////////////////////////////////	BUTTON ////////////////////////////////////////////////
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

////////////////////////////////////	FIGURE ////////////////////////////////////////////////
class Figure : public Shape
{
	protected :
		int xVel, yVel; // Calcul
		int speed; 
		int direction; // NORTH = 0; SOUTH = 1; EAST = 2; WEST = 3	
		void updateSprite();
	
	public :
		Figure();
		Figure(SDL_Surface*, SDL_Rect, int);
		virtual ~Figure();
		void show(SDL_Surface*);
		void MoveUp();
		void MoveDown();
		void MoveLeft();
		void MoveRight();
		void resetSprite();
		
		int getXvel() { return xVel; };
		int getYvel() { return yVel; };
		int getSpeed() { return speed; };
		void setXvel(int x) { xVel = x; };
		void setYvel(int y) { yVel = y; };
};

////////////////////////////////////	MARIO ////////////////////////////////////////////////
class Mario : public Figure
{
	protected :
	
	public :
		Mario();
		~Mario();
		void show(SDL_Surface*);
};

////////////////////////////////////	BOMBER ////////////////////////////////////////////////
class Bomber : public Figure
{
	protected :
	
	public :
		Bomber();
		~Bomber();
		void show(SDL_Surface*);
};

////////////////////////////////////	TIMER	////////////////////////////////////////////////
class Timer
{
    private:
    // Le temps quand le timer est lancé
    int startTicks;

    // Les "ticks" enregistrés quand le Timer a été mit en pause
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

#endif

