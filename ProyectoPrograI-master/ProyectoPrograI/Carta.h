#ifndef CARTA_H
#define CARTA_H


#include<iostream>
#include <cstdlib>
#include <ctime>
#include<string>

class Carta
{
public:
	Carta();
	int getValor();
	int getPalo(); 
	void Voltear();
	~Carta();

private:
	enum palo { Corazones, Diamantes, Treboles, Espadas };
	enum valor { Dos = 2, Tres=3, Cuatro=4, Cinco=5, Seis=6, Siete=7, Ocho=8, Nueve=9, Diez=10, Jota=10, Reina=10, Rey=10, As=1&&10 };
	bool bocaAbajo;
	int num;

	int paloV;
};



#endif