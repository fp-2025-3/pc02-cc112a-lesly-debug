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
            cout<<"Presupuesto: ";
            cin>>p.presupuesto;
            cout<<"Duracion (en meses): ";
            cin>>p.duracionMeses;
            archivo.write((char*)&p,sizeof(Proyecto));
        }
    }
    archivo.clear();
    archivo.seekp(0,ios::beg);
    Proyecto* proyectos=new Proyecto[n];
    for(int i=0;i<n;i++){
        archivo.read((char*)&proyectos[i],sizeof(Proyecto));
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(proyectos[i].presupuesto<proyectos[j].presupuesto){
                Proyecto aux=proyectos[i];
                proyectos[i]=proyectos[j];
                proyectos[j]=aux;
            }
        }
    }
    archivo.clear();
    archivo.seekp(0,ios::beg);
    for(int i=0;i<n;i++){
        archivo.write((char*)&proyectos[i],sizeof(Proyecto));
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
void insertarProyecto(){
    Proyecto nuevo;
    cout<<"\nNuevo proyecto\n";
    cout<<"ID: ";
    cin>>nuevo.id;
    if(buscarRegistro(nuevo.id)){
        cout<<"Ya existe un proyecto con ese ID\n";
        return;
    }
    cin.ignore();
    cout<<"Titulo: ";
    cin.getline(nuevo.titulo,40);
    cout<<"Presupuesto: ";
    cin>>nuevo.presupuesto;
    cout<<"Duracion (meses): ";
    cin>>nuevo.duracionMeses;
    fstream archivo("proyectos.dat",ios::binary|ios::in|ios::out);
    archivo.seekg(0,ios::end);
    int n=archivo.tellg()/sizeof(Proyecto);
    Proyecto actual;
    int pos=0;
    archivo.seekg(0);
    while(pos<n){
        archivo.read((char*)&actual,sizeof(Proyecto));
        if(nuevo.presupuesto>actual.presupuesto){
            break;
        }
        pos=pos+1;
    }
    for(int i=n;i>pos;i--){
        archivo.seekg((i-1)*sizeof(Proyecto));
        archivo.read((char*)&actual,sizeof(Proyecto));
        archivo.seekp(i*sizeof(Proyecto));
        archivo.write((char*)&actual,sizeof(Proyecto));
    }
    archivo.seekp(pos*sizeof(Proyecto));
    archivo.write((char*)&nuevo,sizeof(Proyecto));
    archivo.close();
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
    insertarProyecto();
    mostrarRegistros();
    return 0;
}