#include<iostream>
using namespace std;
void leerDatos(int* codigo,float* nota,int* faltas,int N){
    for(int i=0;i<N;i++){
        cout<<"ESTUDIANTE "<<i+1<<endl;
        cout<<"Codigo: ";
        cin>>*(codigo+i);
        cout<<"Nota: ";
        cin>>*(nota+i);
        cout<<"Faltas: ";
        cin>>*(faltas+i);
    }
}
void ordenarPorNota(float* nota,int* codigo,int* faltas,int N){
    for(int i=0;i<N-1;i++){
        int max=i;
        for(int j=i+1;j<N;j++){
            if((nota[j]>nota[max])||((nota[j]==nota[max])&&(faltas[j]<faltas[max]))){
                max=j;
            }
        }
        float auxNota=nota[i];
        nota[i]=nota[max];
        nota[max]=auxNota;
        int auxCod=codigo[i];
        codigo[i]=codigo[max];
        codigo[max]=auxCod;
        int auxFal=faltas[i];
        faltas[i]=faltas[max];
        faltas[max]=auxFal;
    }
}
void mostrarRanking(float* nota,int* codigo,int* faltas,int n){
    float suma=0;
    int contador=0;
    for(int i=0;i<n;i++){
        suma=suma+nota[i];
        if(nota[i]<10){
            contador=contador+1;
        }
    }
    double promedioCurso=suma/n;
    cout<<"\n=== TOP 5 ESTUDIANTES ===\n";
    for(int i=0;i<n&&i<5;i++){
        cout<<i+1<<" Codigo: "<<codigo[i]<<" Faltas: "<<faltas[i]<<endl;
    }
    cout<<"Promedio del curso: "<<promedioCurso<<endl;
    cout<<"Numero de desaprobados: "<<contador<<endl;
}
int busquedaSecuencialTop5(int* codigo,int n,int clave){
    int limite;
    if(n<5){
        limite=n;
    }else{
        limite=5;
    }
    for(int i=0;i<limite;i++){
        if(codigo[i]==clave){
            return i;
        }
    }
    return -1;
}
int busquedaSecuencial(int* codigo,int n,int clave){
    for(int i=0;i<n;i++){
        if(codigo[i]==clave){
            return i;
        }
    }
    return -1;
}
void ordenarPorCodigo(float* nota,int* codigo,int* faltas,int n){
    for(int i=1;i<n;i++){
        int c=codigo[i];
        int f=faltas[i];
        float nt=nota[i];
        int j=i-1;
        while(j>=0&&codigo[j]>c){
            codigo[j+1]=codigo[j];
            faltas[j+1]=faltas[j];
            nota[j+1]=nota[j];
            j=j-1;
        }
        codigo[j+1]=c;
        faltas[j+1]=f;
        nota[j+1]=nt;
    }
}
int busquedaBinaria(int* codigo,int n,int clave){
    int inicio=0,final=n-1;
    while(inicio<=final){
        int mitad=(inicio+final)/2;
        if(codigo[mitad]==clave){
            return mitad;
        }else if(codigo[mitad]<clave){
            inicio=mitad+1;
        }else{
            final=mitad-1;
        }
    }
    return -1;
}
int main(){
    int* codigo;
    float* nota;
    int* faltas;
    int n;
    cout<<"N= ";
    cin>>n;
    codigo=new int[n];
    faltas=new int[n];
    nota=new float[n];
    leerDatos(codigo,nota,faltas,n);
    ordenarPorNota(nota,codigo,faltas,n);
    mostrarRanking(nota,codigo,faltas,n);
    int clave;
    cout<<"Ingrese el codigo del estudiante: ";
    cin>>clave;
    int pos=busquedaSecuencial(codigo,n,clave);
    if(pos!=-1){
        pos=busquedaSecuencialTop5(codigo,n,clave);
        if(pos!=-1){
            cout<<" Nota "<<nota[pos]<<"\tFaltas: "<<faltas[pos]<<"\tPosicion en el ranking "<<pos+1<<endl;
        }else{
            cout<<"El codigo ingresado no se encuentra en el ranking"<<endl;
        }
    }else{
        cout<<"Codigo no encontrado"<<endl;
    }
    ordenarPorCodigo(nota,codigo,faltas,n);
    int valor;
    cout<<"Ingrese el codigo del estudiante: ";
    cin>>valor;
    int ind=busquedaSecuencial(codigo,n,valor);
    if(ind!=-1){
        ind=busquedaBinaria(codigo,n,valor);
        if(ind!=-1){
            cout<<" Nota "<<nota[ind]<<"\tFaltas: "<<faltas[ind]<<endl;
        }else{
            cout<<"El codigo ingresado no se encuentra en el ranking"<<endl;
        }
    }else{
        cout<<"Codigo no encontrado"<<endl;
    }
    return 0;
}
