#include "Header.h"


Input::Input()
{
    // On met à 0 le tableau contenant l'état des touches du clavier
    memset(this,0,sizeof(*this));

    // Initialisation du nombre de joystick
    nbJoysticks = SDL_NumJoysticks();

    // Création du tableau de structure de joysticks
    joysticks = (InputJoystick*) malloc ( nbJoysticks * sizeof(InputJoystick) );

    // Création des joysticks
    for( int i = 0 ; i < nbJoysticks ; i++ ) {
        joysticks[i].joystick = SDL_JoystickOpen(i);
        joysticks[i].id = i;
        joysticks[i].buttons = (char*) malloc ( SDL_JoystickNumButtons(joysticks[i].joystick) * sizeof(char) );
        joysticks[i].hats = (int*) malloc ( SDL_JoystickNumHats(joysticks[i].joystick) * sizeof(int) );

        memset( joysticks[i].buttons, 0, SDL_JoystickNumButtons(joysticks[i].joystick) * sizeof(char) );
        memset( joysticks[i].hats, 0, SDL_JoystickNumHats(joysticks[i].joystick) * sizeof(int) );
    }
}

Input::~Input()
{	
	
}

void Input::update()
{
    SDL_Event event;
    mouseButtons[SDL_BUTTON_WHEELUP] = 0;
    mouseButtons[SDL_BUTTON_WHEELDOWN] = 0;

    while(SDL_PollEvent(&event))
    {
        if( nbJoysticks != 0 )
        {
            switch (event.type)
            {
                case SDL_JOYBUTTONDOWN:
                    joysticks[ event.jbutton.which ].buttons[ event.jbutton.button ] = 1;
                    //cout << "Button : " << (int) event.jbutton.button << endl;
                    break;
                case SDL_JOYBUTTONUP:
                    joysticks[ event.jbutton.which ].buttons[ event.jbutton.button ] = 0;
                    break;
                case SDL_JOYHATMOTION:
                    joysticks[ event.jhat.which ].hats[ event.jhat.hat ] = event.jhat.value;
                    //cout << "Hat : " << (int) event.jhat.which << " ; Valeur :" << (int) event.jhat.value << endl;
                    break;
                default:
                    break;
            }
        }

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