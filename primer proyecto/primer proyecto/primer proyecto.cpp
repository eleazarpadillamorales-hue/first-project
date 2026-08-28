#include <iostream>
#include "Cliente.h"
#include "Cancha.h"
#include "Reserva.h"
int main()
{
    std::cout << "Hello World!\n";
}
// primer proyecto.cpp : This file contains the 'main' function. Program execution begins and ends there.
/* acciones por hacer crear las siguientes cosas s
* classDiagram
    class Cliente {
        - string id                                                           Completado Pregunta deberia de pasarlo a numero??segun yo no porque puede que alguien 
        - string nombre                                                       Completado
        - string telefono                                                     Completado
        + Cliente()                                                           Completado
        + Cliente(string, string, string)                                     Completado
        + string getId()                                                      Completado
        + string getNombre()                                                  Completado
        + string getTelefono()                                                Completado
        + void setNombre(string)                                              Completado
        + void setTelefono(string)                                            Completado
    }

    class Cancha {
        - int codigo                                                          Completado
        - string tipoDeporte                                                  Completado
        - double precioPorHora                                                Completado
        - char franjasHorarias[12]                                            Completado
        + Cancha()                                                            Completado
        + Cancha(int, string, double)                                         Completado 
        + string getCodigo()                                                  Completado
        + string getTipoDeporte()                                             Completado
        + double getPrecioPorHora()                                           Completado
        + void setPrecioPorHora(double)                                       Completado   
        + char getEstadoFranja(int)                                           Completado
        + bool cambiarEstadoFranja(int, char)                                 Completado         
        + double calcularPorcentajeOcupacion()                                Completado          
    }

    class Reserva {
        - int numeroReserva
        - Cliente* cliente
        - Cancha* cancha
        - int franjaInicial
        - int cantidadFranjas
        - double montoTotal
        - bool activa
        + Reserva()
        + Reserva(int, Cliente*, Cancha*, int, int)
        + int getNumeroReserva()
        + Cliente* getCliente()
        + Cancha* getCancha()
        + int getFranjaInicial()
        + int getCantidadFranjas()
        + double getMontoTotal()
        + bool isActiva()
        + void cancelarReserva()
    }

    class RegistroEspera {
        - int numeroRegistro
        - Cliente* cliente
        - Cancha* cancha
        - int franjaHoraria
        - string estado
        + RegistroEspera()
        + RegistroEspera(int, Cliente*, Cancha*, int)
        + int getNumeroRegistro()
        + Cliente* getCliente()
        + Cancha* getCancha()
        + int getFranjaHoraria()
        + string getEstado()
        + void setEstado(string)
    }

    class ColeccionClientes {
        - Cliente** clientes
        - int cantidad
        - int capacidad
        + ColeccionClientes(int)
        + ~ColeccionClientes()
        + bool agregarCliente(Cliente*)
        + Cliente* buscarPorId(string)
        + void listarClientes()
    }

    class ColeccionCanchas {
        - Cancha** canchas
        - int cantidad
        - int capacidad
        + ColeccionCanchas(int)
        + ~ColeccionCanchas()
        + bool agregarCancha(Cancha*)
        + Cancha* buscarPorCodigo(string)
        + void listarCanchas()
    }

    class ColeccionReservas {
        - Reserva** reservas
        - int cantidad
        - int capacidad
        - int contadorSecuencial
        + ColeccionReservas(int)
        + ~ColeccionReservas()
        + Reserva* crearReserva(Cliente*, Cancha*, int, int)
        + Reserva* buscarPorNumero(int)
        + void mostrarReservasPorCliente(string)
        + void mostrarReservasPorCancha(string)
        + bool cancelarReserva(int, RegistroEspera** listadoEspera, int cantEspera)
        + double calcularIngresoTotal()
        + void reportarCanchaMasReservada()
        + void reportarClienteMasReservas()
        + void reportarHorasPico()
    }

    class SistemaGimnasio {
        - ColeccionClientes* clientes
        - ColeccionCanchas* canchas
        - ColeccionReservas* reservas
        - RegistroEspera** listadoEspera
        - int cantEspera
        - int capacidadEspera
        + SistemaGimnasio()
        + ~SistemaGimnasio()
        + void menuPrincipal()
        + void menuCanchas()
        + void menuClientes()
        + void menuReservas()
        + void menuEspera()
        + void menuReportes()
    }

    Reserva "0..*" --> "1" Cliente : asocia
    Reserva "0..*" --> "1" Cancha : asocia
    RegistroEspera "0..*" --> "1" Cliente : asocia
    RegistroEspera "0..*" --> "1" Cancha : asocia

    ColeccionClientes "1" o-- "0..100" Cliente : administra
    ColeccionCanchas "1" o-- "0..10" Cancha : administra
    ColeccionReservas "1" o-- "0..120" Reserva : administra

    SistemaGimnasio *-- "1" ColeccionClientes
    SistemaGimnasio *-- "1" ColeccionCanchas
    SistemaGimnasio *-- "1" ColeccionReservas
    SistemaGimnasio o-- "0..10" RegistroEspera




    el menu interactivo 
*/



