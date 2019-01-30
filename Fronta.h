#pragma once
class Fronta
{
private:
	struct polozka {
		// atrib�ty polozky , zoznamu atd 
		int cislo;
		char znak;
		struct polozka *next;
	};
	typedef struct polozka polozka;

	polozka *first;
	polozka *last;
	
	int pocet;


public:
	// zakladne funkcie pre frontu
	void add(int i, char a); // atrib�ty novej polozky 
	void zmaz(int poradie);
	void presun(int co, int kde);
	void usporiadaj();
	void vycisti();
	void vypis();

	Fronta();
	~Fronta();
};

