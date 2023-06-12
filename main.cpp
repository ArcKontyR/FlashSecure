#include "mainwindow.h"
#include <QApplication>
#include <QDir>

int main(int argc, char *argv[])
{
    QDir dir;
    QApplication a(argc, argv);
    system(qPrintable(QString("chmod +x %1/scripts/checkusb.sh").arg(QCoreApplication::applicationDirPath())));
    system(qPrintable(QString("chmod +x %1/scripts/install.sh").arg(QCoreApplication::applicationDirPath())));
    system(qPrintable(QString("chmod +x %1/scripts/uninstall.sh").arg(QCoreApplication::applicationDirPath())));
    system(qPrintable(QString("chmod +x %1/scripts/add.sh").arg(QCoreApplication::applicationDirPath())));
    system(qPrintable(QString("chmod +x %1/scripts/copy.sh").arg(QCoreApplication::applicationDirPath())));
    MainWindow w;
    w.setWindowIcon(QIcon(":/logo.png"));
    w.show();

    return a.exec();
}
