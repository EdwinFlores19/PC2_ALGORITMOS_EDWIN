#include <iostream>
#include <cctype>

using namespace std;

//Tiempo de cada etapa del ciclista 
struct Tiempo {
    int horas;
    int minutos;
    int segundos;
};

bool esNumero(const string& input) {
    for (char c : input) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

int obtenerEntero(const string& mensaje) {
    string input;
    cout << mensaje;
    cin >> input;
    while (!esNumero(input)) {
        cout << "Error: ingrese un valor numérico. " << mensaje;
        cin >> input;
    }
    return stoi(input);
}

Tiempo obtenerTiempo() {
    Tiempo tiempo;
    tiempo.horas = obtenerEntero("Ingrese las horas: ");
    tiempo.minutos = obtenerEntero("Ingrese los minutos: ");
    tiempo.segundos = obtenerEntero("Ingrese los segundos: ");
    return tiempo;
}

Tiempo sumarTiempos(const Tiempo& tiempo1, const Tiempo& tiempo2) {
    Tiempo resultado;
    resultado.horas = tiempo1.horas + tiempo2.horas;
    resultado.minutos = tiempo1.minutos + tiempo2.minutos;
    resultado.segundos = tiempo1.segundos + tiempo2.segundos;

    if (resultado.segundos >= 60) {
        resultado.minutos += resultado.segundos / 60;
        resultado.segundos %= 60;
    }
    if (resultado.minutos >= 60) {
        resultado.horas += resultado.minutos / 60;
        resultado.minutos %= 60;
    }

    return resultado;
}

void imprimirTiempo(const Tiempo& tiempo) {
    cout << "Tiempo: " << tiempo.horas << " horas, " << tiempo.minutos << " minutos, " << tiempo.segundos << " segundos" << endl;
}

int main() {
    Tiempo tiempoTotal;
    tiempoTotal.horas = 0;
    tiempoTotal.minutos = 0;
    tiempoTotal.segundos = 0;

    for (int i = 1; i <= 3; i++) {
        cout << "=== Etapa " << i << " ===" << endl;
        Tiempo tiempoEtapa = obtenerTiempo();
        tiempoTotal = sumarTiempos(tiempoTotal, tiempoEtapa);
        cout << "Tiempo de la etapa " << i << " registrado correctamente." << endl;
        cout << endl;
    }

    cout << "=== Tiempo Total ===" << endl;
    imprimirTiempo(tiempoTotal);

    return 0;
}

