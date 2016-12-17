#include "model_bagaglio_non_vivente.h"

bagaglio_non_vivente::bagaglio_non_vivente(){}

bagaglio_non_vivente::bagaglio_non_vivente(int c, double m, double a, double l, double p, const Proprietario& prop, const Viaggio& v, QString descr){
    code=c;massa=m;altezza=a;larghezza=l;
    prof=p;pro=prop;viaggio=v;description=descr;
}

bagaglio_non_vivente::bagaglio_non_vivente(const bagaglio_non_vivente& copia): bagaglio_in_stiva(copia){}

QString bagaglio_non_vivente::getTipo() const{return bagaglio_in_stiva::getTipo()+", non biologico";}
