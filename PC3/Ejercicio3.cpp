#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
const int NFILAS=9;
const int NCOLS=9;
void generar(int** matriz){
    for(int i=0;i<NFILAS;i++){
        for(int j=0;j<NCOLS;j++){
            *(*matriz+i*NCOLS+j)=rand()%9+1;
        }
    }
}
void imprimir(int** matriz){
    for(int i=0;i<NFILAS;i++){
        for(int j=0;j<NCOLS;j++){
            cout<<*(*matriz+i*NCOLS+j)<<" ";
        }
        cout<<endl;
    }
}
void actualizarValores(int** matriz,int fila,int col){
    int valor=*(*matriz+fila*NCOLS+col);
    for(int i=0;i<NFILAS;i++){
        int pos;
        for(pos=0;pos<NCOLS;pos++){
            if(*(*matriz+i*NCOLS+pos)==valor){
                break;
            }
        }
        int desp=(col-pos+NCOLS)%NCOLS;
        int aux[NCOLS];
        for(int j=0;j<NCOLS;j++){
            aux[(j+desp)%NCOLS]=*(*matriz+i*NCOLS+j);
        }
        for(int j=0;j<NCOLS;j++){
            *(*matriz+i*NCOLS+j)=aux[j];
        }
    }
    cout<<"Valor seleccionado: "<<valor<<endl;
}
int main(){
    srand(time(NULL));
    int M[NFILAS][NCOLS];
    int* p=&M[0][0];
    int** A=&p;
    int fila;
    int columna;
    generar(A);
    imprimir(A);
    cout<<"Fila inicial (1-9): ";
    cin>>fila;
    cout<<"Columna inicial (1-9): ";
    cin>>columna;
    cout<<"Tablero final: "<<endl;
    actualizarValores(A,fila-1,columna-1);
    imprimir(A);
    cout<<endl;
    return 0;
}