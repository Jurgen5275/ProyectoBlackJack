#include "JugadorGenerico.h"

JugadorGenerico::JugadorGenerico()
{
	nickname = "";
	mano = nullptr;
}

JugadorGenerico::JugadorGenerico(std::string nombre, Mano* man)
{
	mano = man;
	nickname = nombre;
}

JugadorGenerico::~JugadorGenerico()
{
	if (mano) delete mano;
}