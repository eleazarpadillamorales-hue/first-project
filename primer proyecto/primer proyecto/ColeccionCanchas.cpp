#include "ColeccionCanchas.h"

// Constructor: Inicializa punteros en nullptr
ColeccionCanchas::ColeccionCanchas() {
    for (int i = 0; i < TOTAL_CANCHAS; i++) {
        this->canchas[i] = nullptr;
    }
    cantidad = 0;
}

// Destructor: Libera la memoria de cada objeto Cancha creado dinámicamente
ColeccionCanchas::~ColeccionCanchas() {
    for (int i = 0; i < cantidad; i++) {
        if (canchas[i] != nullptr) {
            delete canchas[i];
            canchas[i] = nullptr;
        }
    }
}

// Agrega una nueva cancha guardando su puntero
bool ColeccionCanchas::agregarCancha(Cancha* nuevaCancha) {
    if (cantidad < TOTAL_CANCHAS && nuevaCancha != nullptr) {
        // Validar que no exista cancha con el mismo código antes de agregar
        if (buscarPorCodigo(nuevaCancha->getCodigo()) != nullptr) {
            cout << "Error: Ya existe una cancha con el codigo " << nuevaCancha->getCodigo() << endl;
            return false;
        }
        canchas[cantidad] = nuevaCancha;
        cantidad++;
        return true;
    }
    cout << "Error: Se ha alcanzado el limite maximo de canchas (" << TOTAL_CANCHAS << ")." << endl;
    return false;
}

// Busca una cancha por su código y retorna el puntero original
Cancha* ColeccionCanchas::buscarPorCodigo(string codigo) {
    for (int i = 0; i < cantidad; i++) {
        if (canchas[i] != nullptr && canchas[i]->getCodigo() == codigo) {
            return canchas[i]; // Retorna el puntero real para modificar su estado/precio
        }
    }
    return nullptr; // No se encontró
}

// Muestra en consola la lista de canchas
void ColeccionCanchas::listaCanchas() const {
    if (cantidad == 0) {
        cout << "No hay canchas registradas en el sistema." << endl;
        return;
    }

    cout << "\n=== LISTADO DE CANCHAS (" << cantidad << " / " << TOTAL_CANCHAS << ") ===" << endl;
    for (int i = 0; i < cantidad; i++) {
        if (canchas[i] != nullptr) {
            canchas[i]->mostrar(); // Llama al método mostrar() de Cancha
            cout << "---------------------------------------" << endl;
        }
    }
}

int ColeccionCanchas::getCantidad() const {
    return this->cantidad;
}

Cancha* ColeccionCanchas::getCancha(int indice) const {
    if (indice >= 0 && indice < cantidad) {
        return canchas[indice];
    }
    return nullptr;
}
