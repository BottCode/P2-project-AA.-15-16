#ifndef MODEL_PROPRIETARIO_H
#define MODEL_PROPRIETARIO_H

#include<QDate>
#include <QString>
#include<iostream>
class Proprietario{
    friend std::ostream& operator <<(std::ostream&,const Proprietario&);
private:
    QString nome;
    QString cognome;
    QDate QDate_nascita; // gg/mm/aa
    QString residenza;
    bool parte; // true <=> il proprietario sale sullo stesso aereo. (magari deve solo spedire)
public:
    Proprietario();
    Proprietario(QString,QString,const QDate&,QString,bool);
    Proprietario(const Proprietario&);
    QString getNome() const;
    QString getCognome() const;
    QString getFullName() const;
    QDate getQDateNascita() const;
    QString getResidenza() const;
    bool getParte() const;
    ~Proprietario();
};

std::ostream& operator <<(std::ostream&,const Proprietario&);
#endif // MODEL_PROPRIETARIO_H
