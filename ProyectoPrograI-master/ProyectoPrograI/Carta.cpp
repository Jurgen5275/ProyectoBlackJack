#include"Carta.h"


Carta::Carta()
{

	valor = 1;
	palo = 1;
	bocaAbajo = false;

}
Carta::Carta(int pValor, int pPalo)
{
	 
	valor = pValor;
	palo = pPalo;
	bocaAbajo = false;
	
}

Carta::~Carta()
{

}

int Carta::getValor()
{
	return valor;
}

int Carta::getPalo()
{
	return palo;
}

void Carta::Voltear()
{
	if (bocaAbajo) {
		std::cout << "el Valor es  ?? y el palo es ?? ";
	}
	else {
		std::cout << "el Valor es  " << valor << "  y el palo es " << palo;
	}
}
