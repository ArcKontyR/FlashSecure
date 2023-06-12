#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>

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

    void toggleDevMode(bool);
    void updateRules();
    void addFlashToRules();
    void installRules();
    void uninstallRules();
    void deleteFlashFromRules();
    void updateConnectedUSBStorages();
//    void about();
//    void help();

    //Дополнительные настройки
    void devRemoveTmpRules();
    void devCopyRules();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
