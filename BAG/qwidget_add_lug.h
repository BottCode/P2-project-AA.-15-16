#ifndef QWIDGET_ADD_LUG_H
#define QWIDGET_ADD_LUG_H
#include <QLabel>
#include <QFont>
#include <QComboBox>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QDateEdit>
#include <QCheckBox>

class QWidget_add_lug : public QWidget
{
    Q_OBJECT
public:
    explicit QWidget_add_lug(QWidget *parent = 0);
    void build();
    QComboBox* getcombo() const;
    QLineEdit* getWeight() const;
    QLineEdit* getHeight() const;
    QLineEdit* getWidth() const;
    QLineEdit* getDepth() const;
    QPlainTextEdit* getDescription() const;
    ~QWidget_add_lug();
private:
    QVBoxLayout* bag_l;
    QComboBox* type_combo;
    QLineEdit* weight_line,* height_line,* width_line,* depth_line;
    QPlainTextEdit* description_line;
};

#endif // QWIDGET_ADD_LUG_H
