#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "view_lista_bagagli.h"
#include "view_add_bagagli.h"
#include "qdialog_search.h"
#include <QMainWindow>
#include <QDebug>
#include <QFileDialog>

// MATTIA BOTTARO #1097723

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    void closeEvent(QCloseEvent *event);
    ~MainWindow();

private slots:
    void on_refreshButton_clicked();
    void on_actionRefresh_list_triggered();
    void on_removeLast_clicked();
    void on_actionRemove_last_triggered();
    void on_dropButton_clicked();
    void on_actionRemove_all_triggered();
    void on_searchButton_clicked();
    void on_addButton_clicked();
    void on_resetButton_clicked();
    void on_actionLoad_triggered();
    void on_actionSave_triggered();

public:
    // alcuni puntatori sono inizializzati a 0 nel costruttore. Questo perchè non è detto che essi punteranno a qualcosa. E questa informazione mi serve per capire se
    // distruggere o meno nel corpo del distruttore
    QMessageBox* msg;
    Ui::MainWindow *ui;
    QVBoxLayout* list_layout; // layout in cui inserire tab_vis
    QHBoxLayout* add_layout; // layout in cui inserire add_vis
    QDialog_search* qds;
    view_lista_bagagli* tab_vis; // È la view per la lista dei bagagli
    view_add_bagagli* add_vis; // È la view per aggiungere un bagaglio
    controller_lista_bagagli* ct; // con esso accedo al model
    void on_update_view();
};

#endif // MAINWINDOW_H
