///PROGRAMA MODIFICADO POR BRAYAN GUADALUPE HERNANDEZ
#include <iostream>
#include <stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<windows.h>
#include <iomanip>
using namespace std;
int auxX=0;
int arreglo[10]= {10,9,30,11,7,5,0,4,9,10};
struct Nodo
{
    int dato;
    Nodo *der;
    Nodo *izq;

};
void gotoxy(int x, int y);
Nodo *arbol =NULL;
///prototipos
///void funcion de menu
void menu();

Nodo *crearNodo(int);

void insertarNodo(Nodo *&, int);
void mostrarArbol(Nodo *, int);
void mostrarArbol2(Nodo *, int);
///Nodo *arbol = NULL;
int main()
{

    menu();


    getch();
    return 0;
}
///FUNCION PARA CREAR UN NUEVO NODO
Nodo *crearNodo(int n)
{

    Nodo *nuevo_nodo = new Nodo();

    nuevo_nodo->dato = n;
    nuevo_nodo->der = NULL;
    nuevo_nodo->izq = NULL;
    return nuevo_nodo;

}

void insertarNodo(Nodo *&arbol, int n)
{
    if(arbol==NULL)
    {
        ///si el arbol esta vacio crear nuevo nodo
        Nodo *nuevo_nodo =crearNodo(n);
        arbol=nuevo_nodo;
    }
    else
    {
///si el arbol tiene un nodo o mas
        int valorRaiz= arbol->dato;///obtenemos el valor de la raiz
        if (n==valorRaiz)
        {
            return;
        }
        if(n< valorRaiz) ///SI EL ELEMTO ES MENOS A LA RAIZ insertar a izq
        {
            insertarNodo(arbol->izq,n);
        }
        else
        {
            ///si el elemento es mayor ala raiz inserata a la derecha
            insertarNodo(arbol->der,n);
        }


    }


}
void menu()
{
    int dato, opcion, contador=0,masdatos;
    do
    {
        cout<<"\t._ _ _ _ _ _ _ _ _MENU:_ _ _ _ _ _ _ _ _ _ "<<endl;
        cout<<"\n1 Insertar los datos del arreglo que son: arreglo[10]= {10,9,30,11,7,5,0,4,9,10}\n2 Mostrar en horizontal y vertical\n3 Insertar mas datos\n4 salir"<<endl;
        cout<<"_ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _";
        cout<<"\nopcion ----->";
        cin>>opcion;
        switch(opcion)
        {
        case 1:
            cout<<"\nNUMEROS DEL ARREGLO INSERTANDOS CORECTAMENTE:\n ";
            for(int i=0; i<=9; i++)
            {
                dato= arreglo[i];
                insertarNodo(arbol,dato); ///insertar un nuevo nodo
            }

            cout<<"\n";
           ;
            break;
        case 2:
            cout<<"\nMOSTRANDO EL ARBOL COMPLETO\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n";

            auxX=0;

            mostrarArbol2(arbol,auxX);
            cout<<endl<<endl;
            mostrarArbol(arbol,contador);
            cout<<"................................."<<endl<<endl;

            break;
        case 3:
            int cantidad;
            cout<<"\nINSERTAR MAS DATOS\n";
            cout<<"¿CUANTOS DATOS MAS QUIERES?\n";
            cin>>cantidad;
            for (int i=0; i<cantidad; i++)
            {
                cout<<"Inserta dato "<<i+1<<".....";
                cin>>masdatos;
                cout<<endl;
                insertarNodo(arbol,masdatos); ///insertqar un nuevo nodo
            }
            break;

        }
        cout<<"\n\n\n\n";
        system("pause");
        system("cls");
    }
    while (opcion !=4);
    cout<<"\n\tPROGRAMA MODIFICADO POR BRAYAN GUADALUPE HERNANDEZ (con fines estudiantiles)\n\n\n";
    cout<<"\t          ****             ****\n";
    cout<<"\t          *(0)*             *(0)*\n";
    cout<<"\t          ****             ****\n";
    cout<<"\t                               \n";
    cout<<"\t                   **             \n";
    cout<<"\t                  ****             \n";
    cout<<"\t    ++         <<<< >>>>>           ++\n";
    cout<<"\t     ++                            ++\n";
    cout<<"\t      ++  ++++++++++++++++++++++++ +                        \n";
    cout<<"\t       ++ ++++++++++++++++++++++ +                      \n";
    cout<<"\t          ++ +++++++++++++++++ +                     \n";
     cout<<"\t           ++ ++++++++++++ +                     \n";

}

///funcion para mostrar arbol
void mostrarArbol(Nodo *arbol, int cont)
{
    if (arbol==NULL)
    {
        ///si el arbol esta vacio
        return;

    }
    else
    {
        mostrarArbol(arbol->der, cont+1);
        for (int i=0; i<cont; i++)
        {

            cout<<"   ";
        }
        cout<<arbol->dato<<endl;
        mostrarArbol(arbol->izq, cont+1);

    }
}
void mostrarArbol2(Nodo *arbol, int auxY)
{
    if (arbol==NULL)
    {
        return;
    }
    auxX +=5;
    mostrarArbol2(arbol->izq,auxY+2);
    gotoxy (10+auxX-auxY, 15+auxY);
    cout << arbol -> dato << endl << endl;
    mostrarArbol2(arbol->der,auxY+2);

}
void gotoxy(int x,int y)
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);

}









