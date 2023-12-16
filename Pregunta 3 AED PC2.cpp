#include <iostream>
#include <cctype>

using namespace std;

bool esVocal(char letra) {
    letra = tolower(letra);
    return (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u');
}

int contarVocales(const char* nombre) {
    int contador = 0;
    while (*nombre != '\0') {
        if (isalpha(*nombre) && esVocal(*nombre)) {
            contador++;
        }
        nombre++;
    }
    return contador;
}

int main() {
    char nombre[100];
    cout << "Ingrese su nombre: ";
    cin.getline(nombre, sizeof(nombre));

    int numVocales = contarVocales(nombre);
    cout << "El número de vocales en su nombre es: " << numVocales << endl;

    return 0;
}

