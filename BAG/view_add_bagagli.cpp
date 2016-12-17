#include "view_add_bagagli.h"

view_add_bagagli::view_add_bagagli(QWidget* parent){
    setBagWid=new QWidget_add_lug(parent);
    setPropWid=new QWidget_add_owner(parent);
    setViaWid=new QWidget_add_travel(parent);
}

void view_add_bagagli::resetFields(QWidget_add_lug* lug, QWidget_add_owner* own, QWidget_add_travel* tr) const{
    QPalette palette;
    palette.setColor(QPalette::Base,Qt::white);
    // lugWid
    lug->getcombo()->setCurrentIndex(0);
    lug->getDepth()->clear();lug->getDepth()->setPalette(palette);
    lug->getHeight()->clear();lug->getHeight()->setPalette(palette);
    lug->getWeight()->clear();lug->getWeight()->setPalette(palette);
    lug->getWidth()->clear();lug->getWidth()->setPalette(palette);
    lug->getDescription()->clear();lug->getDescription()->setPalette(palette);
    //ownWid
    own->getBirth()->setCurrentSectionIndex(0);
    own->getDomicile()->clear();own->getDomicile()->setPalette(palette);
    own->getLeave()->setChecked(false);own->getLeave()->setPalette(palette);
    own->getName()->clear();own->getName()->setPalette(palette);
    own->getSurname()->clear();own->getSurname()->setPalette(palette);
    //travelWid
    tr->getBy()->setCurrentIndex(0);
    tr->getDep()->setCurrentSectionIndex(0);
    tr->getDest()->clear();tr->getDest()->setPalette(palette);
}

QWidget_add_lug* view_add_bagagli::getBagWid() const{return setBagWid;}
QWidget_add_owner* view_add_bagagli::getPropWid() const{return setPropWid;}
QWidget_add_travel* view_add_bagagli::getViaWid() const{return setViaWid;}

view_add_bagagli::~view_add_bagagli(){
    delete setBagWid;
    delete setPropWid;
    delete setViaWid;
}
