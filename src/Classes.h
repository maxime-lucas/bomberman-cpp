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

		void setSprite(SDL_Surface*);
};


class Player : public Shape
{
	protected:
	    int xVel , yVel; // Vecteurs vitesse du personnage
	    int speed; // vitesse de déplacement du personnage
	    int direction; //North = 0 , South = 1 , East = 2 , West = 3
	    void updateSprite();
	    SDL_Rect box;
	    void updateBox();
	    int nbBomb;

	public:
		Player();
		Player(SDL_Surface* , SDL_Rect , int);
		virtual ~Player();
		void show(SDL_Surface*);

		// Déplacement du sprite
		void MoveUp();
		void MoveDown();
		void MoveLeft();
		void MoveRight();
		void resetSprite();

		// Gestion des bombes
		void dropBomb();
		void pickBomb();

		// Accesseurs
		void setXvel(int x){ this->xVel = x; }
		int getXvel() { return this->xVel; }
		void setYvel(int y){ this->yVel = y; }
		int getYvel() { return this->yVel; }
		int getSpeed() { return this->speed; }
		SDL_Rect getBox(){ return this->box; }
		void setBox(SDL_Rect box){ this->box = box; }
		int getNbBomb() { return this->nbBomb; }
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


class Timer
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

class Input
{
	protected:
		char key[SDLK_LAST];
		int mouseX, mouseY;
		int mouseXRel, mouseYRel;
		char mouseButtons[8];
		char quit;

	public:
		Input();
		~Input();
		void Update();
		void resetKey(int i) { this->key[i] = 0; };
		char& getKey(int i) { return key[i]; }
		int getMouseX(){ return mouseX; }
		int getMouseY(){ return mouseY; }
		int getMouseXRel(){ return mouseXRel; }
		int getMouseYRel(){ return mouseYRel; }
		int getMouseButton(int i){ return mouseButtons[i]; }
		int getQuit(){ return quit; }
		void setQuit(int i){this->quit = i; }
};

class TileSet
{
	protected :
		SDL_Rect clips[  NB_TILES_WIDTH *  NB_TILES_HEIGHT ];
		SDL_Surface *tileSet;

	public :
		TileSet();
		SDL_Rect getClip(int i) { return this->clips[i]; }
		SDL_Surface* getTileSet() { return this->tileSet; }
};

class Tile
{
	protected :
		SDL_Rect box;
		int type;

	public:
		Tile( int, int, int);
		void show(TileSet*, SDL_Surface*);
		int getType();
		SDL_Rect getBox();
};

class Map
{
	protected :
		void **tab;
		int nb;
	public :
		Map();
		Map& operator=(const Map&);
		~Map();
		
		void add(void *);
		void remove(void *);
		void* get(int i) { return tab[i]; }
		int getNb(){ return nb; }
};

class TileMap : public Map
{
	protected :
	public :
		TileMap();
		~TileMap();
		
		void draw(TileSet*, SDL_Surface*);
};

class BombMap : public Map
{
	protected :
	public :
		BombMap();
		~BombMap();
		
		void draw(SDL_Surface*);
};

class ExplosionMap : public Map
{
	protected :
	public :
		ExplosionMap();
		~ExplosionMap();
		
		void draw(SDL_Surface*);
};

class PlayerMap : public Map
{
	protected :
	public :
		PlayerMap();
		~PlayerMap();
		
		void draw(SDL_Surface*);
};

class Bomb: public Shape
{
	public:
	    Bomb();
	    ~Bomb();
	    void nextSprite();
	    void nextStep();
	    void show(SDL_Surface*);
	    void resetSprite();
	    int getStep() {return step;};
	    int getDateOfExplosion() {return dateOfExplosion;};
	    int getDelay() {return delay;};

	protected:
	    int step;
	    int delay;
	    int dateOfExplosion;
};

class Explosion: public Shape
{
	protected :
		int step;
		int duration;
		int strength;
		int dateOfDisparition;
	
	public :
		Explosion();
		~Explosion();
		void nextSprite();
		void nextStep();
		void show(SDL_Surface*);
		void resetSprite();
		
		int getStrength() {return strength; };
		int getStep() {return step;};
		int getDateOfDisparition() {return dateOfDisparition;};
		int getDuration() {return duration;};
};

class Game
{
	protected :
		TileMap *mapBackground;
		TileMap *mapWalls;
		BombMap *mapBombs;
		PlayerMap *mapPlayers;
		ExplosionMap *mapExplosions;
		
		TileSet *tileSet;
		SDL_Surface* ecran;

	public :
		Game(SDL_Surface*);
		Game(SDL_Surface*, Player[]);
		void setupGame();
		void evolue(Input&);
		void render();
		void flip();

		bool touchesTile( SDL_Rect , TileMap* , int );
};



#endif // CLASSES_H_INCLUDED
