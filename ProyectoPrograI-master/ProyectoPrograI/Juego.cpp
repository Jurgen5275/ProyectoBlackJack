#include "Juego.h"

Juego::Juego() {
    // Inicializar la baraja y la lista de jugadores
    baraja.inicializar();
    baraja.barajar();
}

Juego::~Juego() {

}

void Juego::jugar() {
    std::cout << "¡Bienvenido al juego de Blackjack!\n" << std::endl;

    // Agregar jugadores
    int numJugadores;
    std::cout << "Ingrese el número de jugadores (máximo 7): ";
    std::cin >> numJugadores;

    for (int i = 0; i < numJugadores; ++i) {
        std::string nombre;
        std::cout << "Ingrese el nombre del jugador " << i + 1 << ": ";
        std::cin >> nombre;
        Jugador* jugador = new Jugador(nombre);
        listaJugadores.insertar(jugador);
    }

    // Crear el dealer
    Dealer dealer;

    for (Nodo* nodo = listaJugadores.getInicio(); nodo != nullptr; nodo = nodo->getNext()) {
        Jugador* jugador = dynamic_cast<Jugador*>(nodo->getDato());
        if (jugador != nullptr) {
            jugador->pedirCarta(&baraja);
            jugador->pedirCarta(&baraja);
        }
    }
    dealer.pedirCarta(&baraja);
    dealer.pedirCarta(&baraja);
    dealer.volteaSegunda();

    // Jugar la mano de cada jugador
    for (Nodo* nodo = listaJugadores.getInicio(); nodo != nullptr; nodo = nodo->getNext()) {
        Jugador* jugador = dynamic_cast<Jugador*>(nodo->getDato());
        if (jugador != nullptr) {
            std::cout << "Turno de " << jugador->getNombre() << ":\n";
            Carta* nuevaCarta = jugador->pedirCarta(&baraja);
            while (nuevaCarta != nullptr) {
                std::cout << "Ha recibido una carta.\n";
                if (jugador->sePaso(nuevaCarta)) {
                    std::cout << "Se ha pasado.\n";
                    break;
                }
                std::cout << "Desea pedir otra carta? (s/n): ";
                char respuesta;
                std::cin >> respuesta;
                if (respuesta == 's') {
                    nuevaCarta = jugador->pedirCarta(&baraja);
                }
                else {
                    nuevaCarta = nullptr;
                }
            }
        }
    }

    // Jugar la mano del dealer
    std::cout << "Turno del dealer:\n";
    Carta* nuevaCarta = dealer.pedirCarta(&baraja);
    while (nuevaCarta != nullptr) {
        std::cout << "El dealer ha recibido una carta.\n";
        if (dealer.sePaso(nuevaCarta)) {
            std::cout << "El dealer se ha pasado.\n";
            break;
        }
        if (dealer.mano->getPuntos(nuevaCarta) >= 17) {
            std::cout << "El dealer se planta.\n";
            break;
        }
        nuevaCarta = dealer.pedirCarta(&baraja);
    }

    // Determinar el ganador
    for (Nodo* nodo = listaJugadores.getInicio(); nodo != nullptr; nodo = nodo->getNext()) {
        Jugador* jugador = dynamic_cast<Jugador*>(nodo->getDato());
        if (jugador != nullptr && !jugador->sePaso()) {
            if (dealer.sePaso() || jugador->mano->getPuntos() > dealer.mano->getPuntos()) {
                std::cout << jugador->getNombre() << " gana!\n";
            }
            else if (jugador->mano->getPuntos() == dealer.mano->getPuntos()) {
                std::cout << "Empate entre " << jugador->getNombre() << " y el dealer.\n";
            }
            else {
                std::cout << jugador->getNombre() << " pierde.\n";
            }
        }
    }
}       