#ifndef QWIDGET_ADD_OWNER_H
#define QWIDGET_ADD_OWNER_H
#include <QHBoxLayout>
#include <QLineEdit>
#include <QDateEdit>
#include <QCheckBox>
#include <QWidget>
#include <QLabel>
#include <QFont>
class QWidget_add_owner : public QWidget
{
    Q_OBJECT
public:
    explicit QWidget_add_owner(QWidget *parent = 0);
    void build();
    QLineEdit* getName() const;
    QLineEdit* getSurname() const;
    QLineEdit* getDomicile() const;
    QDateEdit* getBirth() const;
    QCheckBox* getLeave() const;
    ~QWidget_add_owner();
private:
    QVBoxLayout* prop_l;
    QLineEdit* name_line,* surname_line,* domicile_line;
    QDateEdit* birth_line;
    QCheckBox* leave_line;
};

#endif // QWIDGET_ADD_OWNER_H
