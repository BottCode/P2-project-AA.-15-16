#ifndef MODEL_BAGAGLIO_NON_VIVENTE_SPECIALE_H
#define MODEL_BAGAGLIO_NON_VIVENTE_SPECIALE_H
#include "model_bagaglio_non_vivente.h"

class bagaglio_speciale: public bagaglio_non_vivente{
public:
    bagaglio_speciale();
    bagaglio_speciale(int,double,double,double,double,const Proprietario&,const Viaggio&,QString descr="No description");
    bagaglio_speciale(const bagaglio_speciale&);
    virtual double Tassa() const ; // aggiunta di 0.80 euro per ogni kg
    virtual QString getType() const;
    virtual QString getTipo() const;
};

#endif // MODEL_BAGAGLIO_NON_VIVENTE_SPECIALE_H
