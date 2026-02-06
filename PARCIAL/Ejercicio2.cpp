#include<iostream>
#include<cstring>
using namespace std;
void leerDatos(string* nombre,int* tiempo,int n){
    cin.ignore();
    for(int i=0;i<n;i++){
        cout<<"Nombre del corredor "<<i+1<<": ";
        getline(cin,nombre[i],'\n');
        cout<<"Tiempo (en segundos):";
        cin>>tiempo[i];
        cin.ignore();
    }
}
void ordenarPorTiempo(string* nombre,int* tiempo,int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(tiempo[j]<tiempo[min]){
                min=j;
            }
            if(tiempo[j]==tiempo[min]){
                if(j<min){
                    min=j;
                }
            string auxNombre=nombre[i];
            nombre[i]=nombre[min];
            nombre[min]=auxNombre;
            int auxTiempo=tiempo[i];
            tiempo[i]=tiempo[min];
            tiempo[min]=auxTiempo;
        }
    }
}
}
void mostrarRanking(string* nombre,int* tiempo,int n){
    cout<<"RANKING FNAL\n";
    for(int i=0;i<n;i++){
        cout<<i+1<<".  "<<nombre[i]<<" - "<<tiempo[i]<<endl;
    }
}
int buscarCorredor(string* nombre,string buscado,int n){
    for(int i=0;i<n;i++){
        if(nombre[i]==buscado){
            return i;
        }
    }
    return -1;
}
void mostrarRango(int min,int max,int* tiempo,string* nombre){
    cout<<"Corredores en el rango ["<<min<<","<<max<<"]:"<<endl;
    int i=0;
    while(min<=max){
        if(min<=tiempo[i]&&tiempo[i]<=max){
            cout<<nombre[i]<<" - "<<tiempo[i]<<endl;
        }
        i=i+1;
    }
}
int main(){
    string* nombre;
    int* tiempo;
    int n;
    cout<<"Ingrese el numero de corredores: ";
    cin>>n;
    nombre=new string[n];
    tiempo=new int[n];
    leerDatos(nombre,tiempo,n);
    ordenarPorTiempo(nombre,tiempo,n);
    mostrarRanking(nombre,tiempo,n);
    string buscado;
    cout<<"Ingrese el nombre a buscar: ";
    getline(cin,buscado,'\n');
    int pos=buscarCorredor(nombre,buscado,n);
    if(pos!=-1){
        cout<<"Corredor encontrado"<<endl;
        cout<<"Posicion: "<<pos+1;
        cout<<"\tTiempo: "<<tiempo[pos];
    }else{
        cout<<"Corredor no encontrado"<<endl;
    }
    int min;
    int max;
    cout<<"\nIngrese tiempo minimo y maximo: ";
    cin>>min>>max;
    mostrarRango(min,max,tiempo,nombre);
    delete[] nombre;
    delete[] tiempo;
    return 0;
}