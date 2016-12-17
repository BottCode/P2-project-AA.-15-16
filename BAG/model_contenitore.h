#ifndef MODEL_CONTENITORE_H
#define MODEL_CONTENITORE_H
#include <QString>
#include <iostream>
#include <QFile>
#include <QDebug>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include "model_bagaglio_a_mano.h"
#include "model_bagaglio_animale_mansueto.h"
#include "model_bagaglio_animale_pericoloso.h"
#include "model_bagaglio_non_vivente_normale.h"
#include "model_bagaglio_non_vivente_speciale.h"
#include "model_bagaglio_pianta.h"
#include <vector>
/* contiene le info di tutti i bagagli passati al controllo.
 * Il contenitore è implementato come una lista double-linked.
 * Questo perchè sono previste operazioni di rimozione in qualsiasi punto della lista. Per
 * questo motivo, è preferibile una lista.
 * Per facilitare e rendere migliore l'accesso ad un elemento della lista, verrà definito un
 * oggetto iteratore.
*/

template <class T> class Lista;

template <class T> std::ostream& operator<< (std::ostream&,const Lista<T>&);

template<class T>
class Lista{
    friend class iteratore;
private:
    class nodo{
    public:
        nodo():b(T()),prev(0),next(0){}
        nodo(const T& bag, nodo* p, nodo* n): b(bag),prev(p),next(n){}
        T b;
        nodo* prev;
        nodo* next;
    };
    nodo* first, *last;
    int n_el;
public:
    nodo* getFirst() const{return first;}
    Lista():first(0),last(0),n_el(0){}
    class iteratore{
        friend class Lista;
    private:
        nodo* punt;
    public:
        iteratore(){punt=0;}
        iteratore(nodo* ptr){punt=ptr;}
        nodo* getPunt() const{return punt;}
        bool operator ==(const iteratore& it) const{return punt == it.punt;}
        bool operator !=(const iteratore& it) const{return punt != it.punt;}
        iteratore& operator ++() // prefissi
        {
            if(punt) punt=punt->next;
            return *this;
        }
        iteratore& operator --(){
            if(punt) punt=punt->prev;
            return *this;
        }
        iteratore operator ++(int) // postfissi
        {
            iteratore tmp=*this;
            if(punt) punt=punt->next;
            return tmp;
        }
        iteratore operator--(int){
            iteratore tmp=*this;
            if(punt) punt=punt->prev;
            return tmp;
        }
        nodo& operator *() const{ return *punt;}
        // non ridefinisco ~iteratore in quanto quell std
        // fa ciò di cui ho bisogno: deallocare il ptr.
        // La deallocazione del nodo è compito di ~Lista
    };

    int size() const{return n_el;}
    bool isEmpty() const{return n_el<=0;}
    void push_back(const T& b){
        if(first && last){
            last->next=new nodo(b,last,0);
            last=last->next;
        }else first=last=new nodo(b,0,0);
        n_el++;
    }
    void pop_back(){ // funziona
        if(!isEmpty()){
            n_el--;
            nodo* tmp=last;
            last=last->prev;
            if(last) last->next=0;
            delete tmp;
        }
    }
    iteratore delete_node(nodo* tmp){
        iteratore aux;
        if(tmp){
               if(tmp==first){
                   first=aux.punt=first->next;
                   if(first) first->prev=0;
               }else if(tmp==last){
                   last=last->prev;
                   if(last) last->next=0; // non servirebbe il controllo su last perchè se entro in questo if => ho almeno due nodi
               }else{
                   tmp->prev->next=aux.punt=tmp->next;
                   tmp->next->prev=tmp->prev;
               }
               delete tmp;
               n_el--;
           }
        return aux;
    }

    iteratore pop(const iteratore& it){
        if(!isEmpty()) return delete_node(it.getPunt());
        else return iteratore();
    }

    void drop(){ // dealloca tutta la lista
            while(!isEmpty()) pop_back(); // dealloca dall'ultimo al primo
    }
    nodo& operator[](const iteratore& it) const{return *(it.punt);}
    iteratore begin() const{
        iteratore tmp;
        tmp.punt=first;
        return tmp;
    }
    iteratore end() const{
        iteratore tmp;
        tmp.punt=0;
        return tmp;
    }
    ~Lista(){ // deve deallocare la lista al termine del programma
        drop();
    }
};

#endif // MODEL_CONTENITORE_H
