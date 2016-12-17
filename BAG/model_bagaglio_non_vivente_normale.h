#ifndef MODEL_BAGAGLIO_NON_VIVENTE_NORMALE_H
#define MODEL_BAGAGLIO_NON_VIVENTE_NORMALE_H
#include "model_bagaglio_non_vivente.h"

class bagaglio_normale: public bagaglio_non_vivente{
public:
    bagaglio_normale();
    bagaglio_normale(int,double,double,double,double,const Proprietario&,const Viaggio&,QString descr="No description");
    bagaglio_normale(const bagaglio_normale&);
    virtual QString getType() const;
    virtual QString getTipo() const;
};

#endif // MODEL_BAGAGLIO_NON_VIVENTE_NORMALE_H
