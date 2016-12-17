#include "qwidget_add_travel.h"

QWidget_add_travel::QWidget_add_travel(QWidget *parent){
    via_l=new QVBoxLayout();
    setLayout(via_l);
    build();
}

void QWidget_add_travel::build(){
    // label titolo
    QLabel* via_wid_label=new QLabel("TRAVEL",this);
    QFont font=via_wid_label->font();
    font.setBold(true);
    via_wid_label->setFont(font);
    // combo box per lamodalità di viaggio
    QLabel* bytravel_label=new QLabel("Travel by",this);
    via_l->addWidget(bytravel_label);
    bytravel_combo=new QComboBox(this);
    QStringList qsl; qsl<<"PLANE"<<"TRAIN"<<"TRUCK"<<"SHIP";
    bytravel_combo->addItems(qsl);
    via_l->addWidget(bytravel_combo);
    // text fields per inserire la destinazione
    QLabel* dest_label=new QLabel("Destination",this);
    via_l->addWidget(dest_label);
    dest_line=new QLineEdit(this);
    via_l->addWidget(dest_line);
    // qdate per inserire la data di partenza
    QLabel* depday_label=new QLabel("Departure Day",this);
    via_l->addWidget(depday_label);
    depday_line=new QDateEdit(this);
    via_l->addWidget(depday_line);
}

QComboBox *QWidget_add_travel::getBy() const
{
    return bytravel_combo;
}

QLineEdit *QWidget_add_travel::getDest() const
{
    return dest_line;
}

QDateEdit *QWidget_add_travel::getDep() const
{
    return depday_line;
}

QWidget_add_travel::~QWidget_add_travel(){
    delete via_l;
    delete bytravel_combo;
    delete dest_line;
    delete depday_line;
}

