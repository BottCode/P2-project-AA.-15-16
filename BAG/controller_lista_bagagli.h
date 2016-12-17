#ifndef CONTROLLER_BAGAGLIO_H
#define CONTROLLER_BAGAGLIO_H
#include <QDebug>
#include <QRegExp>
#include <QMessageBox>
#include <fstream>
#include "data.h"
#include "model_bagaglio.h"
#include "view_add_bagagli.h"
class controller_lista_bagagli{ // in pratica è il controller sul contenitore
private:
    Data bag;
public:
    controller_lista_bagagli();
    controller_lista_bagagli(Lista<bagaglio*>&);
    void ctrl_setFileData(QString);
    void ctrl_setViaggio(QString,Lista<bagaglio*>::iteratore&);
    void ctrl_setMassa(int,Lista<bagaglio*>::iteratore&);
    QString ctrl_getFileData();
    void ctrl_load_init(QString);
    void ctrl_save_end(QString);
    void ctrl_push_back(bagaglio&);
    void ctrl_pop_back();
    bagaglio* ctrl_searh_id(int) const; // ritorna il bagaglio* trovato
    std::vector<bagaglio*> ctrl_search_own(QString,int&) const; // ritorna l'array dei bagagli di owner
    std::vector<bagaglio*> ctrl_search_dest(QString) const;
    Lista<bagaglio*>::iteratore ctrl_pop(const Lista<bagaglio*>::iteratore& it);
    void ctrl_drop();
    int ctrl_getSize();
    void ctrl_delete_by_id(int);
    bool build_lug(QWidget_add_lug*,QWidget_add_owner*,QWidget_add_travel*);
    bool inputOk(QWidget_add_lug*,QWidget_add_owner*,QWidget_add_travel*) const;
    Lista<bagaglio*>& getList();
};


#endif // CONTROLLER_BAGAGLIO_H
