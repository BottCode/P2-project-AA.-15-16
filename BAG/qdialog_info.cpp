#include "qdialog_info.h"

QDialog_info::QDialog_info(const bagaglio& tmp,QWidget *parent){
    l=new QVBoxLayout();
    lb=new QLabel();
    own_name=new QLabel();
    leave=new QLabel();
    setLayout(l);
    setMinimumSize(300,40);
    setMaximumSize(600,500);
    setWindowTitle("INFORMATIONS");
    write_info(tmp);
    show();
}

void QDialog_info::write_info(const bagaglio& tmp){
    lb->setText("Description: "+tmp.getDescription()+". Travel by:"+tmp.getViaggio().getModo());
    lb->setMaximumSize(800,50);
    l->addWidget(lb);
    own_name->setText("Owner: "+tmp.getProprietario().getFullName()+", Born: "+tmp.getProprietario().getQDateNascita().toString());
    l->addWidget(own_name);
    QString r=tmp.getProprietario().getParte() ? "yes" : "no";
    leave->setText("Leave with the luggage: "+r);
    l->addWidget(leave);
}

QDialog_info::~QDialog_info(){
    delete lb;
    delete l;
    delete leave;
    delete own_name;
}
