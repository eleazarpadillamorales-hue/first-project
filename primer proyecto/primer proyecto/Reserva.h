#pragma once
#include <iostream>
#include <string>
#include"Cancha.h"
#include"Cliente.h"
#include"ColeccionCanchas.h"
#include"ColeccionClientes.h"

using namespace std;

class Reserva
{
private:
	int numeroReserva;
	Cliente* cliente;
	Cancha* cancha;
	float monto;
	bool activa;

public:
    Reserva();
    Reserva(Cliente* clientePtr, Cancha* canchaPtr, float monto);

    // Getters
    int getIdReserva() const;
    Cliente* getCliente() const;
    Cancha* getCancha() const;
    float getMonto() const;
    bool isActiva() const;
    void cancelar();
    void mostrarInformacion() const;
};

