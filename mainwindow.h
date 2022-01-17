#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <string>
#include <QVector>
#include <QMainWindow>
#include <QPainter>
#include <QPen>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    QVector<QPoint> vector;
    bool drawing;

public:
    MainWindow(QWidget *parent = nullptr);
    void Crtanje();
    void savePoints();
    void loadPoints();
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *e)override;
    void mousePressEvent(QMouseEvent *event)override;

private slots:
    void on_actionDrawing_ON_OFF_triggered();
    void on_actionSave_triggered();
    void on_actionLoad_triggered();
};
#endif // MAINWINDOW_H
