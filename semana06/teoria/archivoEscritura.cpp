#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ofstream out("miprimerArchivo.txt");//ios::out crea o sobreescribe
    if(!out.is_open()){
        cout<<"Error: el archivo no pudo crearse\n";
        return 1;
    }
    out<<"Este es el contenido de\n";
    out<<"mi primer archivo de texto.\n";
    out.close();
    cout<<"Archivo creado exitosamente\n";
    ofstream out2("miprimerArchivo.txt",ios::app);
    if(out2.is_open()){
        out2<<"Texto agregado\n";
        out2.close();
    }
    return 0;
}