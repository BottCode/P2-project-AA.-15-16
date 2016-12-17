#ifndef MODEL_BAGAGLIO_NON_VIVENTE_H
#define MODEL_BAGAGLIO_NON_VIVENTE_H
#include "model_bagaglio_in_stiva.h"

class bagaglio_non_vivente: public bagaglio_in_stiva{
public:
    bagaglio_non_vivente();
    bagaglio_non_vivente(int,double,double,double,double,const Proprietario&,const Viaggio&,QString descr="No description");
    bagaglio_non_vivente(const bagaglio_non_vivente&);
    virtual QString getTipo() const;
};

#endif // MODEL_BAGAGLIO_NON_VIVENTE_H
