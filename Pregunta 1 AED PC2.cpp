#include <iostream>
#include <cctype>
#include <locale.h>

using namespace std;

// Creamos la estructura trabajador (nombre, sexo, categoría(a,b,c), sueldo)
struct Trabajador {
    string nombre;
    char sexo;
    char categoria;
    double sueldo;
};

//Función para ingresar todos los atributos del trabajador 

void ingresarTrabajador(Trabajador& trabajador) {
    cout << "Ingrese el nombre del trabajador: ";
    cin >> trabajador.nombre; //se les puede llamar cómo si fueran objetos

    cout << "Ingrese el sexo del empleado (M/F): ";
    cin >> trabajador.sexo;//se les puede llamar cómo si fueran objetos

    cout << "Ingrese la categoría del empleado (a/b/c): ";
    cin >> trabajador.categoria;//se les puede llamar cómo si fueran objetos

    cout << "Ingrese el sueldo del empleado: ";
    cin >> trabajador.sueldo;//Este es poder de struct
}

// Para "validar los datos" y que no pueda romperse nuestro código usamos isdigit
bool esNumero(const string& str) {
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

int main() {
	
	//Mostrar tildes, y caracteres especiales en consola 
	setlocale(LC_ALL, "");
    
	//Aquí se menciona la cantidad de veces que se repetirá el pedido de datos
	//Al ingresar la cantidad de trabajadores
    int n;
    cout << "Ingrese la cantidad de trabajadores: ";
    cin >> n;
	//Se crea el array Trabajador [n] con N valores (N se ingresa arriba)
    Trabajador* trabajador = new Trabajador[n];

	//Se crea un bucle por la cantidad de veces que se repetirá 
    for (int i = 0; i < n; i++) {
        cout << "\nIngrese los datos del empleado N°" << i + 1 << ":" << endl;
        ingresarTrabajador(trabajador[i]);
    }

    // Buscar empleado con mayor y menor salario
    //Con estos se comparará dentro de los condicionales para determinar mayor y menor
    int indiceMayorSalario = 0;
    int indiceMenorSalario = 0;
    for (int i = 1; i < n; i++) {
        if (trabajador[i].sueldo > trabajador[indiceMayorSalario].sueldo) {
            indiceMayorSalario = i;
        }
        if (trabajador[i].sueldo < trabajador[indiceMenorSalario].sueldo) {
            indiceMenorSalario = i;
        }
    }

    // Imprimir todos los datos del empleado con mayor salario, el más pudiente
    cout << "\nTrabajador con mayor salario:" << endl;
    cout << "Nombre: " << trabajador[indiceMayorSalario].nombre << endl;
    cout << "Sexo: " << trabajador[indiceMayorSalario].sexo << endl;
    cout << "Categoría: " << trabajador[indiceMayorSalario].categoria << endl;
    cout << "Sueldo: " << trabajador[indiceMayorSalario].sueldo << endl;

    // Imprimir todos los datos del empleado con menor salario :( ójala le den un aumento
    cout << "\nTrabajador con menor salario:" << endl;
    cout << "Nombre: " << trabajador[indiceMenorSalario].nombre << endl;
    cout << "Sexo: " << trabajador[indiceMenorSalario].sexo << endl;
    cout << "Categoría: " << trabajador[indiceMenorSalario].categoria << endl;
    cout << "Sueldo: " << trabajador[indiceMenorSalario].sueldo << endl;

	//una vez impresos los datos, se usa delete para la liberación de memoria 

    delete[] trabajador;

    return 0;
}

