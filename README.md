========================================================================
       UNIVERSIDAD NACIONAL - ESCUELA DE INFORMÁTICA (EIF-201)
            PROYECTO I: SISTEMA ZONA ACTIVA (II CICLO 2026)
========================================================================

DATOS DE LOS INTEGRANTES:
------------------------------------------------------------------------
Eleazar Daniel Padilla Morales  402300795 
Luis Andrés Segura Carballo     402320129
Carlos Luis Solís Alonso        208300381

DESCRIPCIÓN DEL PROYECTO:
------------------------------------------------------------------------
Aplicación de consola en C++ orientada a objetos para la gestión integral 
de canchas, clientes, reservas, listado de espera y reportes del centro 
deportivo "Zona Activa" para una jornada diaria de 12 franjas horarias 
(08:00 a 20:00).

REQUISITOS TÉCNICOS Y ARQUITECTURA:
------------------------------------------------------------------------
- Lenguaje: C++ (Estándar C++11 o superior).
- Estructuras de Datos: Arreglos unidimensionales estáticos y de memoria 
  dinámica mediante punteros.
- Paradigma POO: Encapsulamiento, manejo dinámico de memoria (new/delete), 
  relaciones de composición y asociación sin el uso de librerías STL 
  (std::vector, std::list, etc.).

ESTRUCTURA DE ARCHIVOS DEL CÓDIGO FUENTE:
------------------------------------------------------------------------
- main.cpp                     : Punto de entrada principal e inicializador del sistema.
- Cancha.h / .cpp              : Entidad que modela la cancha y las 12 franjas horarias (L, O, M).
- Cliente.h / .cpp             : Entidad que almacena los datos personales del cliente.
- Reserva.h / .cpp             : Entidad que vincula a un Cliente y una Cancha en un horario.
- RegistroEspera.h / .cpp      : Entidad para solicitudes de espera en franjas ocupadas.
- ColeccionCanchas.h / .cpp    : Gestión dinámica del arreglo de canchas (Capacidad: 10).
- ColeccionClientes.h / .cpp   : Gestión dinámica del arreglo de clientes (Capacidad: 100).
- ColeccionReservas.h / .cpp   : Gestión dinámica del arreglo de reservas (Capacidad: 120).
- ColeccionEspera.h / .cpp     : Gestión dinámica del arreglo de lista de espera (Capacidad: 100).
- SistemaCentroDeportivo.h/.cpp: Controlador principal, gestión de submenús y módulo de reportes.

INSTRUCCIONES DE COMPILACIÓN Y EJECUCIÓN:
------------------------------------------------------------------------
1. Abrir el proyecto en el IDE de preferencia (Visual Studio, CLion, Code::Blocks, etc.).
2. Asegurarse de incluir todos los archivos .h y .cpp en el target de compilación.
3. Compilar el proyecto utilizando C++11 o superior.
   Comando g++ de consola:
   g++ -std=c++11 main.cpp Cancha.cpp Cliente.cpp Reserva.cpp RegistroEspera.cpp ColeccionCanchas.cpp ColeccionClientes.cpp ColeccionReservas.cpp ColeccionEspera.cpp SistemaCentroDeportivo.cpp -o ZonaActiva
4. Ejecutar el ejecutable generado (`./ZonaActiva` o `ZonaActiva.exe`).

========================================================================
