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
                
                SDL_Rect getDimCoordEcran() { return dimCoordEcran; };

		void setSprite(SDL_Surface*);
};


class Player : public Shape
{
	protected:
	    int xVel , yVel; // Vecteurs vitesse du personnage
	    int speed; // vitesse de d�placement du personnage
	    int direction; //North = 0 , South = 1 , East = 2 , West = 3
	    void updateSprite();
	    SDL_Rect box;
	    void updateBox();
	    int nbBomb;
            bool alive;

	public:
            Player();
            Player(SDL_Surface* , SDL_Rect , int);
            virtual ~Player();
            Player& operator=(const Player&);
            void show(SDL_Surface*);

            // D�placement du sprite
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
            int getNbBomb() { return this->nbBomb; }
            void setAlive(bool k) { alive = k; };
            bool isAlive() { return alive; };
            SDL_Rect getBox() { return box; };
            void setBox(SDL_Rect b) { this->box = b; };
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

class InputJoystick
{
    friend class Input;
    
    protected:
        SDL_Joystick* joystick;
        char* buttons;
        int* hats;
        int id;	

    public:
};

class Input
{
    friend class InputJoystick;
    
    protected:
            char key[SDLK_LAST];
            int mouseX, mouseY;
            int mouseXRel, mouseYRel;
            int nbJoysticks;
            InputJoystick* joysticks;

            char mouseButtons[8];
            char quit;

    public:
            Input();
            ~Input();

            void update();
            void resetKey(int i) { this->key[i] = 0; };
            void resetButton(int joy, int btn) { joysticks[joy].buttons[btn] = 0; };

            int getHat(int idJoystick, int idHat) { return joysticks[idJoystick].hats[idHat]; }
            int getButton(int idJoystick, int idButton) { return joysticks[idJoystick].buttons[idButton]; }
            char& getKey(int i) { return key[i]; }
            int getMouseX(){ return mouseX; }
            int getMouseY(){ return mouseY; }
            int getMouseXRel(){ return mouseXRel; }
            int getMouseYRel(){ return mouseYRel; }
            int getMouseButton(int i){ return mouseButtons[i]; }
            int getQuit(){ return quit; }
            void setQuit(int i){this->quit = i; }
            int getNbJoysticks() { return nbJoysticks; }
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
                bool enabled;

	public:
		Tile( int, int, int);
		void show(TileSet*, SDL_Surface*);
		int getType();
		SDL_Rect getBox();
                bool isEnabled() const { return enabled; }
                void setEnabled(bool enabled) { this->enabled = enabled; }

};

class Explosion: public Shape
{
	protected :
		int step;
		int duration;
		int strength;
		int dateOfEnd;
		std::vector<SDL_Rect> collisionBoxes;
	
	public :
		Explosion();
                Explosion(int, int);
		~Explosion();
		void nextSprite();
		void nextStep();
		void show(SDL_Surface*);
		void resetSprite();
		
		int getStrength() { return strength; };
		int getStep() { return step;};
		int getDateOfEnd() { return dateOfEnd; };
		int getDuration() { return duration;};
		
		void evolueUp();
		void evolueDown();
		void evolueLeft();
		void evolueRight();

                std::vector<SDL_Rect> getCollisionBoxes() const { return collisionBoxes; }
                void setCollisionBoxes(std::vector<SDL_Rect> collisionBoxes) { this->collisionBoxes = collisionBoxes; }
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

class ExplosionMap
{
    protected :
         std::vector<Explosion*> tab;
         
    public :
        ExplosionMap();
        ~ExplosionMap();

        std::vector<Explosion*> getTab() const { return tab; }
        void draw(SDL_Surface*);
};

class PlayerMap
{
    protected :
         std::vector<Player*> tab;
    public :
        PlayerMap();
        ~PlayerMap();

        std::vector<Player*> getTab() { return tab; }
        void draw(SDL_Surface*);
};

class TileMap
{
    protected :
         std::vector<Tile*> tab;
         
    public :
        TileMap();
        ~TileMap();

        std::vector<Tile*> getTab() const { return tab; }
        void draw(TileSet*, SDL_Surface*);
};

class BombMap
{
    protected :
         std::vector<Bomb*> tab;
         
    public :
        BombMap();
        ~BombMap();
        
        std::vector<Bomb*> getTab() const { return tab; }
        void draw(SDL_Surface*);
};

class Animation
{
    protected:
        SDL_Surface* img;
        string path;
        int nbFrames;
        int currentFrame;
        
    public:
        Animation();
        Animation(string, int);
        Animation(const Animation&);
        ~Animation();
        void nextFrame();
        void render(SDL_Surface*);
        void resetFrames();
        
        int getCurrentFrame() { return currentFrame; };
        int getNbFrames() { return nbFrames; };
        void setNbFrames(int i) { this->nbFrames = i; };
        string getPath() { return this->path; };
        void setPath(string p) { this->path = p; };
};

class AnimationPlayer : public Animation
{
    protected:
        int indexPlayer;
        
    public:
        AnimationPlayer();
        AnimationPlayer(char*, int, int);
        ~AnimationPlayer();
        void render(SDL_Surface*);
        void setIndexPlayer(int i) { this->indexPlayer = i; };
};

class Game
{
	protected :
		std::vector<Tile *> mapBackground;
		std::vector<Tile *> mapWalls;
		std::vector<Bomb *> mapBombs;
		std::vector<Explosion*> mapExplosions;
                std::vector<Player*> mapPlayers;
                
                AnimationPlayer *title;
                int nbPlayersAlive;
		
		TileSet *tileSet;
		SDL_Surface* ecran;
                
                bool endOfGame;
                bool endOfAnimation;

	public :
		Game(SDL_Surface*, Player[]);
		void setupGame();
		void evolue(Input&);
		void render();
		void flip();

		bool explosionTouchesTile( SDL_Rect box, std::vector<Tile*> tm );
                bool touchesTile( SDL_Rect box, std::vector<Tile*> tm );
                bool touchesBomb( SDL_Rect box, std::vector<Bomb*> bm );
                void evolueExplosion( int );
                void updateBomb( int );
                void updateExplosion( int );
                void killPlayer(int);
                
                void doMoveUp(Player*);
                void doMoveDown(Player*);
                void doMoveRight(Player*);
                void doMoveLeft(Player*);
                void doDropBomb(Player*);
};

#endif // CLASSES_H_INCLUDED
