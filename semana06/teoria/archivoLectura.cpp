#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
    ifstream in("miprimerArchivo.txt");
    if(!in.is_open()){
        cout<<"Error al abrir el archivo.\n";
        return 1;
    }
    string linea;
    while(getline(in,linea)){
        cout<<linea<<endl;
    }
    in.close();
    return 0;
}