#include<iostream>
using namespace std;
int my_strcmp(const char* a,const char* b){
    while(*a!='\0'&&*b!='\0'&&*a==*b){
        a=a+1;
        b=b+1;
    }
    return *a-*b;
}
void ordenar(const char** cadena,int n){
    for(const char** i=cadena;i<cadena+n-1;i++){
        for(const char** j=i+1;j<cadena+n;j++){
            if(my_strcmp(*i,*j)>0){
                const char* temp=*i;
                *i=*j;
                *j=temp;
            }
        }
    }
}
void imprimir(const char** cadena,int n){
    for(const char** p=cadena;p<cadena+n;p++){
        cout<<*p<<" ";
    }
}
int main(){
    const char* cadena[]={"cc112","a"};
    imprimir(cadena,2);
    ordenar(cadena,2);
    imprimir(cadena,2);
    return 0;
}