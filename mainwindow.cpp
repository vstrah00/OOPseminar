#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    drawing=true;
    ui->pushButton->setText("Drawing - ON");
}

void MainWindow::Crtanje()
{
    if(drawing==true){
        drawing=false;
        ui->pushButton->setText("Drawing - OFF");
    }
    else{
        drawing=true;
        ui->pushButton->setText("Drawing - ON");
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    QPen pen1(Qt::black);
    pen1.setWidth(5);
    painter.setPen(pen1);

    if(vector.begin()!=vector.end()){
        for(int i=0; i<vector.size(); i++){
            if(i>0){
                painter.drawLine(vector.at(i-1), vector.at(i));
            }
        }
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(drawing==true){
        if(event->button()==Qt::LeftButton){
            if(vector.begin()!=vector.end()){
                vector.prepend(event->pos());
                update();
            }
            else{
                vector.prepend(event->pos());
                }
        }
    }
}



void MainWindow::savePoints()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save As...", "", "FESB File (*.fsb)");
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly)) {
            QMessageBox::information(this, "Unable to Open File", file.errorString());
            return;
        }
        QDataStream out(&file);
        out << vector;
        file.close();

   }
}

void MainWindow::loadPoints()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open Geometry...", "", "FESB File (*.fsb)");
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::information(this, "Unable to Open File", file.errorString());
            return;
        }
        vector.clear();
        QDataStream in(&file);
        in >> vector;
        file.close();
        update();

    }
}
void MainWindow::on_actionSave_triggered()
{
    savePoints();
}


void MainWindow::on_actionLoad_triggered()
{
    loadPoints();
}


void MainWindow::on_pushButton_clicked()
{
    Crtanje();
}

