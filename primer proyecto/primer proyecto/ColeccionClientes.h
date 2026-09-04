#pragma once
#include <iostream>
#include <string>
#include "Cliente.h"

using namespace std;
const int capacidad = 100;

class ColeccionClientes{
private:
    // Atributos privados
    Cliente* clientes[capacidad];
    int cantidad;   
public:
    // Constructor por con parametros no se hace el por defecto porque no existe 
    ColeccionClientes();
    //Destructor
    ~ColeccionClientes();
    // metodos gettters y setters para esta clase
    void agregarCliente(Cliente Cliente);
    Cliente buscarPorId(string id);
    //metodo para mostrar
    void listaClientes();
    int getCantidad();
};

