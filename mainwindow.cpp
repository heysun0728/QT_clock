#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("LCD Timer");
    resize(300,280);
    setStyleSheet("background-color:#BDC3C7;");
    myLCD=new QLCDNumber(this);
    myLCD->setSegmentStyle(QLCDNumber::Flat);
    myLCD->setGeometry(50,30,200,120);
    myLCD->setDigitCount(8);
    myTimer=new QTimer(this);
    myTimer->start(1000);
    showTime();
    connect(myTimer,SIGNAL(timeout()),this,SLOT(showTime()));

    rbtn=new QPushButton("R",this);
    rbtn->setStyleSheet("QPushButton{border:2px solid #95A5A6;border-radius:10px;color:red;}");
    rbtn->setFont(QFont("Courier",25,QFont::Bold));
    rbtn->setGeometry(50,180,50,50);
    connect(rbtn,SIGNAL(clicked()),this,SLOT(Red_clicked()));

    gbtn=new QPushButton("G",this);
    gbtn->setStyleSheet("QPushButton{border:2px solid #95A5A6;border-radius:10px;color:green;}");
    gbtn->setFont(QFont("Courier",25,QFont::Bold));
    gbtn->setGeometry(125,180,50,50);
    connect(gbtn,SIGNAL(clicked()),this,SLOT(Green_clicked()));

    bbtn=new QPushButton("B",this);
    bbtn->setStyleSheet("QPushButton{border:2px solid #95A5A6;border-radius:10px;color:blue;}");
    bbtn->setFont(QFont("Courier",25,QFont::Bold));
    bbtn->setGeometry(200,180,50,50);
    connect(bbtn,SIGNAL(clicked()),this,SLOT(Blue_clicked()));

}
void MainWindow::showTime(){
    QTime time=QTime::currentTime();
    QString text=time.toString("hh:mm:ss");
    myLCD->display(text);
}

void MainWindow::Red_clicked(){
    QPalette lcdpat= myLCD->palette();
    lcdpat.setColor(QPalette::Normal,QPalette::WindowText,Qt::red);
    myLCD->setPalette(lcdpat);
    update();
}

void MainWindow::Green_clicked(){
    QPalette lcdpat= myLCD->palette();
    lcdpat.setColor(QPalette::Normal,QPalette::WindowText,Qt::green);
    myLCD->setPalette(lcdpat);
    update();
}

void MainWindow::Blue_clicked(){
    QPalette lcdpat= myLCD->palette();
    lcdpat.setColor(QPalette::Normal,QPalette::WindowText,Qt::blue);
    myLCD->setPalette(lcdpat);
    update();
}


MainWindow::~MainWindow()
{
    delete ui;
}
