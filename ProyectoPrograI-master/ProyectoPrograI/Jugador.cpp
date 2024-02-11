#include "Jugador.h"

Jugador::~Jugador() {

}

std::string Jugador::getNombre() {
	return nickname;
}

bool Jugador::sePaso() {
	if (mano->getPuntos() > 21) {
		return true;
	}
	return false;
}

Carta* Jugador::pedirCarta(Mazo* mazo) {
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