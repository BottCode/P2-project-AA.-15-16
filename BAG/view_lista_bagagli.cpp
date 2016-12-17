#include "view_lista_bagagli.h"

view_lista_bagagli::view_lista_bagagli(QWidget* parent){
    msg=0;in_w=0;w=0;
    l=0;label=0;button=0;
    ctrl_l_b=new controller_lista_bagagli();
    QObject::connect(this,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(build_actions(int,int)));
    QObject::connect(this,SIGNAL(cellChanged(int,int)),this,SLOT(update_container(int,int)));
}

controller_lista_bagagli *view_lista_bagagli::getCtrl() const{return ctrl_l_b;}

void view_lista_bagagli::build_view_list(Lista<bagaglio *> &L){
    QStringList name_col;
    name_col<<"Del"<<"ID"<<"Type"<<"Holder"<<"Travel"<<"Leave Data"<<"Price"<<"Weight(kg)"<<"Size(cm)"<<"Info";
    setColumnCount(10);
    setHorizontalHeaderLabels(name_col);
    setColumnWidth(0,30);setColumnWidth(1,30);setColumnWidth(6,60);
    setColumnWidth(2,220);setColumnWidth(8,180);setColumnWidth(7,80);setColumnWidth(9,35);
}

void view_lista_bagagli::more_info_action_clicked(int row,int col){
    //qDebug()<<__FUNCTION__<<QString::number(row)<<" "<<QString::number(col);
    bagaglio* tmp=ctrl_l_b->ctrl_searh_id(item(row,1)->text().toInt());
    if(tmp){
        if(in_w) delete in_w;
        in_w=new QDialog_info(*tmp,this);
        in_w->show();
    }else qDebug()<<"ID non trovato";
}

void view_lista_bagagli::delete_action_clicked(int row, int col){
    //qDebug()<<__FUNCTION__<<QString::number(row)<<" "<<QString::number(col);
    msg=new QMessageBox();
    msg->setIcon(QMessageBox::Question);
    msg->setText("Remove luggage with ID: "+item(row,1)->text()+", are you sure?");
    msg->setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
    msg->setDefaultButton(QMessageBox::Cancel);
    int ch=msg->exec();
    if(ch==QMessageBox::Yes){
        ctrl_l_b->ctrl_delete_by_id(item(row,1)->text().toInt());
        removeRow(row);
    }
}

Lista<bagaglio*>::iteratore view_lista_bagagli::FindIter(int id){
    for(Lista<bagaglio*>::iteratore it=ctrl_l_b->getList().begin();it!=ctrl_l_b->getList().end();++it)
        if(it.getPunt()->b->getCode() == id) return it;
    return 0;
}

void view_lista_bagagli::build_actions(int row, int col){
    //qDebug()<<__FUNCTION__<<QString::number(row)<<" "<<QString::number(col);
    if(!col) delete_action_clicked(row,col);
    else if(col==9) more_info_action_clicked(row,col);
}

void view_lista_bagagli::update_container(int row,int col){
    if(item(row,1) && item(row,col))
        modify_container_item(ctrl_l_b->getList(),row,col);
}

void view_lista_bagagli::modify_container_item(Lista<bagaglio *>& L, int row, int col){  // dalla lista grafica copio nel contenitore
    // qDebug()<<__FUNCTION__;
    QRegExp weight("[1-9]{1,1}[0-9]{0,3}[\\.]{0,1}[0-9]{0,3}");
    QRegExp vi("[a-z]{1,13}[\\.]{0,1}[\\s]{0,2}[a-z]{0,13}[\\.]{0,1}",Qt::CaseInsensitive);
    Lista<bagaglio*>::iteratore it=FindIter(item(row,1)->text().toInt()); // ritorna l'iteratore del bagaglio con l'ID passato per parametro
    if(col==4 && vi.exactMatch(item(row,4)->text()))
       ctrl_l_b->ctrl_setViaggio(item(row,4)->text(),it);
    if(col==7 && weight.exactMatch(item(row,7)->text()))
       ctrl_l_b->ctrl_setMassa(item(row,7)->text().toDouble(),it);
}

void view_lista_bagagli::update_view_list(Lista<bagaglio *>& L){
    // qDebug()<<__FUNCTION__;
    int row=0;
    QStringList name_col;
    name_col<<"Del"<<"ID"<<"Type"<<"Holder"<<"Travel"<<"Leave Data"<<"Price"<<"Weight(kg)"<<"Size(cm)"<<"Info";
    setHorizontalHeaderLabels(name_col);
    setColumnWidth(0,30);setColumnWidth(1,30);setColumnWidth(6,60);
    setColumnWidth(2,220);setColumnWidth(8,180);setColumnWidth(7,80);setColumnWidth(9,35);
    QString space=" ";
    for(Lista<bagaglio*>::iteratore it=L.begin();row<L.size();++it,row++){
        setRowCount(row+1);
        //QTableWidgetItem* elim=new QTableWidgetItem();
        QTableWidgetItem* s=new QTableWidgetItem();
        QTableWidgetItem* type=new QTableWidgetItem(L[it].b->getTipo());
        QTableWidgetItem* code=new QTableWidgetItem(QString::number(L[it].b->getCode()));
        QTableWidgetItem* price=new QTableWidgetItem(QString::number(L[it].b->Tassa())); // chiamata polimorfa
        QTableWidgetItem* weight=new QTableWidgetItem((QString::number(L[it].b->getMassa())));
        QTableWidgetItem* size=new QTableWidgetItem((L[it].b->getSize())+" = "+QString::number(L[it].b->getVolume())+" m cubi");
        QTableWidgetItem* holder=new QTableWidgetItem(QString((L[it].b->getProprietario()).getNome())+space+(L[it].b->getProprietario()).getCognome());
        QTableWidgetItem* travel=new QTableWidgetItem(L[it].b->getViaggio().getDest());
        QTableWidgetItem* data_entry=new QTableWidgetItem(L[it].b->getViaggio().getQDate().toString());
        QTableWidgetItem* more_info=new QTableWidgetItem();
        QIcon del(":/icon/icone/remove_this.png");
        QIcon info(":/icon/icone/more_info.png");
        s->setIcon(del); more_info->setIcon(info);
        setItem(row,0,s);
        setItem(row,1,code); code->setFlags(Qt::ItemIsEditable);
        setItem(row,2,type); type->setFlags(Qt::ItemIsEditable);
        setItem(row,3,holder); holder->setFlags(Qt::ItemIsEditable);
        setItem(row,4,travel);
        setItem(row,5,data_entry); data_entry->setFlags(Qt::ItemIsEditable);
        setItem(row,6,price); price->setFlags(Qt::ItemIsEditable);
        setItem(row,7,weight); ;
        setItem(row,8,size); size->setFlags(Qt::ItemIsEditable);
        setItem(row,9,more_info);
    }
}

void view_lista_bagagli::closeEvent(QCloseEvent *event){
    if(in_w) in_w->close();
    QTableWidget::closeEvent(event);
}

view_lista_bagagli::~view_lista_bagagli(){
    delete ctrl_l_b;
    if(button) delete button;
    if(label) delete label;
    if(l) delete l;
    if(w) delete w;
    if(in_w) delete in_w;
    if(msg) delete msg;
}

