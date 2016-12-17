#include "model_bagaglio_vivente.h"

bagaglio_vivente::bagaglio_vivente()
{
}

bagaglio_vivente::bagaglio_vivente(int c, double m, double a, double l, double p, const Proprietario& prop, const Viaggio& v, QString descr){
    code=c;massa=m;altezza=a;larghezza=l;
    prof=p;pro=prop;viaggio=v;description=descr;
}

bagaglio_vivente::bagaglio_vivente(const bagaglio_vivente& copia):bagaglio_in_stiva(copia){}

double bagaglio_vivente::Tassa() const{return (0.2*massa + bagaglio::Tassa());}
QString bagaglio_vivente::getTipo() const{return bagaglio_in_stiva::getTipo()+". vivente";}
