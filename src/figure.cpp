Class Figure
{
	private:
		// Position
		int xPos, yPos;
		
		// Vitesse
		int xVel, yVel;
		
		// Frame courante
		int frame;
		
		// Statut d'animation : up, down, left, right
		int status;
	public:
		Figure();
		void handle_events();
		void show();
}

Figure::Figure()
{
	xPos = 0;
	yPos = 0;

	xVel = 0;
	yVel = 0;

	frame = 0;
	status = FIGURE_DOWN;
}
