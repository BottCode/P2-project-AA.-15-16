#ifndef VIEW_ADD_BAGAGLI_H
#define VIEW_ADD_BAGAGLI_H
#include "qwidget_add_lug.h"
#include "qwidget_add_owner.h"
#include "qwidget_add_travel.h"

class view_add_bagagli: public QWidget{
public:
    view_add_bagagli(QWidget* parent=0);
    void resetFields(QWidget_add_lug*,QWidget_add_owner*,QWidget_add_travel*) const; // resetta i campi della ui
    QWidget_add_lug* getBagWid() const;
    QWidget_add_owner* getPropWid() const;
    QWidget_add_travel* getViaWid() const;
    ~view_add_bagagli();
private:
    // sono i 3 sottoWidget
    QWidget_add_lug* setBagWid;
    QWidget_add_owner* setPropWid;
    QWidget_add_travel* setViaWid;
};

#endif // VIEW_ADD_BAGAGLI_H
