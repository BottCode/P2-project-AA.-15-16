#include "model_bagaglio_non_vivente_speciale.h"

bagaglio_speciale::bagaglio_speciale(int c, double m, double a, double l, double p, const Proprietario& prop, const Viaggio& v, QString descr){
    code=c;massa=m;altezza=a;larghezza=l;
    prof=p;pro=prop;viaggio=v;description=descr;
}

bagaglio_speciale::bagaglio_speciale(const bagaglio_speciale& copia): bagaglio_non_vivente(copia){}

double bagaglio_speciale::Tassa() const{return 0.80*massa + bagaglio::Tassa();}

QString bagaglio_speciale::getType() const{
    return "SPECIAL";
}

QString bagaglio_speciale::getTipo() const{return bagaglio_non_vivente::getTipo()+", speciale";}

