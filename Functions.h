#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

void apply_surface( int x, int y, SDL_Surface* src, SDL_Surface* dest, SDL_Rect* clip ); /*prototype de la fonction d'affichage*/

void start_screen(SDL_Surface *ecran); /*prototype de la fonction gérant la page d'accueil*/

typedef struct /*structure de stockage des états clavier et souris*/
{
	char key[SDLK_LAST];
	int mousex,mousey;
	int mousexrel,mouseyrel;
	char mousebuttons[8];
        char quit;
} Input;


void UpdateEvents(Input* in); /*fonction de gestion des évènements clavier et souris*/

#endif // FUNCTIONS_H_INCLUDED
