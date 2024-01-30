#ifndef JUGADORGENERICO_H
#define JUGADORGENERICO_H

#include <iostream>
#include <string>
#include"Carta.h"
#include "Mano.h"

class JugadorGenerico
{
public:
	JugadorGenerico();
	~JugadorGenerico();
	virtual Carta* pedirCarta()=0;
	bool sePaso();

private:
	std::string nickname;
	Mano* mano;
};
#endif