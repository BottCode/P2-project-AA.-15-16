#include "controller_lista_bagagli.h"
#include "model_bagaglio_a_mano.h"
#include "model_bagaglio_animale_mansueto.h"
#include "model_bagaglio_animale_pericoloso.h"
#include "model_bagaglio_non_vivente_normale.h"
#include "model_bagaglio_non_vivente_speciale.h"
#include "model_bagaglio_pianta.h"

controller_lista_bagagli::controller_lista_bagagli(){
    ctrl_load_init(ctrl_getFileData()); // carica dei dati iniziali
}

controller_lista_bagagli::controller_lista_bagagli(Lista<bagaglio*>& L): bag(L){}

void controller_lista_bagagli::ctrl_setFileData(QString path){
    bag.setFileData(path);
}

void controller_lista_bagagli::ctrl_setViaggio(QString v,Lista<bagaglio*>::iteratore& it){
    bag.getList().operator [](it).b->setViaggio(v);
}

void controller_lista_bagagli::ctrl_setMassa(int m, Lista<bagaglio*>::iteratore& it){
    bag.getList().operator [](it).b->setMassa(m);
}

QString controller_lista_bagagli::ctrl_getFileData(){
    return bag.getFileData();
}

void controller_lista_bagagli::ctrl_load_init(QString path){
    bag.load(path);
}

void controller_lista_bagagli::ctrl_save_end(QString path){
    bag.save(path);
}

void controller_lista_bagagli::ctrl_push_back(bagaglio& b){
    bag.getList().push_back(&b);
}

void controller_lista_bagagli::ctrl_pop_back(){
    bag.getList().pop_back();
}

bagaglio* controller_lista_bagagli::ctrl_searh_id(int id) const{
    return bag.search_id(id);
}

std::vector<bagaglio *>controller_lista_bagagli::ctrl_search_own(QString owner, int& i) const{
    return bag.search_own(owner,i);
}

std::vector<bagaglio*> controller_lista_bagagli::ctrl_search_dest(QString dest) const{
    return bag.search_dest(dest);
}
Lista<bagaglio*>::iteratore controller_lista_bagagli::ctrl_pop(const Lista<bagaglio*>::iteratore& it){
    return bag.getList().pop(it);
}

void controller_lista_bagagli::ctrl_drop(){
    bag.getList().drop();
}

int controller_lista_bagagli::ctrl_getSize(){
    return bag.getList().size();
}

void controller_lista_bagagli::ctrl_delete_by_id(int id){
    bag.delete_by_id(id);
}

bool controller_lista_bagagli::inputOk(QWidget_add_lug* lug,QWidget_add_owner* own,QWidget_add_travel* tr) const{
    // almeno una cifra, la prima != da zero. max 7 cifre. la parte decimale è divisa da quella intera con il punto.
    QRegExp weight("[1-9]{1,1}[0-9]{0,3}[\\.]{0,1}[0-9]{0,3}");
    QRegExp height(weight),width(weight),depth(weight);
    // almeno un nome, massimo due. Idem il cognome. Sono ammesse abbreviazioni (tipo J.K. Rowling). CaseInsensitive
    QRegExp name("[a-z]{1,13}[\\.]{0,1}[\\s]{0,2}[a-z]{0,13}[\\.]{0,1}",Qt::CaseInsensitive);
    QRegExp surname(name),domicile(name),destination(name);
    QRegExp descr(".{0,100}",Qt::CaseInsensitive);
    // due nomi al massimo, sono ammesse abbreviazioni (tipo St. tropez)
    bool a=true;
    QPalette palette,ok;
    ok.setColor(QPalette::Base,Qt::white);
    own->getDomicile()->setPalette(ok);lug->getDescription()->setPalette(ok);own->getName()->setPalette(ok);
    own->getSurname()->setPalette(ok);lug->getDepth()->setPalette(ok);lug->getDescription()->setPalette(ok);
    lug->getHeight()->setPalette(ok);lug->getWeight()->setPalette(ok);
    lug->getWidth()->setPalette(ok);tr->getDest()->setPalette(ok);
    palette.setColor(QPalette::Base,Qt::yellow);
    if(!descr.exactMatch(lug->getDescription()->toPlainText())) {
        lug->getDescription()->clear(); a=false;
        lug->getDescription()->setFocus();
        lug->getDescription()->setPalette(palette);
    }
    if(!domicile.exactMatch(own->getDomicile()->text())){
        own->getDomicile()->clear();a=false;
        own->getDomicile()->setFocus();
        own->getDomicile()->setPalette(palette);
    }
    if(!name.exactMatch(own->getName()->text())){
        own->getName()->clear();a=false;
        own->getName()->setFocus();
        own->getName()->setPalette(palette);
    }
    if(!surname.exactMatch(own->getSurname()->text())){
        own->getSurname()->clear();a=false;
        own->getSurname()->setFocus();
        own->getSurname()->setPalette(palette);
    }
    if(!weight.exactMatch(lug->getWeight()->text())){
        lug->getWeight()->clear();a=false;
        lug->getWeight()->setFocus();
        lug->getWeight()->setPalette(palette);
    }
    if(!height.exactMatch(lug->getHeight()->text())){
        lug->getHeight()->clear();a=false;
        lug->getHeight()->setFocus();
        lug->getHeight()->setPalette(palette);
    }
    if(!width.exactMatch(lug->getWidth()->text())){
        lug->getWidth()->clear();a=false;
        lug->getWidth()->setFocus();
        lug->getWidth()->setPalette(palette);
    }
    if(!depth.exactMatch(lug->getDepth()->text())){
        lug->getDepth()->clear();a=false;
        lug->getDepth()->setFocus();
        lug->getDepth()->setPalette(palette);
    }
    if(!destination.exactMatch(tr->getDest()->text())){
        tr->getDest()->clear();a=false;
        tr->getDest()->setFocus();
        tr->getDest()->setPalette(palette);
    }
    return a;
}

bool controller_lista_bagagli::build_lug(QWidget_add_lug* lug,QWidget_add_owner* own,QWidget_add_travel* tr){
  bagaglio* tmp=0;
  bool a=inputOk(lug,own,tr);
  if(a){
    // lugWid
    double massa=(lug->getWeight()->text()).toDouble();
    double altezza=(lug->getHeight()->text()).toDouble();
    double larghezza=(lug->getWidth()->text()).toDouble();
    double prof=(lug->getDepth()->text().toDouble());
    QString descr=(lug->getDescription()->toPlainText());
    // ownWid
    QString nome=own->getName()->text();
    QString cognome=own->getSurname()->text();
    QDate QDate_nascita=own->getBirth()->date();
    QString residenza=own->getDomicile()->text();
    bool parte=own->getLeave()->isChecked();
    Proprietario pro=Proprietario(nome,cognome,QDate_nascita,residenza,parte);
    // travWid
    QString mod_vi=tr->getBy()->currentText();
    QString Destinazione=tr->getDest()->text();
    QDate data=tr->getDep()->date();
    int id_bag=bag.getIdMax(),id_vi=bag.getIdMin(); bag.setIdMax(1);bag.setIdMin(1);
    Viaggio vi(id_vi,Destinazione,data,mod_vi);
    // costruzione di bagaglio
    if(lug->getcombo()->currentText() == "HAND") tmp=new bagaglio_a_mano(id_bag,massa,altezza,larghezza,prof,pro,vi,descr);
    else if(lug->getcombo()->currentText() == "SPECIAL") tmp=new bagaglio_speciale(id_bag,massa,altezza,larghezza,prof,pro,vi,descr);
    else if(lug->getcombo()->currentText() == "NORMAL") tmp=new bagaglio_normale(id_bag,massa,altezza,larghezza,prof,pro,vi,descr);
    else if(lug->getcombo()->currentText() == "PLANT") tmp=new bagaglio_pianta(id_bag,massa,altezza,larghezza,prof,pro,vi,descr);
    else if(lug->getcombo()->currentText() == "TAME ANIMAL") tmp=new bagaglio_animale_mansueto(id_bag,massa,altezza,larghezza,prof,pro,vi,descr);
    else if(lug->getcombo()->currentText() == "DANGEROUS ANIMAL") tmp=new bagaglio_animale_pericoloso(id_bag,massa,altezza,larghezza,prof,pro,vi,descr);
    if(tmp){ // se la costruzione del bagaglio è andata a buon fine, inserisco nella lista
        ctrl_push_back(*tmp);
        ctrl_save_end(bag.getFileData());
    }
    else qDebug()<<"Error: luggage not added"; // altrimenti segnalo l'errore
  }
  return a;
}

Lista<bagaglio*>& controller_lista_bagagli::getList(){
    return bag.getList();
}

