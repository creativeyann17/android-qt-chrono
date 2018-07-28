#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_startBt_clicked();
    void on_resetBt_clicked();
    void tick();
    void on_actionExit_triggered();
    void on_actionAbout_triggered();

    void resizeEvent(QResizeEvent*);
    void showEvent(QShowEvent *);

private:
    void display(const QString &);

private:
    Ui::MainWindow *ui;
    QTimer*m_pTimer;
    qint64 ticks;

};

#endif // MAINWINDOW_H
