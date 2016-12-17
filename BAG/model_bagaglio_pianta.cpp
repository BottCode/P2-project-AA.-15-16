#include "model_bagaglio_pianta.h"


bagaglio_pianta::bagaglio_pianta(int c, double m, double a, double l, double p, const Proprietario& prop, const Viaggio& v, QString descr){
    code=c;massa=m;altezza=a;larghezza=l;
    prof=p;pro=prop;viaggio=v;description=descr;
}
bagaglio_pianta::bagaglio_pianta(const bagaglio_pianta& copia): bagaglio_vivente(copia){}

QString bagaglio_pianta::getType() const{
    return "PLANT";
}

QString bagaglio_pianta::getTipo() const{return bagaglio_vivente::getTipo()+", pianta";}
