#pragma once
#include <iostream>
#include <string>

using namespace std;

class Cancha {
private:
    // Atributos privados
    int codigo;
    string tipoDeporte;
    double precioPorHora;
    char franjasHorarias[12]; // Representa 12 horas del día chambeando

public:
    // Constructor por defecto
    Cancha();
    // Constructor con parámetros
    Cancha(int codigo, string tipoDeporte, double precioPorHora);
    // Destructor
    ~Cancha();
    // Métodos Getters
    int getCodigo();
    string getTipoDeporte();
    double getPrecioPorHora();
    // Métodos Setters
    void setPrecioPorHora(double precioPorHora);
    // Obtener el estado de una franja específica (índice 0 a 11)
    char getEstadoFranja(int indice);
    // Cambiar el estado de una franja (ej: 'L' por Libre, 'O' por Ocupada)
    bool cambiarEstadoFranja(int indice, char nuevoEstado);
    // Calcula el porcentaje de franjas que NO están libres ('L')
    double calcularPorcentajeOcupacion();
};
