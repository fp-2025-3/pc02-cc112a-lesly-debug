#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct Estudiante{
    char nombre[50];
    int nota;
};
void escribirArchivo(const string& nombreArchivo,const string& nombre,int nota){
    ofstream archivo(nombreArchivo,ios::app);
    if(!archivo){
        cerr<<"Error al crear el archivo.\n";
        return;
    }
    archivo<<nombre<<" "<<nota<<"\n";
}
void leerArchivo(const string& nombreArchivo){
    ifstream archivo(nombreArchivo);
    if(!archivo){
        cerr<<"Error al abrir el archivo.\n";
        return;
    }
    string nombre;
    int n;
    while(archivo>>nombre>>n){
        cout<<nombre<<" "<<n<<endl;
    }
    archivo.close();
}
void agregarArchivo(const string& nombreArchivo,const string nombre,int nota){
    fstream archivo(nombreArchivo,ios::app|ios::out);
    if(!archivo){
        cerr<<"Error al abrir el archivo.\n";
    }
    archivo<<nombre<<" "<<nota;
}
void escribirBinario(const string& nombreArchivo,const string& nombre,int nota){
    ofstream archivo(nombreArchivo,ios::binary|ios::app);
    if(!archivo){
        cerr<<"Error al abrir el archivo.\n";
        return;
    }
    Estudiante e;
    e.nota=nota;
    strncpy(e.nombre,nombre.c_str(),sizeof(e.nombre));
    e.nombre[sizeof(e.nombre)-1]='\0';
    archivo.write((char*)&e,sizeof(Estudiante));
    archivo.close();
}
void leerBinario(const string& nombreArchivo){
    ifstream archivo(nombreArchivo,ios::binary);
    if(!archivo){
        cerr<<"Error al leer el archivo binario.\n";
        return;
    }
    Estudiante e;
    while(archivo.read((char*)&e,sizeof(Estudiante))){
        cout<<e.nombre<<"--"<<e.nota<<endl;
    }
    archivo.close();
}
void leerMostrarAprobados(const string& nombreArchivo){
    ifstream archivo(nombreArchivo,ios::binary);
    if(!archivo){
        cerr<<"Error al abrir el archivo.\n";
        return;
    }
    Estudiante e;
    cout<<"\nEstudiantes aprobados:\n";
    while(archivo.read((char*)&e,sizeof(Estudiante))){
        if(e.nota>=10){
            cout<<e.nombre<<"--"<<e.nota<<endl;
        }
    }
    archivo.close();
}
int main(){
    string nombreArchivo="notas.txt";
    escribirArchivo(nombreArchivo,"Juan",17);
    escribirArchivo(nombreArchivo,"Pedro",11);
    escribirArchivo(nombreArchivo,"Maria",18);
    cout<<"Inicio:\n";
    leerArchivo(nombreArchivo);
    agregarArchivo(nombreArchivo,"Melisa",14);
    agregarArchivo(nombreArchivo,"Arturo",15);
    agregarArchivo(nombreArchivo,"Andres",17);
    cout<<"\nFinal:\n";
    leerArchivo(nombreArchivo);
    const string archivoBinario="notas.dat";
    escribirBinario(archivoBinario,"Juan",9);
    escribirBinario(archivoBinario,"Pedro",11);
    escribirBinario(archivoBinario,"Maria",8);
    cout<<"\nContenido del archivo binario\n";
    leerBinario(archivoBinario);
    leerMostrarAprobados(archivoBinario);
    return 0;
}