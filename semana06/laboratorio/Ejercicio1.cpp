#include<iostream>
#include<string>
#include<fstream>
using namespace std;
void escribirArchivo(double* numVenta,const string& nombreArchivo){
    ofstream archivo;
    archivo.open(nombreArchivo);
    if(!archivo){
        cerr<<"Error al crear el archivo.\n";
        return;
    }
    double total=0;
    double mayor=0;
    double menor=0; 
    double promedio;
    for(int i=0;i<7;i++){
        cout<<"Ingrese la venta del dia "<<i+1<<": ";
        cin>>numVenta[i];
        archivo<<numVenta[i]<<endl;
        total=total+numVenta[i];
        if(i==0){
            mayor=menor=numVenta[i];
        }else{
            if(mayor<numVenta[i]){
                mayor=numVenta[i];
            }
            if(numVenta[i]<menor){
                menor=numVenta[i];
            }
        }
    }
    promedio=total/7;
    archivo<<"--------------------------"<<endl;
    archivo<<"RESUMEN"<<endl;
    archivo<<"Total: "<<total<<endl;
    archivo<<"Promedio: "<<promedio<<endl;
    archivo<<"Mayor venta: "<<mayor<<endl;
    archivo<<"Menor venta: "<<menor<<endl;
    archivo.close();
}
int main(){
    double numVenta[7];
    escribirArchivo(numVenta,"ventas.txt");
    return 0;
}