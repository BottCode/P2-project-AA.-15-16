#ifndef MODEL_BAGAGLIO_ANIMALE_MANSUETO_H
#define MODEL_BAGAGLIO_ANIMALE_MANSUETO_H
#include "model_bagaglio_animale.h"

class bagaglio_animale_mansueto: public bagaglio_animale{
public:
    bagaglio_animale_mansueto();
    bagaglio_animale_mansueto(int,double,double,double,double,const Proprietario&,const Viaggio&,QString descr="No description");
    bagaglio_animale_mansueto(const bagaglio_animale_mansueto&);
    virtual QString getType() const;
    virtual QString getTipo() const;
};

#endif // MODEL_BAGAGLIO_ANIMALE_MANSUETO_H
