#include<iostream>//'' de consola
#include<fstream>//flujo para entrada y salida de archivos
#include<string>
using namespace std;
int main(){
    ofstream archivoEscritura;
    archivoEscritura.open("notas.txt");
    if(!archivoEscritura){
        cerr<<"Error al abrir el archivo para escritura.\n";
        return 1;
    }
    archivoEscritura<<"Juan 15\n";
    archivoEscritura<<"Pedro 11\n";
    archivoEscritura<<"Maria 18\n";
    archivoEscritura.close();
    ifstream archivoLectura("notas.txt");
    if(!archivoLectura){
        cerr<<"No existe el archivo.\n";
        return 1;
    }
    string nombre;
    int nota;
    while(archivoLectura>>nombre>>nota){
        cout<<nombre<<" "<<nota<<endl;
    }
    archivoLectura.close();
    ofstream fout("notas.txt",ios::app|ios::out);
    if(!fout){
        cerr<<"Error al abrir el archivo escritura.\n";
        return 1;
    }
    fout<<"Melisa 14\n";
    fout<<"Arturo 15\n";
    fout<<"Andres 17\n";
    cout<<"Datos agregados correctamente.\n";
    return 0;
}