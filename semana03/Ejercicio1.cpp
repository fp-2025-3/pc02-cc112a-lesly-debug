#include<iostream>
using namespace std;
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
int longitud_palabra(const char* p){
    int longitud=0;
    while(*p!='\0'&&*p!=' '){
        longitud=longitud+1;
        p=p+1;
    }
    return longitud;
}
void clasificar(char* palabras[],int n,char* cortas[],int& nc,char* largas[],int& nl){
    int indCortas=0,indLargas=0;
    for(int i=0;i<n;i++){
        int longitud=longitud_palabra(palabras[i]);
        if(longitud<=3){
            cortas[indCortas]=palabras[i];
            indCortas=indCortas+1;
            nc=nc+1;
        }else{
            largas[indLargas]=palabras[i];
            indLargas=indLargas+1;
            nl=nl+1;
        }
    }
}
int comparar_palabras(const char* a,const char* b){
    while(*a!=' '&&*b!=' '&&*a!='\0'&&*b!='\0'){
        char ca=*a;
        char cb=*b;
        if(ca>='A'&&ca<='Z'){
            ca=ca+'a'-'A';
        }
        if(cb>='A'&&cb<='Z'){
            cb=cb+'a'-'A';
        }
        if(ca!=cb){
            return ca-cb;
        }
        a=a+1;
        b=b+1;
    }
    if((*a==' '||*a=='\0')&&(*b==' '||*b=='\0')){
        return 0;
    }
    if(*b==' '||*b=='\0'){
        return 1;
    }
    return -1;
}
void swap(char*& a,char*& b){
    char* temp=a;
    a=b;
    b=temp;
}
void ordenar(char* v[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(comparar_palabras(v[j],v[j+1])>0){
                swap(v[j],v[j+1]);
            }
        }
    }
}
void imprimir_grupo(const char* titulo,char* v[],int n){
    cout<<"Palabras "<<titulo<<endl;
    for(int i=0;i<n;i++){
        char* p=v[i];
        while(*p!='\0'&&*p!=' '){
            cout<<*p;
            p=p+1;
        }
        cout<<endl;
    }
}
int main(){
    char texto[300]={"Programar en C++ requiere logica C++ exige DisCipliNa"};
    char* palabras[60];
    char* cortas[60];
    char* largas[60];
    int n=separar_palabras(texto,palabras);
    int nc=0,nl=0;
    clasificar(palabras,n,cortas,nc,largas,nl);
    ordenar(cortas,nc);
    ordenar(largas,nl);
    cout<<"Texto original:\n";
    cout<<texto<<"\n";
    imprimir_grupo("Cortas",cortas,nc);
    imprimir_grupo("Largas",largas,nl);
    return 0;
}