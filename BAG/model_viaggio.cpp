#include "model_viaggio.h"

int Viaggio::getID() const{return ID;}
QString Viaggio::getDest() const{return Destinazione;}

void Viaggio::setDestinazione(QString d){Destinazione=d;}
QDate Viaggio::getQDate() const{return data;}

QString Viaggio::getModo() const{return modo;}

Viaggio::Viaggio(){}

Viaggio::Viaggio(int ident, QString dest, QDate qd, QString m): ID(ident),Destinazione(dest),data(qd),modo(m){}

Viaggio::Viaggio(const Viaggio& copia): ID(copia.ID), Destinazione(copia.Destinazione),data(copia.data),modo(copia.modo){}

