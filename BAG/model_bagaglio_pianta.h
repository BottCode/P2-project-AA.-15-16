#ifndef MODEL_BAGAGLIO_PIANTA_H
#define MODEL_BAGAGLIO_PIANTA_H
#include "model_bagaglio_vivente.h"
class bagaglio_pianta: public bagaglio_vivente{
public:
    bagaglio_pianta();
    bagaglio_pianta(int,double,double,double,double,const Proprietario&,const Viaggio&,QString descr="No description");
    bagaglio_pianta(const bagaglio_pianta&);
    virtual QString getType() const;
    virtual QString getTipo() const;
};


#endif // MODEL_BAGAGLIO_PIANTA_H
