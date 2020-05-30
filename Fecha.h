#include <iostream>
using namespace std;

class Fecha{
private:
    int dd, mm, aa;
public:
    string nombreMes();
    Fecha(){dd=0;mm=0;aa=0;};
    Fecha(int d, int m, int a){dd=d;mm=m;aa=a;};
    int getdd(){return dd;};
    int getmm(){return mm;};
    int getaa(){return aa;};
    void setFecha(int d, int m, int a){dd=d;mm=m;aa=a;};
    Fecha operator+(int);
    bool operator>=(Fecha);
    bool operator<=(Fecha);
    bool operator>(Fecha);
    bool operator<(Fecha);
    bool operator==(Fecha);
    friend ostream & operator << (ostream &out, Fecha &f);
    friend istream & operator >> (istream &in,  Fecha &f);
};


string Fecha::nombreMes(){
    int x=getmm();
    switch (x){
        case 1:{
        return "Ene";
        break;
        }
        case 2:{
        return "Feb";
        break;
        }
        case 3:{
        return "Mar";
        break;
        }
        case 4:{
        return "Abr";
        break;
        }
        case 5:{
        return "May";
        break;
        }
        case 6:{
        return "Jun";
        break;
        }
        case 7:{
        return "Jul";
        break;
        }
        case 8:{
        return "Ago";
        break;
        }
        case 9:{
        return "Sep";
        break;
        }
        case 10:{
        return "Oct";
        break;
        }
        case 11:{
        return "Nov";
        break;
        }
        case 12:{
        return "Dic";
        break;
        }
    }
}

Fecha Fecha::operator+(int d){
    if(mm==1||mm==3||mm==5||mm==7||mm==8||mm==10||mm==12){
            if(d>31){
                int y=d/31;
                int x=d-(y*31);
                int nm=mm+y;
                int nd=dd+x;
                if(nd>=32){
                    int yy=nd/31;
                    nd=nd-(yy*31);
                    nm=nm+yy;
                    if(nm>12){
                            int w=nm/12;
                            int v=nm-(12*w);
                            int na=aa+w;
                            nm=nm+v;
                            Fecha nuevo(nd,nm,na);
                            return nuevo;
                    }
                    else{
                        int na=aa;
                        Fecha nuevo(nd,nm,na);
                        return nuevo;
                    }
                }
                else {
                    if(nm>12){
                            int w=nm/12;
                            int v=nm-(12*w);
                            int na=aa+w;
                            nm=nm+v;
                            Fecha nuevo(nd,nm,na);
                            return nuevo;
                    }
                    else{
                        int na=aa;
                        Fecha nuevo(nd,nm,na);
                        return nuevo;
                    }

                }
            }
            else if(d<=31){
                int nd=(dd+d);
                int nm=mm;
                if(nd>=32){
                    int yy=nd/31;
                    nd=nd-(yy*31);
                    nm=nm+yy;
                    if(nm>12){
                            int w=nm/12;
                            int v=nm-(12*w);
                            int na=aa+w;
                            nm=nm+v;
                            Fecha nuevo(nd,nm,na);
                            return nuevo;
                    }
                    else{
                        int na=aa;
                        Fecha nuevo(nd,nm,na);
                        return nuevo;
                    }
                }
                else{
                    if(nm>12){
                            int w=nm/12;
                            int v=nm-(12*w);
                            int na=aa+w;
                            nm=nm+v;
                            Fecha nuevo(nd,nm,na);
                            return nuevo;
                    }
                    else{
                        int na=aa;
                        Fecha nuevo(nd,nm,na);
                        return nuevo;
                    }

                }
            }
        }
    else if(mm==4||mm==6||mm==9||mm==11){
            if(d>30){
                int y=d/30;
                int x=d-(y*30);
                int nm=mm+y;
                int nd=dd+x;
                if(nd>30){
                    int yy=nd/30;
                    nd=nd-(yy*30);
                    nm=nm+yy;
                    if(nm>12){
                            int w=nm/12;
                            int v=nm-(12*w);
                            int na=aa+w;
                            nm=nm+v;
                            Fecha nuevo(nd,nm,na);
                            return nuevo;
                    }
                    else{
                        int na=aa;
                        Fecha nuevo(nd,nm,na);
                        return nuevo;
                    }
                }
                else{
                    if(nm>12){
                            int w=nm/12;
                            int v=nm-(12*w);
                            int na=aa+w;
                            nm=nm+v;
                            Fecha nuevo(nd,nm,na);
                            return nuevo;
                    }
                    else{
                        int na=aa;
                        Fecha nuevo(nd,nm,na);
                        return nuevo;
                    }

                }
            }
            else if(d<=30){
                int nd=dd+d;
                int nm=mm;
                if(nd>30){
                    int yy=nd/30;
                    nd=nd-(yy*30);
                    nm=nm+yy;
                    if(nm>12){
                            int w=nm/12;
                            int v=nm-(12*w);
                            int na=aa+w;
                            nm=nm+v;
                            Fecha nuevo(nd,nm,na);
                            return nuevo;
                    }
                    else{
                        int na=aa;
                        Fecha nuevo(nd,nm,na);
                        return nuevo;
                    }
                }
                else{
                    if(nm>12){
                            int w=nm/12;
                            int v=nm-(12*w);
                            int na=aa+w;
                            nm=nm+v;
                            Fecha nuevo(nd,nm,na);
                            return nuevo;
                    }
                    else{
                        int na=aa;
                        Fecha nuevo(nd,nm,na);
                        return nuevo;
                    }

                }
            }
        }
    else if(mm==2){
        if(d>28){
            int y=d/28;
            int x=d-(y*28);
            int nm=mm+y;
            int nd=dd+x;
            if(nd>=29){
                int yy=nd/28;
                    nd=29-(yy*28);
                    nm=nm+yy;
                if(nm>12){
                        int w=nm/12;
                        int v=nm-(12*w);
                        int na=aa+w;
                        nm=nm+v;
                        Fecha nuevo(nd,nm,na);
                        return nuevo;
                }
                else{
                    int na=aa;
                    Fecha nuevo(nd,nm,na);
                    return nuevo;
                }
            }
            else{
                if(nm>12){
                        int w=nm/12;
                        int v=nm-(12*w);
                        int na=aa+w;
                        nm=nm+v;
                        Fecha nuevo(nd,nm,na);
                        return nuevo;
                }
                else{
                    int na=aa;
                    Fecha nuevo(nd,nm,na);
                    return nuevo;
                }

            }
        }
        else if(d<=28){
            int nd=dd+d;
            int nm=mm;
            if(nd>28){
                int yy=nd/28;
                nd=nd-(yy*28);
                nm=nm+yy;
                if(nm>12){
                        int w=nm/12;
                        int v=nm-(12*w);
                        int na=aa+w;
                        nm=nm+v;
                        Fecha nuevo(nd,nm,na);
                        return nuevo;
                }
                else{
                    int na=aa;
                    Fecha nuevo(nd,nm,na);
                    return nuevo;
                }
            }
            else{
                if(nm>12){
                        int w=nm/12;
                        int v=nm-(12*w);
                        int na=aa+w;
                        nm=nm+v;
                        Fecha nuevo(nd,nm,na);
                        return nuevo;
                }
                else{
                    int na=aa;
                    Fecha nuevo(nd,nm,na);
                    return nuevo;
                }

            }
        }
    }
}


bool Fecha::operator>=(Fecha ob2){
    if(aa>ob2.aa){
        return true;
    }
    else if(aa==ob2.aa){
        if(mm>ob2.mm){
            return true;
        }
        else if(mm==ob2.mm){
            if(dd>ob2.dd||dd==ob2.dd){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

bool Fecha::operator<=(Fecha ob2){
    if(aa<ob2.aa){
        return true;
    }
    else if(aa==ob2.aa){
        if(mm<ob2.mm){
            return true;
        }
        else if(mm==ob2.mm){
            if(dd<ob2.dd||dd==ob2.dd){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

bool Fecha::operator>(Fecha ob2){
    if(aa>ob2.aa){
        return true;
    }
    else if(aa==ob2.aa){
        if(mm>ob2.mm){
            return true;
        }
        else if(mm==ob2.mm){
            if(dd>ob2.dd){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

bool Fecha::operator<(Fecha ob2){
    if(aa<ob2.aa){
        return true;
    }
    else if(aa==ob2.aa){
        if(mm<ob2.mm){
            return true;
        }
        else if(mm==ob2.mm){
            if(dd<ob2.dd){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

bool Fecha::operator==(Fecha ob2){
    if(aa==ob2.aa){
        if(mm==ob2.mm){
                if(dd==ob2.dd){
                    return true;
                }
                else{
                    return false;
                }
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

ostream & operator << (ostream &out, Fecha &f){
    out<<f.dd<<"/";
    out<<f.mm<<"/";
    out<<f.aa<<endl;
}

istream & operator >> (istream &in,  Fecha &f){
    cout<<"Dia: ";
    in>>f.dd;
    cout<<"Mes: ";
    in>>f.mm;
    cout<<"Anio: ";
    in>>f.aa;
}
