#include <iostream>
#include <locale.h>

using namespace std;

//Se crea el struct, Nodo 
// Donde se colocar� el valor tiene la lista enlazada, y el puntero con quien se enlaza
struct Nodo {
    int valor;
    Nodo* siguiente;
    //si fuera doblemente enlazada, se usar�a Nodo* anterior;

	// Aqu� podemos ver c�mo V es el valor que va a tomar en la lista 
	//Y s la siguiente posici�n (con punteros) 
    Nodo(int v, Nodo* s = nullptr) : valor(v), siguiente(s) {}
};

//Se crea la clase: ListaEnlazada
class ListaEnlazada {
private:
    Nodo* primero;

public:
    ListaEnlazada() : primero(nullptr) {}

	//Destructor
    ~ListaEnlazada() {
        while (primero != nullptr) {
            Nodo* temp = primero;
            primero = primero->siguiente;
            delete temp;
        }
    }
	
	//func que determina si la lista est� vac�a
    bool estaVacio() const {
        return primero == nullptr;
    }
	
	//Funci�n para agregar un nuevo elemento a la lista enlazada, al final
	//Siendo secuencial
	//Ingresa: 1 - Ingresa: 2 - Ingresa 3 - Lista Final: 1 2 3
    void agregarFinal(int valor) {
        Nodo* nuevo = new Nodo(valor);
        if (estaVacio()) {
            primero = nuevo;
        } else {
            Nodo* actual = primero;
            while (actual->siguiente != nullptr) {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevo;
        }
    }
	//Funci�n para mostrar los elementos de la lista enlazada 
    void mostrarLista() const {
        Nodo* actual = primero;
        while (actual != nullptr) {
        	//Se imprime llamando al valor
            cout << actual->valor << " ";
            //Se pasa a la sig pos, para imprimir todos los elementos
            actual = actual->siguiente;
        }
        cout << endl;
    }

	//Funci�n para borrar un elemento de la lista enlazada
    void borrarLista() {
        while (primero != nullptr) {
            Nodo* temp = primero;
            primero = primero->siguiente;
            delete temp;
        }
    }

	//Funci�n para invertir el orden de los elementos de la lista enlazada 
	
	// nueva_posici�n = antigua_posici�n
    void invertirLista() {
        Nodo* previo = nullptr;
        Nodo* actual = primero;
        Nodo* siguiente = nullptr;
		
		//mientras actual sea distinto de null
        while (actual != nullptr) {
            siguiente = actual->siguiente;
            actual->siguiente = previo;
            previo = actual;
            actual = siguiente;
        }

        primero = previo;
    }
};

//Se usa para evitar errores al ingresar un caracter, cuando es un n�mero
int obtenerEntero() {
    string x;
    while (true) {
        

        bool esEntero = true;
        for (char c : x) {
        	//el famoso, is digit
            if (!isdigit(c)) {
                esEntero = false;
                break;
            }
        }
    }
}

int main() {
	
	//Mostrar tildes, y caracteres especiales en consola 
	setlocale(LC_ALL, "");

	//Se crea un objeto de la clase: ListaEnlazada
    ListaEnlazada lista;

    int opcion;
    do { //se muestra el men� con todas las opciones 1-7
        cout << "------ Men� ------" << endl;
        cout << "1. Mostrar lista" << endl;
        cout << "2. Verificar si la lista esta vac�a" << endl;
        cout << "3. Agregar elemento al final de la lista" << endl;
        cout << "4. Borrar la lista completa" << endl;
        cout << "5. Crear lista por defecto (1-8)" << endl;
        cout << "6. Invertir la lista" << endl;
        cout << "7. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

		//de acuerdo al n�mero ingresado, se va al conditional switch case n
		
        switch (opcion) {
            case 1:
            	//Imprime la lista de elementos
				// En caso no hubiera elementos saldr�a c�mo: Lista:        *vac�o*
                cout << "Lista: ";
                lista.mostrarLista();
                
                //realizar una pausa para que se muestre lo impreso en pantalla
                system("pause");
                //se limpia la consola
                system("cls");
                
                break;
            case 2:
            	//Te dice si la lista est�, o no est� vac�a 
                cout << (lista.estaVacio() ? "La lista esta vacia" : "La lista no esta vacia") << endl;
                system("pause");
                system("cls");
				break;
            case 3:
                int valor;
                //Se ingresa un valor para ingresarlo al final de la lista
                
                
                cout << "Ingrese un valor: ";
                cin >> valor;
                lista.agregarFinal(valor);
                
                cout << "Elemento agregado al final de la lista." << endl;
                
                system("pause");
                system("cls");
				break;
            case 4:
                lista.borrarLista();
                //Se borra toda la lista, por completo 
                cout << "Lista borrada." << endl;
                system("pause");
                system("cls");
				break;
            case 5:
            	//Se agregan valores por defecto directamente a la lista 
                lista.borrarLista();
                lista.agregarFinal(1);
                lista.agregarFinal(2);
                lista.agregarFinal(3);
                lista.agregarFinal(4);
                lista.agregarFinal(5);
                lista.agregarFinal(6);
                lista.agregarFinal(7);
                lista.agregarFinal(8);
                //Estos valores sobreeescriben a los que ya exist�an all�
                cout << "Lista creada por defecto. " << endl;
                system("pause");
                system("cls");
				break;
            case 6:
                lista.invertirLista();
                //Llamando a la funci�n, se invierte la lista
                cout << "Lista invertida." << endl;
                system("pause");
                system("cls");
				break;
            case 7:
            	//Se sale del programa
                cout << "Saliendo del programa." << endl;
                system("pause");
                system("cls");
				break;
            default:
            	//En el caso que se ingrese un n�mero distinto a 1-7, se volver� al men�
                cout << "Opci�n inv�lida. Intente nuevamente." << endl;
                system("pause");
                system("cls");
                main();
				break;
        }
    } while (opcion != 7);

    return 0;
}

