#include "ColeccionReservas.h"

// Constructor: Inicializa los punteros en nullptr
ColeccionReservas::ColeccionReservas() {
    for (int i = 0; i < TAM_RESERVAS; i++) {
        this->reservas[i] = nullptr;
    }
    cantidad = 0;
}

// Destructor: Libera la memoria consumida por cada Reserva instanciada
ColeccionReservas::~ColeccionReservas() {
    for (int i = 0; i < cantidad; i++) {
        if (reservas[i] != nullptr) {
            delete reservas[i];
            reservas[i] = nullptr;
        }
    }
}

// Agrega una reserva apuntando al objeto creado
bool ColeccionReservas::agregarReserva(Reserva* nuevaReserva) {
    if (cantidad < TAM_RESERVAS && nuevaReserva != nullptr) {
        reservas[cantidad] = nuevaReserva;
        cantidad++;
        return true;
    }
    return false; // Arreglo lleno o reserva nula
}

// Busca una reserva por su número consecutivo único
Reserva* ColeccionReservas::buscarPorNumero(int numeroReserva) {
    for (int i = 0; i < cantidad; i++) {
        if (reservas[i] != nullptr && reservas[i]->getIdReserva() == numeroReserva) {
            return reservas[i];
        }
    }
    return nullptr; // No encontrada
}

// Muestra en consola todas las reservas registradas en el sistema
void ColeccionReservas::listarTodas() const {
    if (cantidad == 0) {
        cout << "No hay reservas registradas en el sistema." << endl;
        return;
    }

    cout << "\n=== LISTADO GENERAL DE RESERVAS (" << cantidad << ") ===" << endl;
    for (int i = 0; i < cantidad; i++) {
        if (reservas[i] != nullptr) {
            reservas[i]->mostrarInformacion();
        }
    }
}

// Muestra las reservas asociadas a un código de cancha específico
void ColeccionReservas::listarPorCancha(string codigoCancha) const {
    bool encontradas = false;
    cout << "\n=== RESERVAS PARA LA CANCHA " << codigoCancha << " ===" << endl;
    for (int i = 0; i < cantidad; i++) {
        if (reservas[i] != nullptr && reservas[i]->getCancha() != nullptr) {
            if (reservas[i]->getCancha()->getCodigo() == codigoCancha) {
                reservas[i]->mostrarInformacion();
                encontradas = true;
            }
        }
    }
    if (!encontradas) {
        cout << "No se encontraron reservas asociadas a esta cancha." << endl;
    }
}

// Muestra las reservas asociadas a la cédula/ID de un cliente
void ColeccionReservas::listarPorCliente(string idCliente) const {
    bool encontradas = false;
    cout << "\n=== RESERVAS DEL CLIENTE ID: " << idCliente << " ===" << endl;
    for (int i = 0; i < cantidad; i++) {
        if (reservas[i] != nullptr && reservas[i]->getCliente() != nullptr) {
            if (reservas[i]->getCliente()->getId() == idCliente) {
                reservas[i]->mostrarInformacion();
                encontradas = true;
            }
        }
    }
    if (!encontradas) {
        cout << "No se encontraron reservas asociadas a este cliente." << endl;
    }
}

int ColeccionReservas::getCantidad() const {
    return this->cantidad;
}

Reserva* ColeccionReservas::getReserva(int indice) const {
    if (indice >= 0 && indice < cantidad) {
        return reservas[indice];
    }
    return nullptr;
}
