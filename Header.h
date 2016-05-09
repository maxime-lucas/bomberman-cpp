#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

	#include <stdio.h>
	#include <stdlib.h>

	#include <SDL.h>
	#include <SDL_image.h>
	#include <SDL_ttf.h>

	// Attributs de l'écran : Largeur, Hauteur, Profondeur de couleur
	const int SCREEN_WIDTH = 600;
	const int SCREEN_HEIGHT = 440;
	const int SCREEN_BPP = 32;

	// Constantes pour l'orientation du personnage
	const int NORTH = 0;
	const int SOUTH = 1;
	const int WEST = 2;
	const int EAST = 3;

	// Vitesse de déplacement, par défaut, du personnage ( en px / sec )
	const int DEFAULT_SPEED = 300;

	// Nombre d'images devant s'afficher par seconde
	const int FRAMES_PER_SECOND = 30;

	// Constantes pour les tuiles
	const int TILE_WIDTH = 40;
	const int TILE_HEIGHT = 40;
	const int TOTAL_TILES = 192;
	const int NB_TILES_WIDTH = 15;
	const int NB_TILES_HEIGHT = 11;
	const int TILE_GRASS = 0;
	const int TILE_WALL = 2;
	const int TILE_BRICK = 1;

	// Constantes pour le jeu
	const int NB_PLAYERS = 2;

	#include "Classes.h"
	#include "Functions.h"
#endif // HEADER_H_INCLUDED
