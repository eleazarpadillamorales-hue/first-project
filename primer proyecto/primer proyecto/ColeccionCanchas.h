#pragma once
#include <iostream>
#include <string>
#include "Cancha.h"

using namespace std;

//máximo de 10 canchas
const int TOTAL_CANCHAS = 10;

class ColeccionCanchas {
private:
    Cancha* canchas[TOTAL_CANCHAS];
    int cantidad;

public:
    ColeccionCanchas();
    ~ColeccionCanchas();

    // Métodos de gestión
    bool agregarCancha(Cancha* nuevaCancha);
    Cancha* buscarPorCodigo(string codigo); 
    // Retorna puntero para permitir modificaciones reales

    // Muestra y consultas
    void listaCanchas() const;
    int getCantidad() const;
    Cancha* getCancha(int indice) const; 
};
