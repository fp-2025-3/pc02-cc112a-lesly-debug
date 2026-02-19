#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
struct punto2D{
    double x;
    double y;
};
void leerArchivo(const string& nombreArchivo){
    ifstream archivo;
    archivo.open(nombreArchivo);
    if(!archivo){
        cerr<<"Error al abrir el archivo.\n";
        return;
    }
    int nt,nv;
    archivo>>nt;
    archivo>>nv;
    punto2D* vertice=new punto2D[nv];
    for(int i=0;i<nv;i++){
        archivo>>vertice[i].x>>vertice[i].y;
    }
    int (*triangulo)[3]=new int[nt][3];
    for(int i=0;i<nt;i++){
        archivo>>triangulo[i][0]>>triangulo[i][1]>>triangulo[i][2];
    }
    archivo.close();
    double areaTotal=0;
    for(int i=0;i<nt;i++){
        punto2D p1=vertice[triangulo[i][0]-1];//Si no resto 1, se pierde el indice 0 y produce un error al llegar al ultimo elemento
        punto2D p2=vertice[triangulo[i][1]-1];
        punto2D p3=vertice[triangulo[i][2]-1];
        areaTotal=areaTotal+fabs(p1.x*(p3.y-p2.y)+p2.x*(p1.y-p3.y)+p3.x*(p2.y-p1.y))/2;
    }
    fstream out;
    out.open("output/area.txt",ios::out);
    out<<"Area: "<<areaTotal;
    delete[] triangulo;
    delete[] vertice;
    out.close();
}
int main(){
    leerArchivo("input/laguna.txt");
    return 0;
}