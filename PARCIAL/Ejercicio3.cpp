#include<iostream>
using namespace std;
const int N=4;
bool esFilaDominanteEstricta(int (*M)[N],int fila){
    for(int j=0;j<N;j++){
        int elementoFila=*(*(M+fila)+j);
        for(int i=0;i<N;i++){
            if(i==fila){
                continue;
            }
            if(elementoFila<*(*(M+i)+j)){
                return false;
            }
            if(elementoFila<=*(*(M+i)+j)){
                return false;
            }
        }
    }
    return true;
}
bool esFilaFuertementeDominante(int (*M)[N],int fila){
    int sumaFila=0;
    for(int j=0;j<N;j++){
        sumaFila=sumaFila+M[fila][j];
    }
    for(int i=0;i<N;i++){
        int suma=0;
        for(int j=0;j<N;j++){
            suma=suma+M[i][j];
        }
        if(sumaFila<suma){
            return false;
        }
        if(esFilaDominanteEstricta(M,fila)&&(sumaFila>suma)){
            return true;
        }
    }
    return true;
}
int main(){
    int A[][4]={{2,3,1,4},{1,2,3,2},{5,6,7,8},{0,1,2,1}};
    cout<<"Fila\tDominante Estricta\tFuertemente Dominante\n";
    cout<<"----------------------------------------------\n";
    for(int i=0;i<N;i++){
        cout<<i;
        if(esFilaDominanteEstricta(A,i)){
            cout<<"\tSI";
        }else{
            cout<<"\tNO";
        }
        if(esFilaFuertementeDominante(A,i)){
            cout<<"\tSI";
        }else{
            cout<<"\tNO";
        }
        cout<<endl;
        }
    return 0;
}