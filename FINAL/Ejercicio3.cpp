#include<iostream>
#include<string>
#include<fstream>
using namespace std;
struct Proyecto{
    int id;
    char titulo[40];
    double presupuesto;
    int duracionMeses;
};
void crearArchivo(int n){
    fstream archivo("proyectos.dat",ios::binary|ios::in|ios::out);
    if(!archivo){
        archivo.open("proyectos.dat",ios::out|ios::binary);
        archivo.close();
        archivo.open("proyectos.dat",ios::binary|ios::in|ios::out);
    }
    Proyecto p;
    for(int i=0;i<n;i++){
        cout<<"Proyecto "<<i+1<<endl;
        cout<<"ID: ";
        cin>>p.id;
        int posicion=(p.id-1)*sizeof(Proyecto);
        archivo.seekg(posicion,ios::beg);
        Proyecto temp;
        archivo.read((char*)&temp,sizeof(Proyecto));
        if(archivo){
            cout<<"Ya existe un proyecto con ese ID.\n";
            i=i-1;
        }else{
            archivo.clear();
            archivo.seekp(posicion,ios::beg);
            cout<<"Titulo: ";
            cin.ignore();
            cin.getline(p.titulo,40);
            cout<<"Saldo: ";
            cin>>p.presupuesto;
            cout<<"Duracion (en meses): ";
            cin>>p.duracionMeses;
            archivo.write((char*)&p,sizeof(Proyecto));
        }
    }
    Proyecto* proyectos=new Proyecto[n];
    for(int i=0;i<n;i++){
        archivo.read((char*)&proyectos[i],ios::beg);
    }
    int posicion=proyectos[n-1].id-1;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(proyectos[i].presupuesto>proyectos[j].presupuesto){
                archivo.seekg(posicion*sizeof(Proyecto),ios::beg);
                archivo.read((char*)&proyectos[i],sizeof(Proyecto));
                Proyecto aux=proyectos[i];
                proyectos[i]=proyectos[j];
                proyectos[j]=aux;
                archivo.seekp(posicion*sizeof(Proyecto),ios::beg);
                archivo.write((char*)&proyectos[j],sizeof(Proyecto));
            }
            posicion=posicion-1;
        }
    }
    delete[] proyectos;
    archivo.close();
    return;
}
bool buscarRegistro(int idBuscado){
    ifstream archivo("proyectos.dat",ios::binary);
    if(!archivo){
        cout<<"Error al abrir el archivo.\n";
        return false;
    }
    Proyecto p;
    while(archivo.read((char*)&p,sizeof(Proyecto))){
        if(p.id==idBuscado){
            return true;
        }
    }
    return false;
}
void mostrarRegistros(){
    ifstream archivo("proyectos.dat",ios::binary);
    if(!archivo){
        cout<<"Error al abrir el archivo.\n";
        return;
    }
    Proyecto p;
    cout<<"\nPROYECTOS ORDENADOS POR PRESUPUESTO\n"<<endl;
    while(archivo.read((char*)&p,sizeof(Proyecto))){
        cout<<"ID: "<<p.id<<endl;
        cout<<"Titulo: "<<p.titulo<<endl;
        cout<<"Presupuesto: "<<p.presupuesto<<endl;
        cout<<"Tiempo (en meses): "<<p.duracionMeses;
        cout<<endl;
    }
    archivo.close();
    return;
}
int main(){
    int n;
    cout<<"Ingrese el numero de proyectos: ";
    cin>>n;
    crearArchivo(n);
    mostrarRegistros();
    return 0;
}