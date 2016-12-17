#ifndef MODEL_VIAGGIO_H
#define MODEL_VIAGGIO_H

#include<iostream>
#include<QDate>
#include<QString>
class Viaggio{
    friend std::ostream& operator <<(std::ostream&,const Viaggio&);
private:
    int ID;
    QString Destinazione;
    QDate data;
    QString modo;
public:
    Viaggio();
    Viaggio(int, QString,QDate,QString);
    Viaggio(const Viaggio&);
    int getID() const;
    QString getDest() const;
    void setDestinazione(QString);
    QDate getQDate() const;
    QString getModo() const;
};

std::ostream& operator <<(std::ostream&,const Viaggio&);
#endif // MODEL_VIAGGIO_H
