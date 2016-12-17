#ifndef MODEL_BAGAGLIO_ANIMALE_PERICOLOSO_H
#define MODEL_BAGAGLIO_ANIMALE_PERICOLOSO_H
#include "model_bagaglio_animale.h"
#include <QString>

class bagaglio_animale_pericoloso: public bagaglio_animale{
public:
     bagaglio_animale_pericoloso();
     bagaglio_animale_pericoloso(int,double,double,double,double,const Proprietario&,const Viaggio&,QString descr="No description");
     bagaglio_animale_pericoloso(const bagaglio_animale_pericoloso&);
     virtual double Tassa() const; // aggiunta di 0.75 euro per ogni kg
     virtual QString getType() const ;
     virtual QString getTipo() const ;
};


#endif // MODEL_BAGAGLIO_ANIMALE_PERICOLOSO_H
