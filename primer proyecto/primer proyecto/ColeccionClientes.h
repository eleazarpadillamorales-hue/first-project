#pragma once
#include <iostream>
#include <string>
#include "Cliente.h"

using namespace std;

// El enunciado establece un máximo de 100 clientes
const int CAPACIDAD_CLIENTES = 100;

class ColeccionClientes {
private:
    Cliente* clientes[CAPACIDAD_CLIENTES];
    int cantidad;

public:
    ColeccionClientes();
    ~ColeccionClientes();

    // Métodos de gestión de clientes
    bool agregarCliente(Cliente* clientePtr);
    Cliente* buscarPorId(string id) const;

    // Métodos de visualización y consulta
    void listaClientes() const;
    int getCantidad() const;
    Cliente* getCliente(int indice) const;
};
