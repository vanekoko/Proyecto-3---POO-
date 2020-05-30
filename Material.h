#include <iostream>
using namespace std;

class Material{
protected:
    int idMaterial;
    string Titulo;
public:
    Material(){idMaterial=0;Titulo="";};
    Material(int i,string t){idMaterial=i;Titulo=t;};
    void setid(int i){idMaterial=i;};
    void setTitulo(string t){Titulo=t;};
    int getid(){return idMaterial;};
    string getTitulo(){return Titulo;};
    virtual void muestraDatos()=0;
    virtual int cantidadDiasPrestamo()=0;
};

class Libro: public Material{
private:
    int numPag;
    string autor;
public:
    Libro():Material(){numPag=0;autor="";};
    Libro(int n, string a,int i, string t):Material(i,t){numPag=n;autor=a;};
    void setnumPag(int n){numPag=n;};
    void setautor(string a){autor=a;};
    int getnumPag(){return numPag;};
    string getautor(){return autor;};
    void muestraDatos(){cout<<"ID: "<<idMaterial<<"\tTitulo: "<<Titulo<<"\t\tNumero de Paginas: "<<numPag<<"\tAutor: "<<autor<<endl;};
    int cantidadDiasPrestamo(){return 7;};
};

class Disco: public Material{
private:
    int duracion;
    string genero;
public:
    Disco():Material(){duracion=0;genero="";};
    Disco(int n, string a,int i, string t):Material(i,t){duracion=n;genero=a;};
    void setduracion(int n){duracion=n;};
    void setgenero(string a){genero=a;};
    int getduracion(){return duracion;};
    string getgenero(){return genero;};
    void muestraDatos(){cout<<"ID: "<<idMaterial<<"\tTitulo: "<<Titulo<<"\t\tDuracion: "<<duracion<<"\tGenero: "<<genero<<endl;};
    int cantidadDiasPrestamo(){return 2;};
};

class Software: public Material{
private:
    int version;
    string SO;
public:
    Software():Material(){version=0;SO="";};
    Software(int n, string a,int i, string t):Material(i,t){version=n;SO=a;};
    void setversion(int n){version=n;};
    void setSO(string a){SO=a;};
    int getversion(){return version;};
    string getSO(){return SO;};
    void muestraDatos(){cout<<"ID: "<<idMaterial<<"\tTitulo: "<<Titulo<<"\t\tVersion: "<<version<<"\tSistema Operativo: "<<SO<<endl;};
    int cantidadDiasPrestamo(){return 1;};
};
