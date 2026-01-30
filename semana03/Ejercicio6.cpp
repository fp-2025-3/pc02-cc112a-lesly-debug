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
char* my_strcpy(char* destino,const char* origen){
    char* inicio=destino;
    while(*origen!='\0'){
        *destino=*origen;
        destino=destino+1;
        origen=origen+1;
    }
    *destino='\0';
    return inicio;
}
void ordenar(char* cadena){
    int n=my_strlen(cadena);
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(*(cadena+j)>*(cadena+j+1)){
                char temp=*(cadena+j);
                *(cadena+j)=*(cadena+j+1);
                *(cadena+j+1)=temp;
            }
        }
    }
}
int esAnagrama(char* a,char* b){
    if(my_strlen(a)!=my_strlen(b)){
        return 0;
    }
    char x[100];
    char y[100];
    char* p1=my_strcpy(x,a);
    char* p2=my_strcpy(y,b);
    ordenar(p1);
    ordenar(p2);
    while(*p1!='\0'){
        if(*p1!=*p2){
            return 0;
        }
        p1=p1+1;
        p2=p2+1;
    }
    return 1;
}
int separar_palabras(char* frase,char* palabras[]){
    int i=0;
    char* p=frase;
    bool nuevaPalabra=true;
    while(*p!='\0'){
        if(*p!=' '&&nuevaPalabra){
            palabras[i]=p;
            i=i+1;
            nuevaPalabra=false;
        }
        if(*p==' '){//Solo interesan dos palabras
            *p='\0';
            nuevaPalabra=true;
        }
        p=p+1;
    }
    return i;
}
int main(){
    char frase[200];
    while(cin.getline(frase,200)){
        if(frase[0]=='.'){
            break;
        }
        if(frase[0]=='\0'){
            continue;//Ignora líneas vacías
        }
        char* palabras[5];
        int n=separar_palabras(frase,palabras);
        if(n>=2){
            cout<<esAnagrama(palabras[0],palabras[1])<<endl;
        }
    }
    return 0;
}