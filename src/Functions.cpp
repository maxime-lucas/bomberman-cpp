#include "Header.h"

// Fonction pour gérer affichage
void apply_surface( int x, int y, SDL_Surface* src, SDL_Surface* dest, SDL_Rect* clip = NULL )
{
    SDL_Rect offset;

    offset.x = x;
    offset.y = y;

    //On blitte la surface
    SDL_BlitSurface( src, clip, dest, &offset );
}

bool checkCollision( SDL_Rect a, SDL_Rect b )
{
    // Les côtes des rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    // Côtes de A
    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    // Côtes de B
    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;

    if( bottomA <= topB )
    {
        return false;
    }

    if( topA >= bottomB )
    {
        return false;
    }

    if( rightA <= leftB )
    {
        return false;
    }

    if( leftA >= rightB )
    {
        return false;
    }

    return true;
}

void init(SDL_Surface** s)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	*s = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_HWSURFACE | SDL_DOUBLEBUF);
	SDL_WM_SetCaption("Bomberman", NULL);
}

void playIntro(SDL_Surface* ecran) {
    Timer fps;
    string path = "img/animations/intro/%d.png";
    Animation *intro = new Animation(path, 90);
    for(int i = 0; i <  intro->getNbFrames() ; i++)
    {
        fps.start();

        intro->render(ecran);
        intro->nextFrame();
        SDL_Flip(ecran);

        while( fps.get_ticks() < 1000 / FRAMES_PER_SECOND ) {}
        fps.stop();
    }
}

void playStage1(SDL_Surface* ecran) {
    Timer fps;
    string path = "img/animations/stage1/%d.png";
    
    Animation *stage1 = new Animation(path, 42);
    for(int i = 0; i <  stage1->getNbFrames() ; i++)
    {
        fps.start();

        stage1->render(ecran);
        stage1->nextFrame();
        SDL_Flip(ecran);

        while( fps.get_ticks() < 1000 / FRAMES_PER_SECOND ) {}
        fps.stop();
    }
}

void playGame(SDL_Surface * ecran)
{
    // Objet pour gérer les évènements
    Input in;
    SDL_JoystickEventState(SDL_ENABLE);
        
    // Instanciation des joueurs
    /*Player* players = NULL;
    players = (Player*) malloc ( NB_PLAYERS * sizeof(Player) );
    for(int i = 0 ; i < NB_PLAYERS ; i++ )
    {
        Player* p = new Player();
        players[i] = *p;
    }*/
    Player p1,p2;
    Player players[] = {(Player) p1, (Player) p2 };
    

    // Instanciation du jeu
    Game *g = new Game( ecran, players);
    g->setupGame();

    
    // Variables temporelles
    double previous = SDL_GetTicks();
    double lag = 0.0;

    while( !in.getQuit() && !in.getKey(SDLK_ESCAPE)  && !(in.getNbJoysticks() > 0 && in.getButton(0,7)) )
    {
        // Calcul du lag
        int i = 0;
        double current = SDL_GetTicks();
        double elapsed = current - previous;
        previous = current;
        lag += elapsed;

        // Mise � jour des �v�nements
        in.update();
        
        /*
        // Evolution du jeu, en fonction du lag
        while (lag >= MS_PER_UPDATE)
        {
            g->evolue(in);
            i++;
            lag -= MS_PER_UPDATE;
        }

        // G�n�ration de la map
        g->render();
        g->flip();
        */
    }
}

vector<int> parseStageFile(string filePath)
{
    vector<int> res;
    
    ifstream is ("stages/stage-1.txt", std::ifstream::binary);
        
    if (is) {
        is.seekg (0, is.end);
        int length = is.tellg();
        is.seekg (0, is.beg);

        char * buffer = new char [length];
        is.read (buffer,length);
        
        vector<int> tmp;
        for(int i = 0, x = 0 , y = 0; i < length ; i++)
        {
            x++;
            char nb = buffer[i];
            int inb = nb - '0';
            res.push_back(inb);
        }
        
        is.close();
        
        delete[] buffer;
        
        return res;
    }
}
