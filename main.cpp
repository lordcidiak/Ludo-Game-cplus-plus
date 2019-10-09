#include <iostream>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
#include <windows.h>

#define maxiju 15
#define maxix 100
#define maxiy 100
/** juan pablo sanchez gaitan**/
void datos (struct parques jugadores [maxiju],int numjug);

void mapa(char tablero [maxix][maxiy],int tablerofantasma [maxix][maxiy],struct parques jugadores [maxiju],int numjug,int tamtabx,int tamtaby);

void juegoconlamaquina (int tablero [maxix][maxiy],struct parques jugadores [maxiju],int numjug,int tamtabx,int tamtaby);

void juego (char tablero [maxix][maxiy],int tablerofantasma [maxix][maxiy],struct parques jugadores [maxiju],int numjug,int tamtabx,int tamtaby);

void vista (char tablero [maxix][maxiy],int tablerofantasma [maxix][maxiy],struct parques jugadores [maxiju],int numjug,int tamtabx,int tamtaby);


struct parques
{
    char nombre[30];
    int dadox=0;
    int dadoy=0;
    int fichasfinales=0;
    int movfich = 0;
    int salidax=0,saliday=0;
    int llegadax=0,llegaday=0;
    int ficha1x=0,ficha1y=0;
    int basex=0,basey=0;
    int ficha2x=0,ficha2y=0;
    int contador1=0;
    int dcotador2=0;
    int cambiox=0;
    int cambioy=0;
    int basefantasma=0;
    char base;
    bool fichas =false;
    bool todas=false;
    bool ganador = false;
    bool nu2 =true;
    bool nu3 =true;
    bool nu4 =true;
    bool nu5 =true;
    bool nu6 =true;
};
using namespace std;

int main()
{
    struct parques jugadores [maxiju];
    int numjug=0,opcion=0,tamtabx=0,tamtaby=0;
    int opmapa=0;
    srand(time(NULL));
    char tablero [maxix][maxiy];
    int tablerofantasma [maxix][maxiy];
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
            cout<<"Cuantos jugadores van a jugar?"<<endl;
            cin>>numjug;
            cout<<"Que tipo de mapa escoges?"<<endl;
            cout<<"1. Peque"<<endl;
            cout<<"2. Grande"<<endl;
            cout<<"3. Personalizado"<<endl;
            cin>>opmapa;
            if (opmapa == 1)
            {
                tamtabx = 4;
                tamtaby = 6;
                if(numjug == 1 )
                {
                    cout<<"No puedes jugar solo, consiguete a alguien"<<endl;
                    cout<<"Vas a jugar contra la maquina en difultad normal"<<endl;

                    mapa(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                    datos (jugadores,numjug);
                    juego(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                    // juegoconlamaquina (tablero,jugadores,numjug,tamtab);
                }
                if(numjug >= 2)
                {
                    mapa(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                    datos (jugadores,numjug);
                    juego(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);

                }
            }
            if (opmapa == 2)
            {
                tamtabx = 10;
                tamtaby = 10;
                if(numjug == 1 )
                {
                    cout<<"No puedes jugar solo, consiguete a alguien"<<endl;
                    cout<<"Vas a jugar contra la maquina en difultad normal"<<endl;

                    mapa(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                    datos (jugadores,numjug);
                    juego(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                    // juegoconlamaquina (tablero,jugadores,numjug,tamtab);
                }
                if(numjug >= 2)
                {
                    mapa(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                    datos (jugadores,numjug);
                    juego(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);

                }

            }
            if (opmapa == 3)
            {
                cout<<"Digite el numero de filas"<<endl;
                cin>>tamtabx;
                cout<<"Digite el numero de columnas"<<endl;
                cin>>tamtaby;
                if(numjug == 1 )
                {
                    cout<<"No puedes jugar solo, consiguete a alguien"<<endl;
                    cout<<"Vas a jugar contra la maquina en difultad normal"<<endl;

                    mapa(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                    datos (jugadores,numjug);
                    juego(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                    // juegoconlamaquina (tablero,jugadores,numjug,tamtab);
                }
                if(numjug >= 2)
                {
                    mapa(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                    datos (jugadores,numjug);
                    juego(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);

                }

            }
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
void mapa(char tablero [maxix][maxiy],int tablerofantasma [maxix][maxiy],struct parques jugadores [maxiju],int numjug,int tamtabx,int tamtaby)
{
    int mitadx=0;
    int mitady=0;
    mitadx=tamtabx/2;
    mitady=tamtaby/2;
    cout<<mitadx<<" "<<mitady<<endl;
    for(int i = 0; i < tamtabx; i++)
    {
        for(int j = 0; j < tamtaby; j++)
        {
            tablerofantasma[i][j]=0;
        }
    }
    jugadores[0].salidax=0;
    jugadores[0].saliday=1;
    jugadores[0].llegadax=mitadx;
    jugadores[0].llegaday=mitady;
    jugadores[0].base='@';
    jugadores[0].basefantasma=1;
    jugadores[0].basex=0;
    jugadores[0].basey=0;
//jugador 2
    jugadores[1].salidax=tamtabx-1;
    jugadores[1].saliday=1;
    jugadores[1].llegadax=mitadx+1;
    jugadores[1].llegaday=mitady;
    jugadores[1].base='&';
    jugadores[1].basefantasma=2;
    jugadores[1].basex=tamtabx-1;
    jugadores[1].basey=0;
//jugador 3
    jugadores[2].salidax=tamtabx-1;
    jugadores[2].saliday=tamtaby-2;
    jugadores[2].llegadax=mitadx+1;
    jugadores[2].llegaday=mitady+1;
    jugadores[2].base='#';
    jugadores[2].basefantasma=3;
    jugadores[2].basex=tamtabx-1;
    jugadores[2].basey=tamtaby-1;
    //jugador 4
    jugadores[3].salidax=0;
    jugadores[3].saliday=tamtaby-2;
    jugadores[3].llegadax=mitadx;
    jugadores[3].llegaday=mitady+1;
    jugadores[3].base='$';
    jugadores[3].basefantasma=4;
    jugadores[3].basex=0;
    jugadores[3].basey=tamtaby-1;
    for(int x = 0; x < tamtabx; x++)
    {
        for(int y = 0; y < tamtaby; y++)
        {
            tablero[x][y]='-';
        }
    }
    for(int i=0; i<4; i++)
    {
        tablero[jugadores[i].basex][jugadores[i].basey]=jugadores[i].base;
        tablero[jugadores[i].llegadax][jugadores[i].llegaday]=jugadores[i].base;
        tablerofantasma[jugadores[i].basex][jugadores[i].basey]=jugadores[i].basefantasma;



    }
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
void vista (char tablero [maxix][maxiy],int tablerofantasma [maxix][maxiy],struct parques jugadores [maxiju],int numjug,int tamtabx,int tamtaby)
{

    for(int i = 0; i < tamtabx; i++)
    {
        for(int j = 0; j < tamtaby; j++)
        {
            cout<<setw(3.5)<<tablero[i][j]<<'|';
        }
        cout<<endl;
    }
}
void juego (char tablero [maxix][maxiy],int tablerofantasma [maxix][maxiy],struct parques jugadores [maxiju],int numjug,int tamtabx,int tamtaby)
{
    int turno=0,i=0,respu=0,contador=0,lanzamientos=3,fichmov=0;
    int dadox=0,dadoy=0;
    bool salio =false;
    bool finalista = false;

    do
    {
        vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
        if(i == numjug)
        {
            i=0;
            turno++;

        }
        cout<<"Turno #"<<turno<<endl;
        cout<<"Juega "<<jugadores[i].nombre<<endl;
        cout<<"Tirar dados? 1.si"<<endl;
        cin>>respu;
        if (respu == 1)
        {
            do
            {
                cout<<"Lanzamiento #"<<contador+1<<endl;
                dadox = rand() % 6 + 1;
                if (jugadores[i].fichas==true)
                {
                    cout<<dadox<<endl;
                    if (turno>0)
                    {
                        salio=true;
                    }
                }
                if (jugadores[i].fichas == false)
                {
                    dadoy = rand() % 6 + 1;
                    cout<<dadox<<","<<dadoy<<endl;

                    if(dadox==1)
                    {
                        if(dadoy==1)
                        {
                            cout<<"SALEN TODAS LAS FICHAS"<<endl;
                            salio=true;
                            lanzamientos =1;

                            jugadores[i].todas=true;
                            jugadores[i].fichas=true;
                        }
                        if(dadoy != 1)
                        {
                            contador++;
                        }
                    }
                    if(dadox==2)
                    {
                        if(dadoy==2)
                        {
                            cout<<"SALE 1 FICHA"<<endl;
                            salio=true;
                            lanzamientos =1;

                            jugadores[i].fichas=true;
                        }
                        if(dadoy != 2)
                        {
                            contador++;
                        }
                    }
                    if(dadox==3)
                    {
                        if(dadoy==3)
                        {
                            cout<<"SALE 1 FICHA"<<endl;
                            salio=true;
                            lanzamientos =1;

                            jugadores[i].fichas=true;
                        }
                        if(dadoy != 3)
                        {
                            contador++;
                        }
                    }
                    if(dadox==4)
                    {
                        if(dadoy==4)
                        {
                            cout<<"SALE 1 FICHA"<<endl;
                            salio=true;
                            lanzamientos =1;

                            jugadores[i].fichas=true;
                        }
                        if(dadoy != 4)
                        {
                            contador++;
                        }
                    }
                    if(dadox==5)
                    {
                        if(dadoy==5)
                        {
                            cout<<"SALE 1 FICHA"<<endl;
                            salio=true;
                            lanzamientos =1;

                            jugadores[i].fichas=true;
                        }
                        if(dadoy != 5)
                        {
                            contador++;
                        }
                    }
                    if(dadox==6)
                    {
                        if(dadoy==6)
                        {
                            cout<<"SALEN TODAS LAS FICHAS"<<endl;
                            salio=true;
                            lanzamientos =1;
                            jugadores[i].todas=true;
                            jugadores[i].fichas=true;
                        }
                        if(dadoy != 6)
                        {
                            contador++;
                        }
                    }
                    if (contador == lanzamientos)
                    {
                        salio = true;
                    }
                }
            }
            while (salio == false);

            if (turno >0)
            {
                if (jugadores[i].fichas == true)
                {
                    cout<<"que fichas quieres mover?: "<<endl;
                    cout<<"1. ficha 1"<<endl;
                    jugadores[i].ficha1x=jugadores[i].salidax;
                    jugadores[i].ficha1y=jugadores[i].saliday;
                    if (i == 0)
                    {
                        tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='@';
                        tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=1;
                    }
                    if (jugadores[i].todas == true)
                    {
                        cout<<"2. ficha 2"<<endl;
                        jugadores[i].ficha2x=jugadores[i].salidax;
                        jugadores[i].ficha2y=jugadores[i].saliday;
                        if (i == 0)
                        {
                            tablero[jugadores[i].ficha2x][jugadores[i].ficha2y]='@';
                            tablerofantasma[jugadores[i].ficha2x][jugadores[i].ficha2y]=1;
                        }
                    }
                    cin>>fichmov;
                    if(fichmov == 1)
                    {
                        cout<<"cuantas casillas quieres mover la ficha?"<<endl;
                        cout<<"Op 1 "<<dadox<<" posiciones"<<endl;
                        cin>>jugadores[i].movfich;
                        if (jugadores[i].movfich == 1)
                        {
                            if (dadox == 1)
                            {
                                if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] != tablero[jugadores[i].salidax][jugadores[i].saliday])
                                {
                                    if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[jugadores[i].ficha1x][1])
                                    {
                                        tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='-';
                                        jugadores[i].ficha1x = jugadores[i].ficha1x + 1;
                                        if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[jugadores[i].salidax][jugadores[i].saliday])
                                        {
                                            jugadores[i].ficha1x = jugadores[i].ficha1x - 1;
                                            jugadores[i].ficha1y = jugadores[i].ficha1y + 1;
                                            if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[jugadores[i].llegadax][jugadores[i].llegaday])
                                            {
                                                jugadores[i].fichasfinales= jugadores[i].fichasfinales + 1;
                                                if (jugadores[i].fichasfinales == 2)
                                                {
                                                    finalista=true;
                                                    //ganador();
                                                }
                                            }
                                        }
                                        if (jugadores[i].nombre ==jugadores[0].nombre)
                                        {
                                            jugadores[i].contador1= jugadores[i].contador1 +1;
                                            tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='@';
                                            tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=1;
                                            vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                                        }
                                        if (jugadores[i].nombre ==jugadores[1].nombre)
                                        {
                                            jugadores[i].contador1= jugadores[i].contador1 +1;
                                            tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='#';
                                            tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=2;
                                            vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                                        }
                                        if (jugadores[i].nombre ==jugadores[2].nombre)
                                        {
                                            jugadores[i].contador1= jugadores[i].contador1 +1;
                                            tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='$';
                                            tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=3;
                                            vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                                        }
                                        if (jugadores[i].nombre ==jugadores[3].nombre)
                                        {
                                            jugadores[i].contador1= jugadores[i].contador1 +1;
                                            tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='&';
                                            tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=4;
                                            vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                                        }
                                    }
                                }
                                if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] != tablero[jugadores[i].salidax][jugadores[i].saliday])
                                {
                                    if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[jugadores[i].ficha1x][4])
                                    {

                                        tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='-';
                                        jugadores[i].ficha1x = jugadores[i].ficha1x - 1;
                                        if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[jugadores[i].salidax][jugadores[i].saliday])
                                        {
                                            jugadores[i].ficha1x = jugadores[i].ficha1x + 1;
                                            jugadores[i].ficha1y = jugadores[i].ficha1y - 1;
                                            if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[jugadores[i].llegadax][jugadores[i].llegaday])
                                            {
                                                jugadores[i].fichasfinales= jugadores[i].fichasfinales + 1;
                                                if (jugadores[i].fichasfinales == 2)
                                                {
                                                    finalista=true;
                                                    //ganador();
                                                }
                                            }
                                        }
                                        if (jugadores[i].nombre ==jugadores[0].nombre)
                                        {
                                            jugadores[i].contador1= jugadores[i].contador1 +1;
                                            tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='@';
                                            tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=1;
                                            vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                                        }
                                        if (jugadores[i].nombre ==jugadores[1].nombre)
                                        {
                                            jugadores[i].contador1= jugadores[i].contador1 +1;
                                            tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='#';
                                            tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=2;
                                            vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                                        }
                                        if (jugadores[i].nombre ==jugadores[2].nombre)
                                        {
                                            jugadores[i].contador1= jugadores[i].contador1 +1;
                                            tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='$';
                                            tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=3;
                                            vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                                        }
                                        if (jugadores[i].nombre ==jugadores[3].nombre)
                                        {
                                            jugadores[i].contador1= jugadores[i].contador1 +1;
                                            tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='&';
                                            tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=4;
                                            vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                                        }
                                    }
                                }
                                if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] != tablero[jugadores[i].salidax][jugadores[i].saliday])
                                {
                                    if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[0][jugadores[i].ficha1y])
                                    {
                                        tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='-';
                                        jugadores[i].ficha1y = jugadores[i].ficha1y - 1;
                                        if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[jugadores[i].salidax][jugadores[i].saliday])
                                        {
                                            jugadores[i].ficha1x = jugadores[i].ficha1x + 1;
                                            jugadores[i].ficha1y = jugadores[i].ficha1y + 1;
                                            if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[jugadores[i].llegadax][jugadores[i].llegaday])
                                            {
                                                jugadores[i].fichasfinales= jugadores[i].fichasfinales + 1;
                                                if (jugadores[i].fichasfinales == 2)
                                                {
                                                    finalista=true;
                                                    //ganador();
                                                }
                                            }
                                        }
                                        if (jugadores[i].nombre ==jugadores[0].nombre)
                                        {
                                            jugadores[i].contador1= jugadores[i].contador1 +1;
                                            tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='@';
                                            tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=1;
                                            vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                                        }
                                        if (jugadores[i].nombre ==jugadores[1].nombre)
                                        {
                                            jugadores[i].contador1= jugadores[i].contador1 +1;
                                            tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='#';
                                            tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=2;
                                            vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                                        }
                                        if (jugadores[i].nombre ==jugadores[2].nombre)
                                        {
                                            jugadores[i].contador1= jugadores[i].contador1 +1;
                                            tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='$';
                                            tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=3;
                                            vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                                        }
                                        if (jugadores[i].nombre ==jugadores[3].nombre)
                                        {
                                            jugadores[i].contador1= jugadores[i].contador1 +1;
                                            tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='&';
                                            tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=4;
                                            vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                                        }
                                    }
                                }
                                if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] != tablero[jugadores[i].salidax][jugadores[i].saliday])
                                {
                                    if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[3][jugadores[i].ficha1y])
                                    {
                                        tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='-';
                                        jugadores[i].ficha1y = jugadores[i].ficha1y + 1;
                                        if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[jugadores[i].salidax][jugadores[i].saliday])
                                        {
                                            jugadores[i].ficha1x = jugadores[i].ficha1x + 1;
                                            jugadores[i].ficha1y = jugadores[i].ficha1y - 1;
                                            if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[jugadores[i].llegadax][jugadores[i].llegaday])
                                            {
                                                jugadores[i].fichasfinales= jugadores[i].fichasfinales + 1;
                                                if (jugadores[i].fichasfinales == 2)
                                                {
                                                    finalista=true;
                                                    //ganador();
                                                }
                                            }
                                        }
                                        if (jugadores[i].nombre ==jugadores[0].nombre)
                                        {
                                            jugadores[i].contador1= jugadores[i].contador1 +1;
                                            tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='@';
                                            tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=1;
                                            vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                                        }
                                        if (jugadores[i].nombre ==jugadores[1].nombre)
                                        {
                                            jugadores[i].contador1= jugadores[i].contador1 +1;
                                            tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='#';
                                            tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=2;
                                            vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                                        }
                                        if (jugadores[i].nombre ==jugadores[2].nombre)
                                        {
                                            jugadores[i].contador1= jugadores[i].contador1 +1;
                                            tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='$';
                                            tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=3;
                                            vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                                        }
                                        if (jugadores[i].nombre ==jugadores[3].nombre)
                                        {
                                            jugadores[i].contador1= jugadores[i].contador1 +1;
                                            tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='&';
                                            tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=4;
                                            vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                                        }
                                    }
                                }
                            }
                            if (jugadores[i].nu2 == true)
                            {
                                if (dadox == 2)
                                {
                                    if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] != tablero[jugadores[i].salidax][jugadores[i].saliday])
                                    {
                                        if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[jugadores[i].ficha1x][1])
                                        {
                                            tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='-';
                                            jugadores[i].ficha1x = jugadores[i].ficha1x + 2;
                                            if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[tamtabx][1])
                                            {
                                                jugadores[i].ficha1x = jugadores[i].ficha1x -1;
                                                jugadores[i].ficha1y = jugadores[i].ficha1y +1;
                                                if (jugadores[i].nombre ==jugadores[0].nombre)
                                                {
                                                    jugadores[i].contador1= jugadores[i].contador1 +2;
                                                    tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='@';
                                                    tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=1;
                                                    vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                                                }
                                                if (jugadores[i].nombre ==jugadores[1].nombre)
                                                {
                                                    jugadores[i].contador1= jugadores[i].contador1 +2;
                                                    tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='#';
                                                    tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=2;
                                                    vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                                                }
                                                if (jugadores[i].nombre ==jugadores[2].nombre)
                                                {
                                                    jugadores[i].contador1= jugadores[i].contador1 +2;
                                                    tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='$';
                                                    tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=3;
                                                    vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                                                }
                                                if (jugadores[i].nombre ==jugadores[3].nombre)
                                                {
                                                    jugadores[i].contador1= jugadores[i].contador1 +2;
                                                    tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='&';
                                                    tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=4;
                                                    vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                                                }
                                            }
                                            if (jugadores[i].nombre ==jugadores[0].nombre)
                                            {
                                                jugadores[i].contador1= jugadores[i].contador1 +2;
                                                tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='@';
                                                tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=1;
                                                vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                                            }
                                            if (jugadores[i].nombre ==jugadores[1].nombre)
                                            {
                                                jugadores[i].contador1= jugadores[i].contador1 +2;
                                                tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='#';
                                                tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=2;
                                                vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                                            }
                                            if (jugadores[i].nombre ==jugadores[2].nombre)
                                            {
                                                jugadores[i].contador1= jugadores[i].contador1 +2;
                                                tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='$';
                                                tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=3;
                                                vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                                            }
                                            if (jugadores[i].nombre ==jugadores[3].nombre)
                                            {
                                                jugadores[i].contador1= jugadores[i].contador1 +2;
                                                tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='&';
                                                tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=4;
                                                vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                                            }
                                        }
                                    }
                                    if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] != tablero[jugadores[i].salidax][jugadores[i].saliday])
                                    {
                                        if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[jugadores[i].ficha1x][jugadores[i].cambioy])
                                        {
                                            tablero[jugadores[i].ficha1x]
                                            [jugadores[i].ficha1y]='-';
                                            jugadores[i].ficha1x = jugadores[i].ficha1x - 2;
                                            if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[-1][4])
                                            {
                                                jugadores[i].ficha1x = jugadores[i].ficha1x +1;
                                                jugadores[i].ficha1y = jugadores[i].ficha1y -1;
                                                if (jugadores[i].nombre ==jugadores[0].nombre)
                                                {
                                                    jugadores[i].contador1= jugadores[i].contador1 +2;
                                                    tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='@';
                                                    tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=1;
                                                    vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                                                }
                                                if (jugadores[i].nombre ==jugadores[1].nombre)
                                                {
                                                    jugadores[i].contador1= jugadores[i].contador1 +2;
                                                    tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='#';
                                                    tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=2;
                                                    vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                                                }
                                                if (jugadores[i].nombre ==jugadores[2].nombre)
                                                {
                                                    jugadores[i].contador1= jugadores[i].contador1 +2;
                                                    tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='$';
                                                    tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=3;
                                                    vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                                                }
                                                if (jugadores[i].nombre ==jugadores[3].nombre)
                                                {
                                                    jugadores[i].contador1= jugadores[i].contador1 +2;
                                                    tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='&';
                                                    tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=4;
                                                    vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                                                }
                                            }

                                            if (jugadores[i].nombre ==jugadores[0].nombre)
                                            {
                                                tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='@';
                                                tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=1;
                                                vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                                            }
                                            if (jugadores[i].nombre ==jugadores[1].nombre)
                                            {
                                                tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='#';
                                                tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=2;
                                                vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                                            }
                                            if (jugadores[i].nombre ==jugadores[2].nombre)
                                            {
                                                tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='$';
                                                tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=3;
                                                vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                                            }
                                            if (jugadores[i].nombre ==jugadores[3].nombre)
                                            {
                                                tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='&';
                                                tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=4;
                                                vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                                            }
                                        }
                                    }
                                    if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] != tablero[jugadores[i].salidax][jugadores[i].saliday])
                                    {
                                        if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[0][jugadores[i].ficha1y])
                                        {
                                            tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='-';
                                            jugadores[i].ficha1y = jugadores[i].ficha1y - 2;
                                            if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[jugadores[i].salidax][jugadores[i].saliday])
                                            {
                                                jugadores[i].ficha1y = jugadores[i].ficha1y +1;
                                                jugadores[i].ficha1x = jugadores[i].ficha1x + 1;
                                                if (jugadores[i].nombre ==jugadores[0].nombre)
                                                {
                                                    tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='@';
                                                    tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=1;
                                                    vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                                                }
                                                if (jugadores[i].nombre ==jugadores[1].nombre)
                                                {
                                                    tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='#';
                                                    tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=2;
                                                    vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                                                }
                                                if (jugadores[i].nombre ==jugadores[2].nombre)
                                                {
                                                    tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='$';
                                                    tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=3;
                                                    vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                                                }
                                                if (jugadores[i].nombre ==jugadores[3].nombre)
                                                {
                                                    tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='&';
                                                    tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=4;
                                                    vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                                                }
                                            }
                                            if (jugadores[i].nombre ==jugadores[0].nombre)
                                            {
                                                tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='@';
                                                tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=1;
                                                vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                                            }
                                            if (jugadores[i].nombre ==jugadores[1].nombre)
                                            {
                                                tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='#';
                                                tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=2;
                                                vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                                            }
                                            if (jugadores[i].nombre ==jugadores[2].nombre)
                                            {
                                                tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='$';
                                                tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=3;
                                                vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                                            }
                                            if (jugadores[i].nombre ==jugadores[3].nombre)
                                            {
                                                tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='&';
                                                tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=4;
                                                vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                                            }
                                        }
                                    }
                                    if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] != tablero[jugadores[i].salidax][jugadores[i].saliday])
                                    {
                                        if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[3][jugadores[i].ficha1y])
                                        {
                                            jugadores[i].ficha1y = jugadores[i].ficha1y + 2;
                                            if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[3][5])
                                            {
                                                jugadores[i].ficha1y = jugadores[i].ficha1y -1;
                                                jugadores[i].ficha1x = jugadores[i].ficha1x +1;
                                                if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[4][1])
                                                {
                                                    jugadores[i].ficha1x = jugadores[i].ficha1x -1;
                                                    jugadores[i].ficha1y = jugadores[i].ficha1y +1;
                                                }
                                                if (jugadores[i].nombre ==jugadores[0].nombre)
                                                {
                                                    tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='@';
                                                    tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=1;
                                                    vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                                                }
                                                if (jugadores[i].nombre ==jugadores[1].nombre)
                                                {
                                                    tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='#';
                                                    tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=2;
                                                    vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                                                }
                                                if (jugadores[i].nombre ==jugadores[2].nombre)
                                                {
                                                    tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='$';
                                                    tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=3;
                                                    vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                                                }
                                                if (jugadores[i].nombre ==jugadores[3].nombre)
                                                {
                                                    tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='&';
                                                    tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=4;
                                                    vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                                                }
                                            }
                                        }
                                    }
                                    if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[1][2])
                                    {
                                        jugadores[i].fichasfinales++;
                                        if (jugadores[i].fichasfinales == 2)
                                        {
                                            finalista=true;
                                            //  ganador()
                                        }
                                    }

                                }
                            }
                            if (jugadores[i].nu3 == true)
                            {
                                if (dadox == 3)
                                {
                                    if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] != tablero[jugadores[i].salidax][jugadores[i].saliday])
                                    {
                                        if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[jugadores[i].ficha1x][1])
                                        {
                                            jugadores[i].ficha1x = jugadores[i].ficha1x + 3;
                                            if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[4][1])
                                            {
                                                jugadores[i].ficha1x = jugadores[i].ficha1x -1;
                                                jugadores[i].ficha1y = jugadores[i].ficha1y +1;
                                            }
                                            if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[5][1])
                                            {
                                                jugadores[i].ficha1x = jugadores[i].ficha1x -2;
                                                jugadores[i].ficha1y = jugadores[i].ficha1y +2;
                                            }
                                        }
                                    }
                                    if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] != tablero[jugadores[i].salidax][jugadores[i].saliday])
                                    {
                                        if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[jugadores[i].ficha1x][4])
                                        {
                                            jugadores[i].ficha1x = jugadores[i].ficha1x - 2;
                                            if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[jugadores[i].salidax][jugadores[i].saliday])
                                            {
                                                jugadores[i].ficha1x = jugadores[i].ficha1x + 1;
                                                jugadores[i].ficha1y = jugadores[i].ficha1y - 1;
                                            }
                                        }
                                    }
                                    if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] != tablero[jugadores[i].salidax][jugadores[i].saliday])
                                    {
                                        if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[0][jugadores[i].ficha1y])
                                        {
                                            jugadores[i].ficha1y = jugadores[i].ficha1y - 2;
                                            if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[jugadores[i].salidax][jugadores[i].saliday])
                                            {
                                                jugadores[i].ficha1y = jugadores[i].ficha1y +1;
                                                jugadores[i].ficha1x = jugadores[i].ficha1x + 1;
                                            }
                                        }
                                    }
                                    if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] != tablero[jugadores[i].salidax][jugadores[i].saliday])
                                    {
                                        if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[3][jugadores[i].ficha1y])
                                        {
                                            jugadores[i].ficha1y = jugadores[i].ficha1y + 2;
                                            if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[3][5])
                                            {
                                                jugadores[i].ficha1y = jugadores[i].ficha1y -1;
                                                jugadores[i].ficha1x = jugadores[i].ficha1x +1;
                                            }
                                        }
                                    }

                                    if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[jugadores[i].llegadax][jugadores[i].llegaday])
                                    {
                                        jugadores[i].fichasfinales = jugadores[i].fichasfinales + 1;
                                        if (jugadores[i].fichasfinales == 2)
                                        {
                                            finalista=true;
                                            //  ganador()
                                        }
                                    }
                                    if (jugadores[i].nombre ==jugadores[0].nombre)
                                    {
                                        tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='@';
                                        tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=1;
                                        vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                                    }
                                    if (jugadores[i].nombre ==jugadores[1].nombre)
                                    {
                                        tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='#';
                                        tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=2;
                                        vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                                    }
                                    if (jugadores[i].nombre ==jugadores[2].nombre)
                                    {
                                        tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='$';
                                        tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=3;
                                        vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                                    }
                                    if (jugadores[i].nombre ==jugadores[3].nombre)
                                    {
                                        tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='&';
                                        tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=4;
                                        vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                                    }
                                }
                            }
                            if (dadox == 4)
                            {
                                if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[jugadores[i].ficha1x][1])
                                {
                                    tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='-';
                                    jugadores[i].ficha1x = jugadores[i].ficha1x + 3;
                                    jugadores[i].ficha1y = jugadores[i].ficha1y + 1;

                                    if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[4][1])
                                    {
                                        jugadores[i].ficha1x = jugadores[i].ficha1x -1;
                                        jugadores[i].ficha1y = jugadores[i].ficha1y +1;
                                    }
                                }
                                if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[jugadores[i].ficha1x][4])
                                {
                                    jugadores[i].ficha1x = jugadores[i].ficha1x - 2;
                                    if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[jugadores[i].salidax][jugadores[i].saliday])
                                    {
                                        jugadores[i].ficha1x = jugadores[i].ficha1x + 1;
                                        jugadores[i].ficha1y = jugadores[i].ficha1y - 1;
                                    }
                                }
                                if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[0][jugadores[i].ficha1y])
                                {
                                    jugadores[i].ficha1y = jugadores[i].ficha1y - 2;
                                    if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[jugadores[i].salidax][jugadores[i].saliday])
                                    {
                                        jugadores[i].ficha1y = jugadores[i].ficha1y +1;
                                        jugadores[i].ficha1x = jugadores[i].ficha1x + 1;
                                    }
                                }
                                if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[3][jugadores[i].ficha1y])
                                {
                                    jugadores[i].ficha1y = jugadores[i].ficha1y + 2;
                                    if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[3][5])
                                    {
                                        jugadores[i].ficha1y = jugadores[i].ficha1y -1;
                                        jugadores[i].ficha1x = jugadores[i].ficha1x +1;
                                    }
                                }
                                if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[0][2])
                                {
                                    jugadores[i].ficha1x = jugadores[i].ficha1x + 1;
                                }
                                if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[1][2])
                                {
                                    jugadores[i].fichasfinales++;
                                    if (jugadores[i].fichasfinales == 2)
                                    {
                                        finalista=true;
                                        //  ganador()
                                    }
                                }
                                if (jugadores[i].nombre ==jugadores[0].nombre)
                                {
                                    tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='@';
                                    tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=1;
                                    vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                                }
                                if (jugadores[i].nombre ==jugadores[1].nombre)
                                {
                                    tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='#';
                                    tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=2;
                                    vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                                }
                                if (jugadores[i].nombre ==jugadores[2].nombre)
                                {
                                    tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='$';
                                    tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=3;
                                    vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                                }
                                if (jugadores[i].nombre ==jugadores[3].nombre)
                                {
                                    tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='&';
                                    tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=4;
                                    vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                                }
                            }
                            if (jugadores[i].nu5 == true)
                            {
                                if (dadox == 5)
                                {
                                    if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[jugadores[i].ficha1x][1])
                                    {
                                        jugadores[i].ficha1x = jugadores[i].ficha1x + 2;
                                        if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[4][1])
                                        {
                                            jugadores[i].ficha1x = jugadores[i].ficha1x -1;
                                            jugadores[i].ficha1y = jugadores[i].ficha1y +1;
                                        }
                                    }
                                    if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[jugadores[i].ficha1x][4])
                                    {
                                        jugadores[i].ficha1x = jugadores[i].ficha1x - 2;
                                        if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[jugadores[i].salidax][jugadores[i].saliday])
                                        {
                                            jugadores[i].ficha1x = jugadores[i].ficha1x + 1;
                                            jugadores[i].ficha1y = jugadores[i].ficha1y - 1;
                                        }
                                    }
                                    if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[0][jugadores[i].ficha1y])
                                    {
                                        jugadores[i].ficha1y = jugadores[i].ficha1y - 2;
                                        if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[jugadores[i].salidax][jugadores[i].saliday])
                                        {
                                            jugadores[i].ficha1y = jugadores[i].ficha1y +1;
                                            jugadores[i].ficha1x = jugadores[i].ficha1x + 1;
                                        }
                                    }
                                    if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[3][jugadores[i].ficha1y])
                                    {
                                        jugadores[i].ficha1y = jugadores[i].ficha1y + 2;
                                        if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[3][5])
                                        {
                                            jugadores[i].ficha1y = jugadores[i].ficha1y -1;
                                            jugadores[i].ficha1x = jugadores[i].ficha1x +1;
                                        }
                                    }
                                    if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[0][2])
                                    {
                                        jugadores[i].ficha1x = jugadores[i].ficha1x + 1;
                                    }
                                    if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[1][2])
                                    {
                                        jugadores[i].fichasfinales++;
                                        if (jugadores[i].fichasfinales == 2)
                                        {
                                            finalista=true;
                                            //  ganador()
                                        }
                                    }
                                    if (jugadores[i].nombre ==jugadores[0].nombre)
                                    {
                                        tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='@';
                                        tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=1;
                                        vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                                    }
                                    if (jugadores[i].nombre ==jugadores[1].nombre)
                                    {
                                        tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='#';
                                        tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=2;
                                        vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                                    }
                                    if (jugadores[i].nombre ==jugadores[2].nombre)
                                    {
                                        tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='$';
                                        tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=3;
                                        vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                                    }
                                    if (jugadores[i].nombre ==jugadores[3].nombre)
                                    {
                                        tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='&';
                                        tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=4;
                                        vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                                    }
                                }
                            }
                            if (jugadores[i].nu6 == true)
                            {
                                if (dadox == 6)
                                {
                                    if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[jugadores[i].ficha1x][1])
                                    {
                                        tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='-';
                                        jugadores[i].ficha1x = jugadores[i].ficha1x + 6;
                                        if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[tamtabx][1])
                                        {
                                            jugadores[i].ficha1x = jugadores[i].ficha1x - 3;
                                            jugadores[i].ficha1y = jugadores[i].ficha1y + 3;


                                        }

                                        if (jugadores[i].nombre ==jugadores[0].nombre)
                                        {
                                            tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='@';
                                            tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=1;
                                            vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                                        }
                                        if (jugadores[i].nombre ==jugadores[1].nombre)
                                        {
                                            tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='#';
                                            tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=2;
                                            vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                                        }
                                        if (jugadores[i].nombre ==jugadores[2].nombre)
                                        {
                                            tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='$';
                                            tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=3;
                                            vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                                        }
                                        if (jugadores[i].nombre ==jugadores[3].nombre)
                                        {
                                            tablero[jugadores[i].ficha1x][jugadores[i].ficha1y]='&';
                                            tablerofantasma[jugadores[i].ficha1x][jugadores[i].ficha1y]=4;
                                            vista(tablero,tablerofantasma,jugadores,numjug,tamtabx,tamtaby);
                                        }
                                    }
                                    if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[jugadores[i].ficha1x][4])
                                    {
                                        jugadores[i].ficha1x = jugadores[i].ficha1x - 2;
                                        if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[jugadores[i].salidax][jugadores[i].saliday])
                                        {
                                            jugadores[i].ficha1x = jugadores[i].ficha1x + 1;
                                            jugadores[i].ficha1y = jugadores[i].ficha1y - 1;
                                        }
                                    }
                                    if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[0][jugadores[i].ficha1y])
                                    {
                                        jugadores[i].ficha1y = jugadores[i].ficha1y - 2;
                                        if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[jugadores[i].salidax][jugadores[i].saliday])
                                        {
                                            jugadores[i].ficha1y = jugadores[i].ficha1y +1;
                                            jugadores[i].ficha1x = jugadores[i].ficha1x + 1;
                                        }
                                    }
                                    if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[3][jugadores[i].ficha1y])
                                    {
                                        jugadores[i].ficha1y = jugadores[i].ficha1y + 2;
                                        if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[3][5])
                                        {
                                            jugadores[i].ficha1y = jugadores[i].ficha1y -1;
                                            jugadores[i].ficha1x = jugadores[i].ficha1x +1;
                                        }
                                    }
                                    if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[0][2])
                                    {
                                        jugadores[i].ficha1x = jugadores[i].ficha1x + 1;
                                    }
                                    if (tablero[jugadores[i].ficha1x][jugadores[i].ficha1y] == tablero[1][2])
                                    {
                                        jugadores[i].fichasfinales++;
                                        if (jugadores[i].fichasfinales == 2)
                                        {
                                            finalista=true;
                                            //  ganador()
                                        }
                                    }
                                }
                            }
                        }
                    }

                }
            }
        }
        salio = false;
        contador = 0;
        i++;
        if (jugadores[i].fichas == false)
        {
            lanzamientos = 3;
            contador =0;
        }
        Sleep(2000);
        system("cls");
    }
    while(finalista == false);
}
void ganador ()
{
    cout<<"has ganado felicidades jugador"<<endl;
}

