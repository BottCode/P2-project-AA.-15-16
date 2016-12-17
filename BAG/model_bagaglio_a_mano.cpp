#include "model_bagaglio_a_mano.h"

bagaglio_a_mano::bagaglio_a_mano(){}

bagaglio_a_mano::bagaglio_a_mano(int c, double m, double a, double l, double p, const Proprietario& prop, const Viaggio& v, QString descr){
    code=c;massa=m;altezza=a;larghezza=l;
    prof=p;pro=prop;viaggio=v;description=descr;
}

bagaglio_a_mano::bagaglio_a_mano(const bagaglio_a_mano &copia): bagaglio(copia){}

QString bagaglio_a_mano::getType() const{return "HAND";}

QString bagaglio_a_mano::getTipo() const{return bagaglio::getTipo()+" a mano";}
