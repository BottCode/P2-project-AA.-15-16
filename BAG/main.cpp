#include "mainwindow.h"
#include "model_bagaglio_a_mano.h"
#include "model_bagaglio_non_vivente_speciale.h"
#include "model_bagaglio_pianta.h"
#include <QApplication>
#include <QDate>
#include<iostream>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
