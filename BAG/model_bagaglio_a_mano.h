#ifndef MODEL_BAGAGLIO_A_MANO_H
#define MODEL_BAGAGLIO_A_MANO_H
#include <QString>
#include "model_bagaglio.h"

class bagaglio_a_mano: public bagaglio{
public:
    bagaglio_a_mano();
    bagaglio_a_mano(int,double,double,double,double,const Proprietario&,const Viaggio&,QString descr="No description");
    bagaglio_a_mano(const bagaglio_a_mano &);
    virtual QString getType() const;
    virtual QString getTipo() const;
};

#endif // MODEL_BAGAGLIO_A_MANO_H
