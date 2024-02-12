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
	JugadorGenerico(std::string, Mano*);
	~JugadorGenerico();
	virtual Carta* pedirCarta(Mazo*)=0;
	virtual bool sePaso()=0;
	virtual std::string getNombre()=0;
	

	std::string nickname;
	Mano* mano;
};
#endif