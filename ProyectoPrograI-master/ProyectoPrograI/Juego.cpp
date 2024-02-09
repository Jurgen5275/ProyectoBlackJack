#include "Juego.h"

Juego::Juego() {

}

Juego::~Juego() {

}

void Juego::jugar() {
    std::cout << "¡Bienvenido al juego de Blackjack!\n" << std::endl;

    baraja.inicializar();
    baraja.barajar();

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
    Dealer* dealer = new Dealer();
    listaJugadores.insertar(dealer);

    // Repartir cartas a los jugadores
    for (int i = 0; i < 2; ++i) {
        for (Nodo* nodo = listaJugadores.getInicio(); nodo != nullptr; nodo = nodo->getNext()) {
            JugadorGenerico* jugador = nodo->getDato();
            jugador->pedirCarta(&baraja);
        }
    }

    // Voltear la segunda carta del dealer
    dealer->volteaSegunda();

    // Lógica del juego
    bool continuarJugando = true;
    while (continuarJugando) {
        // Turnos de los jugadores
        actual = listaJugadores.getInicio();
        while (actual != nullptr) {
            JugadorGenerico* jugador = actual->dato;
            std::cout << "Turno de " << jugador->getNombre() << ":" << std::endl;
            std::cout << "Mano: ";
            jugador->mostrarMano();
            std::cout << std::endl;

            std::string opcion;
            std::cout << "¿Deseas pedir carta (P) o pasar (S)?: ";
            std::cin >> opcion;

            if (opcion == "P" || opcion == "p") {
                Carta* nuevaCarta = jugador->pedirCarta(&baraja);
                if (nuevaCarta) {
                    std::cout << "Carta obtenida: " << nuevaCarta->toString() << std::endl;
                }
            }
            else if (opcion == "S" || opcion == "s") {
                std::cout << "El jugador decide pasar." << std::endl;
            }
            else {
                std::cout << "Opción no válida. Se asume pasar." << std::endl;
            }

            if (jugador->sePaso()) {
                std::cout << jugador->getNombre() << " se ha pasado de 21." << std::endl;
            }
            std::cout << std::endl;

            actual = actual->next;
        }

        // Turno del dealer
        std::cout << "Turno del dealer:" << std::endl;
        std::cout << "Mano: ";
        dealer.mostrarMano();
        std::cout << std::endl;

        while (dealer.debePedir()) {
            Carta* nuevaCarta = dealer.pedirCarta(&baraja);
            if (nuevaCarta) {
                std::cout << "Carta obtenida por el dealer: " << nuevaCarta->toString() << std::endl;
            }
        }

        if (dealer.sePaso()) {
            std::cout << "El dealer se ha pasado de 21." << std::endl;
        }

        // Determinar ganadores y mostrar resultados
        // ...

        // Preguntar si los jugadores quieren jugar otra ronda
        std::string respuesta;
        std::cout << "¿Quieres jugar otra ronda? (s/n): ";
        std::cin >> respuesta;
        if (respuesta != "s") {
            continuarJugando = false;
        }
    }

    std::cout << "¡Gracias por jugar al Blackjack!" << std::endl;
}
