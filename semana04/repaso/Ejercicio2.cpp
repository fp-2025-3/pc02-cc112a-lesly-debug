#include<iostream>
using namespace std;
const int N=5;
bool esFilaDominante(int (*M)[N],int fila){
    for(int j=0;j<N;j++){
        int elementoFila=*(*(M+fila)+j);
        for(int i=0;i<N;i++){
            if(i==fila){
                continue;
            }
            if(elementoFila<=*(*(M+i)+j)){
                return false;
            }
        }
    }
    return true;
}
int contarColumnasCriticas(int (*M)[N]){
    int contador=0;
    for(int j=0;j<N;j++){
        int sumaCol=0;
        bool esCritica=true;
        for(int i=0;i<N;i++){
            sumaCol=sumaCol+*(*(M+i)+j);
        }
        for(int i=0;i<N;i++){
            int sumaFila=0;
            int* fila=*(M+i);
            for(int k=0;k<N;k++){
                sumaFila=sumaFila+*(fila+k);
            }
            if(sumaCol<=sumaFila){
                esCritica=false;
                break;
            }
        }
        if(esCritica){
            contador=contador+1;
        }
    }
    return contador;
}
bool esMatrizEscalonada(int (*M)[N]){
    int posAnterior=-1;
    for(int i=0;i<N;i++){
        int* fila=*(M+i);
        int posActual=-1;
        for(int j=0;j<N;j++){
            if(*(fila+j)!=0){
                posActual=j;
                break;
            }
        }
        if(posActual!=-1){
            if(posActual<=posAnterior){
                return false;
            }
            posAnterior=posActual;
        }else{
            posAnterior=N;
        }
    }
    return true;
}
int main(){
    int M[N][N]={{0,0,7,8,9},{0,0,0,5,6},{0,0,0,0,4},{1,2,3,4,5},{9,8,7,6,5}};
    int numCol_C=contarColumnasCriticas(M);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<*(*(M+i)+j)<<" ";
        }
        cout<<endl;
    }
    if(esMatrizEscalonada(M)){
        cout<<"Matriz escalonada"<<endl;
    }else{
        cout<<"No es matriz escalonada"<<endl;
    }
    cout<<"Numero de columnas criticas: "<<numCol_C<<endl;
    return 0;
}