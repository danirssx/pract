#include <iostream>
using namespace std;

// Operaciones básicas

struct Pila {
    int dato;
    Pila *next;
};

Pila *crearPila(int valor) {
    Pila *nuevo = new Pila;

    if(nuevo) {
        nuevo->dato = valor;
        nuevo->next = NULL;
    }

    return nuevo;

};

bool PilaVacia(Pila *pila) {
    return pila == NULL;

};

int Tope(Pila *pila) {
    if(!PilaVacia(pila)) {
        return pila->dato;
    } else {
        return -111;
    }
};

// Agregar y alterar la pila

Pila* Apilar(Pila **pila, int valor) {
    Pila *nuevo = crearPila(valor);
    nuevo->next = *pila;
    *pila = nuevo;
    
    return nuevo;
};

Pila* Desapilar(Pila **pila) {
    int adn;

    if (!PilaVacia(*pila)) {
        *pila = (*pila)->next;
    } else {
        cout << "Pila vacia imposible de desapilar" << endl;
    }

    return *pila;
};

// Lectura de la pila

void mostrarPila (Pila *pila) {
    while (!PilaVacia(pila)) {
        cout << Tope(pila) << " ";
        Desapilar(&pila);
    }
};

// Ejercicios
// 
// 1.1

Pila* aggFondo(Pila **pila, int valor) {
    Pila *actual = *pila;
    Pila *auxPila = NULL;

    // Desenredar pila actual

    while(!PilaVacia(actual)) {
        auxPila = Apilar(&auxPila, actual->dato);
        actual = Desapilar(&actual);
    };

    Apilar(&actual, valor);

    // Volver a aclopar

    while(!PilaVacia(auxPila)) {
        actual = Apilar(&actual, auxPila->dato);
        auxPila = Desapilar(&auxPila);
    };

    return actual;
}

Pila* mezclarPilas(Pila **pila1, Pila **pila2) {
    Pila *aux1 = *pila1;
    Pila *aux2 = *pila2;
    Pila *temporal = NULL;
    Pila *nuevaPila = NULL;

    int elemento1, elemento2, auxelemento, adn;

    if (PilaVacia(aux1) || PilaVacia(aux2)) { // En caso de que la pila este vacia
        return 0;
    } else {
        while(!PilaVacia(aux1)) {

            elemento1 = Tope(aux1);
            aux1 = Desapilar(&aux1);

            while(!PilaVacia(aux2)) {
                elemento2 = Tope(aux2);
                aux2 = Desapilar(&aux2);

                    cout << "Indica cantidad de elementos a ser colocados en la pila:" << elemento2 << endl;

            // Evaluo los elementos

             if(elemento1 <= elemento2) {
                temporal = Apilar(&temporal, elemento1);
                aux2 = Apilar(&aux2, elemento2);
                break;
            }  else { // If elemento 2 <= elemento1
                temporal = Apilar(&temporal, elemento2);
            };

            // En caso de que se hayan acabado los valores

            if(PilaVacia(aux1) && !PilaVacia(aux2)) {
                temporal = Apilar(&temporal, elemento2);
            }

            if(PilaVacia(aux2) && !PilaVacia(aux1)) {
                temporal = Apilar(&temporal, elemento1);
            };
            }
        }
    }

    // while(temporal != NULL) {
    //     auxelemento = Tope(temporal);
    //     temporal = Desapilar(&temporal);
    //     nuevaPila = Apilar(&nuevaPila, auxelemento);

    // };

    return temporal;
};



// Main

int main() {
    int cantidad, i, valor;
    Pila *pila = NULL;
    Pila *pilaAparte = NULL;
    cout << "Indica cantidad de elementos a ser colocados en la pila:";
    cin >> cantidad;

    // Nueva pila
    Pila *pilaMezclada = NULL;

    i = 0;

    while(i != cantidad) {
        cout << "Indica valor a colocar: ";
        cin >> valor;
        Apilar(&pila, valor);
        Apilar(&pilaAparte, (i+2));
        i++;
    };

    cout << "Contenido de las Pila: " << endl;  
    mostrarPila(pila);
    cout << "\n " << endl;
    mostrarPila(pilaAparte);

    cout << "\n\nContenido de las pilas:" << endl;

    // Crear la nueva pilota

    pilaMezclada = mezclarPilas(&pila, &pilaAparte);


    cout << "\n\n PILA FINAL: " << endl;

    mostrarPila(pilaMezclada);

    return 0;
}