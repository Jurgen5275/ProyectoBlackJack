#include "Juego.h"

Juego::Juego() {
    // Inicializar la baraja y el dealer
    baraja.inicializar();
    baraja.barajar();
    dealer = new Dealer();
}

Juego::~Juego() {
    // Limpiar la memoria del dealer
    delete dealer;
    // Limpiar la memoria de las cartas de los jugadores
    listaJugadores.limpiar();
}

void Juego::jugar() {
    std::cout << "¡Bienvenido al juego de Blackjack!\n" << std::endl;

    // Agregar jugadores
    int numJugadores;
    std::cout << "Ingrese el número de jugadores (máximo 7): ";
    std::cin >> numJugadores;
    if (numJugadores < 1 || numJugadores > 7) {
        std::cerr << "Número de jugadores no válido." << std::endl;
        return;
    }

    for (int i = 0; i < numJugadores; ++i) {
        std::string nombre;
        std::cout << "Ingrese el nombre del jugador " << i + 1 << ": ";
        std::cin >> nombre;
        Jugador* jugador = new Jugador(nombre);
        listaJugadores.insertar(jugador);
    }

    // Barajar la baraja
    baraja.barajar();

    // Repartir cartas a jugadores y dealer
    for (Nodo* nodo = listaJugadores.getInicio(); nodo != nullptr; nodo = nodo->getNext()) {
        Jugador* jugador = dynamic_cast<Jugador*>(nodo->getDato());
        if (jugador != nullptr) {
            jugador->pedirCarta(&baraja);
            jugador->pedirCarta(&baraja);
        }
    }
    dealer->pedirCarta(&baraja);
    dealer->pedirCarta(&baraja);
    dealer->volteaSegunda();

    // Juego de los jugadores
    for (Nodo* nodo = listaJugadores.getInicio(); nodo != nullptr; nodo = nodo->getNext()) {
        Jugador* jugador = dynamic_cast<Jugador*>(nodo->getDato());
        if (jugador != nullptr) {
            std::cout << "Turno de " << jugador->getNombre() << ":\n";
            Carta* nuevaCarta = jugador->pedirCarta(&baraja);
            char opcion = ' ';
            while (nuevaCarta != nullptr && opcion != 'P' && opcion != 'p') {
                std::cout << "Opciones:\n";
                std::cout << "(D)eme carta - (P)asar - (G)uardar Partida - (S)alir\n";
                std::cout << "Seleccione una opción: ";
                std::cin >> opcion;
                if (opcion == 'D' || opcion == 'd') {
                    nuevaCarta = jugador->pedirCarta(&baraja);
                }
            }
        }
    }

    // Juego del dealer
    std::cout << "Turno del dealer:\n";
    Carta* nuevaCarta = dealer->pedirCarta(&baraja);
    while (nuevaCarta != nullptr) {
        if (dealer->mano->getPuntos() < 16) {
            nuevaCarta = dealer->pedirCarta(&baraja);
        }
        else {
            break;
        }
    }

    // Comparar resultados y determinar ganador
    for (Nodo* nodo = listaJugadores.getInicio(); nodo != nullptr; nodo = nodo->getNext()) {
        Jugador* jugador = dynamic_cast<Jugador*>(nodo->getDato());
        if (jugador != nullptr && !jugador->sePaso()) {
            if (dealer->sePaso() || jugador->mano->getPuntos() > dealer->mano->getPuntos()) {
                std::cout << jugador->getNombre() << " gana!\n";
            }
            else if (jugador->mano->getPuntos() == dealer->mano->getPuntos()) {
                std::cout << "Empate entre " << jugador->getNombre() << " y el dealer.\n";
            }
            else {
                std::cout << jugador->getNombre() << " pierde.\n";
            }
        }
    }

    // Mostrar la carta oculta del dealer
    dealer->mano->getCarta(1)->Voltear();

    // Opciones al final del juego
    std::cout << "\nOpciones:\n";
    std::cout << "(G)uardar Partida - (S)alir\n";
    std::cout << "Seleccione una opción: ";
    char opcion;
    std::cin >> opcion;
    if (opcion == 'G' || opcion == 'g') {
        std::string nombreArchivo;
        std::cout << "Ingrese el nombre del archivo para guardar la partida: ";
        std::cin >> nombreArchivo;
        std::ofstream archivo(nombreArchivo);
        if (archivo.is_open()) {
            archivo << numJugadores << std::endl;
            for (Nodo* nodo = listaJugadores.getInicio(); nodo != nullptr; nodo = nodo->getNext()) {
                Jugador* jugador = dynamic_cast<Jugador*>(nodo->getDato());
                if (jugador != nullptr) {
                    archivo << jugador->getNombre() << std::endl;
                }
            }
            archivo.close();
            std::cout << "Partida guardada exitosamente." << std::endl;
        }
        else {
            std::cerr << "Error al abrir el archivo para guardar la partida." << std::endl;
        }
    }
    else if (opcion == 'S' || opcion == 's') {
        std::cout << "¡Hasta luego!\n";
    }
    else {
        std::cerr << "Opción no válida. Saliendo del juego.\n";
    }

    // Limpiar la memoria de los jugadores
    listaJugadores.limpiar();
}

void Juego::cargarPartida(std::string& nombreArchivo) {
    // Abrir el archivo para lectura
    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo de partida." << std::endl;
        return;
    }

    // Limpiar la lista de jugadores actual
    listaJugadores.limpiar();

    // Leer la cantidad de jugadores
    int cantidadJugadores;
    archivo >> cantidadJugadores;
    if (cantidadJugadores < 1 || cantidadJugadores > 6) {
        std::cerr << "Error: Cantidad de jugadores no válida." << std::endl;
        archivo.close();
        return;
    }

    // Leer los jugadores y sus manos desde el archivo
    std::string nombreJugador;
    for (int i = 0; i < cantidadJugadores; ++i) {
        archivo >> nombreJugador;
        Jugador* jugador = new Jugador(nombreJugador);
        listaJugadores.insertar(jugador);

        // Leer las cartas de la mano del jugador desde el archivo
        for (int j = 0; j < 2; ++j) {
            int valor, palo;
            archivo >> valor >> palo;
            Carta* carta = new Carta(valor, palo);
            jugador->mano->agregarCarta2(carta);
        }
    }

    // Crear el dealer
    dealer = new Dealer();

    // Leer las cartas del dealer desde el archivo
    for (int i = 0; i < 2; ++i) {
        int valor, palo;
        archivo >> valor >> palo;
        Carta* carta = new Carta(valor, palo);
        dealer->mano->agregarCarta2(carta);
    }

    // Cerrar el archivo
    archivo.close();

    // Continuar el juego desde donde se dejó
    jugar();
}