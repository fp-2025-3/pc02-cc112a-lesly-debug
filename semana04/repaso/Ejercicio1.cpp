#include<iostream>
#include<cctype>//tolower();
using namespace std;
int my_strlen(char* cadena){//No considera el caracter nulo;
    int contador=0;
    while(*cadena!='\0'){
        contador=contador+1;
        cadena=cadena+1;
    }
    return contador;
}
int my_isspace(int c){
    return(c==' '||c=='\n'||c=='\r'||c=='\t'||c=='\f');
}
char* leerFrase(){
    char temp[1000];
    cout<<"Ingrese una frase: ";
    cin.getline(temp,1000);
    int len=my_strlen(temp);
    char* frase=new char[len+1];
    for(int i=0;i<len+1;i++){
        frase[i]=temp[i];
    }
    return frase;
}
char* normalizarFrase(char* frase){
    char temp[1000];//buffer temporal
    int i=0;
    int j=0;
    bool esEspacio=true;
    while(frase[i]!='\0'){
        if(!my_isspace(frase[i])){
            temp[j]=tolower(frase[i]);
            j=j+1;
            esEspacio=false;
        }else{
            if(!esEspacio){
                temp[j]=' ';
                j=j+1;
                esEspacio=true;
            }
        }
        i=i+1;
    }
    if(j>0&&temp[j-1]==' '){
        j=j-1;
    }
    temp[j]='\0';
    char* normalizada=new char[j+1];
    for(int k=0;k<j+1;k++){
        normalizada[k]=temp[k];
    }
    return normalizada;
}
int contarPalabras(char* frase){
    int cont=0;
    bool estoyPalabra=false;
    for(int i=0;frase[i]!='\0';i++){
        if(!my_isspace(frase[i]&&!estoyPalabra)){
            cont=cont+1;
            estoyPalabra=true;
        }
        if(my_isspace(frase[i])){
            estoyPalabra=false;
        }
    }
    return cont;
}
char** separarPalabras(char* frase,int n){
    char** palabras=new char*[n];
    int i=0;//para recorrer frases
    int j=0;//para manipular indices de palabras
    while(frase[i]!='\0'){
        while(my_isspace(frase[i])){
            i=i+1;
        }
        int inicio=i;
        int len=0;
        while(frase[i]!='\0'&&!isspace(frase[i])){
            i=i+1;
            len=len+1;
        }
        palabras[j]=new char[len+1];
        for(int k=0;k<len;k++){
            palabras[j][k]=frase[inicio+k];
        }
        palabras[j][len]='\0';
        j=j+1;
    }
    return palabras;
}
void mostrarPalabras(char** palabras,int n){
    for(int i=0;i<n;i++){
        cout<<palabras[i]<<"\t"<<my_strlen(palabras[i])<<endl;
    }
}
void liberarMemoria(char** palabras,int n){
    for(int i=0;i<n;i++){
        delete[] palabras[i];
    }
    delete[] palabras;
}
int main(){
    char* frase=leerFrase();
    char* normalizada=normalizarFrase(frase);
    cout<<normalizada<<endl;
    int numPal=contarPalabras(frase);
    char** palabras=separarPalabras(normalizada,numPal);
    mostrarPalabras(palabras,numPal);
    delete[] frase;
    frase=nullptr;
    delete[] normalizada;
    normalizada=nullptr;
    liberarMemoria(palabras,numPal);
    palabras=nullptr;
    return 0;
}