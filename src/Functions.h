#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

	void apply_surface( int x, int y, SDL_Surface* src, SDL_Surface* dest, SDL_Rect* clip );
	void start_screen(SDL_Surface *ecran);
	void init(SDL_Surface**);
	bool checkCollision( SDL_Rect, SDL_Rect);
	void playGame(SDL_Surface*);
        void playIntro(SDL_Surface*);
        void playStage1(SDL_Surface*);
	void menu(SDL_Surface*);
        vector<int> parseStageFile(string);

#endif // FUNCTIONS_H_INCLUDED
