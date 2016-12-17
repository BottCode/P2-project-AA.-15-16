#ifndef QWIDGET_ADD_TRAVEL_H
#define QWIDGET_ADD_TRAVEL_H
#include <QWidget>
#include <QLabel>
#include <QFont>
#include <QComboBox>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QDateEdit>
#include <QWidget>

class QWidget_add_travel : public QWidget
{
    Q_OBJECT
public:
    explicit QWidget_add_travel(QWidget *parent = 0);
    void build();
    QComboBox* getBy() const;
    QLineEdit* getDest() const;
    QDateEdit* getDep() const;
    ~QWidget_add_travel();
private:
    QVBoxLayout* via_l;
    QComboBox* bytravel_combo;
    QLineEdit* dest_line;
    QDateEdit* depday_line;    
};

#endif // QWIDGET_ADD_TRAVEL_H
