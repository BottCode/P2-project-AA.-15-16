#ifndef MODEL_BABAGLIO_ANIMALE_H
#define MODEL_BABAGLIO_ANIMALE_H
#include "model_bagaglio_vivente.h"
#include "model_gabbia.h"

class bagaglio_animale: public bagaglio_vivente{
public:
    bagaglio_animale();
    bagaglio_animale(int,double,double,double,double,const Proprietario&,const Viaggio&,QString descr="No description");
    bagaglio_animale(const bagaglio_animale&);
    virtual QString getTipo() const;
};


#endif // MODEL_BABAGLIO_ANIMALE_H
