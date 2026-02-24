#define LIBRO.H
#include<string>
using namespace std;
class Libro{
    private:
    string titulo;
    string autor;
    int paginas;
    public:
    Libro();
    Libro(string& t,string& a,int p);
    ~Libro();
};
