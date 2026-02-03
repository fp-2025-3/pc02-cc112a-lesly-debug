#include<iostream>
#include<iomanip>
using namespace std;
double promedio(double* E,int n){
    int suma=0;
    for(int i=0;i<n;i++){
        suma=suma+*(E+i);
    }
    return suma/n;
}
void diferenciaCentrada(double* E,double* D,int n){
    D[0]=0;
    D[n-1]=0;
    if(n<3){
        for(int i=0;i<n;i++){
            D[i]=0;
        }
        return;
    }
    for(int i=1;i<n-1;i++){
        *(D+i)=(*(E+i+1)-*(E+i-1))/2;
    }
}
int main(){
    int n;
    double E[10];
    double D[10];
    cout<<"Ingrese n: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>*(E+i);
    }
    for(int i=0;i<n;i++){
        cout<<*(E+i);
    }
    double prom=promedio(E,n);
    diferenciaCentrada(E,D,n);
    cout<<fixed<<setprecision(3);//Permite imprimir los double con 3 decimales
    cout<<"\nIndice E_Original D_centrada\n";
    cout<<"-----------------------------\n";
    for(int i=0;i<n;i++){
        cout<<setw(5)<<i+1<<setw(12)<<E[i];//setw (fija ancho)
        if(i==0||i==n-1){
            cout<<setw(12)<<"--"<<endl;
        }else{
            cout<<setw(12)<<D[i]<<endl;
        }
    }
    cout<<"\nPromedio= "<<prom;
    return 0;
}