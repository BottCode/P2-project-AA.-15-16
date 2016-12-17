#include "qdialog_search.h"
#include <QMainWindow>
QDialog_search::QDialog_search(controller_lista_bagagli* ct,QWidget *parent){
    d=0;qs=0;l=0;ls=0;w=0;dest=0;
    type=0;price=0;owner=0;fail=0;
    id_lab=0;id_line=0;id_button=0;
    ow_lab=0;ow_line=0;ow_button=0;
    dest_lab=0;dest_line=0;dest_button=0;
    ctrl_l_b=ct;
    main=new QVBoxLayout();
    tab=new QTabWidget();
    search_id=new QWidget(tab);
    id_l=new QVBoxLayout();
    search_owner=new QWidget(tab);
    ow_l=new QVBoxLayout();
    search_dest=new QWidget(tab);
    dest_l=new QVBoxLayout();
    setLayout(main);
    setWindowTitle("SEARCH");
    setWindowIcon(QIcon(":/icon/icone/search.png"));
    setMinimumSize(200,200);
    main->addWidget(tab);
    tab->addTab(search_id,"ID");
    tab->addTab(search_dest,"destination");
    tab->addTab(search_owner,"owner");
    buildSearchId();
    buildSearchDest();
    buildSearchOwner();
    setParent(parent);
    show();
}

void QDialog_search::buildSearchId(){
    search_id->setLayout(id_l);
    if(id_lab) delete id_lab;
    id_lab=new QLabel("Search ID",search_id);id_lab->setMaximumSize(60,30);
    id_l->addWidget(id_lab);
    if(id_line) delete id_line;
    id_line=new QLineEdit(search_id);id_line->setMaximumSize(120,30);
    id_l->addWidget(id_line);
    if(id_button) delete id_button;
    id_button=new QPushButton(search_id);id_button->setMaximumSize(120,30);
    id_button->setIcon(QIcon(":/icon/icone/search.png"));
    id_l->addWidget(id_button);
    connect(id_button,SIGNAL(clicked()),this,SLOT(on_search_id_clicked()));
}

void QDialog_search::buildSearchOwner(){
    search_owner->setLayout(ow_l);
    if(ow_lab) delete ow_lab;
    ow_lab=new QLabel("Search owner",search_owner);ow_lab->setMaximumSize(190,30);
    ow_l->addWidget(ow_lab);
    if(ow_line) delete ow_line;
    ow_line=new QLineEdit();
    ow_line->setMaximumSize(120,30);
    ow_l->addWidget(ow_line);
    if(ow_button) delete ow_button;
    ow_button=new QPushButton(search_owner);ow_button->setMaximumSize(120,30);
    ow_button->setIcon(QIcon(":/icon/icone/search.png"));
    ow_l->addWidget(ow_button);
    connect(ow_button,SIGNAL(clicked()),this,SLOT(on_search_owner_clicked()));
}

void QDialog_search::buildSearchDest(){
    search_dest->setLayout(dest_l);
    if(dest_lab) delete dest_lab;
    dest_lab=new QLabel("Search destination",search_dest);dest_lab->setMaximumSize(120,30);
    dest_l->addWidget(dest_lab);
    if(dest_line) delete dest_line;
    dest_line=new QLineEdit(search_dest);dest_line->setMaximumSize(120,30);
    dest_l->addWidget(dest_line);
    if(dest_button) delete dest_button;
    dest_button=new QPushButton(search_dest);dest_button->setMaximumSize(120,30);
    dest_button->setIcon(QIcon(":/icon/icone/search.png"));
    dest_l->addWidget(dest_button);
    connect(dest_button,SIGNAL(clicked()),this,SLOT(on_search_dest_clicked()));
}


void QDialog_search::build_search_id_result(bagaglio* b){
    /* voglio assicurarmi di lasciare meno garbage possibile
     * e che ogni oggetto sia distrutto solo se esiste già/ancora
    */
    if(price){delete price;price=0;}
    if(dest){delete dest;dest=0;}
    if(type){delete type;type=0;}
    if(owner){delete owner;owner=0;}
    if(l){delete l;l=0;}

    if(d){delete d;d=0;}
    d=new QDialog(this);
    d->setWindowIcon(QIcon(":/icon/icone/search_result.png"));
    l=new QVBoxLayout();
    d->setLayout(l);
    owner= new QLabel();
    if(b){
        type=new QLabel();
        type->setText("ID: "+QString::number(b->getCode())+". Type: "+b->getType());
        l->addWidget(type);
        owner->setText("Owner: "+b->getProprietario().getNome()+" "+b->getProprietario().getCognome());
        l->addWidget(owner);
        dest=new QLabel();
        dest->setText("Destination: "+b->getViaggio().getDest()+" BY "+b->getViaggio().getModo()+" at "+b->getViaggio().getQDate().toString());
        l->addWidget(dest);
        price=new QLabel();
        price->setText("Price: "+QString::number(b->Tassa())+" euro"); // chiamata polimorfa
        l->addWidget(price);
        d->show();
    }else{
        if(fail) delete fail;
        fail=new QLabel("No result");
        fail->show();;
    }
}

void QDialog_search::on_search_id_clicked(){
    //qDebug()<<__FUNCTION__;
    bagaglio* tmp=ctrl_l_b->ctrl_searh_id(id_line->text().toInt());
    build_search_id_result(tmp);

}

void QDialog_search::build_search_id_owner(std::vector<bagaglio*> b,int i){
    if(price){delete price;price=0;}
    if(dest){delete dest;dest=0;}
    if(type){delete type;type=0;}
    if(owner){delete owner;owner=0;}
    if(qs){delete qs;qs=0;}
    if(d){delete d;d=0;}
    d=new QDialog(this);
    qs=new QScrollArea();
    l=new QVBoxLayout();ls=new QVBoxLayout();
    d->setLayout(ls);
    w=new QWidget;
    if(i>0){
        owner= new QLabel();
        owner->setText("Owner: "+b[0]->getProprietario().getFullName());
        QFont font=owner->font();
        font.setBold(true);
        owner->setFont(font);
        ls->addWidget(owner);ls->addWidget(qs);
        w->setLayout(l); qs->setWidget(w);
        w->setGeometry(0,0,350,80*i);
        for(int j=0;j<i;j++){
            dest=new QLabel();
            l->addWidget(dest);
            dest->setText(QString::number(j+1)+" - Destination: "+b[j]->getViaggio().getDest()+" BY "+b[j]->getViaggio().getModo());
            QFont font2=dest->font();font2.setBold(true);dest->setFont(font2);
            type=new QLabel();
            type->setText("Type: "+b[j]->getType());
            l->addWidget(type);
            price=new QLabel();
            price->setText("Price: "+QString::number(b[j]->Tassa())+" euro."); // chiamata polimorfa
            l->addWidget(price);
            d->show();
        }
    }else{
        if(fail) delete fail;
        fail=new QLabel("No result");
        fail->show();
    }
}

void QDialog_search::on_search_owner_clicked(){
    //qDebug()<<__FUNCTION__;
    int i=0;
    std::vector<bagaglio*> tmp=ctrl_l_b->ctrl_search_own(ow_line->text(),i);
    build_search_id_owner(tmp,i);
}

void QDialog_search::build_search_dest_result(std::vector<bagaglio*> b){
    if(price){delete price;price=0;}
    if(dest){delete dest;dest=0;}
    if(type){delete type;type=0;}
    if(owner){delete owner;owner=0;}
    if(qs){delete qs;qs=0;}
    if(d){delete d;d=0;}
    d=new QDialog(this);qs=new QScrollArea();
    l=new QVBoxLayout();ls=new QVBoxLayout();
    d->setLayout(ls);
    w= new QWidget();
    if(b.size()>0){
        dest=new QLabel();
        dest->setText("Destination: "+b[0]->getViaggio().getDest());
        QFont font=dest->font();
        font.setBold(true);
        dest->setFont(font);
        ls->addWidget(dest);ls->addWidget(qs);
        w->setLayout(l); qs->setWidget(w);
        w->setGeometry(0,0,350,80*b.size());
        for(unsigned int i=0;i<b.size();i++){
            owner=new QLabel();
            owner->setText("Owner: "+b[i]->getProprietario().getFullName());
            l->addWidget(owner);
            QFont font2=owner->font();
            font2.setBold(true);
            owner->setFont(font2);
            type=new QLabel();
            type->setText("Type: "+b[i]->getType());
            l->addWidget(type);
            price=new QLabel();
            price->setText("Price: "+QString::number(b[i]->Tassa())+" euro."); // chiamata polimorfa
            l->addWidget(price);
        }
        d->show();
    }else{
        if(fail) delete fail;
        fail=new QLabel("No result");
        fail->show();
    }
}

void QDialog_search::on_search_dest_clicked(){
    //qDebug()<<__FUNCTION__;
    std::vector<bagaglio*> tmp=ctrl_l_b->ctrl_search_dest(dest_line->text());
    build_search_dest_result(tmp);
}

void QDialog_search::closeEvent(QCloseEvent *event){
    if(d) d->close();
    if(fail) fail->close();
    close();
    QDialog::closeEvent(event);
}

QDialog_search::~QDialog_search(){
    /* voglio assicurarmi di lasciare meno garbage possibile
     * e che ogni oggetto sia distrutto solo se esiste già/ancora
    */
    if(fail){delete fail;fail=0;}
    if(price){delete price;price=0;}
    if(dest){delete dest;dest=0;}
    if(type){delete type;type=0;}
    if(owner){delete owner;owner=0;}
    // owner
    if(ow_lab) delete ow_lab;
    if(ow_line) delete ow_line;
    if(ow_button) delete ow_button;
    delete ow_l;
    delete search_owner;
    // destination
    if(dest_line) delete dest_line;
    if(dest_lab) delete dest_lab;
    if(dest_button) delete dest_button;
    delete dest_l;
    delete search_dest;
    // id
    if(id_lab) delete id_lab;
    if(id_button) delete id_button;
    if(id_line) delete id_line;
    delete id_l;
    delete search_id;

    if(l){delete l;l=0;}
    if(d){delete d;d=0;}

    delete tab;
    delete main;
    //if(w) delete w;
}
