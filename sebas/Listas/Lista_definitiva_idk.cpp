#include <iostream>
#include <math.h>

using namespace std;

struct nodo
{
    int dato = 0;
    nodo *siguiente = NULL;
    /* data */
};

nodo *crear_nodo(int elemento, nodo *direccion)
{
    nodo *p;
    p = new nodo;
    p->dato = elemento;
    p->siguiente = direccion;
    return p;
};

agregar_nodo_inicio(nodo **head, int elemento) // pasar direccion de head
{
    nodo **pcabeza = head;                       // copia direccion de mi variable cabeza
    nodo *segundo = *head;                       // apunta al anterior primer nodo de la lista
    nodo *nuevo = crear_nodo(elemento, segundo); // guarda direccion de nuevo primer nodo
    *pcabeza = nuevo;                            // asigna nuevo primer nodo al puntero head

    return 0;
}

agregar_nodo_final(nodo *head, int elemento) // pasar head y elemnto
{
    nodo *final = crear_nodo(elemento, NULL);
    nodo *actual = head;
    while (actual->siguiente != NULL)
    {
        actual = actual->siguiente;
    }
    actual->siguiente = final;

    return 0;
}

remover_nodos(nodo **phead, int elemento)
{
    nodo *actual = *phead;
    nodo *previo = NULL;
    int i = 0;
    do
    {
        // cout << actual->dato << endl;
        if (actual->dato == elemento)
        {

            if (previo == NULL) // primer nodo
            {
                // cout << "El elemento esta al principio " << endl;
                *phead = actual->siguiente;
                actual->siguiente = NULL;
                actual = *phead;
            }
            else
            {
                previo->siguiente = actual->siguiente;
                // previo= actual;
                actual = actual->siguiente;
            }
            // actual->siguiente=NULL;
        }
        else
        {
            i++;
            previo = actual;
            actual = actual->siguiente;
            // cout<<"estoy en elemento"<<i<<endl;
        }

    } while (actual != NULL); // mientras no sea el ultimo elemento

    return 0;
};

imprimir_lista(nodo *head)
{
    nodo *actual = head;

    while (actual != NULL)
    {
        cout << actual->dato;
        if (actual->siguiente != NULL)
        {
            cout << "->";
        }
        else
            cout << "--]";

        actual = actual->siguiente;
    }
    cout << endl;
    return 0;
};

int main(int argc, char const *argv[])
{
    nodo *head = crear_nodo(14, NULL);

    for (int i = 0; i < 10; i++)
        agregar_nodo_final(head, i);

    agregar_nodo_inicio(&head, 9);
    imprimir_lista(head);
    remover_nodos(&head, 9);
    imprimir_lista(head);
    /* code */
    return 0;
}
