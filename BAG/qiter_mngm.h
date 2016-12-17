#ifndef QITER_MNGM_H
#define QITER_MNGM_H
#include <QString>
#include <model_contenitore.h>
#include <model_bagaglio.h>

class QIter_mngm: public QString{
private:
    Lista<bagaglio*>::iteratore iter;
public:
    QIter_mngm();
    QIter_mngm(Lista<bagaglio*>::iteratore&);
    Lista<bagaglio*>::iteratore getIt() const;
};

#endif // QITER_MNGM_H
