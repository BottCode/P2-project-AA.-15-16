#include "model_bagaglio_non_vivente_normale.h"

bagaglio_normale::bagaglio_normale(int c, double m, double a, double l, double p, const Proprietario& prop, const Viaggio& v, QString descr){
    code=c;massa=m;altezza=a;larghezza=l;
    prof=p;pro=prop;viaggio=v;description=descr;
}

bagaglio_normale::bagaglio_normale(const bagaglio_normale& copia): bagaglio_non_vivente(copia){}

QString bagaglio_normale::getType() const{
    return "NORMAL";
}

QString bagaglio_normale::getTipo() const{return bagaglio_non_vivente::getTipo()+", normale";}
