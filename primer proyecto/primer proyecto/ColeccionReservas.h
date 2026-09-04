#pragma once
#include <iostream>
#include <string>
#include "Cliente.h"

using namespace std;
const int tam = 10; // tam = tamaño

class ColeccionReservas{
private:
    // Atributos privados
    Cliente* clientes[tam];
    int cantidad;
public:
    // Constructor por con parametros no se hace el por defecto porque no existe 
    ColeccionReservas();
    //Destructor
    ~ColeccionReservas();
    // metodos gettters y setters para esta clase
    void agregarCliente(Cliente Cliente);
    Cliente* buscarPorId(string id);
    //metodo para mostrar
    void listaClientes();
    int getCantidad();
};