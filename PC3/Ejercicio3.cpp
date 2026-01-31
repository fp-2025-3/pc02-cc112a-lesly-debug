#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
const int NFILAS=9;
const int NCOLS=9;
//La funcion genera cada fila como una permutacion del 1 al 9,llena y luego mezcla aleatoriamente
void generar(int** matriz){
    for(int i=0;i<NFILAS;i++){
        for(int j=0;j<NCOLS;j++){
            *(*(matriz+i)+j)=j+1;
        }
        for(int j=0;j<NCOLS;j++){
            int r=rand()%NCOLS;
            int temp=*(*(matriz+i)+j);
            *(*(matriz+i)+j)=*(*(matriz+i)+r);
            *(*(matriz+i)+r)=temp;
        }
    }
}
void imprimir(int** matriz){
    for(int i=0;i<NFILAS;i++){
        for(int j=0;j<NCOLS;j++){
            cout<<*(*(matriz+i)+j)<<" ";
        }
        cout<<endl;
    }
}
void actualizarValores(int** matriz,int fila,int col){
    int valor=*(*(matriz+fila)+col);
    for(int i=0;i<NFILAS;i++){
        int pos;
        for(pos=0;pos<NCOLS;pos++){
            if(*(*(matriz+i)+pos)==valor){
                break;
            }
        }
        int desp=(col-pos+NCOLS)%NCOLS;
        int aux[NCOLS];
        for(int j=0;j<NCOLS;j++){
            aux[(j+desp)%NCOLS]=*(*(matriz+i)+j);
        }
        for(int j=0;j<NCOLS;j++){
            *(*(matriz+i)+j)=aux[j];
        }
    }
    cout<<"Valor seleccionado: "<<valor<<endl;
}
int main(){
    srand(time(NULL));
    int** A=new int*[NFILAS];
    for(int i=0;i<NFILAS;i++){
        *(A+i)=new int[NCOLS];
    }
    int fila,columna;
    generar(A);
    imprimir(A);
    cout<<"Fila inicial (1-9): ";
    cin>>fila;
    cout<<"Columna inicial (1-9): ";
    cin>>columna;
    cout<<"Tablero final: "<<endl;
    actualizarValores(A,fila-1,columna-1);
    imprimir(A);
    for(int i=0;i<NFILAS;i++){
        delete[] A[i];//libera memoria de columnas
    }
    delete[] A;//libera memoria de filas
    return 0;
}