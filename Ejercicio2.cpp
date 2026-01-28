#include<iostream>
using namespace std;
int* buscar(int* inicio,int* fin,bool (*equivale)(int,int),int clave);
bool igual(int a,int b){
    return a==b;
}
bool mismaParidad(int a,int b){
    return a%2==b%2;
}
bool divideA(int a,int b){
    if(a==0||b==0){
        return false;
    }
    return (a%b==0||b%a==0);
}
bool mismoResiduoMod5(int a,int b){
    return a%5==b%5;
}
int contar(int n){
    if(n==0){
        return 1;
    }
    int contador=0;
    while(contador>0){
        n=n/10;
        contador=contador+1;
    }
    return contador;
}
bool cantidadDigitos(int a,int b){
    return contar(a)==contar(b);
}
int main(){
    int A[]={-1,21,2,-2,8,13,25};
    int n=sizeof(A)/sizeof(A[0]);
    int* p=&A[0];
    int* q=&A[7];
    int valor;
    cout<<"Arreglo: ";
    for(int i=0;i<n;i++){
        cout<<*(p+i)<<" ";
    }
    cout<<endl;
    cout<<"Clave: ";
    cin>>valor;
    int* r1=buscar(p,q,igual,valor);
    int* r2=buscar(p,q,mismaParidad,valor);
    int* r3=buscar(p,q,divideA,valor);
    int* r4=buscar(p,q,mismoResiduoMod5,valor);
    int* r5=buscar(p,q,cantidadDigitos,valor);
    if(r1){
        cout<<"Igualdad exacta: valor encontrado: "<<*r1<<"Posicion: "<<r1;
    }else{
        cout<<"No encontrado.";
    }
    cout<<endl;
    if(r2){
        cout<<"Misma paridad: valor encontrado: "<<*r2<<"Posicion: "<<r2;
    }else{
        cout<<"No encontrado.";
    }
    cout<<endl;
    if(r3){
        cout<<"Divide a: valor encontrado: "<<*r3<<"Posicion: "<<r3;
    }else{
        cout<<"No encontrado.";
    }
    cout<<endl;
    if(r4){
        cout<<"Mismo residuo modulo 5: valor encontrado: "<<*r4<<"Posicion: "<<r4;
    }else{
        cout<<"No encontrado.";
    }
    cout<<endl;
    if(r5){
        cout<<"Misma cantidad de digitos "<<*r5<<"Posicion: "<<r5;
    }else{
        cout<<"No encontrado.";
    }
    return 0;
}
int* buscar(int* inicio,int* fin,bool (*equivale)(int,int),int clave){
    for(int* p=inicio;p<fin;p++){
        if(equivale(*p,clave)){
            return p;
        }
    }
    return nullptr;
}