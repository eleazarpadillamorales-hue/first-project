========================================================================
       UNIVERSIDAD NACIONAL - ESCUELA DE INFORMÁTICA (EIF-201)
            PROYECTO I: SISTEMA ZONA ACTIVA (II CICLO 2026)
========================================================================

DATOS DE LOS INTEGRANTES:
------------------------------------------------------------------------
Eleazar Daniel Padilla Morales 402300795 
Luis Andrés Segura Carballo 402320129
Carlos Luis Solís Alonso 208300381

DESCRIPCIÓN DEL PROYECTO:
------------------------------------------------------------------------
Aplicación de consola en C++ para la gestión de canchas, clientes, 
reservas, lista de espera y reportes del centro deportivo Zona Activa 
para una sola fecha de trabajo (12 franjas horarias de 08:00 a 20:00).

REQUISITOS TÉCNICOS Y ARQUITECTURA:
------------------------------------------------------------------------
- Lenguaje: C++
- Estructuras: Arreglos unidimensionales estáticos y de memoria dinámica.
- POO: Encapsulamiento, punteros, relaciones entre objetos y clases 
  colección personalizadas sin uso de la STL (std::vector, std::list, etc.).

ESTRUCTURA DE ARCHIVOS DE CÓDIGO FUENTE:
------------------------------------------------------------------------
- main.cpp                : Punto de entrada principal y control de menú.
- Cancha.h / .cpp         : Modela la información y franjas horarias (L, O, M).
- Cliente.h / .cpp        : Modela los datos de los clientes.
- Reserva.h / .cpp        : Modela la reserva vinculando Cliente y Cancha.
- ListaEspera.h / .cpp     : Modela los registros en lista de espera.
- ColeccionCanchas.h/.cpp : Administración dinámica/arreglos de canchas.
- ColeccionClientes.h/.cpp: Administración dinámica/arreglos de clientes.
- ColeccionReservas.h/.cpp: Administración dinámica/arreglos de reservas.
- ColeccionEspera.h/.cpp  : Administración del arreglo de lista de espera.
- Sistema.h / .cpp        : Coordinador de módulos y reportes estadísticos.

INSTRUCCIONES DE COMPILACIÓN Y EJECUCIÓN:
------------------------------------------------------------------------
1. Abrir el proyecto en el IDE correspondiente (p. ej. Visual Studio / CLion / Code::Blocks).
2. Asegurarse de incluir todos los archivos .h y .cpp en el target de compilación.
3. Compilar el proyecto utilizando C++11 o superior.
4. Ejecutar la aplicación de consola generada.

========================================================================
