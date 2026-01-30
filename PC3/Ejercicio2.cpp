#include<iostream>
using namespace std;
int my_strlen(const char* cadena){
    int contador=0;
    while(*cadena!='\0'){
        contador=contador+1;
        cadena=cadena+1;
    }
    return contador;
}
int separar_palabras(char* texto,char* palabras[]){
    int i=0;
    char* p=texto;
    while(*p!='\0'){
        if((p==texto&&*p!=' ')||((*p!=' ')&&(*(p-1)==' '))){
            palabras[i]=p;
            i=i+1;
        }
        p=p+1;
    }
    return i;
}
int contador(char* cadena[],int n){
    int c=0;
    for(int i=0;i<n;i++){
        if(*cadena[i]=='a'||*cadena[i]=='A'){
            c=c+1;
        }
        if(*cadena[i]=='e'||*cadena[i]=='E'){
            c=c+1;
        }
        if(*cadena[i]=='i'||*cadena[i]=='I'){
            c=c+1;
        }
        if(*cadena[i]=='o'||*cadena[i]=='O'){
            c=c+1;
        }
        if(*cadena[i]=='u'||*cadena[i]=='U'){
            c=c+1;
        }
    }
    return c;
}
int main(){
    char frase[]={"Este es    un ejemplo en C++ END"};
    char* palabras[50];
    int n=separar_palabras(frase,palabras);
    cout<<frase<<endl;
    cout<<"Numero de palabras que comienzan con vocal: "<<contador(palabras,n);
    return 0;
}