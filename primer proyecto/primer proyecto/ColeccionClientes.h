#pragma once
#include <iostream>
#include <string>
#include "Cliente.h"

using namespace std;

class ColeccionClientes{
private:
    // Atributos privados
    Cliente** clientes{};
    int cantidad{};
    int capacidad{};
public:
    // Constructor por con parametros no se hace el por defecto porque no existe 
    ColeccionClientes(int capacidad= 100 ) {};
    //Destructor
    ~ColeccionClientes() {};
    // metodos gettters y setters para esta clase
    bool agregarCliente(Cliente* Cliente) {};
    Cliente * buscarPorId(string id) {};
    //metodo para mostrar
    void listarClientes() {};
    int getCantidad() {};
    int getCapacidad() {};

};

