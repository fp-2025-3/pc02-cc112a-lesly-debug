#ifndef LIBRO_H
#define LIBRO_H
#include<string>
using namespace std;
class Libro{
    private:
    string titulo;
    string autor;
    int paginas;
    public:
    Libro();
    Libro(const string& t,const string& a,int p);
    ~Libro();
    string getTitulo() const;
    string getAutor() const;
    int getPaginas() const;
    void setTitulo(string& t);
    void setAutor(string& a);
    void setPaginas(int p);
    void mostrarInfo() const;
};
#endif