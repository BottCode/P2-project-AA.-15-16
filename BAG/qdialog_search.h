#ifndef QDIALOG_SEARCH_H
#define QDIALOG_SEARCH_H
#include <QRegExp>
#include <QDialog>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QDebug>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QScrollArea>
#include <vector>
#include "controller_lista_bagagli.h"
class QDialog_search: public QDialog{
    Q_OBJECT
private:
    controller_lista_bagagli* ctrl_l_b; // serve per la ricerca
    QVBoxLayout* main;
    QTabWidget* tab;
    // id
    QWidget* search_id;
    QVBoxLayout* id_l;
    QLineEdit* id_line;
    QPushButton* id_button;
    QLabel* id_lab;
    // owner
    QWidget* search_owner;
    QVBoxLayout* ow_l;
    QLineEdit* ow_line;
    QPushButton* ow_button;
    QLabel* ow_lab;
    // destination
    QWidget* search_dest;
    QVBoxLayout* dest_l;
    QLineEdit* dest_line;
    QPushButton* dest_button;
    QLabel* dest_lab;
    // search
    QDialog* d;
    QScrollArea* qs;
    QVBoxLayout* l,* ls;
    QWidget* w;
    QLabel* dest,*type,*price,*owner,*fail;
public:
    QDialog_search(controller_lista_bagagli*,QWidget* parent=0);
    void buildSearchId();
    void build_search_id_result(bagaglio*);
    void buildSearchOwner();
    void build_search_id_owner(std::vector<bagaglio*>, int);
    void buildSearchDest();
    void build_search_dest_result(std::vector<bagaglio*>);
    void closeEvent(QCloseEvent *event);
    ~QDialog_search();
public slots:
    void on_search_id_clicked();
    void on_search_owner_clicked();
    void on_search_dest_clicked();
};

#endif // QDIALOG_SEARCH_H
