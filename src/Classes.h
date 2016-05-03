#ifndef CLASSES_H_INCLUDED
#define CLASSES_H_INCLUDED

#include "Header.h"
////////////////////////////////////	SHAPE	////////////////////////////////////////////////
class Shape
{
	protected: 
		SDL_Rect dimCoordSprite; // Coordonnées dans l'image
		SDL_Rect dimCoordShape; // Coordonnées dans l'écran
		SDL_Surface *sprite; // Feuille de sprite stockée ici
		int nbSprites; // Nombre de sprites (surtout pour les personnages)
		
	public:
		Shape();
		Shape(SDL_Surface*,SDL_Rect,int);
		virtual ~Shape();
		virtual void show(SDL_Surface*) = 0;
};

////////////////////////////////////	FIGURE ////////////////////////////////////////////////
class Figure : public Shape
{
	protected :
		int xVel, yVel; // Calcul
		int speed; 
		int direction; // NORTH = 0; SOUTH = 1; EAST = 2; WEST = 3	
	
	public :
		Figure();
		Figure(SDL_Surface*, SDL_Rect, int);
		virtual ~Figure();
		void show(SDL_Surface*);
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

