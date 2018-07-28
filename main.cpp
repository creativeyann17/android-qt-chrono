#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
#ifdef __ANDROID_API__
    w.showFullScreen();
#else
    w.show();
#endif
    return a.exec();
}
