#include<iostream>
using namespace std;
int convertir_entero(char* cad){
    int n=0;
    while(*cad!='\0'){
        n=n*10+(*cad-'0');
        cad=cad+1;
    }
    return n;
}
float convertir_flotante(char* cad){
    float entero=0,decimal=0;
    float pot=1;
    int i=0;
    while(cad[i]!='.'&&cad[i]!='\0'){
        entero=entero*10+(cad[i]-'0');
        i=i+1;
    }
    if(cad[i]=='.'){
        i=i+1;
    }
    while(cad[i]!='\0'){
        pot=pot*10;
        decimal=decimal*10+(cad[i]-'0');
        i=i+1;
    }
    return entero+decimal/pot;
}
int my_strlen(const char* cadena){
    int contador=0;
    while(*cadena!='\0'){
        contador=contador+1;
        cadena=cadena+1;
    }
    return contador;
}
char* my_strcpy(char* destination,const char* origen){
    char* inicio=destination;
    while(*origen!='\0'){
        *destination=*origen;
        destination=destination+1;
        origen=origen+1;
    }
    *destination='\0';
    return inicio;
}
int es_delimitador(char c,const char* delimitador){
    while(*delimitador!='\0'){
        if(c==*delimitador){
            return 1;
        }
        delimitador=delimitador+1;
    }
    return 0;
}
char* my_strtok(char* str,const char* delimiters){
    static char* ptr=NULL;
    if(str!=NULL){
        ptr=str;
    }
    if(ptr==NULL){
        return NULL;
    }
    while(*ptr!='\0'&&es_delimitador(*ptr,delimiters)){
        ptr=ptr+1;
    }
    if(*ptr=='\0'){
        ptr=NULL;
        return NULL;
    }
    char* inicio=ptr;
    while(*ptr!='\0'){
        const char* d=delimiters;
        int esDel=0;
        while(*d!='\0'){
            if(*ptr==*d){
                esDel=1;
                break;
            }
            d=d+1;
        }
        if(esDel){
            break;
        }
        ptr=ptr+1;
    }
    if(*ptr!='\0'){
        *ptr='\0';
        ptr=ptr+1;
    }
    return inicio;
}
void imprimirColumna(const char* texto,int ancho){
    int longitud=0;
    const char* p=texto;
    while(*p!='\0'){
        longitud=longitud+1;
        p=p+1;
    }
    cout<<texto;
    for(int i=longitud;i<ancho;i++){
        cout<<' ';
    }
}
void imprimirNumero(int num,int ancho){
    int digitos=0;
    int temp=num;
    if(temp==0){
        digitos=1;
    }
    while(temp>0){
        digitos=digitos+1;
        temp=temp/10;
    }
    cout<<num;
    for(int i=digitos;i<ancho;i++){
        cout<<' ';
    }
}
int main(){
    int N;
    cout<<"Ingrese N: ";
    cin>>N;
    cin.ignore();
    char nombres[50][150];
    char direcciones[50][150];
    char celulares[50][150];
    int edades[50];
    float talla[50];
    int cont=0;
    for(int i=0;i<N;i++){
        char entrada[300];
        cout<<"Ingrese entrada "<<i+1<<": ";
        cin.getline(entrada,300);
        int totalComas=0;
        char* p=entrada;
        while(*p!='\0'){
            if(*p==','){
                totalComas=totalComas+1;
            }
            p=p+1;
        }
        if(totalComas==4){
            char* dato;
            dato=my_strtok(entrada,",");
            my_strcpy(nombres[cont],dato);
            dato=my_strtok(NULL,",");
            my_strcpy(direcciones[cont],dato);
            dato=my_strtok(NULL,",");
            my_strcpy(celulares[cont],dato);
            dato=my_strtok(NULL,",");
            edades[cont]=convertir_entero(dato);
            dato=my_strtok(NULL,",");
            talla[cont]=convertir_flotante(dato);
            cont=cont+1;
        }else{
            cout<<"Formato incorrecto, se descarta del almacenamiento.";
        }
    }
    cout<<"Los datos guardados en el directorio son:\n";
    imprimirColumna("Nombre",20);
    imprimirColumna("Direccion",30);
    imprimirColumna("Celular",15);
    imprimirColumna("Edad",8);
    imprimirColumna("Talla",8);
    cout<<endl;
    for(int i=0;i<cont;i++){
        imprimirColumna(nombres[i],20);
        imprimirColumna(direcciones[i],30);
        imprimirColumna(celulares[i],15);
        imprimirNumero(edades[i],8);
        cout<<talla[i];
        cout<<endl;
    }
    return 0;
}