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
    if (!PilaVacia(*pila)) {
        *pila = (*pila)->next;
    } else {
        cout << "Pila vacia imposible de desapilar" << endl;
    }

    return *pila;
};

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

// Lectura de la pila

void mostrarPila (Pila *pila) {
    while (!PilaVacia(pila)) {
        cout << Tope(pila) << " ";
        Desapilar(&pila);
    }
};

// Main

int main() {
    int cantidad, i, valor;
    Pila *pila = NULL;
    cout << "Indica cantidad de elementos a ser colocados en la pila:";
    cin >> cantidad;

    i = 0;

    while(i != cantidad) {
        cout << "Indica valor a colocar: ";
        cin >> valor;
        Apilar(&pila, valor);
        i++;
    };

    cout << "Contenido de la Pila: " << endl;  
    mostrarPila(pila);

    cout << "Contenido de la pila al poner de fondo 4:" << endl;

    // Agregar al fondo de la pila

    pila = aggFondo(&pila, 4);
    mostrarPila(pila);

    return 0;
}