const int FIGURE_WIDTH = 18;
const int FIGURE_HEIGHT = 30;

SDL_Rect *spritesUp[6];
SDL_Rect *spritesDown[6];
SDL_Rect *spritesLeft[6];
SDL_Rect *spritesRight[6];

void set_sprites()
{
	for(int i = 0; i < 6; i++)
	{
		spritesRight[i].x = 6*FIGURE_WIDTH + FIGURE_WIDTH*i;
		spritesRight[i].y = 0;
		spritesRight[i].w = FIGURE_WIDTH;
		spritesRight[i].h = FIGURE_HEIGHT;

		spritesLeft[i].x = 6*FIGURE_WIDTH + FIGURE_WIDTH*i;
		spritesLeft[i].y = FIGURE_HEIGHT;
		spritesLeft[i].w = FIGURE_WIDTH;
		spritesLeft[i].h = FIGURE_HEIGHT;

		spritesUp[i].x = FIGURE_WIDTH*i;
		spritesUp[i].y = FIGURE_HEIGHT;
		spritesUp[i].w = FIGURE_WIDTH;
		spritesUp[i].h = FIGURE_HEIGHT;

		spritesDown[i].x = FIGURE_WIDTH*i;
		spritesDown[i].y = 0;
		spritesDown[i].w = FIGURE_WIDTH;
		spritesDown[i].h = FIGURE_HEIGHT;

	}
}
