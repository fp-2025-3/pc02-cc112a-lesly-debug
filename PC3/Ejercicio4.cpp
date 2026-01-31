#include<iostream>
using namespace std;
int construir_indice(char* texto,char* indice[]) {
    int i=0;
    char* p=texto;
    if(*p!=' '&&*p!='\0') {
        indice[i]=p;
        i=i+1;
    }
    p=p+1;
    while(*p!='\0') {
        if(*p!=' '&&*(p-1)==' '){
            indice[i]=p;
            i=i+1;
        }
        p=p+1;
    }
    return i;
}

int comparar(const char* a,const char* b){
    while(*a!=' '&&*a!='\0'&&*b!=' '&&*b!='\0'){
        if(*a!=*b){
            return *a-*b;
        }
        a=a+1;
        b=b+1;
    }
    if((*a==' '||*a=='\0')&&(*b=='\0'||*b==' ')){
        return 0;
    }
    if(*a==' '||*a=='\0'){
        return -1;
    }
    return 1;
}
void ordenar_indice(char* indice[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(comparar(indice[j],indice[j+1])>0){
                char* temp=*(indice+j);
                *(indice+j)=*(indice+j+1);
                *(indice+j+1)=temp;
            }
        }
    }
}
void imprimir_indice(char* texto,char* indice[],int n){
    for(int i=0;i<n;i++){
        char* p=indice[i];
        while(*p!='\0'&&*p!=' '){
            cout<<*p;
            p=p+1;
        }
        int posicion=indice[i]-texto;
        cout<<"\t(posicion "<<posicion<<")"<<endl;
    }
}
int main(){
    char texto[300]="los punteros no se copian se referencian y se ordenan";
    char* indice[60];
    int n=construir_indice(texto,indice);
    ordenar_indice(indice,n);
    imprimir_indice(texto,indice,n);
    return 0;
}