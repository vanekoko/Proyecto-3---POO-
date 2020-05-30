#include <iostream>
#include <fstream>
#include "Reserva.h"
#include <ctime>
using namespace std;

int main(){
    string tit,tipo,tex;
    int idm, num,dd,mm,aa,idc;
    Material *mate[30];
    Reserva ar[60];
    ifstream in_material,in_reserva;
    in_material.open("Material.txt");
    in_reserva.open("Reserva.txt");
    Libro lib[30];
    Disco dis[30];
    Software soft[30];
    int m=0, l=0, d=0,s=0;
    while(in_material>>idm>>tit>>tipo>>num>>tex){
            if(tipo=="L"){
                lib[l].setid(idm);
                lib[l].setTitulo(tit);
                lib[l].setnumPag(num);
                lib[l].setautor(tex);
                mate[m]=&lib[l];
                l++;
            }
            else if(tipo=="D"){
                dis[d].setid(idm);
                dis[d].setTitulo(tit);
                dis[d].setduracion(num);
                dis[d].setgenero(tex);
                mate[m]=&dis[d];
                d++;
            }
            else if(tipo=="S"){
                soft[s].setid(idm);
                soft[s].setTitulo(tit);
                soft[s].setversion(num);
                soft[s].setSO(tex);
                mate[m]=&soft[s];
                s++;
            }
            m++;
        }
    int r=0;
    Fecha finReser[60];
    while(in_reserva>>dd>>mm>>aa>>idm>>idc){
        ar[r].setfechaReservacion(dd,mm,aa);
        ar[r].setidMaterial(idm);
        ar[r].setidCliente(idc);
        for(int c=0;c<m;c++){
            int *id=&idm;
            if(*id==mate[c]->getid()){
                finReser[r]=ar[r].calculaFechaFinReserva(mate[c]->cantidadDiasPrestamo());
                //cout<<finReser[r].getdd()<<"   "<<finReser[r].nombreMes()<<"   "<<finReser[r].getaa()<<endl;
                break;
            }
        }
        r++;
    }
    in_material.close();
    in_reserva.close();
    char op;
    while(op!='f'){
        cout<<"\nBienvenido al menu de reservaciones: \nIngrese la opcion deseada:"<<endl;
        cout<<"a. Ver lista de materiales disponibles\nb. Ver lista de reservaciones\nc. Consultar reservaciones por material"<<endl;
        cout<<"d. Ver reservaciones por fecha\ne. Hacer una reservacion\nf. Terminar"<<endl;
        cin>>op;
        switch(op){
            case 'a':{
                cout<<"----------------------------------------------\nLibro"<<endl;
                for(int a=0;a<l;a++){
                    lib[a].muestraDatos();
                }
                cout<<"----------------------------------------------\nDisco"<<endl;
                for(int a=0;a<d;a++){
                    dis[a].muestraDatos();
                }
                cout<<"----------------------------------------------\nSoftware"<<endl;
                for(int a=0;a<s;a++){
                    soft[a].muestraDatos();
                }
                break;
            }
            case 'b':{
                for(int b=0;b<r;b++){
                    cout<<"ID Material: "<<ar[b].getidMaterial()<<" ID Cliente: "<<ar[b].getidCliente();
                    cout<<" Fecha inicio: "<<ar[b].getfechaReservacion().getdd()<<" "<<ar[b].getfechaReservacion().nombreMes()<<" "<<ar[b].getfechaReservacion().getaa();
                    cout<<" Fecha fin: "<<finReser[b].getdd()<<" "<<finReser[b].nombreMes()<<" "<<finReser[b].getaa()<<endl;
                }
                break;
            }
            case 'c':{
                int check;
                int inid;
                cout<<"Ingrese ID del material: ";cin>>inid;
                for(int c=0;c<m;c++){
                        int *ainid=&inid;
                        if(*ainid==mate[c]->getid()){
                            for(int c2=0;c2<r;c2++){
                                if(mate[c]->getid()==ar[c2].getidMaterial()){
                                    cout<<"Cliente: "<<ar[c2].getidCliente();
                                    cout<<"\tFecha inicio: "<<ar[c2].getfechaReservacion().getdd()<<" " <<ar[c2].getfechaReservacion().nombreMes()<<" "<<ar[c2].getfechaReservacion().getaa();
                                    cout<<"\tFecha fin: "<<finReser[c2].getdd()<<" " <<finReser[c2].nombreMes()<<" "<<finReser[c2].getaa()<<endl;
                                }
                            }
                        check=1;
                        }
                }
                if(check==1){
                    cout<<endl;
                }
                else{
                    cout<<"El material no existe. Porfavor intentelo de nuevo"<<endl;
                }
                check=0;
                break;
            }
            case 'd':{
                int ind,inm,ina, check;
                cout<<"Ingrese dia: ";cin>>ind;cout<<" Mes: ";cin>>inm;cout<<" Anio: ";cin>>ina;
                if(ind>=0 && ind<61 && inm>=0 && inm<13 && ina>=2000 && ina<2100){
                    Fecha prueba(ind,inm,ina);
                    for(int d=0;d<r;d++){
                        if(prueba>=ar[d].getfechaReservacion() && prueba<=finReser[d]){
                            cout<<"ID Material: "<<ar[d].getidMaterial()<<" Cliente: "<<ar[d].getidCliente();
                            cout<<"\tFecha inicio: "<<ar[d].getfechaReservacion().getdd()<<" " <<ar[d].getfechaReservacion().nombreMes()<<" "<<ar[d].getfechaReservacion().getaa();
                            cout<<"\tFecha fin: "<<finReser[d].getdd()<<" " <<finReser[d].nombreMes()<<" "<<finReser[d].getaa()<<endl;
                            check=1;
                        }
                    }
                    if(check!=1){
                        cout<<"Fecha no coincide con alguna reservacion. Porfavor intente de nuevo"<<endl;
                    }
                }
                else{
                    cout<<"Fecha invalida. Porfavor intente de nuevo."<<endl;
                }
                check=0;
                break;
            }
            case 'e':{
                ofstream oreserva;
                time_t now=time(0);
                tm *time=localtime(&now);
                Fecha ahora(time->tm_mday,(time->tm_mon+1),(time->tm_year+1900));
                int inic,inim;
                cout<<"\nIngrese ID Cliente: ";cin>>inic;cout<<"\nIngrese ID Material: ";cin>>inim;
                int rr=r+1;
                int check,check2;
                Fecha temp;
                for(int e=0;e<r;e++){
                    if(inim==ar[e].getidMaterial()){
                        if(temp<=finReser[e]){
                            temp=finReser[e];
                            if(temp>=ahora){
                                check=0;
                            }
                            else{
                               check=1;
                               check2=e;
                            }
                        }
                    }
                }
                if(check2>100){
                    cout<<"El material no existe. Intentelo de nuevo"<<endl;
                    break;
                }
                if(check==1){
                    ar[r].setidCliente(inic);
                    ar[r].setidMaterial(inim);
                    ar[r].setfechaReservacion(time->tm_mday,(time->tm_mon+1),(time->tm_year+1900));
                    finReser[r]=ar[r].calculaFechaFinReserva(mate[check2]->cantidadDiasPrestamo());
                    oreserva.open("Reserva.txt");
                    for(int e=0;e<rr;e++){
                        oreserva<<ar[e].getfechaReservacion().getdd()<<" "<<ar[e].getfechaReservacion().getmm()<<" "<<ar[e].getfechaReservacion().getaa()<<" "<<ar[e].getidMaterial()<<" "<<ar[e].getidCliente()<<endl;
                        //cout<<ar[e].getfechaReservacion().getdd()<<" "<<ar[e].getfechaReservacion().getmm()<<" "<<ar[e].getfechaReservacion().getaa()<<" "<<ar[e].getidMaterial()<<" "<<ar[e].getidCliente()<<endl;
                    }
                    oreserva.close();
                    cout<<"\nEl registro ha sido exitoso"<<endl;
                    cout<<"El material "<<" vence el "<<finReser[r].getdd()<<" "<<finReser[r].nombreMes()<<" "<<finReser[r].getaa()<<endl;
                }
                else if(check==0 ){
                    cout<<"El material no esta disponible"<<endl;
                }
                check=0;
                check2=100;
                break;
            }
        }
    }
    return 0;
}
