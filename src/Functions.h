#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

typedef struct /*structure de stockage des états clavier et souris*/
{
	char key[SDLK_LAST];
	int mousex,mousey;
	int mousexrel,mouseyrel;
	char mousebuttons[8];
        char quit;
} Input;

void UpdateEvents(Input* in); /*fonction de gestion des évènements clavier et souris*/
void apply_surface( int x, int y, SDL_Surface* src, SDL_Surface* dest, SDL_Rect* clip);
void start_screen(SDL_Surface *ecran);
#endif
