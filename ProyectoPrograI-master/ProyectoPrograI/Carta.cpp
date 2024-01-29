#include"Carta.h"

Carta::Carta()
{
	 

	srand(time(NULL));
	
	// Obtener un valor aleatorio entre 0 y el número de elementos en el enum
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	int num = std::rand() % (As + 1);
	static_cast<valor>(num);
	int paloV = std::rand() % (Espadas + 1);
	static_cast<palo>(paloV);
	
}

Carta::~Carta()
{

}

int Carta::getValor()
{
	return num;
}

int Carta::getPalo()
{
	return paloV;
}

void Carta::Voltear()
{
	getValor();
	getPalo();
	if (bocaAbajo=true)
	{
		std::cout  << "el Valor es  ?? y el palo es ?? ";
	}
	else
	{
		std::cout << "el Valor es  "<<num<<"  y el palo es "<<paloV;
	}
	
}