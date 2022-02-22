#include<iostream>
///#include<cmath>
#include<conio.h>
#include<cstdlib>
#include"rlutil.h"
#include"funciones.h"
using namespace std;
using namespace rlutil;

/*-------------HELP----------------------------------------------*/int main()/*-----------------------------------------------------------*/
{
int Posx=45,posy=15;
  int opcion = 0, tecla;
  int cursorx = Posx-2, cursory = posy;

  setBackgroundColor(0);

  do{
     cls();
     setColor(YELLOW);
     gotoxy(Posx,posy);
     cout<<" Jueguito de dado 10.000"<<endl;

     setColor(RED);
     gotoxy(Posx,posy+2);
     cout<<" Juego nuevo para un jugador."<<endl;

     setColor(2);
     gotoxy(Posx,posy+4);
     cout<<" Juego nuevo para dos jugadores"<<endl;

     setColor(3);
     gotoxy(Posx,posy+6);
     cout<<" Puntuacion mas alta"<<endl;

     setColor(5);
     gotoxy(Posx,posy+8);
     cout<<" Salir";

     gotoxy(cursorx, cursory);

     setColor(6);
     cout<<(char)175;

     tecla = getch();

    switch(tecla){
        case 72:
            cursory-=2;
            if(cursory < posy){
                cursory = posy;

            }
            break;
        case 80:
            cursory+=2;
            if(cursory > posy+8){
                cursory = posy+8;
            }
            break;
        case 13:
            switch(cursory){

            case 17:
 char nombre[10];             ///UN JUGADOR
                int const T=6;///COL NAIN UAN UAN
                int tirada=1,enter ,VecDados[T], Puntos=0;

                cls();
                gotoxy(Posx,posy+5);
                cout<<"-Nombre del jugador-";
                gotoxy(Posx,posy+6);
                cin>>nombre;
                cls();

                gotoxy(Posx,posy+5);              /// Gotoxy es puta y no quiere leer las x, gotoxy hace drama con \n
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


                ///Hice mal, Full of   R E G E R T Z

                };



                break;

            case 19:
                break;

            case 23:
                opcion=5;
            break;
            }
    }



  }while(opcion!=5);
cls();
cout<<"\n"<<endl;
 gotoxy(Posx,posy+5);system("pause");
 return 0;
 }




