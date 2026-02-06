#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
const int NFILAS=9;
const int NCOLS=9;
void generar(int** A){
    for(int i=0;i<NFILAS;i++){
        for(int j=0;j<NCOLS;j++){
            *(*A+i*NCOLS+j)=rand()%9+1;
        }
    }
}
void imprimir(int** A){
    for(int i=0;i<NFILAS;i++){
        for(int j=0;j<NCOLS;j++){
            cout<<*(*A+i*NCOLS+j)<<" ";
        }
        cout<<endl;
    }
}
void actualizar(int** A,int fila,int col){
    int valor=*(*A+fila*NCOLS+col);
    for(int i=0;i<NFILAS;i++){
        int pos;
        for(pos=0;pos<NCOLS;pos++){
            if(*(*A+i*NCOLS+pos)==valor){
                break;
            }
        }
        int desp=(col-pos+NCOLS)%NCOLS;
        int temp[NCOLS];
        for(int j=0;j<NCOLS+1;j++){
            temp[(j+desp)%NCOLS]=*(*A+i*NCOLS+j);
        }
        for(int j=0;j<NCOLS+1;j++){
            *(*A+i*NCOLS+j)=temp[j];
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
    actualizar(A,fila,columna);
    cout<<"Tablero final: "<<endl;
    imprimir(A);
    cout<<endl;
    return 0;
}