#include "model_bagaglio_animale.h"

bagaglio_animale::bagaglio_animale(){}

bagaglio_animale::bagaglio_animale(int c, double m, double a, double l, double p, const Proprietario& prop, const Viaggio& v,QString descr){
    code=c;massa=m;altezza=a;larghezza=l;
    prof=p;pro=prop;viaggio=v;description=descr;
}

bagaglio_animale::bagaglio_animale(const bagaglio_animale& copia):bagaglio_vivente(copia){}

QString bagaglio_animale::getTipo() const{return bagaglio_vivente::getTipo()+", animale";}
