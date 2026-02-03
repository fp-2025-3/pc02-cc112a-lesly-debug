#include<iostream>
using namespace std;
double** crearMatriz(int n){
    double** A;
    A=new double*[n];
    for(int i=0;i<n,i++){
        *(A+i)=new double[n];
    }
    return A;
}
void leerMatriz(double** a,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>*(*(a+i)+j);
        }
    }
}
void imprimir(double** a,int n){
    cout<<fixed<<setprecision(2);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<setw(7)<<*(*(a+i)+j)<<" ";
        }
        cout<<endl;
    }
}
double** transpuesta(double** a,int n){
    double** aT=crearMatriz(int n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            double temp=*(*(aT+i)+j);
            *(*(aT+i)+j)=*(*(aT+j)+i);
            *(*(aT+j)+i)=temp;
        }
    }
}
void multiplicar(double** a,double** b,double** I,int n){
    for(int i=0;i<n;++){
        for(int j=0;j<n;j++){
            *(*(I+i)+j)=0;
            for(int k=0;k<n;k++){
                *(*(I+i)+j)=*(*(I+i)+j)+(*(*(A+i)+k))*(*(*(B+k)+j));
            }
        }
    }
}
double traza(double** I,int n){
    double trz=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            trz=trz+*(*(A+i)+i);
        }
    }
    return trz;
}
double energia(double** I,int n){
    double suma=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            suma=suma+(*(*(I+i)+j))*(*(*(I+i)+j));
        }
    }
    return suma/(n*n);
}
int main(){
    return 0;
}