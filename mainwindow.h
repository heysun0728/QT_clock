#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLCDNumber>
#include <QTimer>
#include <QTime>
#include <QPushButton>
#include <QPalette>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QLCDNumber *myLCD;
    QTimer *myTimer;
    QPushButton *rbtn,*gbtn,*bbtn;

private slots:
    void showTime();
    void Red_clicked();
    void Green_clicked();
    void Blue_clicked();
};

#endif // MAINWINDOW_H
