#include <iostream>
#include <iomanip>
#include "time.h"
#include "stdlib.h"
#include <iomanip>
#include "windows.h"
#define maxiju 15
#define maxix 100
#define maxy 100
/** juan pablo sanchez gaitan**/
void datos (struct parques jugadores [maxiju],int numjug);
void juego (int tablero [maxix][maxy],struct parques jugadores [maxiju],int numjug);
void vista (int tablero [maxix][maxy],struct parques jugadores [maxiju],int numjug,int tamtab);


struct parques
{
    char nombre[30];
    int dado1=0,dado2=0;
    int pos=0;

};
using namespace std;

int main()
{
    struct parques jugadores [maxiju];
    int numjug=0,opcion=0,tamtab=0;
    srand(time(NULL));
    int tablero [maxix][maxy];
    cout<<"Bienvenido al juego parques"<<endl;
    do
    {
        cout<<"MENU"<<endl;
        cout<<"1. JUGAR"<<endl;
        cout<<"2. REGLAS"<<endl;
        cout<<"3. SALIR"<<endl;
        cin>>opcion;
        if (opcion == 1)
        {
            cout<<"cuantos jugadores van a jugar?"<<endl;
            cin>>numjug;
            if (numjug <=4)
            {
                tamtab=7;
            }
            datos (jugadores,numjug);
            vista(tablero,jugadores,numjug,tamtab);
            juego(tablero,jugadores,numjug);

        }
        if (opcion == 2)
        {
            cout<<"Las reglas son: "<<endl;
            cout<<endl;
            cout<<"Regla No1. "<<endl;
        }
        if (opcion == 3)
        {
            system("cls");
        }
    }
    while(opcion !=3);
}
void datos (struct parques jugadores [maxiju],int numjug)
{
    for(int i =0; i<numjug; i++)
    {
        cout<<"jugador No."<<i<<endl;
        cout<<"Nombre"<<endl;
        cin>>jugadores[i].nombre;
    }

}
void vista (int tablero [maxix][maxy],struct parques jugadores [maxiju],int numjug,int tamtab)
{
    for(int i=0; i<tamtab; i++)
    {
        for(int j=0; j<tamtab; j++)
        {

            cout<<setw(3.5)<<'|';
        }
        cout<<endl;
    }

}
void juego (int tablero [maxix][maxy],struct parques jugadores [maxiju],int numjug)
{
    int turno=1,i=0,resd=0;
    bool ganador=false;
    do
    {

        cout<<"turno #"<<turno<<endl;
        cout<<"juega "<<jugadores[i].nombre<<endl;
        if (turno == 1)
        {
            cout<<"recuerda que para sacar las 4 fichas que tienes tienes que sacar par 1,1-2,2-3,3-4,4-5,5-6,6 para sacar las fichas"<<endl;
        }
        cout<<"Tirar dados? 1.si 2.no"<<endl;
        cin>>resd;
        if(resd == 1)
        {
            jugadores[i].dado1 = rand() % 6 + 1;
            jugadores[i].dado2 = rand() % 6 + 1;
            cout<<jugadores[i].dado1<<","<<jugadores[i].dado2<<endl;
            if (turno == 1)
            {
                if(jugadores[i].dado1==1)
                {
                    if(jugadores[i].dado2==1)
                    {

                    }
                }
                if(jugadores[i].dado1==2)
                {
                    if(jugadores[i].dado2==2)
                    {

                    }
                }
                if(jugadores[i].dado1==2)
                {
                    if(jugadores[i].dado2==2)
                    {

                    }
                }
            }
        }



        i++;
        if (i>numjug-1)
        {
            i=0;
            turno++;
        }
    }
    while(ganador==false);
}
