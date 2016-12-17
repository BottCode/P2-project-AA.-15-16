#include "model_proprietario.h"

QString Proprietario::getNome() const{return nome;}
QString Proprietario::getCognome() const{return cognome;}
QString Proprietario::getFullName() const{return nome+" "+cognome;}
QDate Proprietario::getQDateNascita() const{return QDate_nascita;}
QString Proprietario::getResidenza() const{return residenza;}
bool Proprietario::getParte() const{return parte;}

Proprietario::~Proprietario(){}

Proprietario::Proprietario(){}

Proprietario::Proprietario(QString n, QString c, const QDate &d, QString r, bool b)
    :nome(n),cognome(c),QDate_nascita(d),residenza(r),parte(b){}

Proprietario::Proprietario(const Proprietario& copia)
    :nome(copia.nome),cognome(copia.cognome),QDate_nascita(copia.QDate_nascita),residenza(copia.residenza)
    , parte(copia.parte){}


