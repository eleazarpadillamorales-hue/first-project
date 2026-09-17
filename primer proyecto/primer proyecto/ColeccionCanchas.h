#pragma once
#include <iostream>
#include <string>
#include"Cancha.h"

using namespace std;
const int totalCanchas = 10;

class ColeccionCanchas{
private:
    // Atributos privados
    Cancha* canchas[totalCanchas];
    int cantidad;
public:
    // Constructor por con parametros no se hace el por defecto porque no existe 
    ColeccionCanchas();
    //Destructor
    ~ColeccionCanchas();
    // metodos gettters y setters para esta clase
    void agregarCancha(Cancha cancha);
    Cancha buscarPorCodigo(int codigo);
    //metodo para mostrar
    void listaCanchas() const;
    int getCantidad() const;
};

