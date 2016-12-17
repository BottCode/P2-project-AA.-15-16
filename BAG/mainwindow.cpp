#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent):ui(new Ui::MainWindow){
    msg=0;qds=0;
    list_layout=new QVBoxLayout();
    add_layout=new QHBoxLayout();
    tab_vis=new view_lista_bagagli(ui->scrollAreaViewWidgetContents);
    add_vis=new view_add_bagagli(ui->widgetadd);
    ct=tab_vis->getCtrl();
    ui->setupUi(this);
    this->setCentralWidget(ui->centralWidget);
    ui->scrollAreaViewWidgetContents->setLayout(list_layout);
    list_layout->addWidget(tab_vis);
    tab_vis->build_view_list(ct->getList());
    ui->widgetadd->setLayout(add_layout);
    add_layout->addWidget(add_vis->getBagWid());
    add_layout->addWidget(add_vis->getPropWid());
    add_layout->addWidget(add_vis->getViaWid());
    on_update_view();
    setParent(parent);
}

// list view
void MainWindow::on_refreshButton_clicked(){ // funzione che dalla view modifica il contenuto del conteitore
    //qDebug()<<__FUNCTION__;
    tab_vis->clear();
    tab_vis->update_view_list(ct->getList());
    if(!ct->ctrl_getSize()) tab_vis->removeRow(0);
    ui->statusBar->showMessage(ct->ctrl_getFileData());
}

void MainWindow::on_actionRefresh_list_triggered(){
    //qDebug()<<__FUNCTION__;
    on_update_view();
}

void MainWindow::on_removeLast_clicked(){
    //qDebug()<<__FUNCTION__;
    if(msg) delete msg;
    msg=new QMessageBox();
    msg->setWindowTitle("Message");
    msg->setIcon(QMessageBox::Question);
    msg->setText("Remove last luggage inserted?");
    msg->setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
    msg->setDefaultButton(QMessageBox::Cancel);
    int ch=msg->exec();
    if(ch==QMessageBox::Yes){
        ct->ctrl_pop_back();
        on_update_view();
    }
}

void MainWindow::on_actionRemove_last_triggered(){
    //qDebug()<<__FUNCTION__;
    on_removeLast_clicked();
}

void MainWindow::on_dropButton_clicked(){
    //qDebug()<<__FUNCTION__;
    if(msg) delete msg;
    msg=new QMessageBox();
    msg->setWindowTitle("Message");
    msg->setIcon(QMessageBox::Question);
    msg->setText("Remove ALL luggages?");
    msg->setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
    msg->setDefaultButton(QMessageBox::Cancel);
    int ch=msg->exec();
    if(ch==QMessageBox::Yes){
        ct->ctrl_drop();
        while(tab_vis->rowCount()>0) tab_vis->removeRow(0);
    }
}

void MainWindow::on_actionRemove_all_triggered(){
    //qDebug()<<__FUNCTION__;
    on_dropButton_clicked();
}

void MainWindow::on_searchButton_clicked(){
    //qDebug()<<__FUNCTION__;
    if(qds) delete qds;
    qds=new QDialog_search(ct);
}

// add luggage view
void MainWindow::on_addButton_clicked(){
    //qDebug()<<__FUNCTION__;
    if(msg) delete msg;
    msg=new QMessageBox();
    msg->setWindowTitle("Message");
    if(ct->build_lug(add_vis->getBagWid(),add_vis->getPropWid(),add_vis->getViaWid())){
        msg->setText("Add!");
        on_resetButton_clicked();
        on_update_view();
    }else msg->setText("Invalid input.");
    msg->setWindowIcon(QIcon(":/icon/icone/vis-lug.png"));
    msg->show();
}

void MainWindow::on_resetButton_clicked(){
    //qDebug()<<__FUNCTION__;
    add_vis->resetFields(add_vis->getBagWid(),add_vis->getPropWid(),add_vis->getViaWid());
}

void MainWindow::on_actionLoad_triggered(){
    //qDebug()<<__FUNCTION__;
    QString path=QFileDialog::getOpenFileName(this,"Load",QString(),"*.xml");
    if(!path.isEmpty()){
        tab_vis->getCtrl()->ctrl_save_end(tab_vis->getCtrl()->ctrl_getFileData()); // salvo la lista attuale
        tab_vis->getCtrl()->ctrl_setFileData(path); // aggiorno il percorso del file in uso con quello nuovo
        while(tab_vis->rowCount()>0) tab_vis->removeRow(0);
        tab_vis->getCtrl()->ctrl_load_init(path); // infine aggiorno il contenitore
        ui->statusBar->showMessage(ct->ctrl_getFileData());
        on_update_view();
    }
    else qDebug()<<"Errore: percorso vuoto";
}

void MainWindow::on_update_view(){
    //qDebug()<<__FUNCTION__;
    tab_vis->clear();
    tab_vis->update_view_list(ct->getList());
    if(!ct->ctrl_getSize()) tab_vis->removeRow(0);
    ui->statusBar->showMessage(ct->ctrl_getFileData());
}

void MainWindow::on_actionSave_triggered(){
    // qDebug()<<__FUNCTION__;
    QString path=QFileDialog::getSaveFileName();
    ct->ctrl_save_end(path);
    qDebug()<<path;
}

void MainWindow::closeEvent(QCloseEvent *event){
   if(qds) qds->closeEvent(event);
   if(tab_vis) tab_vis->closeEvent(event);
   QMainWindow::closeEvent(event);
}

MainWindow::~MainWindow(){
    tab_vis->getCtrl()->ctrl_save_end(tab_vis->getCtrl()->ctrl_getFileData());
    if(qds) delete qds;
    if(msg) delete msg;
    delete list_layout;
    delete add_layout;
    delete tab_vis;
    delete add_vis;
    delete ui;
    // non si fa delete ct; perchè il controller viene deallocato in view_lista_bagagli
}

