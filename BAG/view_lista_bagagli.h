#ifndef VIEW_BAGAGLIO_H
#define VIEW_BAGAGLIO_H
#include <QTableWidget>
#include <QPushButton>
#include <QCheckBox>
#include <QDebug>
#include "qiter_mngm.h"
#include "controller_lista_bagagli.h"
#include "qdialog_info.h"
class view_lista_bagagli: public QTableWidget{
    Q_OBJECT
private:
    controller_lista_bagagli* ctrl_l_b;
    QMessageBox* msg;
    QDialog_info* in_w;
    QDialog* w;
    QVBoxLayout* l;
    QLabel* label;
    QPushButton* button;
signals:
    void get_id_for_info(int);
public slots:
    void build_actions(int, int);
    void update_container(int, int);
public:
    view_lista_bagagli(QWidget* parent=0);
    controller_lista_bagagli* getCtrl() const;
    void build_view_list(Lista<bagaglio*>&);
    void update_view_list(Lista<bagaglio*>&);
    void modify_container_item(Lista<bagaglio*>&, int,int);
    void more_info_action_clicked(int row, int col);
    void delete_action_clicked(int row, int col);
    Lista<bagaglio*>::iteratore FindIter(int);
    void closeEvent(QCloseEvent *event);
    ~view_lista_bagagli();

};

#endif // VIEW_BAGAGLIO_H
