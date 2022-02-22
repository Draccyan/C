#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include<iostream>
#include<cstdlib>
#include"rlutil.h"
#include"funciones.h"
#include<ctime>


///HECHO POR ZAIR MAR, SOFIA VIGLIACCIO, ADRIANO PISTOIA :)

using namespace rlutil;
using namespace std;

void TirarDados(int VecDados[],int T);
void MostrarDados(int V[],int T);
int SumarPuntos(int Dados[],int T);
void modo_un_jugador(int Posx, int posy,char vecNombre[],int *rondasMay);
int EncontrarCombinaciones(int Posx, int posy,char vecNombre[],int *rondasMay);
void guardarRondas(int rondas,int *rondasMay,char vecNombre[],char jugadorGanador[]);

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
    cout<<V[I]<<" ";

    }
}

void DibujarCuadro(int Posx, int posy){
int i;
gotoxy(Posx-15,posy-7);
for(i=0;i<55;i++){
    cout<<(char)205;
}
gotoxy(Posx-15,posy+15);
for(i=0;i<55;i++){
    cout<<(char)205;
}
gotoxy(Posx-15,posy-7);
for(i=0;i<55;i++){
    cout<<(char)205;
}
for(i=posy-7;i<posy+15;i++){
    gotoxy(Posx-15,i);
    cout<<(char)186<<endl;
}
for(i=posy-7;i<posy+15;i++){
    gotoxy(Posx+39,i);
    cout<<(char)186<<endl;
}

gotoxy(Posx-15,posy-7);
cout<<(char)201;
gotoxy(Posx+39,posy-7);
cout<<(char)187;
gotoxy(Posx-15,posy+15);
cout<<(char)200;
gotoxy(Posx+39,posy+15);
cout<<(char)188;





}

/*void VolverATirar(int Dados[], int x){
srand(time(NULL));
Dados[x]=(rand()%6)+1;
}*/

int EncontrarCombinaciones(int V[],int T){
int Puntos=0, VectorC[6]={},j=0,i=0;
bool VecCombinaciones[9]={false};
int VecPuntos[9]={100,50,1000,100,200,2000,1000,1500,10000};
char NombresCombinaciones[9][20]={"Juego de 1","Juego de 5","Trio 1","Trio X","Trio X++","Trio 1 Ampliado","Tres Pares","Escalera","Sexteto"};

        for(i=0;i<T;i++){
            for(j=1;j<=6;j++){
                if(V[i]==j){
                    VectorC[j-1]++;
                }
            }
        }

        /**---------Sexteto---------**/
        if(VectorC[0]==6){
        ///cout<<NombresCombinaciones[8]<<endl;
        VecCombinaciones[8]=true;
        Puntos=VecPuntos[8];

        /**---------Trio 1 Ampliado---------**/
        }else if((VectorC[0]>=4)&&(Puntos+2000<=10000)){
        ///cout<<NombresCombinaciones[5]<<endl;
        VecCombinaciones[5]=true;
        Puntos=VecPuntos[5];

        /**---------Trio 1---------**/
        }else if((VectorC[0]==3)&&(Puntos+1000<=10000)){
        ///cout<<NombresCombinaciones[2]<<endl;
        VecCombinaciones[2]=true;
        Puntos=VecPuntos[2];

        /**---------Juego de 1---------**/
        }else if((VectorC[0]<=2&&VectorC[0]!=0)&&(Puntos+VectorC[0]*100<=10000)){
        ///cout<<NombresCombinaciones[0]<<endl;
        VecCombinaciones[0]=true;
        VecPuntos[0]=VectorC[0]*VecPuntos[0];
        }

        /**---------Escalera---------**/
        int cont=0;
        for(i=0;i<T;i++){
        if(VectorC[i]==1){
        cont++;
        }
        }
        if(cont==6){
        ///cout<<NombresCombinaciones[7]<<endl;
        VecCombinaciones[7]=true;
        Puntos=VecPuntos[7];
        }

        /**---------Tres Pares---------**/
        int TparC=0;
        if(VectorC[0]!=6){
            for(i=0;i<T;i++){
                if(VectorC[i]==2){
                    TparC++;
                }else if(VectorC[i]==4){
                    TparC+=2;
                }else if(VectorC[i]==6){
                    TparC+=3;
                    }
                }
                if(TparC==3&&Puntos+1000<=10000){
                ///cout<<NombresCombinaciones[6]<<endl;
                VecCombinaciones[6]=true;
                Puntos=VecPuntos[6];
                    }
                }

        /**---------Trio X++---------**/
        for(i=1;i<T;i++){
        if(VectorC[i]>=4){
        ///cout<<NombresCombinaciones[4]<<endl;
        VecCombinaciones[4]=true;
        VecPuntos[4]=(i+1)*VecPuntos[4];
        }
        }

        /**---------Trio X---------**/
        for(i=1;i<T;i++){
        if(VectorC[i]==3){
        ///cout<<NombresCombinaciones[3]<<endl;
        VecCombinaciones[3]=true;
        VecPuntos[3]=(i+1)*VecPuntos[3];
        }
        }

        /**---------Juego de 5---------**/
        if(VectorC[4]<=2&&VectorC[4]!=0){
        ///cout<<NombresCombinaciones[1]<<endl;
        VecCombinaciones[1]=true;
        VecPuntos[1]=VectorC[4]*VecPuntos[1];
        }

        int MayorPuntaje=0;
        int IndiceMayor=9;
        for(i=0;i<9;i++){
            if(VecCombinaciones[i]==true&&VecPuntos[i]>MayorPuntaje){
                    MayorPuntaje=VecPuntos[i];
                    IndiceMayor=i;

            }
        }
        if(IndiceMayor!=9){
            cout<<"COMBINACION: "<<NombresCombinaciones[IndiceMayor];
        }else{
            cout<<"No salio ninguna combinacion ganadora";
        }

return MayorPuntaje;
}

void modo_un_jugador(int Posx, int posy,char vecNombre[],int *rondasMay){
    char nombre[15],Respuesta='n';
    int const T=6;
    int VecDados[T]={};
    int opcion,i;
    int PuntosTotales=0,Puntos=0,Ronda=0,PuntosAcumulados=0;

    cls();

                setColor(CYAN);
                DibujarCuadro(Posx,posy);

                gotoxy(Posx,posy+2);
                cout<<"-NOMBRE DEL JUGADOR-";
                gotoxy(Posx,posy+4);
                cin>>nombre;
                cls();
                setColor(CYAN);
                DibujarCuadro(Posx,posy);

                gotoxy(Posx,posy+2);
                cout<<"IRASSHAIMASE "<<nombre<<"-SAMA!";
                gotoxy(Posx,posy+4);
                cout<<"COMO QUIERE TIRAR LOS DADOS?"<<endl;
                gotoxy(Posx,posy+5);
                cout<<"1-MANUALMENTE"<<endl;
                gotoxy(Posx,posy+6);
                cout<<"2-ALEATORIO"<<endl;
                gotoxy(Posx,posy+7);
                cin>>opcion;


                while (PuntosTotales<10000){

                        cls();
                        setColor(CYAN);
                        DibujarCuadro(Posx,posy);

                        switch(opcion){
                        case 1:

                            gotoxy(Posx-4,posy-5);
                            cout<<nombre<<endl;
                            Ronda++;
                            gotoxy(Posx-4,posy-4);
                            cout<<"RONDA: "<<Ronda<<endl;
                            gotoxy(Posx-4,posy-3);
                            cout<<"PUNTOS TOTALES: "<<PuntosTotales<<endl;

                            for(i=0;i<T;i++){
                            cls();
                            setColor(CYAN);
                            DibujarCuadro(Posx,posy);
                            gotoxy(Posx-4,posy-1);
                            cout<<"INGRESE EL DADO "<<i+1<<" : ";
                            cin>>VecDados[i];
                            }

                            cls();
                            setColor(CYAN);
                            DibujarCuadro(Posx,posy);
                            gotoxy(Posx-4,posy-5);
                            cout<<nombre<<endl;
                            gotoxy(Posx-4,posy-4);
                            cout<<"RONDA: "<<Ronda<<endl;
                            gotoxy(Posx-4,posy-3);
                            cout<<"PUNTOS TOTALES: "<<PuntosTotales<<endl;
                            gotoxy(Posx-4,posy);
                            MostrarDados(VecDados,T);
                            gotoxy(Posx-4,posy+1);
                            Puntos=EncontrarCombinaciones(VecDados,T);
                            gotoxy(Posx-4,posy+2);
                            cout<<"PUNTOS DEL TIRO: "<<Puntos<<endl;
                            if(Puntos==0){
                                    PuntosAcumulados=0;
                                }else{
                                   PuntosAcumulados+=Puntos;
                                }
                                gotoxy(Posx-4,posy+3);
                                cout<<"PUNTOS ACUMULADOS: "<<PuntosAcumulados<<endl;

                            gotoxy(Posx-4,posy+4);
                            cout<<endl;

                            if(Puntos!=0){
                            do{
                            gotoxy(Posx-4,posy+5);
                            cout<<"QUIERE VOLVER A TIRAR LOS DADOS?(s/n)"<<endl;
                            gotoxy(Posx-4,posy+6);
                            cin>>Respuesta;

                            if(Respuesta=='s'){
                                cls();
                                setColor(CYAN);
                                DibujarCuadro(Posx,posy);

                                gotoxy(Posx-4,posy-5);
                                cout<<nombre<<endl;
                                gotoxy(Posx-4,posy-4);
                                cout<<"RONDA: "<<Ronda<<endl;
                                gotoxy(Posx-4,posy-3);
                                cout<<"PUNTOS TOTALES: "<<PuntosTotales<<endl;
                                for(i=0;i<T;i++){
                                cls();
                                setColor(CYAN);
                                DibujarCuadro(Posx,posy);
                                gotoxy(Posx-4,posy-4);
                                cout<<"RONDA: "<<Ronda<<endl;
                                gotoxy(Posx-4,posy-2);
                                cout<<"INGRESE EL DADO "<<i+1<<" : ";
                                cin>>VecDados[i];
                                }
                                cls();
                                setColor(CYAN);
                                DibujarCuadro(Posx,posy);
                                gotoxy(Posx-4,posy-5);
                                cout<<nombre<<endl;
                                gotoxy(Posx-4,posy-4);
                                cout<<"RONDA: "<<Ronda<<endl;
                                gotoxy(Posx-4,posy-3);
                                cout<<"PUNTOS TOTALES: "<<PuntosTotales<<endl;
                                gotoxy(Posx-4,posy-1);
                                MostrarDados(VecDados,T);
                                gotoxy(Posx-4,posy);
                                Puntos=EncontrarCombinaciones(VecDados,T);
                                gotoxy(Posx-4,posy+1);
                                cout<<"PUNTOS DEL TIRO: "<<Puntos<<endl;
                                if(Puntos==0){
                                    PuntosAcumulados=0;
                                    Respuesta='n';
                                }else{
                                   PuntosAcumulados+=Puntos;
                                }
                                gotoxy(Posx-4,posy+2);
                                cout<<"PUNTOS ACUMULADOS: "<<PuntosAcumulados<<endl;
                            }
                            }while(Respuesta=='s');
                            }
                            if((PuntosTotales+PuntosAcumulados)>10000){
                                PuntosTotales+=0;
                            }else{
                                PuntosTotales+=PuntosAcumulados;
                            }
                            gotoxy(Posx-4,posy+9);
                            cout<<"PUNTOS DE LA RONDA: "<<PuntosAcumulados<<endl;
                            PuntosAcumulados=0;
                            gotoxy(Posx-4,posy+10);
                            getch();

                            break;

                        case 2:
                            gotoxy(Posx-4,posy-5);
                            cout<<nombre<<endl;
                            Ronda++;
                            gotoxy(Posx-4,posy-4);
                            cout<<"RONDA: "<<Ronda<<endl;
                            gotoxy(Posx-4,posy-3);
                            cout<<"PUNTOS TOTALES: "<<PuntosTotales<<endl;
                            gotoxy(Posx-4,posy-2);
                            cout<<"TIRE LOS DADOS!"<<endl;
                            gotoxy(Posx+17,posy-2);
                            getch();
                            TirarDados(VecDados,T);
                            gotoxy(Posx-4,posy);
                            MostrarDados(VecDados,T);
                            gotoxy(Posx-4,posy+1);
                            Puntos=EncontrarCombinaciones(VecDados,T);
                            gotoxy(Posx-4,posy+2);
                            cout<<"PUNTOS DEL TIRO: "<<Puntos<<endl;
                            if(Puntos==0){
                                    PuntosAcumulados=0;
                                    Respuesta='n';
                                }else{
                                   PuntosAcumulados+=Puntos;
                                }
                                gotoxy(Posx-4,posy+3);
                                cout<<"PUNTOS ACUMULADOS: "<<PuntosAcumulados<<endl;

                            gotoxy(Posx-4,posy+4);
                            cout<<endl;

                            if(Puntos!=0){
                            do{
                            gotoxy(Posx-4,posy+5);
                            cout<<"QUIERE VOLVER A TIRAR LOS DADOS?(s/n)"<<endl;
                            gotoxy(Posx-4,posy+6);
                            cin>>Respuesta;
                            if(Puntos==0){
                                Respuesta='n';
                            }
                            if(Respuesta=='s'){
                                cls();
                                setColor(CYAN);
                                DibujarCuadro(Posx,posy);
                                gotoxy(Posx-4,posy-5);
                                cout<<nombre<<endl;
                                gotoxy(Posx-4,posy-4);
                                cout<<"RONDA: "<<Ronda<<endl;
                                gotoxy(Posx-4,posy-3);
                                cout<<"PUNTOS TOTALES: "<<PuntosTotales<<endl;
                                TirarDados(VecDados,T);
                                gotoxy(Posx-4,posy-2);
                                MostrarDados(VecDados,T);
                                gotoxy(Posx-4,posy-1);
                                Puntos=EncontrarCombinaciones(VecDados,T);
                                gotoxy(Posx-4,posy);
                                cout<<"PUNTOS DEL TIRO: "<<Puntos<<endl;
                                if(Puntos==0){
                                    PuntosAcumulados=0;
                                    Respuesta='n';
                                }else{
                                   PuntosAcumulados+=Puntos;
                                }
                                gotoxy(Posx-4,posy+1);
                                cout<<"PUNTOS ACUMULADOS: "<<PuntosAcumulados<<endl;
                            }
                            }while(Respuesta=='s');
                            }
                            if((PuntosTotales+PuntosAcumulados)>10000){
                                PuntosTotales+=0;
                            }else{
                                PuntosTotales+=PuntosAcumulados;
                            }
                            gotoxy(Posx-4,posy+9);
                            cout<<"PUNTOS DE LA RONDA: "<<PuntosAcumulados<<endl;
                            PuntosAcumulados=0;
                            gotoxy(Posx-4,posy+10);
                            getch();
                        }
                    }
        cls();
        setColor(CYAN);
        DibujarCuadro(Posx,posy);
        gotoxy(Posx-4,posy+5);
        cout<<"GANASTE EL JUEGO, FELICITACIONES :D"<<endl;
        gotoxy(Posx-4,posy+6);
        cout<<"GANASTE EN "<<Ronda<<" RONDAS"<<endl;
        guardarRondas(Ronda,rondasMay,vecNombre,nombre);
        gotoxy(Posx-4,posy+7);
        getch();
        cls();
}

void modo_dos_jugadores(int Posx,int posy,char vecNombre[],int *rondasMay){
char nombreJ1[10],nombreJ2[10],Respuesta='n';
    int const T=6;
    int VecDados[T]={};
    int opcion,i;
    int PuntosTotalesJ1=0,PuntosTotalesJ2=0;
    int PuntosJ1=0,PuntosJ2=0;
    int PuntosAcumuladosJ1=0,PuntosAcumuladosJ2=0;
    int Ronda=0,Turno=0;

    cls();
    setColor(CYAN);
    DibujarCuadro(Posx,posy);


                gotoxy(Posx-4,posy-5);
                cout<<"-NOMBRE DEL JUGADOR 1-";
                gotoxy(Posx-4,posy-4);
                cin>>nombreJ1;
                cls();
                setColor(CYAN);
                DibujarCuadro(Posx,posy);


                gotoxy(Posx-4,posy-5);
                cout<<"-NOMBRE DEL JUGADOR 2-";
                gotoxy(Posx-4,posy-4);
                cin>>nombreJ2;
                cls();
                setColor(CYAN);
                DibujarCuadro(Posx,posy);


                gotoxy(Posx-4,posy-5);
                cout<<"IRASSHAIMASE "<<nombreJ1<<"-SAMA!";
                gotoxy(Posx-4,posy-4);
                cout<<"IRASSHAIMASE "<<nombreJ2<<"-SAMA!";
                gotoxy(Posx-4,posy-3);
                getch();

                gotoxy(Posx-4,posy-2);
                cout<<"COMO QUIERE TIRAR LOS DADOS?"<<endl;
                gotoxy(Posx-4,posy-1);
                cout<<"1-MANUALMENTE"<<endl;
                gotoxy(Posx-4,posy);
                cout<<"2-ALEATORIO"<<endl;
                gotoxy(Posx-4,posy+1);
                cin>>opcion;

                while (PuntosTotalesJ1<10000&&PuntosTotalesJ2<10000){

                        cls();

                        setColor(CYAN);
                        DibujarCuadro(Posx,posy);
                        switch(opcion){
                        case 1:
                            Turno++;
                            if(Turno%2!=0){
                            Ronda++;
                            gotoxy(Posx-4,posy+3);
                            cout<<"RONDA: "<<Ronda;
                            gotoxy(Posx-4,posy+4);
                            cout<<nombreJ1<<" PUNTOS : "<<PuntosTotalesJ1;
                            gotoxy(Posx-4,posy+5);
                            cout<<nombreJ2<<" PUNTOS : "<<PuntosTotalesJ2;
                            getch();
                            cls();

                            DibujarCuadro(Posx,posy);

                            cout<<"TURNO DEL JUGADOR 1"<<endl;

                            for(i=0;i<T;i++){
                            cls();
                            setColor(CYAN);
                            DibujarCuadro(Posx,posy);
                            gotoxy(Posx-4,posy-1);
                            cout<<"INGRESE EL DADO "<<i+1<<" : ";
                            cin>>VecDados[i];
                            }
                            cls();
                            setColor(CYAN);
                            DibujarCuadro(Posx,posy);
                            gotoxy(Posx-4,posy-5);
                            cout<<"TURNO "<<nombreJ1<<endl;
                            gotoxy(Posx-4,posy-4);
                            cout<<"RONDA: "<<Ronda<<endl;
                            gotoxy(Posx-4,posy-3);
                            cout<<"PUNTOS TOTALES: "<<PuntosTotalesJ1<<endl;
                            gotoxy(Posx-4,posy);
                            MostrarDados(VecDados,T);
                            gotoxy(Posx-4,posy+1);
                            PuntosJ1=EncontrarCombinaciones(VecDados,T);
                            gotoxy(Posx-4,posy+2);
                            cout<<"PUNTOS DEL TIRO: +"<<PuntosJ1<<endl;
                            if(PuntosJ1==0){
                                    PuntosAcumuladosJ1=0;
                                    Respuesta='n';
                                }else{
                                   PuntosAcumuladosJ1+=PuntosJ1;
                                }
                                gotoxy(Posx-4,posy+3);
                                cout<<"PUNTOS ACUMULADOS: "<<PuntosAcumuladosJ1<<endl;

                            gotoxy(Posx-4,posy+4);
                            cout<<endl;

                            if(PuntosJ1!=0){
                            do{
                            gotoxy(Posx-4,posy+5);
                            cout<<"QUIERE VOLVER A TIRAR LOS DADOS?(s/n)"<<endl;
                            gotoxy(Posx-4,posy+6);
                            cin>>Respuesta;

                            if(Respuesta=='s'&&PuntosJ1!=0){
                                cls();
                                setColor(CYAN);
                                DibujarCuadro(Posx,posy);

                                gotoxy(Posx-4,posy-5);
                                cout<<"TURNO DE "<<nombreJ1<<endl;
                                gotoxy(Posx-4,posy-4);
                                cout<<"RONDA: "<<Ronda<<endl;
                                gotoxy(Posx-4,posy-3);
                                cout<<"PUNTOS TOTALES: "<<PuntosTotalesJ1<<endl;
                                for(i=0;i<T;i++){
                                cls();
                                setColor(CYAN);
                                DibujarCuadro(Posx,posy);
                                gotoxy(Posx-4,posy-2);
                                cout<<"INGRESE EL DADO "<<i+1<<" : ";
                                cin>>VecDados[i];
                                }
                                cls();
                                setColor(CYAN);
                                DibujarCuadro(Posx,posy);
                                gotoxy(Posx-4,posy-5);
                                cout<<"TURNO "<<nombreJ1<<endl;
                                gotoxy(Posx-4,posy-4);
                                cout<<"RONDA: "<<Ronda<<endl;
                                gotoxy(Posx-4,posy-3);
                                cout<<"PUNTOS TOTALES: "<<PuntosTotalesJ1<<endl;
                                gotoxy(Posx-4,posy-1);
                                MostrarDados(VecDados,T);
                                gotoxy(Posx-4,posy);
                                PuntosJ1=EncontrarCombinaciones(VecDados,T);
                                gotoxy(Posx-4,posy+1);
                                cout<<"PUNTOS DEL TIRO: +"<<PuntosJ1<<endl;
                                if(PuntosJ1==0){
                                    PuntosAcumuladosJ1=0;
                                    Respuesta='n';
                                }else{
                                   PuntosAcumuladosJ1+=PuntosJ1;
                                }
                                gotoxy(Posx-4,posy+2);
                                cout<<"PUNTOS ACUMULADOS: "<<PuntosAcumuladosJ1<<endl;
                            }
                            }while(Respuesta=='s');
                            }
                            if((PuntosTotalesJ1+PuntosAcumuladosJ1)>10000){
                                PuntosTotalesJ1+=0;
                            }else{
                                PuntosTotalesJ1+=PuntosAcumuladosJ1;
                            }
                            gotoxy(Posx-4,posy+9);
                            cout<<"PUNTOS ADQUIRIDOS: "<<PuntosAcumuladosJ1<<endl;
                            PuntosAcumuladosJ1=0;
                            gotoxy(Posx-4,posy+10);
                            getch();

                            }else{
                                cout<<"TURNO DEL JUGADOR 2"<<endl;

                            for(i=0;i<T;i++){
                            cls();
                            setColor(CYAN);
                            DibujarCuadro(Posx,posy);
                            gotoxy(Posx-4,posy-1);
                            cout<<"INGRESE EL DADO "<<i+1<<" : ";
                            cin>>VecDados[i];
                            }
                            cls();
                            setColor(CYAN);
                            DibujarCuadro(Posx,posy);
                            gotoxy(Posx-4,posy-5);
                            cout<<"TURNO "<<nombreJ2<<endl;
                            gotoxy(Posx-4,posy-4);
                            cout<<"RONDA: "<<Ronda<<endl;
                            gotoxy(Posx-4,posy-3);
                            cout<<"PUNTOS TOTALES: "<<PuntosTotalesJ2<<endl;
                            gotoxy(Posx-4,posy);
                            MostrarDados(VecDados,T);
                            gotoxy(Posx-4,posy+1);
                            PuntosJ2=EncontrarCombinaciones(VecDados,T);
                            gotoxy(Posx-4,posy+2);
                            cout<<"PUNTOS DEL TIRO: "<<PuntosJ2<<endl;
                            if(PuntosJ2==0){
                                    PuntosAcumuladosJ2=0;
                                    Respuesta='n';
                                }else{
                                   PuntosAcumuladosJ2+=PuntosJ2;
                                }
                                gotoxy(Posx-4,posy+3);
                                cout<<"PUNTOS ACUMULADOS: "<<PuntosAcumuladosJ2<<endl;

                            gotoxy(Posx-4,posy+4);
                            cout<<endl;

                            if(PuntosJ2!=0){
                            do{
                            gotoxy(Posx-4,posy+5);
                            cout<<"QUIERE VOLVER A TIRAR LOS DADOS?(s/n)"<<endl;
                            gotoxy(Posx-4,posy+6);
                            cin>>Respuesta;

                            if(Respuesta=='s'&&PuntosJ2!=0){
                                cls();
                                setColor(CYAN);
                                DibujarCuadro(Posx,posy);

                                gotoxy(Posx-4,posy-5);
                                cout<<"TURNO DE "<<nombreJ2<<endl;
                                gotoxy(Posx-4,posy-4);
                                cout<<"RONDA: "<<Ronda<<endl;
                                for(i=0;i<T;i++){
                                cls();
                                setColor(CYAN);
                                DibujarCuadro(Posx,posy);
                                gotoxy(Posx-4,posy-2);
                                cout<<"INGRESE EL DADO "<<i+1<<" : ";
                                cin>>VecDados[i];
                                }
                                cls();
                                setColor(CYAN);
                                DibujarCuadro(Posx,posy);
                                gotoxy(Posx-4,posy-5);
                                cout<<"TURNO "<<nombreJ2<<endl;
                                gotoxy(Posx-4,posy-4);
                                cout<<"RONDA: "<<Ronda<<endl;
                                gotoxy(Posx-4,posy-1);
                                MostrarDados(VecDados,T);
                                gotoxy(Posx-4,posy);
                                PuntosJ2=EncontrarCombinaciones(VecDados,T);
                                gotoxy(Posx-4,posy+1);
                                cout<<"PUNTOS DEL TIRO: +"<<PuntosJ2<<endl;
                                if(PuntosJ2==0){
                                    PuntosAcumuladosJ2=0;
                                    Respuesta='n';
                                }else{
                                   PuntosAcumuladosJ2+=PuntosJ2;
                                }
                                gotoxy(Posx-4,posy+2);
                                cout<<"PUNTOS ACUMULADOS: "<<PuntosAcumuladosJ2<<endl;
                            }
                            }while(Respuesta=='s');
                            }
                            if((PuntosTotalesJ2+PuntosAcumuladosJ2)>10000){
                                PuntosTotalesJ2+=0;
                            }else{
                                PuntosTotalesJ2+=PuntosAcumuladosJ2;
                            }
                            gotoxy(Posx-4,posy+9);
                            cout<<"PUNTOS DE LA RONDA: "<<PuntosAcumuladosJ2<<endl;
                            PuntosAcumuladosJ2=0;
                            gotoxy(Posx-4,posy+10);

                            getch();

                            break;

                        case 2:
                            Turno++;
                            if(Turno%2!=0){

                            Ronda++;
                            gotoxy(Posx-4,posy+3);
                            cout<<"RONDA: "<<Ronda;
                            gotoxy(Posx-4,posy+4);
                            cout<<nombreJ1<<" PUNTOS : "<<PuntosTotalesJ1;
                            gotoxy(Posx-4,posy+5);
                            cout<<nombreJ2<<" PUNTOS : "<<PuntosTotalesJ2;
                            getch();
                            cls();

                            DibujarCuadro(Posx,posy);

                            gotoxy(Posx-4,posy-5);
                            cout<<"TURNO DE "<<nombreJ1<<endl;
                            gotoxy(Posx-4,posy-4);
                            cout<<"RONDA: "<<Ronda<<endl;
                            gotoxy(Posx-4,posy-2);
                            cout<<"TIRE LOS DADOS!"<<endl;
                            gotoxy(Posx+17,posy-2);
                            getch();
                            TirarDados(VecDados,T);
                            gotoxy(Posx-4,posy);
                            MostrarDados(VecDados,T);
                            gotoxy(Posx-4,posy+1);
                            PuntosJ1=EncontrarCombinaciones(VecDados,T);
                            gotoxy(Posx-4,posy+2);
                            cout<<"PUNTOS DEL TIRO: +"<<PuntosJ1<<endl;
                            if(PuntosJ1==0){
                                    PuntosAcumuladosJ1=0;
                                    Respuesta='n';
                                }else{
                                   PuntosAcumuladosJ1+=PuntosJ1;
                                }
                                gotoxy(Posx-4,posy+3);
                                cout<<"PUNTOS ACUMULADOS: "<<PuntosAcumuladosJ1<<endl;

                            gotoxy(Posx-4,posy+4);
                            cout<<endl;

                            if(PuntosJ1!=0){
                            do{
                            gotoxy(Posx-4,posy+5);
                            cout<<"QUIERE VOLVER A TIRAR LOS DADOS?(s/n)"<<endl;
                            gotoxy(Posx-4,posy+6);
                            cin>>Respuesta;

                            if(Respuesta=='s'){
                                cls();
                                setColor(CYAN);
                                DibujarCuadro(Posx,posy);

                                gotoxy(Posx-4,posy-5);
                                cout<<"TURNO DE "<<nombreJ1<<endl;
                                gotoxy(Posx-4,posy-4);
                                cout<<"RONDA: "<<Ronda<<endl;
                                ///gotoxy(Posx-4,posy-3);
                                ///cout<<"PUNTOS TOTALES: "<<PuntosTotalesJ1<<endl;
                                TirarDados(VecDados,T);
                                gotoxy(Posx-4,posy-2);
                                MostrarDados(VecDados,T);
                                gotoxy(Posx-4,posy-1);
                                PuntosJ1=EncontrarCombinaciones(VecDados,T);
                                gotoxy(Posx-4,posy);
                                cout<<"PUNTOS DEL TIRO: +"<<PuntosJ1<<endl;
                                if(PuntosJ1==0){
                                    PuntosAcumuladosJ1=0;
                                    Respuesta='n';
                                }else{
                                   PuntosAcumuladosJ1+=PuntosJ1;
                                }
                                gotoxy(Posx-4,posy+1);
                                cout<<"PUNTOS ACUMULADOS: "<<PuntosAcumuladosJ1<<endl;
                            }
                            }while(Respuesta=='s');
                            }
                            if((PuntosTotalesJ1+PuntosAcumuladosJ1)>10000){
                                PuntosTotalesJ1+=0;
                            }else{
                                PuntosTotalesJ1+=PuntosAcumuladosJ1;
                            }
                            gotoxy(Posx-4,posy+9);
                            cout<<"PUNTOS ADQUIRIDOS: "<<PuntosAcumuladosJ1<<endl;
                            PuntosAcumuladosJ1=0;
                            gotoxy(Posx-4,posy+10);
                            getch();

                            }else{

                            gotoxy(Posx-4,posy-5);
                            cout<<"TURNO DE "<<nombreJ2<<endl;
                            gotoxy(Posx-4,posy-4);
                            cout<<"RONDA: "<<Ronda<<endl;
                            ///gotoxy(Posx-4,posy-3);
                            ///cout<<"PUNTOS TOTALES: "<<PuntosTotalesJ2<<endl;
                            gotoxy(Posx-4,posy-2);
                            cout<<"TIRE LOS DADOS!"<<endl;
                            gotoxy(Posx+17,posy-2);
                            getch();
                            TirarDados(VecDados,T);
                            gotoxy(Posx-4,posy);
                            MostrarDados(VecDados,T);
                            gotoxy(Posx-4,posy+1);
                            PuntosJ2=EncontrarCombinaciones(VecDados,T);
                            gotoxy(Posx-4,posy+2);
                            cout<<"PUNTOS DEL TIRO: +"<<PuntosJ2<<endl;
                            if(PuntosJ2==0){
                                    PuntosAcumuladosJ2=0;
                                    Respuesta='n';
                                }else{
                                   PuntosAcumuladosJ2+=PuntosJ2;
                                }
                                gotoxy(Posx-4,posy+3);
                                cout<<"PUNTOS ACUMULADOS: "<<PuntosAcumuladosJ2<<endl;

                            gotoxy(Posx-4,posy+4);
                            cout<<endl;


                            do{
                            gotoxy(Posx-4,posy+5);
                            cout<<"QUIERE VOLVER A TIRAR LOS DADOS?(s/n)"<<endl;
                            gotoxy(Posx-4,posy+6);
                            cin>>Respuesta;

                            if(Respuesta=='s'){
                                cls();
                                setColor(CYAN);
                                DibujarCuadro(Posx,posy);

                                gotoxy(Posx-4,posy-5);
                                cout<<"TURNO "<<nombreJ2<<endl;
                                gotoxy(Posx-4,posy-4);
                                cout<<"RONDA: "<<Ronda<<endl;
                                ///gotoxy(Posx-4,posy-3);
                                ///cout<<"PUNTOS TOTALES: "<<PuntosTotalesJ2<<endl;
                                TirarDados(VecDados,T);
                                gotoxy(Posx-4,posy-2);
                                MostrarDados(VecDados,T);
                                gotoxy(Posx-4,posy-1);
                                PuntosJ2=EncontrarCombinaciones(VecDados,T);
                                gotoxy(Posx-4,posy);
                                cout<<"PUNTOS DEL TIRO: +"<<PuntosJ2<<endl;
                                if(PuntosJ2==0){
                                    PuntosAcumuladosJ2=0;
                                    Respuesta='n';
                                }else{
                                   PuntosAcumuladosJ2+=PuntosJ2;
                                }
                                gotoxy(Posx-4,posy+1);
                                cout<<"PUNTOS ACUMULADOS: "<<PuntosAcumuladosJ2<<endl;
                            }
                            }while(Respuesta=='s');

                            if((PuntosTotalesJ2+PuntosAcumuladosJ2)>10000){
                                PuntosTotalesJ2+=0;
                            }else{
                                PuntosTotalesJ2+=PuntosAcumuladosJ2;
                            }
                            gotoxy(Posx-4,posy+9);
                            cout<<"PUNTOS DE LA RONDA: "<<PuntosAcumuladosJ2<<endl;
                            PuntosAcumuladosJ2=0;
                            gotoxy(Posx-4,posy+10);
                            getch();
                            break;
                            }
                        }
                }
            }
        cls();
        setColor(CYAN);
        DibujarCuadro(Posx,posy);

        if(PuntosTotalesJ1==10000){
        gotoxy(Posx-4,posy);
        cout<<nombreJ1<<endl;
        gotoxy(Posx-4,posy+1);
        cout<<"GANASTE EL JUEGO, FELICITACIONES :D"<<endl;
        gotoxy(Posx-4,posy+2);
        cout<<"GANASTE EN "<<Ronda<<" RONDAS"<<endl;
        gotoxy(Posx-4,posy+3);
        cout<<"PRESIONE CUALQUIER TECLA PARA VOLVER AL MENU"<<endl;
        guardarRondas(Ronda,rondasMay,vecNombre,nombreJ1);
        gotoxy(Posx-4,posy+4);
        getch();
        cls();
        }else{
        gotoxy(Posx-4,posy);
        cout<<nombreJ2<<endl;
        gotoxy(Posx-4,posy+1);
        cout<<"JUGADOR 2 GANASTE EL JUEGO, FELICITACIONES :D"<<endl;
        gotoxy(Posx-4,posy+2);
        cout<<"GANASTE EN "<<Ronda<<" RONDAS"<<endl;
        gotoxy(Posx-4,posy+3);
        cout<<"PRESIONE CUALQUIER TECLA PARA VOLVER AL MENU"<<endl;
        guardarRondas(Ronda,rondasMay,vecNombre,nombreJ2);
        gotoxy(Posx-4,posy+4);
        getch();
        cls();
        }

}


void guardarRondas(int rondas,int *rondasMay,char vecNombre[],char jugadorGanador[]){

        if(*rondasMay>rondas){
            *rondasMay=rondas;
            strcpy(vecNombre,jugadorGanador);
        }

 ;
 }

#endif // FUNCIONES_H_INCLUDED
