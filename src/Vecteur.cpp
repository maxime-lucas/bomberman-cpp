class Vecteur
{
	protected :
		void **tab;
		int nb;
	public :
		Vecteur();
		Vecteur(const Vecteur&);
		~Vecteur();
		Vecteur& operator=(const Vecteur&);
		void ajoute(void *);
		int supp( void*);
};

Vecteur::Vecteur()
{
	nb = 0;
	tab =  NULL;
}

Vecteur::~Vecteur()
{
	delete(tab);
}

Vecteur::~Vecteur()
{
	delete(tab);
}

Vecteur::ajoute(void* elt)
{
	void **dtab;
	dtab = new void*[nb + 1];
	for(i = 0; i < nb; i++)
		dtab[i] = tab[i];
	dtab[i] = elt;
	if( tab != NULL )
		delete tab;
	tab = dtab;
	nb++;
}

class gestaff : public vect()
{
	protected :
	public :
		gestaff();
		~gestaff();
		void affiche();
};

gestaff::gestaff()  : vect() {}

gestaff::~gestaff()
{
}
