#ifndef MODEL_VIVENTE_H
#define MODEL_VIVENTE_H
#include "model_bagaglio_in_stiva.h"

class bagaglio_vivente: public bagaglio_in_stiva{
public:
    bagaglio_vivente();
    bagaglio_vivente(int,double,double,double,double,const Proprietario&,const Viaggio&,QString descr="No description");
    bagaglio_vivente(const bagaglio_vivente&);
    virtual double Tassa() const; // aggiunta di 0.2 euro per ogni kg
    virtual QString getTipo() const;
};


#endif // MODEL_VIVENTE_H
