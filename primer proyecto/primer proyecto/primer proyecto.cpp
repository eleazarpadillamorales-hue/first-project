#include <iostream>
#include "Cliente.h"
#include "Cancha.h"
#include "Reserva.h"
#include "RegistroEspera.h"
#include "ColeccionClientes.h"
#include "ColeccionCanchas.h"
#include "ColeccionReservas.h"
#include "SistemaGimnasio.h"
#include <cstdlib>

using namespace std;

// --- DECLARACIÓN DE MÓDULOS PRINCIPALES Y SUS CICLOS ---
void menuPrincipal();
void moduloCanchas();
void moduloClientes();
void moduloReservas();
void moduloListaEspera();
void moduloReportes();

int main() {
    menuPrincipal();
    return 0;
}

// =======================================================
// 0. MENÚ PRINCIPAL
// =======================================================
void menuPrincipal() {
    int opcion = 0;
    do {
        system("cls"); // Limpia la pantalla para mantener orden
        cout << "=======================================" << endl;
        cout << "      CENTRO DEPORTIVO ZONA ACTIVA     " << endl;
        cout << "=======================================" << endl;
        cout << "1. Gestion de canchas" << endl;
        cout << "2. Gestion de clientes" << endl;
        cout << "3. Gestion de reservas" << endl;
        cout << "4. Gestion de listado de espera" << endl;
        cout << "5. Reportes y estadisticas" << endl;
        cout << "6. Salir" << endl;
        cout << "=======================================" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: moduloCanchas(); break;
        case 2: moduloClientes(); break;
        case 3: moduloReservas(); break;
        case 4: moduloListaEspera(); break;
        case 5: moduloReportes(); break;
        case 6:
            cout << "\n[!] Saliendo del sistema... ¡Buen dia!" << endl;
            break;
        default:
            cout << "\n[!] Opcion invalida. Intente de nuevo." << endl;
            system("pause");
        }
    } while (opcion != 6);
}

// =======================================================
// 1. SUBMENÚ: GESTIÓN DE CANCHAS
// =======================================================
void moduloCanchas() {
    int opcion = 0;
    do {
        system("cls");
        cout << "--- SUBMENU: GESTION DE CANCHAS ---" << endl;
        cout << "1. Registrar una cancha" << endl;
        cout << "2. Mostrar todas las canchas" << endl;
        cout << "3. Buscar una cancha por codigo" << endl;
        cout << "4. Modificar el precio de una cancha" << endl;
        cout << "5. Mostrar la disponibilidad de una cancha" << endl;
        cout << "6. Volver al Menu Principal" << endl;
        cout << "-----------------------------------" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: cout << "\n[*] Ejecutando: Registrar cancha...\n"; system("pause"); break;
        case 2: cout << "\n[*] Ejecutando: Mostrar todas las canchas...\n"; system("pause"); break;
        case 3: cout << "\n[*] Ejecutando: Buscar cancha por codigo...\n"; system("pause"); break;
        case 4: cout << "\n[*] Ejecutando: Modificar precio...\n"; system("pause"); break;
        case 5: cout << "\n[*] Ejecutando: Mostrar disponibilidad (L/O/M)...\n"; system("pause"); break;
        case 6: break;
        default: cout << "\n[!] Opcion invalida.\n"; system("pause");
        }
    } while (opcion != 6);
}

// =======================================================
// 2. SUBMENÚ: GESTIÓN DE CLIENTES
// =======================================================
void moduloClientes() {
    int opcion = 0;
    do {
        system("cls");
        cout << "--- SUBMENU: GESTION DE CLIENTES ---" << endl;
        cout << "1. Registrar un cliente" << endl;
        cout << "2. Mostrar listado de clientes" << endl;
        cout << "3. Buscar un cliente por identificacion" << endl;
        cout << "4. Mostrar las reservas de un cliente especifico" << endl;
        cout << "5. Volver al Menu Principal" << endl;
        cout << "------------------------------------" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: cout << "\n[*] Ejecutando: Registrar cliente...\n"; system("pause"); break;
        case 2: cout << "\n[*] Ejecutando: Listar clientes...\n"; system("pause"); break;
        case 3: cout << "\n[*] Ejecutando: Buscar por ID...\n"; system("pause"); break;
        case 4: cout << "\n[*] Ejecutando: Ver reservas del cliente...\n"; system("pause"); break;
        case 5: break;
        default: cout << "\n[!] Opcion invalida.\n"; system("pause");
        }
    } while (opcion != 5);
}

// =======================================================
// 3. SUBMENÚ: GESTIÓN DE RESERVAS
// =======================================================
void moduloReservas() {
    int opcion = 0;
    do {
        system("cls");
        cout << "--- SUBMENU: GESTION DE RESERVAS ---" << endl;
        cout << "1. Registrar reserva (L -> O)" << endl;
        cout << "2. Mostrar todas las reservas" << endl;
        cout << "3. Buscar reserva por numero consecutivo" << endl;
        cout << "4. Mostrar reservas asociadas a una cancha" << endl;
        cout << "5. Cancelar una reserva (O -> L)" << endl;
        cout << "6. Volver al Menu Principal" << endl;
        cout << "------------------------------------" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: cout << "\n[*] Ejecutando: Registrar reserva...\n"; system("pause"); break;
        case 2: cout << "\n[*] Ejecutando: Mostrar todas las reservas...\n"; system("pause"); break;
        case 3: cout << "\n[*] Ejecutando: Buscar reserva...\n"; system("pause"); break;
        case 4: cout << "\n[*] Ejecutando: Ver reservas por cancha...\n"; system("pause"); break;
        case 5: cout << "\n[*] Ejecutando: Cancelar reserva...\n"; system("pause"); break;
        case 6: break;
        default: cout << "\n[!] Opcion invalida.\n"; system("pause");
        }
    } while (opcion != 6);
}

// =======================================================
// 4. SUBMENÚ: GESTIÓN DE LISTADO DE ESPERA
// =======================================================
void moduloListaEspera() {
    int opcion = 0;
    do {
        system("cls");
        cout << "--- SUBMENU: LISTADO DE ESPERA ---" << endl;
        cout << "1. Registrar un cliente en listado de espera" << endl;
        cout << "2. Mostrar el listado de espera" << endl;
        cout << "3. Cambiar estado (esperando/asignado/cancelado)" << endl;
        cout << "4. Volver al Menu Principal" << endl;
        cout << "----------------------------------" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: cout << "\n[*] Ejecutando: Registrar en lista de espera...\n"; system("pause"); break;
        case 2: cout << "\n[*] Ejecutando: Mostrar lista de espera...\n"; system("pause"); break;
        case 3: cout << "\n[*] Ejecutando: Cambiar estado del registro...\n"; system("pause"); break;
        case 4: break;
        default: cout << "\n[!] Opcion invalida.\n"; system("pause");
        }
    } while (opcion != 4);
}

// =======================================================
// 5. SUBMENÚ: REPORTES Y ESTADÍSTICAS
// =======================================================
void moduloReportes() {
    int opcion = 0;
    do {
        system("cls");
        cout << "--- SUBMENU: REPORTES Y ESTADISTICAS ---" << endl;
        cout << "1. Cancha con mayor cantidad de reservas activas" << endl;
        cout << "2. Cliente con mayor cantidad de reservas activas" << endl;
        cout << "3. Calcular el ingreso total generado" << endl;
        cout << "4. Mostrar el porcentaje de ocupacion de cada cancha" << endl;
        cout << "5. Mostrar las horas con mayor y menor cantidad de reservas" << endl;
        cout << "6. Volver al Menu Principal" << endl;
        cout << "----------------------------------------" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: cout << "\n[*] Generando: Detalle de cancha mas reservada...\n"; system("pause"); break;
        case 2: cout << "\n[*] Generando: Detalle de cliente mas frecuente...\n"; system("pause"); break;
        case 3: cout << "\n[*] Generando: Calculo totalizado de ingresos...\n"; system("pause"); break;
        case 4: cout << "\n[*] Generando: Porcentajes de uso por cancha...\n"; system("pause"); break;
        case 5: cout << "\n[*] Generando: Picos horarios (alta y baja demanda)...\n"; system("pause"); break;
        case 6: break;
        default: cout << "\n[!] Opcion invalida.\n"; system("pause");
        }
    } while (opcion != 6);
}
// primer proyecto.cpp : This file contains the 'main' function. Program execution begins and ends there.
/* acciones por hacer crear las siguientes cosas
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



