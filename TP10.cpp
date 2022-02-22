#include<iostream>
//#include<conio.h>
#include<cstdlib>
#include"rlutil.h"
#include"funciones.h"

using namespace std;
using namespace rlutil;

int main(){
int Posx=45,posy=12;    //Variables para las posiciones de las opciones del menu.
    int opcion = 0, tecla,rondasMay=999999;
    int cursorx = Posx-2, cursory = posy+2;//variables para la posicion del cursor en el menu.
    char vecNombres[20]={"NO HAY NOMBRES"};
    ///VARIABLES UN JUGADOR

    ///--------------///

  setBackgroundColor(0);

  do{

     setColor(CYAN);
     DibujarCuadro(Posx,posy);

     setColor(YELLOW);
     gotoxy(Posx-2,posy-2);
     cout<<" JUEGO DE DADOS 10.000"<<endl;

     setColor(RED);
     gotoxy(Posx-2,posy);
     cout<<" MODO UN JUGADOR"<<endl;

     setColor(GREEN);
     gotoxy(Posx-2,posy+2);
     cout<<" MODO DOS JUGADORES"<<endl;

     setColor(LIGHTBLUE);
     gotoxy(Posx-2,posy+4);
     cout<<" PUNTUACIONES MAS ALTAS"<<endl;

     setColor(MAGENTA);
     gotoxy(Posx-2,posy+6);
     cout<<" SALIR";

     gotoxy(cursorx-2, cursory-2);

     setColor(6);
     cout<<(char)175;


     tecla = getch();
     gotoxy(cursorx-2, cursory-2);
     cout<<(char) 32;

    switch(tecla){
        case 72:
            cursory-=2;
            if(cursory < posy+2){
                cursory = posy+2;

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

                case 14:
                    modo_un_jugador(Posx,posy,vecNombres,&rondasMay);

                    break;

                case 16:
                    modo_dos_jugadores(Posx,posy,vecNombres,&rondasMay);
                    ///MODO DOS JUGADORES.
                    break;

                case 18:
                    cls();
                    DibujarCuadro(Posx,posy);
                    gotoxy(Posx-4,posy+3);
                    if(rondasMay==999999){
                            cout<<"JUGADOR: "<<vecNombres<<" EN 0 RONDAS :)"<<endl;
                     }else{
                            cout<<"JUGADOR: "<<vecNombres<<" en "<<rondasMay<<" RONDAS :)"<<endl;
                         }

                    getch();
                    cls();
                    break;

                case 20:
                    cout<<"HASTA LUEGO/SAYONARA/GOODBYE"<<endl;
                    opcion=5; ///SALIDA.
                    break;
            }
    }

  }while(opcion!=5);
cls();
cout<<"\n"<<endl;
 gotoxy(Posx,posy+5);system("pause");
 return 0;
}









