#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void escribirArchivo(const string& nombreArchivo){
    ofstream archivo(nombreArchivo);
    if(!archivo){
        cerr<<"Error al crear el archivo.\n";
    }
    archivo<<"Juan 15\n";
    archivo<<"Pedro 11\n";
    archivo<<"Maria 18\n";
}
void leerArchivo(const string& nombreArchivo){
    ifstream archivo(nombreArchivo);
    if(!archivo){
        cerr<<"Error al abrir el archivo.\n";
    }
    string nombre;
    int n;
    while(archivo>>nombre>>n){
        cout<<nombre<<" "<<n<<endl;
    }
    archivo.close();
}
void agregarArchivo(const string& nombreArchivo){
    fstream archivo(nombreArchivo,ios::app|ios::out);
    if(!archivo){
        cerr<<"Error al abrir el archivo.\n";
    }
    archivo<<"Melisa 14\n";
    archivo<<"Arturo 15\n";
    archivo<<"Andres 17\n";
}
int main(){
    escribirArchivo("notas.txt");
    cout<<"Inicio:\n";
    leerArchivo("notas.txt");
    agregarArchivo("notas.txt");
    cout<<"Final:\n";
    leerArchivo("notas.txt");
    return 0;
}