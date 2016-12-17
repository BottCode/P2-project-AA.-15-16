#include "model_bagaglio_animale_pericoloso.h"

bagaglio_animale_pericoloso::bagaglio_animale_pericoloso(int c, double m, double a, double l, double p, const Proprietario& prop, const Viaggio& v, QString descr){
    code=c;massa=m;altezza=a;larghezza=l;
    prof=p;pro=prop;viaggio=v;description=descr;
}

bagaglio_animale_pericoloso::bagaglio_animale_pericoloso(const bagaglio_animale_pericoloso& copia):bagaglio_animale(copia){}

double bagaglio_animale_pericoloso::Tassa() const{return 0.75*massa + bagaglio_vivente::Tassa();}

QString bagaglio_animale_pericoloso::getType() const{return "DANGEROUS ANIMAL";}
QString bagaglio_animale_pericoloso::getTipo() const{return bagaglio_animale::getTipo()+", pericoloso";}
