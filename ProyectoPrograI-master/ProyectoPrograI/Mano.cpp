#include "Mano.h"

Mano::Mano() {
    cant = 0;
    tam = 5;
    cartas = new Carta * [tam];
    for (int i = 0; i < tam; i++) {
        Carta* carta = new Carta();
        cartas[i] = carta;
    }
}

Mano::~Mano() {
    for (int i = 0; i < cant; i++) {
        delete cartas[i];
    }
    delete[] cartas;
}

int Mano::getCant() {
    return cant;
}

Carta* Mano::getCarta(int indice) {
    if (indice >= 0 && indice < cant) {
        return cartas[indice];
    }
    else {
        return nullptr;
    }
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

void Mano::agregarCarta2(Carta* nuevaCarta) {
    if (cant < 5) {
        if (nuevaCarta != nullptr) {
            cartas[cant] = nuevaCarta;
            std::cout << "Carta agregada a la mano" << std::endl;
            cant++;
        }
        else {
            std::cout << "La carta a agregar es nula" << std::endl;
        }
    }
    else {
        std::cout << "Ya no puede pedir más cartas, límite alcanzado" << std::endl;
    }
}

void Mano::limpiar() {
    for (int i = 0; i < cant; i++) {
        delete cartas[i];
    }
    cant = 0;
}

int Mano::getPuntos() {
    int sum = 0;
    int cantAs = 0;

    for (int i = 0; i < cant; i++) {
        if (cartas[i] != nullptr) {
            int valor = cartas[i]->getValor();
            if (valor == 1 || valor == 11) {
                cantAs++;
                sum = sum + 11;
            }
            else if (valor > 11) {
                sum = sum + 10;
            }
            else {
                sum = sum + valor;
            }
        }
    }

    while (cantAs > 0 && sum > 21) {
        sum = sum - 10;
        cantAs--;
    }
    return sum;
}
