#ifndef QDIALOG_INFO_H
#define QDIALOG_INFO_H
#include <QDebug>
#include <QDialog>
#include <QLabel>
#include <QVBoxLayout>
#include "model_bagaglio.h"
class QDialog_info: public QDialog{
public:
    QDialog_info(const bagaglio&, QWidget* parent=0);
    void write_info(const bagaglio &);
    ~QDialog_info();
private:
    QVBoxLayout* l;
    QLabel* lb;
    QLabel* own_name;
    QLabel* leave;
};

#endif // QDIALOG_INFO_H
