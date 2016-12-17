#ifndef MODEL_BAGAGLIO_IN_STIVA_H
#define MODEL_BAGAGLIO_IN_STIVA_H
#include "model_bagaglio.h"

class bagaglio_in_stiva: public bagaglio{
public:
    bagaglio_in_stiva();
    bagaglio_in_stiva(int,double,double,double,double,const Proprietario&,const Viaggio&,QString descr="No description");
    bagaglio_in_stiva(const bagaglio_in_stiva&);
    virtual QString getTipo() const;
};
#endif // MODEL_BAGAGLIO_IN_STIVA_H
