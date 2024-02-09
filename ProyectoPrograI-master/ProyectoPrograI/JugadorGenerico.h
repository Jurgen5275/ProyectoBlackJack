#ifndef JUGADORGENERICO_H
#define JUGADORGENERICO_H

#include <iostream>
#include <string>
#include"Carta.h"
#include "Mano.h"

class JugadorGenerico
{
public:
	JugadorGenerico(std::string);
	~JugadorGenerico();
	virtual Carta* pedirCarta()=0;
	bool sePaso(Carta* &);
	std::string getNombre();

protected:
	std::string nickname;
	Mano* mano;
};
#endif