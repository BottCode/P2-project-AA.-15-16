#include "model_bagaglio.h"

int bagaglio::getCode() const{return code;}
double bagaglio::getMassa() const{ return massa;}
void bagaglio::setMassa(int x){massa=x;}
double bagaglio::getAltezza() const{ return altezza;}
double bagaglio::getLarghezza() const{return larghezza;}
double bagaglio::getProf() const{return prof;}
QString bagaglio::getDescription() const{return description;}
QString bagaglio::getSize() const{return QString::number(altezza)+"x"+QString::number(larghezza)+"x"+QString::number(prof);}
double bagaglio::getVolume() const{return (larghezza/100)*(altezza/100)*(prof/100);}
Proprietario bagaglio::getProprietario() const{return pro;}
Viaggio bagaglio::getViaggio() const{return viaggio;}

void bagaglio::setViaggio(QString v){viaggio.setDestinazione(v);}


QString bagaglio::getType() const{return "";}
double bagaglio::Tassa() const{return (0.5*massa) + (35*getVolume());}
QString bagaglio::getTipo() const{return "Bagaglio";}

bagaglio::bagaglio(int c, double m, double a, double l, double p, const Proprietario& prop, const Viaggio& v, QString descr)
    : code(c),massa(m),altezza(a),larghezza(l),prof(p),pro(prop),viaggio(v),description(descr){}

bagaglio::bagaglio(const bagaglio& copia): code(copia.code),massa(copia.massa),altezza(copia.altezza),larghezza(copia.larghezza),
    prof(copia.prof), pro(copia.pro), viaggio(copia.viaggio), description(copia.description){}

bagaglio::bagaglio(){}

bagaglio::~bagaglio(){}
