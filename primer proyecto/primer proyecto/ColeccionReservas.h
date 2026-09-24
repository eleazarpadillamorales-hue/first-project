#pragma once
#include <iostream>
#include <string>
#include "Reserva.h"

using namespace std;

//máximo de 120 reservas
const int TAM_RESERVAS = 120;

class ColeccionReservas {
private:
    Reserva* reservas[TAM_RESERVAS];
    int cantidad;

public:
    ColeccionReservas();
    ~ColeccionReservas();

    // Métodos de gestión
    bool agregarReserva(Reserva* nuevaReserva);
    Reserva* buscarPorNumero(int numeroReserva);

    // Consultas
    void listarTodas() const;
    void listarPorCancha(string codigoCancha) const;
    void listarPorCliente(string idCliente) const;

    // Métodos utilitarios y reportes
    int getCantidad() const;
    Reserva* getReserva(int indice) const;
};
