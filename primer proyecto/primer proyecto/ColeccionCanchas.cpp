#include"ColeccionCanchas.h"

// Constructor: Reserva espacio para el arreglo dinámico de punteros
ColeccionCanchas::ColeccionCanchas() {
    // Inicialización de punteros en nullptr por seguridad
    for (int i = 0; i < totalCanchas; i++) {
        this->canchas[i] = nullptr;
    }
    cantidad = 0;
}

// Destructor: Libera la memoria consumida por los objetos y el arreglo
ColeccionCanchas::~ColeccionCanchas() {
    for (int i = 0; i < totalCanchas; i++) {
        delete canchas[i]; // Borra el objeto Cliente individual
        canchas[i] = nullptr;
    }
}

void ColeccionCanchas::agregarCancha(Cancha cancha) {
    if (cantidad < totalCanchas) {
        canchas[cantidad] = new Cancha(cancha);
        cantidad++;
    }
}

// Busca un cliente por su número de identificación
Cancha ColeccionCanchas::buscarPorCodigo(int codigo) {
    for (int i = 0; i < cantidad; i++) {
        if (canchas[i]->getCodigo() == codigo) {
            return *(canchas[i]);
        }
    }
    //return *(nullptr; // No se encontró el cliente
}

// Muestra en consola la lista de clientes registrados
void ColeccionCanchas::listaCanchas() const{
    cout << "Cantidad de canchas: " << cantidad << endl;
    for (int i = 0;i < cantidad;i++) {
        canchas[i]->mostrar();
        cout << endl;
    }
}

int ColeccionCanchas::getCantidad() const {
    return this->cantidad;
}
