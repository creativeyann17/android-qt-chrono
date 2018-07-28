#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QMessageBox>

#define STEP 50

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),m_pTimer(new QTimer()),ticks(0)
{
    ui->setupUi(this);
    connect(m_pTimer,SIGNAL(timeout()),this,SLOT(tick()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_pTimer;

}

void MainWindow::on_startBt_clicked()
{
    ui->startBt->setFocusPolicy(Qt::NoFocus);
    if(m_pTimer->isActive()){
        ui->startBt->setText("START");
        ui->startBt->setChecked(false);
        m_pTimer->stop();
    }else{
        ui->startBt->setText("STOP");
        ui->startBt->setChecked(true);
        m_pTimer->start(STEP);
    }
}

void MainWindow::on_resetBt_clicked()
{
    ticks=0;
    m_pTimer->stop();

    ui->resetBt->setFocusPolicy(Qt::NoFocus);

    ui->startBt->setChecked(false);
    ui->startBt->setText("START");

    display("00:00:00");
}

void MainWindow::tick(){
    ticks+=STEP;

    QDateTime dt=QDateTime::fromMSecsSinceEpoch(ticks,Qt::UTC);
    QString txt=dt.toString("mm:ss:zzz");
    display(txt.left(8));

}

void MainWindow::display(const QString & txt){
    ui->timeLabel->setText(txt);
}

void MainWindow::showEvent(QShowEvent *){
    QFont font=ui->timeLabel->font();
    font.setPixelSize(ui->timeLabel->width()/4);
    ui->timeLabel->setFont(font);
}

void MainWindow::resizeEvent(QResizeEvent *){
    QFont font=ui->timeLabel->font();
    font.setPixelSize(ui->timeLabel->width()/4);
    ui->timeLabel->setFont(font);
}

void MainWindow::on_actionExit_triggered()
{
    qApp->exit();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::information(this,"About Chrono","Simple C++/Qt app by Yann MARCOU (c) 2015.",QMessageBox::Ok);
}
