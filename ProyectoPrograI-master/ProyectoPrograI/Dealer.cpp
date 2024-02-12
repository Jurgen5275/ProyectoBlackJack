#include"Dealer.h"

Dealer::Dealer() {
	nickname = "Dealer";
	mano = nullptr;
}

Dealer::~Dealer() {
}

std::string Dealer::getNombre() {
	return nickname;
}

bool Dealer::sePaso() {
	if (mano->getPuntos() > 21) {
		return true;
	}
	return false;
}

Carta* Dealer::pedirCarta(Mazo* mazo) {
	if (!sePaso()) {
		Carta* nuevaCarta = mano->agregarCarta(mazo);
		if (nuevaCarta != nullptr) {
			return nuevaCarta;
		}
		else {
			std::cout << "No hay mas cartas en el mazo\n" << std::endl;
			return nullptr;
		}
	}
	else {
		std::cout << "No se puede pedir mas cartas\n" << std::endl;
		return nullptr;
	}
}

void Dealer::mostrarMano() {
	std::cout << "Mano del dealer: ";
	for (int i = 0; i < mano->getCant(); ++i) {
		Carta* carta = mano->getCarta(i);
		if (carta != nullptr) {
			std::cout << carta->getValor() << carta->getPalo() << " ";
		}
	}
	std::cout << std::endl;
}

void Dealer::volteaSegunda() {
	// Verificar si hay al menos dos cartas en la mano
	if (mano->getCant() >= 2) {
		// Iterar sobre las cartas en la mano
		for (int i = 0; i < 2; ++i) {
			// Voltear la segunda carta
			if (i == 1) {
				mano->getCarta(i)->Voltear();
			}
		}
	}
}
