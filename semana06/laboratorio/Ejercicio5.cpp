#include<iostream>
#include<fstream>
using namespace std;
void escribirFibonacciBinario(const char* nombreArchivo){
    ofstream archivo;
    archivo.open(nombreArchivo,ios::binary);
    if(!archivo){
        cerr<<"Error al crear el archivo.\n";
        return;
    }
    int termino[20];
    for(int i=0;i<20;i++){
        if(i==0||i==1){
            termino[i]=i;
        }else{
            termino[i]=termino[i-1]+termino[i-2];
        }
    }
    archivo.write((char*)termino,20*sizeof(int));
    archivo.close();
    cout<<"Terminos de Fibonacci escritos en el archivo correctamente.\n";
}
void leerFibonacciBinario(const char* nombreArchivo){
    ifstream archivo;
    archivo.open(nombreArchivo,ios::binary);
    if(!archivo){
        cerr<<"Error al abrir el archivo.\n";
        return;
    }
    int termino[20];
    archivo.read((char*)termino,20*sizeof(int));
    for(int i=0;i<20;i++){
        cout<<"Termino "<<i+1<<": "<<termino[i]<<endl;
    }
    archivo.close();
}
int main(){
    escribirFibonacciBinario("fibonacci.bin");
    leerFibonacciBinario("fibonacci.bin");
    return 0;
}