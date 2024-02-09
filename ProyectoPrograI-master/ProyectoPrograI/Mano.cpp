#include"Mano.h"

Mano::Mano() {
    cartas[5];
}

Mano::~Mano() {

}

Carta* Mano::agregarCarta(Mazo* mazo) {
    if (cant < 5) {
        Carta* nuevaCarta = mazo->tomarCarta();
        if (nuevaCarta != nullptr) {
            cartas[cant] = nuevaCarta;
            std::cout << "Carta agarrada\n" << std::endl;
            cant++;
            return nuevaCarta;
        }
        else {
            std::cout << "Ya no hay cartas en el mazo\n" << std::endl;
            return nullptr;
        }
    }
    else {
        std::cout << "Ya no puede pedir mas cartas, limite alcanzado\n" << std::endl;
        return nullptr;
    }
}

void Mano::limpiar() {
    for (int i = 0; i <= 5; i++)
    {
        delete cartas[i];
    }
}

int Mano::getPuntos(Carta* &naipe) {

    int puntos = naipe->getValor();

    switch (puntos) {
    case 0:
        int valor = 0;
        std::cout << "eliga el valor del As, puede ser 1 o 11\n";
        std::cin >> valor;
        if ((valor == 1) || (valor == 11)) { puntos = valor; }
        else
            std::cout << "Invalido\n";


        return puntos;

        break;
    case 1:

        return puntos;

        break;
    case 2:

        return puntos;

        break;
    case 3:

        return puntos;

        break;
    case 4:

        return puntos;

        break;

    case 5:

        return puntos;

        break;

    case 6:

        return puntos;

        break;

    case 7:

        return puntos;

        break;

    case 8:

        return puntos;

        break;

    case 9:

        return puntos;

        break;

    case 10:

        puntos = 10;

        return puntos;

        break;

    case 11:

        puntos = 10;

        return puntos;

        break;

    case 12:

        puntos = 10;

        return puntos;


        break;

    }
}