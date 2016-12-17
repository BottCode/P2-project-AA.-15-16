#include "qwidget_add_owner.h"

QWidget_add_owner::QWidget_add_owner(QWidget *parent){
    prop_l=new QVBoxLayout();
    setLayout(prop_l);
    build();
}

void QWidget_add_owner::build(){
    // label titolo
    QLabel* prop_wid_label=new QLabel("OWNER",this);
    QFont font=prop_wid_label->font();
    font.setBold(true);
    prop_wid_label->setFont(font);
    // text field per inserire il nome
    QLabel* name_label=new QLabel("Name",this);
    prop_l->addWidget(name_label);
    name_line=new QLineEdit(this);
    prop_l->addWidget(name_line);
    //text field per inserire il cognome
    QLabel* surname_label=new QLabel("Surname",this);
    prop_l->addWidget(surname_label);
    surname_line=new QLineEdit(this);
    prop_l->addWidget(surname_line);
    // text field per inserire il domicilio
    QLabel* domicile_label=new QLabel("Domicile",this);
    prop_l->addWidget(domicile_label);
    domicile_line=new QLineEdit(this);
    prop_l->addWidget(domicile_line);
    // qdate field per inserire la data di nascita
    QLabel* birth_label=new QLabel("Date of birth",this);
    prop_l->addWidget(birth_label);
    birth_line=new QDateEdit(this);
    birth_line->setDisplayFormat("dd.MM.yyyy");
    prop_l->addWidget(birth_line);
    // checkbox per dire se parte o meno col bagaglio
    QLabel* leave_label=new QLabel("Leave with the luggage",this);
    prop_l->addWidget(leave_label);
    leave_line=new QCheckBox(this);
    leave_line->setText("checked = yes");
    prop_l->addWidget(leave_line);
}

QLineEdit *QWidget_add_owner::getName() const{
    return name_line;
}

QLineEdit *QWidget_add_owner::getSurname() const
{
    return surname_line;
}

QLineEdit *QWidget_add_owner::getDomicile() const
{
    return domicile_line;
}

QDateEdit *QWidget_add_owner::getBirth() const
{
    return birth_line;
}

QCheckBox *QWidget_add_owner::getLeave() const
{
    return leave_line;
}

QWidget_add_owner::~QWidget_add_owner(){
    delete prop_l;
    delete name_line;
    delete surname_line;
    delete domicile_line;
    delete birth_line;
    delete leave_line;
}
