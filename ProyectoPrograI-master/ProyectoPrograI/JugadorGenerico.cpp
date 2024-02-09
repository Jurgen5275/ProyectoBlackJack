#include "JugadorGenerico.h"

JugadorGenerico::JugadorGenerico(std::string nombre)
{
	nickname = nombre;
}

std::string JugadorGenerico::getNombre() {
	return nickname;
}

JugadorGenerico::~JugadorGenerico()
{

}

bool JugadorGenerico::sePaso(Carta* &naipe)
{
	return mano->getPuntos(naipe) > 21;
}