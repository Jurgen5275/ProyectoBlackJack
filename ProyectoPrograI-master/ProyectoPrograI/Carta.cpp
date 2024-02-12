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

std::string Carta::getPalo() {
	switch (palo) {
	case 0:
		return "C";
	case 1:
		return "D";
	case 2:
		return "T";
	case 3:
		return "E";
	default:
		return "Desconocido";
	}
}


void Carta::Voltear() {
	bocaAbajo = !bocaAbajo;
	if (bocaAbajo) {
		std::cout << "La carta ha sido volteada boca abajo." << std::endl;
	}
	else {
		std::cout << "La carta ha sido volteada boca arriba." << std::endl;
	}
}

