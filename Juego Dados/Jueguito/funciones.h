#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


#include<iostream>
///#include<cmath>
#include<conio.h>
#include<cstdlib>
#include"rlutil.h"
#include"funciones.h"
#include<ctime>

using namespace rlutil;
using namespace std;

void TirarDados(int VecDados[],int T);
void MostrarDados(int V[],int T);
int SumarPuntos(int Dados[],int T);
void modo_un_jugador(int Posx, int posy);


/*int main(){
  const int T=5;
  int Dados[T],Puntos1,Puntos2;

  TirarDados(Dados,T);
  MostrarDados(Dados,T);
  Puntos1=SumarPuntos(Dados,T);
  cout<<"PUNTOS JUGADOR 1: "<<Puntos1<<endl;
  system("pause");


  TirarDados(Dados,T);
  MostrarDados(Dados,T);
  Puntos2=SumarPuntos(Dados,T);
  cout<<"PUNTOS JUGADOR 2: "<<Puntos2<<endl;
  system("pause");


  if(Puntos1>Puntos2){
    cout<<"GANO J1"<<endl;
  }
  else if(Puntos2>Puntos1){
    cout<<"GANO J2"<<endl;
  }
  else{
    cout<<"EMPATARON"<<endl;
  }

system("pause");
return 0;
}
*/

void TirarDados(int VecDados[], int T){
srand(time(NULL));
int I;
for(I=0;I<T;I++){
VecDados[I]=(rand()%6)+1;
}
}

void MostrarDados(int V[],int T){
int I;
for(I=0;I<T;I++){
    cout<<V[I]<<endl;
    }
}

int SumarPuntos(int Dados[], int T){
int I, suma=0;
for(I=0;I<T;I++){
    suma+=Dados[I];
    }
return suma;
}

void modo_un_jugador(int Posx, int posy){
    char nombre[10];             ///UN JUGADOR
    int const T=6;///COL NAIN UAN UAN
    int tirada=1,enter ,VecDados[T], Puntos=0;

    cls();
                gotoxy(Posx,posy+5);
                cout<<"-Nombre del jugador-";
                gotoxy(Posx,posy+6);
                cin>>nombre;
                cls();

                gotoxy(Posx,posy+5);
                cout<<"IRASSHAIMASE "<<nombre<<"-sama!";
                gotoxy(Posx,posy+7);
                system("pause");   ///se me enojo sofi send help
                /* PARTE VISUAL (tirar dados = teclaEspecifica)*/
                system("pause");



                while (Puntos!=10000){
                        if(tirada==1){
                        cout<<"tire los dados!";enter=getch();tirada++;TirarDados(VecDados,T);};
                        /*Preguntar si quiere cambiar algun dado*/
                        /* habilitar elegir los dados manualmente (mover cursor), levantar VisualDadosY+1*/

                }
}







#endif // FUNCIONES_H_INCLUDED
