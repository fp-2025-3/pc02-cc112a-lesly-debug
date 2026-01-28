#include<iostream>
using namespace std;
int separar_palabras(char* frase,char* palabras[]){
    int i=0;
    char* p=frase;
    while(*p!='\0'){
        if((p==frase&&*p!=' ')||(*(p-1)==' '&&*p!=' ')){
            palabras[i]=p;
            i=i+1;
        }
        p=p+1;
    }
    return i;
}
int comparar(const char* a,const char* b){
    while(*a!='\0'&&*b!='\0'&&*a==*b){
        a=a+1;
        b=b+1;
    }
    return *a-*b;
}
void swap(char*& a,char*& b){
    char* temp=a;
    a=b;
    b=temp;
}
void ordenar(char* palabras[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(comparar(palabras[j],palabras[j+1])>0){
                swap(palabras[j],palabras[j+1]);
            }
        }
    }
}
void imprimir(char* palabras[],int n){
    for(int i=0;i<n;i++){
        char* p=palabras[i];
        while(*p!='\0'&&*p!=' '){
            cout<<*p;
            p=p+1;
        }
        cout<<endl;
    }
}
int main(){
    char frase[200]={"aprender punteros exige mucha logica y practica"};
    char* palabras[50];
    int n=separar_palabras(frase,palabras);
    separar_palabras(frase,palabras);
    imprimir(palabras,n);
    return 0;
}