#include<iostream>
#include<string>
using namespace std;
struct Pelicula{
    string titulo;
    string director;
    int anio;
    int minutos;
    float rating;
};
int main(){
    Pelicula* p=new Pelicula[3];
    for(int i=0;i<3;i++){
        cout<<"Titulo: ";
        getline(cin,(p+i)->titulo);
        cout<<"Director: ";
        getline(cin,(p+i)->director);
        cout<<"Anio: ";
        cin>>(p+i)->anio;
        cout<<"Tiempo (en minutos): ";
        cin>>(p+i)->minutos;
        cout<<"Rating: ";
        cin>>(p+i)->rating;
        cin.ignore(1000,'\n');
    }
    cout<<"Pelicula con mayor rating: ";
    int indMax=0;
    for(int i=1;i<3;i++){
        if((p+i)->rating>(p+indMax)->rating){
            indMax=i;
        }
    }
    cout<<(p+indMax)->titulo<<" "<<(p+indMax)->director<<" "<<(p+indMax)->anio<<" "<<(p+indMax)->minutos<<" "<<(p+indMax)->rating<<endl;
    string directorBuscado="James Cameron";
    bool encontrado=false;
    cout<<"Peliculas del director "<<directorBuscado<<" :\n";
    for(int i=0;i<3;i++){
        if((p+i)->director==directorBuscado){
            cout<<(p+i)->titulo<<" ";
            encontrado=true;
        }
    }
    if(!encontrado){
        cout<<"No se encontaron peliculas del director "<<directorBuscado;
    }
    delete[] p;
    return 0;
}