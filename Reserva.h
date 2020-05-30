#include <iostream>
#include "Fecha.h"
#include "Material.h"
using namespace std;

class Reserva{
    private:
        int idMaterial, idCliente;
        Fecha fechaReservacion;
    public:
        Reserva(){idMaterial=0;idCliente=0;}
        Reserva(int iM,int iC,Fecha r){idMaterial=iM;idCliente=iC;fechaReservacion=r;};
        void setidMaterial(int iM){idMaterial=iM;};
        void setidCliente(int iC){idCliente=iC;};
        void setfechaReservacion(int d,int m, int a){Fecha temp(d,m,a);fechaReservacion=temp;};
        int getidMaterial(){return idMaterial;};
        int getidCliente(){return idCliente;};
        Fecha getfechaReservacion(){return fechaReservacion;};
        Fecha calculaFechaFinReserva(int x);
};

Fecha Reserva::calculaFechaFinReserva(int x){
    Fecha nuevo=fechaReservacion+x;
    return nuevo;
}

