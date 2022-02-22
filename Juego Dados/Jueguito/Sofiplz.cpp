/*#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

void TirarDados(int VecDados[],int T);
void MostrarDados(int V[],int T);
int SumarPuntos(int Dados[],int T);


int CACA(){
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
*/
