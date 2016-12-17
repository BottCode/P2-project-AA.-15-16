#include "qwidget_add_lug.h"

QWidget_add_lug::QWidget_add_lug(QWidget *parent){
    bag_l=new QVBoxLayout();
    setLayout(bag_l);
    build();
}

void QWidget_add_lug::build(){
    // label titolo
    QLabel* bag_wid_label=new QLabel("LUGGAGE",this);
    bag_l->addWidget(bag_wid_label);
    QFont font=bag_wid_label->font();
    font.setBold(true);
    bag_wid_label->setFont(font);
    // combobox dei tipi
    QLabel* type_label=new QLabel("Type",this);
    bag_l->addWidget(type_label);
    type_combo=new QComboBox(this);
    QStringList qsl; qsl<<"HAND"<<"SPECIAL"<<"NORMAL"<<"PLANT"<<"TAME ANIMAL"<<"DANGEROUS ANIMAL";
    type_combo->addItems(qsl);
    bag_l->addWidget(type_combo);
    // text field per inserire il peso
    QLabel* weight_label=new QLabel("Weight (KG)",this);
    bag_l->addWidget(weight_label);
    weight_line=new QLineEdit(this);
    bag_l->addWidget(weight_line);
    // text field per inserire l'altezza
    QLabel* height_label=new QLabel("Height (cm)",this);
    bag_l->addWidget(height_label);
    height_line=new QLineEdit(this);
    bag_l->addWidget(height_line);
    // text field per inserire la larghezza
    QLabel* width_label=new QLabel("Width (cm)",this);
    bag_l->addWidget(width_label);
    width_line=new QLineEdit(this);
    bag_l->addWidget(width_line);
    // text field per inserire la profondità
    QLabel* depth_label=new QLabel("Depth (cm)",this);
    bag_l->addWidget(depth_label);
    depth_line=new QLineEdit(this);
    bag_l->addWidget(depth_line);
    // text field grande per aggiungere la descrizione opzionale
    QLabel* description_label=new QLabel("Description (optional, max 100 char)",this);
    bag_l->addWidget(description_label);
    description_line=new QPlainTextEdit(this);
    bag_l->addWidget(description_line);
}

QComboBox *QWidget_add_lug::getcombo() const
{
    return type_combo;
}

QLineEdit *QWidget_add_lug::getWeight() const
{
    return weight_line;
}

QLineEdit *QWidget_add_lug::getHeight() const
{
    return height_line;
}

QLineEdit *QWidget_add_lug::getWidth() const
{
    return width_line;
}

QLineEdit *QWidget_add_lug::getDepth() const
{
    return depth_line;
}

QPlainTextEdit *QWidget_add_lug::getDescription() const{
    return description_line;
}

QWidget_add_lug::~QWidget_add_lug(){
    delete bag_l;
    delete type_combo;
    delete weight_line;
    delete height_line;
    delete width_line;
    delete depth_line;
    delete description_line;
}
