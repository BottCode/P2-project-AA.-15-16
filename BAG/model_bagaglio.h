#ifndef MODEL_BAGAGLIO_H
#define MODEL_BAGAGLIO_H
#include <QString>
#include "model_proprietario.h"
#include "model_viaggio.h"
#include <QDebug>
#include <sstream>
#include <string>
class bagaglio{
   friend std::ostream& operator<<(std::ostream&, const bagaglio&);
protected:
    int code; // è un ID
    double massa;
    double altezza;
    double larghezza;
    double prof;
    Proprietario pro;
    Viaggio viaggio;
    QString description;
public:
    bagaglio();
    bagaglio(int,double,double,double,double,const Proprietario&,const Viaggio&,QString descr="No description");
    bagaglio(const bagaglio&);
    int getCode() const;
    double getMassa() const;
    void setMassa(int);
    double getAltezza() const;
    double getLarghezza() const;
    double getProf() const;
    double getVolume() const;
    QString getSize() const;
    Proprietario getProprietario() const;
    Viaggio getViaggio() const;
    void setViaggio(QString);
    QString getDescription() const;
    virtual QString getType() const;
    virtual QString getTipo() const;
    virtual double Tassa() const; // in euro. 0.5 euro per ogni Kg + 35 euro per ogni metro cubo
    virtual ~bagaglio();
};

#endif // MODEL_BAGAGLIO_H
