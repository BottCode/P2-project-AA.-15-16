#include "model_bagaglio_animale_mansueto.h"

bagaglio_animale_mansueto::bagaglio_animale_mansueto(int c, double m, double a, double l, double p, const Proprietario& prop, const Viaggio& v, QString descr){
    code=c;massa=m;altezza=a;larghezza=l;
    prof=p;pro=prop;viaggio=v;description=descr;
}

bagaglio_animale_mansueto::bagaglio_animale_mansueto(const bagaglio_animale_mansueto& copia): bagaglio_animale(copia){}

QString bagaglio_animale_mansueto::getType() const{return "TAME ANIMAL";}

QString bagaglio_animale_mansueto::getTipo() const{return bagaglio_animale::getTipo()+", mansueto";}
