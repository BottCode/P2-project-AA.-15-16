#include "model_bagaglio_in_stiva.h"

bagaglio_in_stiva::bagaglio_in_stiva(){}

bagaglio_in_stiva::bagaglio_in_stiva(int c, double m, double a, double l, double p, const Proprietario& prop, const Viaggio& v, QString descr){
    code=c;massa=m;altezza=a;larghezza=l;
    prof=p;pro=prop;viaggio=v;description=descr;
}

bagaglio_in_stiva::bagaglio_in_stiva(const bagaglio_in_stiva& copia):bagaglio(copia){}

QString bagaglio_in_stiva::getTipo() const{return bagaglio::getTipo()+" in stiva";}
