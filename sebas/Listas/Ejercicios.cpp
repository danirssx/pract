#include <iostream>
#include <math.h>

using namespace std;

struct nodo
{
    int data;
    nodo *prox = NULL;
};

struct Lista
{
    nodo *cabeza = NULL;
};

nodo *crear_nodo(int dato)
{
    nodo *actual = new nodo;
    actual->data = dato;
    return actual;
}

int crear_lista(Lista *pivote, int dato)
{
    pivote->cabeza = crear_nodo(dato);
    return 0;
}

int push(Lista *plista, int dato)
{
    nodo *head = plista->cabeza;
    nodo *nuevo = crear_nodo(dato);
    nuevo->prox = plista->cabeza;
    plista->cabeza = nuevo;

    return 0;
}

int add(Lista *L, int dato)
{
    nodo *actual = L->cabeza;

    while (actual->prox != NULL)
        actual = actual->prox;

    actual->prox = crear_nodo(dato);
    return 0;
}

int rellenar_lista(Lista *lista, int menor, int mayor)
{
    crear_lista(lista, menor);
    nodo *actual = lista->cabeza;
    for (int i = menor + 1; i < mayor; i++)
    {
        actual->prox = crear_nodo(i);
        actual = actual->prox;
    }

    return 0;
}

int imprimir_lista(Lista *lista)
{
    nodo *actual = lista->cabeza;
    cout << "Lista: \n";
    while (actual != NULL)
    {
        cout << actual->data << "-->";
        actual = actual->prox;
    }
    cout << "NULL" << endl;
    return 0;
}
int main(int argc, char const *argv[])
{
    Lista *L1 = new Lista;
    rellenar_lista(L1, 0, 9);
    imprimir_lista(L1);
    push(L1, 66);
    add(L1, 19);
    imprimir_lista(L1);
    return 0;
}
