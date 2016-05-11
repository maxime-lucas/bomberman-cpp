#include "Header.h"


Input::Input()
{
	memset(this,0,sizeof(*this));
}

Input::~Input(){ }

void Input::Update()
{
	SDL_Event event;
        mouseButtons[SDL_BUTTON_WHEELUP] = 0;
        mouseButtons[SDL_BUTTON_WHEELDOWN] = 0;
	while(SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_KEYDOWN:
			key[event.key.keysym.sym]=1;
			break;
		case SDL_KEYUP:
			key[event.key.keysym.sym]=0;
			break;
		case SDL_MOUSEMOTION:
			mouseX=event.motion.x;
			mouseY=event.motion.y;
			mouseXRel=event.motion.xrel;
			mouseYRel=event.motion.yrel;
			break;
		case SDL_MOUSEBUTTONDOWN:
			mouseButtons[event.button.button]=1;
			break;
		case SDL_MOUSEBUTTONUP:
                        if (event.button.button!=SDL_BUTTON_WHEELUP && event.button.button!=SDL_BUTTON_WHEELDOWN)
  			   mouseButtons[event.button.button]=0;
			break;
		case SDL_QUIT:
			quit = 1;
			break;
		default:
			break;
		}
	}
}
