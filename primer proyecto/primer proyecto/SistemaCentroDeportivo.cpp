#include "SistemaCentroDeportivo.h"

SistemaCentroDeportivo::SistemaCentroDeportivo() {}
SistemaCentroDeportivo::~SistemaCentroDeportivo() {}

// Visualización y Auxiliares de Consola
void SistemaCentroDeportivo::limpiarConsola() const {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void SistemaCentroDeportivo::pausarConsola() const {
    cout << "\nPresione Enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

int SistemaCentroDeportivo::leerOpcionInt() {
    int opcion;
    while (!(cin >> opcion)) {
        cout << "Entrada invalida. Ingrese un numero: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return opcion;
}

double SistemaCentroDeportivo::leerDoublePositivo(string mensaje) {
    double valor;
    cout << mensaje;
    while (!(cin >> valor) || valor < 0) {
        cout << "Valor invalido. Ingrese un numero positivo: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return valor;
}

string SistemaCentroDeportivo::leerTexto(string mensaje) {
    string texto;
    cout << mensaje;
    cin >> texto;
    return texto;
}

// Bucle Principal
void SistemaCentroDeportivo::ejecutar() {
    int opcion = 0;
    do {
        limpiarConsola();
        cout << "========================================" << endl;
        cout << "     CENTRO DEPORTIVO ZONA ACTIVA       " << endl;
        cout << "========================================" << endl;
        cout << "1. Gestion de canchas" << endl;
        cout << "2. Gestion de clientes" << endl;
        cout << "3. Gestion de reservas" << endl;
        cout << "4. Gestion de listado de espera" << endl;
        cout << "5. Reportes y estadisticas" << endl;
        cout << "6. Salir" << endl;
        cout << "----------------------------------------" << endl;
        cout << "Seleccione una opcion: ";

        opcion = leerOpcionInt();

        switch (opcion) {
        case 1: menuGestionCanchas(); break;
        case 2: menuGestionClientes(); break;
        case 3: menuGestionReservas(); break;
        case 4: menuGestionEspera(); break;
        case 5: menuReportesEstadisticas(); break;
        case 6: cout << "\nSaliendo del sistema..." << endl; break;
        default: cout << "\nOpcion no valida. Intente de nuevo." << endl; pausarConsola(); break;
        }
    } while (opcion != 6);
}

// SUBMENÚ: GESTIÓN DE CANCHAS
void SistemaCentroDeportivo::menuGestionCanchas() {
    int opc = 0;
    do {
        limpiarConsola();
        cout << "=== GESTION DE CANCHAS ===" << endl;
        cout << "1. Registrar cancha" << endl;
        cout << "2. Mostrar todas las canchas" << endl;
        cout << "3. Buscar cancha por codigo" << endl;
        cout << "4. Modificar precio por hora" << endl;
        cout << "5. Mostrar disponibilidad de cancha" << endl;
        cout << "6. Colocar / Retirar mantenimiento" << endl;
        cout << "7. Volver al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        opc = leerOpcionInt();

        switch (opc) {
        case 1: registrarCancha(); break;
        case 2:
            limpiarConsola();
            canchas.listaCanchas();
            break;
        case 3: {
            string cod = leerTexto("Ingrese el codigo de la cancha: ");
            Cancha* c = canchas.buscarPorCodigo(cod);
            if (c != nullptr) c->mostrar();
            else cout << "Cancha no encontrada." << endl;
            break;
        }
        case 4: modificarPrecioCancha(); break;
        case 5: {
            string cod = leerTexto("Ingrese el codigo de la cancha: ");
            Cancha* c = canchas.buscarPorCodigo(cod);
            if (c != nullptr) c->mostrarDisponibilidad();
            else cout << "Cancha no encontrada." << endl;
            break;
        }
        case 6: gestionarMantenimientoCancha(); break;
        case 7: return;
        default: cout << "Opcion invalida." << endl; break;
        }
        pausarConsola();
    } while (opc != 7);
}

void SistemaCentroDeportivo::registrarCancha() {
    limpiarConsola();
    cout << "=== REGISTRAR CANCHA ===" << endl;
    string cod = leerTexto("Codigo (ej: C-01): ");
    string deporte = leerTexto("Tipo de deporte: ");
    double precio = leerDoublePositivo("Precio por hora: $");

    Cancha* nueva = new Cancha(cod, deporte, precio);
    if (!canchas.agregarCancha(nueva)) {
        delete nueva; // Liberar memoria en caso de error en registro
    }
    else {
        cout << "--> Cancha registrada exitosamente." << endl;
    }
}

void SistemaCentroDeportivo::modificarPrecioCancha() {
    string cod = leerTexto("Ingrese codigo de la cancha: ");
    Cancha* c = canchas.buscarPorCodigo(cod);
    if (c != nullptr) {
        double nuevoPrecio = leerDoublePositivo("Ingrese el nuevo precio por hora: $");
        c->setPrecioPorHora(nuevoPrecio);
        cout << "--> Precio actualizado correctamente." << endl;
    }
    else {
        cout << "Cancha no encontrada." << endl;
    }
}

void SistemaCentroDeportivo::gestionarMantenimientoCancha() {
    string cod = leerTexto("Ingrese codigo de la cancha: ");
    Cancha* c = canchas.buscarPorCodigo(cod);
    if (c != nullptr) {
        c->mostrarDisponibilidad();
        cout << "Ingrese la posicion de la franja (0-11): ";
        int franja = leerOpcionInt();
        cout << "Accion (1: Poner Mantenimiento 'M' | 2: Retirar 'M' -> 'L'): ";
        int accion = leerOpcionInt();

        if (accion == 1) {
            if (c->cambiarEstadoFranja(franja, 'M')) cout << "--> Franja colocada en mantenimiento." << endl;
        }
        else if (accion == 2) {
            if (c->cambiarEstadoFranja(franja, 'L')) cout << "--> Mantenimiento retirado. Franja Libre." << endl;
        }
        else {
            cout << "Accion no valida." << endl;
        }
    }
    else {
        cout << "Cancha no encontrada." << endl;
    }
}

// SUBMENÚ: GESTIÓN DE CLIENTES
void SistemaCentroDeportivo::menuGestionClientes() {
    int opc = 0;
    do {
        limpiarConsola();
        cout << "=== GESTION DE CLIENTES ===" << endl;
        cout << "1. Registrar cliente" << endl;
        cout << "2. Mostrar listado de clientes" << endl;
        cout << "3. Buscar cliente por identificacion" << endl;
        cout << "4. Mostrar reservas de un cliente" << endl;
        cout << "5. Volver al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        opc = leerOpcionInt();

        switch (opc) {
        case 1: registrarCliente(); break;
        case 2:
            limpiarConsola();
            clientes.listaClientes();
            break;
        case 3: {
            string id = leerTexto("Ingrese ID del cliente: ");
            Cliente* cl = clientes.buscarPorId(id);
            if (cl != nullptr) cl->mostrar();
            else cout << "Cliente no encontrado." << endl;
            break;
        }
        case 4: {
            string id = leerTexto("Ingrese ID del cliente: ");
            reservas.listarPorCliente(id);
            break;
        }
        case 5: return;
        default: cout << "Opcion invalida." << endl; break;
        }
        pausarConsola();
    } while (opc != 5);
}

void SistemaCentroDeportivo::registrarCliente() {
    limpiarConsola();
    cout << "=== REGISTRAR CLIENTE ===" << endl;
    string id = leerTexto("Identificacion/Cedula: ");
    string nombre = leerTexto("Nombre completo: ");
    string tel = leerTexto("Telefono: ");

    Cliente* nuevo = new Cliente(id, nombre, tel);
    if (!clientes.agregarCliente(nuevo)) {
        delete nuevo;
    }
    else {
        cout << "--> Cliente registrado exitosamente." << endl;
    }
}

// SUBMENÚ: GESTIÓN DE RESERVAS
void SistemaCentroDeportivo::menuGestionReservas() {
    int opc = 0;
    do {
        limpiarConsola();
        cout << "=== GESTION DE RESERVAS ===" << endl;
        cout << "1. Registrar reserva" << endl;
        cout << "2. Mostrar todas las reservas" << endl;
        cout << "3. Buscar reserva por numero" << endl;
        cout << "4. Mostrar reservas por cancha" << endl;
        cout << "5. Cancelar reserva" << endl;
        cout << "6. Volver al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        opc = leerOpcionInt();

        switch (opc) {
        case 1: registrarReserva(); break;
        case 2:
            limpiarConsola();
            reservas.listarTodas();
            break;
        case 3: {
            cout << "Ingrese el numero de reserva: ";
            int num = leerOpcionInt();
            Reserva* r = reservas.buscarPorNumero(num);
            if (r != nullptr) r->mostrarInformacion();
            else cout << "Reserva no encontrada." << endl;
            break;
        }
        case 4: {
            string cod = leerTexto("Ingrese codigo de la cancha: ");
            reservas.listarPorCancha(cod);
            break;
        }
        case 5: cancelarReserva(); break;
        case 6: return;
        default: cout << "Opcion invalida." << endl; break;
        }
        pausarConsola();
    } while (opc != 6);
}

void SistemaCentroDeportivo::registrarReserva() {
    limpiarConsola();
    cout << "=== REGISTRAR RESERVA ===" << endl;
    string idCl = leerTexto("Identificacion del Cliente: ");
    Cliente* cl = clientes.buscarPorId(idCl);
    if (cl == nullptr) {
        cout << "Error: Cliente no registrado." << endl;
        return;
    }

    string codCa = leerTexto("Codigo de la Cancha: ");
    Cancha* ca = canchas.buscarPorCodigo(codCa);
    if (ca == nullptr) {
        cout << "Error: Cancha no existente." << endl;
        return;
    }

    ca->mostrarDisponibilidad();
    cout << "Ingrese posicion de franja inicial (0 a 11): ";
    int fInicio = leerOpcionInt();
    cout << "Ingrese la cantidad de horas/franjas consecutivas: ";
    int cantFranjas = leerOpcionInt();

    // Validar limites de franjas
    if (fInicio < 0 || fInicio >= 12 || cantFranjas <= 0 || (fInicio + cantFranjas) > 12) {
        cout << "Error: Horario invalido o excede el limite diario (20:00)." << endl;
        return;
    }

    // Verificar si TODAS las franjas estan Libres 'L'
    for (int i = fInicio; i < fInicio + cantFranjas; i++) {
        if (ca->getEstadoFranja(i) != 'L') {
            cout << "Error: La franja [" << i << "] no esta disponible (Estado: " << ca->getEstadoFranja(i) << ")." << endl;
            if (ca->getEstadoFranja(i) == 'O') {
                cout << "¿Desea registrar al cliente en el Listado de Espera para esa franja? (1: Si | 0: No): ";
                int res = leerOpcionInt();
                if (res == 1) {
                    listaEspera.agregarEsperando(cl, ca, i);
                }
            }
            return;
        }
    }

    // Cambiar estados 'L' -> 'O'
    for (int i = fInicio; i < fInicio + cantFranjas; i++) {
        ca->cambiarEstadoFranja(i, 'O');
    }

    float monto = static_cast<float>(ca->getPrecioPorHora() * cantFranjas);
    Reserva* nuevaRes = new Reserva(cl, ca, fInicio, cantFranjas, monto);

    if (reservas.agregarReserva(nuevaRes)) {
        cout << "--> Reserva #" << nuevaRes->getIdReserva() << " registrada exitosamente!" << endl;
    }
    else {
        // Rollback franjas si se excede capacidad
        for (int i = fInicio; i < fInicio + cantFranjas; i++) {
            ca->cambiarEstadoFranja(i, 'L');
        }
        delete nuevaRes;
    }
}

void SistemaCentroDeportivo::cancelarReserva() {
    cout << "Ingrese el numero de reserva a cancelar: ";
    int num = leerOpcionInt();
    Reserva* r = reservas.buscarPorNumero(num);

    if (r == nullptr) {
        cout << "Error: Reserva no encontrada." << endl;
        return;
    }

    if (!r->isActiva()) {
        cout << "Atencion: Esta reserva ya se encontraba cancelada." << endl;
        return;
    }

    r->cancelar();
    Cancha* ca = r->getCancha();
    int fInicio = r->getFranjaInicial();
    int cant = r->getCantiladFranjas();

    // Liberar las franjas 'O' -> 'L'
    for (int i = fInicio; i < fInicio + cant; i++) {
        ca->cambiarEstadoFranja(i, 'L');
        // Notificar si existen clientes en espera para cada franja liberada
        listaEspera.avisarClientesEnEspera(ca->getCodigo(), i);
    }

    cout << "--> Reserva #" << num << " cancelada con exito y franjas liberadas." << endl;
}

// SUBMENÚ: LISTADO DE ESPERA
void SistemaCentroDeportivo::menuGestionEspera() {
    int opc = 0;
    do {
        limpiarConsola();
        cout << "=== GESTION DE LISTADO DE ESPERA ===" << endl;
        cout << "1. Registrar cliente en lista de espera" << endl;
        cout << "2. Mostrar listado de espera" << endl;
        cout << "3. Cambiar estado de espera" << endl;
        cout << "4. Volver al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        opc = leerOpcionInt();

        switch (opc) {
        case 1: registrarEnEspera(); break;
        case 2:
            limpiarConsola();
            listaEspera.mostrarLista();
            break;
        case 3: cambiarEstadoEspera(); break;
        case 4: return;
        default: cout << "Opcion invalida." << endl; break;
        }
        pausarConsola();
    } while (opc != 4);
}

void SistemaCentroDeportivo::registrarEnEspera() {
    limpiarConsola();
    string idCl = leerTexto("Identificacion del cliente: ");
    Cliente* cl = clientes.buscarPorId(idCl);
    if (cl == nullptr) { cout << "Cliente no registrado." << endl; return; }

    string codCa = leerTexto("Codigo de la cancha: ");
    Cancha* ca = canchas.buscarPorCodigo(codCa);
    if (ca == nullptr) { cout << "Cancha no encontrada." << endl; return; }

    cout << "Ingrese posicion de franja horaria ocupada (0-11): ";
    int f = leerOpcionInt();

    if (f < 0 || f >= 12) { cout << "Franja invalida." << endl; return; }

    if (ca->getEstadoFranja(f) != 'O') {
        cout << "Error: Solo se aceptan registros en espera cuando la franja esta OCUPADA ('O')." << endl;
        return;
    }

    listaEspera.agregarEsperando(cl, ca, f);
}

void SistemaCentroDeportivo::cambiarEstadoEspera() {
    cout << "Ingrese el consecutivo del registro de espera: ";
    int num = leerOpcionInt();
    RegistroEspera* e = listaEspera.buscarPorConsecutivo(num);

    if (e != nullptr) {
        cout << "Seleccione nuevo estado (1: Esperando | 2: Asignado | 3: Cancelado): ";
        int est = leerOpcionInt();
        if (est == 1) e->setEstado(EstadoEspera::ESPERANDO);
        else if (est == 2) e->setEstado(EstadoEspera::ASIGNADO);
        else if (est == 3) e->setEstado(EstadoEspera::CANCELADO);
        else { cout << "Estado invalido." << endl; return; }

        cout << "--> Estado actualizado correctamente." << endl;
    }
    else {
        cout << "Registro no encontrado." << endl;
    }
}

// SUBMENÚ: REPORTES Y ESTADÍSTICAS
void SistemaCentroDeportivo::menuReportesEstadisticas() {
    int opc = 0;
    do {
        limpiarConsola();
        cout << "=== REPORTES Y ESTADISTICAS ===" << endl;
        cout << "1. Cancha con mayor cantidad de reservas activas" << endl;
        cout << "2. Cliente con mayor cantidad de reservas activas" << endl;
        cout << "3. Ingreso total generado por reservas activas" << endl;
        cout << "4. Porcentaje de ocupacion de cada cancha" << endl;
        cout << "5. Horas con mayor y menor cantidad de reservas" << endl;
        cout << "6. Volver al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        opc = leerOpcionInt();

        switch (opc) {
        case 1: reporteCanchaMasReservada(); break;
        case 2: reporteClienteMasReservas(); break;
        case 3: reporteIngresoTotal(); break;
        case 4: reportePorcentajeOcupacionCanchas(); break;
        case 5: reporteHorasExtremasReservas(); break;
        case 6: return;
        default: cout << "Opcion invalida." << endl; break;
        }
        pausarConsola();
    } while (opc != 6);
}

void SistemaCentroDeportivo::reporteCanchaMasReservada() {
    limpiarConsola();
    cout << "=== CANCHA MAS RESERVADA (ACTIVAS) ===" << endl;
    if (canchas.getCantidad() == 0) { cout << "No hay canchas registradas." << endl; return; }

    Cancha* mayorCancha = nullptr;
    int maxReservas = -1;

    for (int i = 0; i < canchas.getCantidad(); i++) {
        Cancha* c = canchas.getCancha(i);
        int cont = 0;
        for (int j = 0; j < reservas.getCantidad(); j++) {
            Reserva* r = reservas.getReserva(j);
            if (r != nullptr && r->isActiva() && r->getCancha() == c) {
                cont++;
            }
        }
        if (cont > maxReservas) {
            maxReservas = cont;
            mayorCancha = c;
        }
    }

    if (mayorCancha != nullptr && maxReservas > 0) {
        cout << "Cancha mas reservada: " << mayorCancha->getCodigo() << " (" << mayorCancha->getTipoDeporte() << ")" << endl;
        cout << "Cantidad de reservas activas: " << maxReservas << endl;
    }
    else {
        cout << "No hay reservas activas registradas en las canchas." << endl;
    }
}

void SistemaCentroDeportivo::reporteClienteMasReservas() {
    limpiarConsola();
    cout << "=== CLIENTE CON MAS RESERVAS (ACTIVAS) ===" << endl;
    if (clientes.getCantidad() == 0) { cout << "No hay clientes registrados." << endl; return; }

    Cliente* mayorCliente = nullptr;
    int maxReservas = -1;

    for (int i = 0; i < clientes.getCantidad(); i++) {
        Cliente* cl = clientes.getCliente(i);
        int cont = 0;
        for (int j = 0; j < reservas.getCantidad(); j++) {
            Reserva* r = reservas.getReserva(j);
            if (r != nullptr && r->isActiva() && r->getCliente() == cl) {
                cont++;
            }
        }
        if (cont > maxReservas) {
            maxReservas = cont;
            mayorCliente = cl;
        }
    }

    if (mayorCliente != nullptr && maxReservas > 0) {
        cout << "Cliente con mayor reservas: " << mayorCliente->getNombre() << " (ID: " << mayorCliente->getId() << ")" << endl;
        cout << "Cantidad de reservas activas: " << maxReservas << endl;
    }
    else {
        cout << "No hay clientes con reservas activas actualmente." << endl;
    }
}

void SistemaCentroDeportivo::reporteIngresoTotal() {
    limpiarConsola();
    cout << "=== INGRESO TOTAL GENERADO (RESERVAS ACTIVAS) ===" << endl;
    double total = 0.0;
    int cont = 0;

    for (int i = 0; i < reservas.getCantidad(); i++) {
        Reserva* r = reservas.getReserva(i);
        if (r != nullptr && r->isActiva()) {
            total += r->getMonto();
            cont++;
        }
    }

    cout << "Reservas activas contabilizadas: " << cont << endl;
    cout << "Monto total acumulado: $" << total << endl;
}

void SistemaCentroDeportivo::reportePorcentajeOcupacionCanchas() {
    limpiarConsola();
    cout << "=== PORCENTAJE DE OCUPACION POR CANCHA ===" << endl;
    if (canchas.getCantidad() == 0) { cout << "No hay canchas registradas." << endl; return; }

    for (int i = 0; i < canchas.getCantidad(); i++) {
        Cancha* c = canchas.getCancha(i);
        if (c != nullptr) {
            cout << "Cancha [" << c->getCodigo() << "] - " << c->getTipoDeporte() << ": "
                << c->calcularPorcentajeOcupacion() << "% de ocupacion." << endl;
        }
    }
}

void SistemaCentroDeportivo::reporteHorasExtremasReservas() {
    limpiarConsola();
    cout << "=== HORAS CON MAYOR Y MENOR CANTIDAD DE RESERVAS ===" << endl;
    int conteoFranjas[12] = { 0 };

    // Contabilizar franjas reservadas
    for (int i = 0; i < reservas.getCantidad(); i++) {
        Reserva* r = reservas.getReserva(i);
        if (r != nullptr && r->isActiva()) {
            int inicio = r->getFranjaInicial();
            int cant = r->getCantiladFranjas();
            for (int k = inicio; k < inicio + cant; k++) {
                if (k >= 0 && k < 12) conteoFranjas[k]++;
            }
        }
    }

    int maxCount = -1, minCount = 99999;
    for (int i = 0; i < 12; i++) {
        if (conteoFranjas[i] > maxCount) maxCount = conteoFranjas[i];
        if (conteoFranjas[i] < minCount) minCount = conteoFranjas[i];
    }

    cout << "\nHoras con MAYOR demanda (" << maxCount << " reservas):" << endl;
    for (int i = 0; i < 12; i++) {
        if (conteoFranjas[i] == maxCount) {
            int h = 8 + i;
            cout << " -> " << (h < 10 ? "0" : "") << h << ":00 a " << (h + 1 < 10 ? "0" : "") << h + 1 << ":00" << endl;
        }
    }

    cout << "\nHoras con MENOR demanda (" << minCount << " reservas):" << endl;
    for (int i = 0; i < 12; i++) {
        if (conteoFranjas[i] == minCount) {
            int h = 8 + i;
            cout << " -> " << (h < 10 ? "0" : "") << h << ":00 a " << (h + 1 < 10 ? "0" : "") << h + 1 << ":00" << endl;
        }
    }
}
