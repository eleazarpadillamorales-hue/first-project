#include "ColeccionClientes.h"

// Constructor: Inicializa los punteros en nullptr por seguridad
ColeccionClientes::ColeccionClientes() {
    for (int i = 0; i < CAPACIDAD_CLIENTES; i++) {
        this->clientes[i] = nullptr;
    }
    cantidad = 0;
}

// Destructor: Libera la memoria consumida por cada objeto Cliente
ColeccionClientes::~ColeccionClientes() {
    for (int i = 0; i < cantidad; i++) {
        if (clientes[i] != nullptr) {
            delete clientes[i];
            clientes[i] = nullptr;
        }
    }
}

// Agrega un cliente verificando capacidad y evitando duplicados de ID
bool ColeccionClientes::agregarCliente(Cliente* clientePtr) {
    if (clientePtr == nullptr) {
        return false;
    }

    if (cantidad >= CAPACIDAD_CLIENTES) {
        cout << "Error: Se ha alcanzado el limite maximo de clientes (" << CAPACIDAD_CLIENTES << ")." << endl;
        return false;
    }

    // Validar que no exista un cliente con la misma identificación
    if (buscarPorId(clientePtr->getId()) != nullptr) {
        cout << "Error: Ya existe un cliente registrado con la identificacion " << clientePtr->getId() << endl;
        return false;
    }

    clientes[cantidad] = clientePtr;
    cantidad++;
    return true;
}

// Busca un cliente por su número de identificación y retorna su puntero
Cliente* ColeccionClientes::buscarPorId(string id) const {
    for (int i = 0; i < cantidad; i++) {
        if (clientes[i] != nullptr && clientes[i]->getId() == id) {
            return clientes[i];
        }
    }
    return nullptr; // No se encontró
}

// Muestra en consola la lista general de clientes
void ColeccionClientes::listaClientes() const {
    if (cantidad == 0) {
        cout << "No hay clientes registrados en el sistema." << endl;
        return;
    }

    cout << "\n=== LISTADO DE CLIENTES (" << cantidad << " / " << CAPACIDAD_CLIENTES << ") ===" << endl;
    for (int i = 0; i < cantidad; i++) {
        if (clientes[i] != nullptr) {
            clientes[i]->mostrar();
            cout << "---------------------------------------" << endl;
        }
    }
}

int ColeccionClientes::getCantidad() const {
    return this->cantidad;
}

Cliente* ColeccionClientes::getCliente(int indice) const {
    if (indice >= 0 && indice < cantidad) {
        return clientes[indice];
    }
    return nullptr;
}
