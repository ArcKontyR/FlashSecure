#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QtDebug>
#include <QTextStream>
#include <QDir>
#include <QtWidgets>
#include <QtMath>

int s=0;
//QString lblText;
QListWidget *lwRules;
QListWidget *lwConnectedUSBS;
QListWidget *lwInstalledRules;
bool installable = true;
const QString startRule = "ENV{ID_USB_DRIVER}=="+QStringLiteral("\"")+"usb-storage"+QStringLiteral("\"")+",ENV{UDISKS_IGNORE}="+QStringLiteral("\"")+"1"+QStringLiteral("\"")+"\n";
const QString installedRulesPath = "/etc/udev/rules.d/99-usb.rules";
const QString rulesPath = "99-usb.rules";
QDir dir;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    lwRules = ui->lwRules;
    lwInstalledRules = ui->lwInstalledRules;
    lwConnectedUSBS = ui->lwConnectedUSBS;

    connect(ui->pbRecreateRulesFile,SIGNAL(clicked()),this,SLOT(installRules()));
    connect(ui->pbClearFlashes,SIGNAL(clicked()),this,SLOT(uninstallRules()));
    connect(ui->cbDevTools, SIGNAL(toggled(bool)),this,SLOT(toggleDevMode(bool)));
    connect(ui->pbDevCopyRules, SIGNAL(clicked()),this,SLOT(devCopyRules()));
    connect(ui->pbDevDeleteTmpRules,SIGNAL(clicked()),this,SLOT(devRemoveTmpRules()));
    connect(ui->pbAddFlash, SIGNAL(clicked()),this,SLOT(addFlashToRules()));
    connect(ui->pbDeleteFlash, SIGNAL(clicked()), this, SLOT(deleteFlashFromRules()));
//    connect(ui->aAbout, SIGNAL(triggered()),this,SLOT(about()));
//     connect(ui->aHelp, SIGNAL(triggered()),this,SLOT(help()));

    toggleDevMode(ui->cbDevTools->isChecked());
    devCopyRules();

    QTimer *updateConnectionsTimer = new QTimer(this);
    connect(updateConnectionsTimer, SIGNAL(timeout()),this,SLOT(updateConnectedUSBStorages()));
    updateConnectionsTimer->start(1000);
    updateRules();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::toggleDevMode(bool isOn){
    ui->pbDevCopyRules->setVisible(isOn);
    ui->pbDevDeleteTmpRules->setVisible(isOn);
    ui->cbDevRulesInstalled->setVisible(isOn);
}

void MainWindow::devRemoveTmpRules(){
    QFile rules("99-usb.rules");
    if (rules.exists()){
        QFile("99-usb.rules").remove();
        qDebug() << "Файл настроек удалены";
    }else{
        qDebug() << "Файл настроек не существует";
    }
    updateRules();
}

void MainWindow::devCopyRules(){
    system("sudo cp -f /etc/udev/rules.d/99-usb.rules 99-usb.rules");
    qDebug() << "Установленные правила скопированы в файл настроек";
    updateRules();
}

//void MainWindow::about(){
//    QString description = "ааа";
//    QMessageBox::about(this,"Помощь",description);
//}

//void MainWindow::help(){
//    QString description = "ААААААААААААААААААААА";
//    QMessageBox::about(this,"Справка",description);
//}

void MainWindow::addFlashToRules(){
    system(qPrintable(QString("sudo %1/scripts/add.sh").arg(QCoreApplication::applicationDirPath())));
    qDebug() << "Подключенные флешки добавлены в файл настроек как разрешенные на данном устройстве";
    updateRules();
}

void MainWindow::installRules(){
    if (!QFile("99-usb.rules").exists()){
        QFile rules("99-usb.rules");
        rules.open(QIODevice::WriteOnly);
        rules.write(startRule.toLatin1());
        rules.close();
    }
    if (lwInstalledRules->count() > 0 && !lwInstalledRules->item(0)->text().contains("Любой")){

        system(qPrintable(QStringLiteral("sudo sed -i '1iENV{ID_USB_DRIVER}==\"usb-storage\",ENV{UDISKS_IGNORE}=\"1\"' 99-usb.rules")));
    }
    system(qPrintable(QString("sudo %1/scripts/install.sh").arg(QCoreApplication::applicationDirPath())));
    qDebug() << "Правила установлены";
    ui->cbDevRulesInstalled->setChecked(QFile(installedRulesPath).exists());
    updateRules();
}

void MainWindow::uninstallRules(){
    system(qPrintable(QString("sudo %1/scripts/uninstall.sh").arg(QCoreApplication::applicationDirPath())));
    ui->cbDevRulesInstalled->setChecked(QFile(installedRulesPath).exists());
    qDebug() << "Правила удалены";
    updateRules();
}

void MainWindow::updateRules(){
    installable = true;
    lwInstalledRules->clear();
    lwRules->clear();
    QFile installedRules(installedRulesPath);
    QFile rules(rulesPath);
    rules.open(QIODevice::ReadOnly);
    QTextStream tsRules(&rules);
    qDebug()<< "Списки правил обновлены";
    while (!tsRules.atEnd()){
        QStringList parameters = tsRules.readLine().split("\"");
        if (parameters[0] == "ENV{ID_USB_DRIVER}=="){
            continue;
        }
        if (lwRules->findItems(parameters[1],Qt::MatchContains).count() == 0){
            QString parameter = QString("Серийный номер - \"%1\" - %2").arg(parameters[1]).arg(parameters[3] == "1" ? "Запрещен" : "Разрешен");
            QListWidgetItem *item = new QListWidgetItem;
            item->setText(parameter);
            lwRules->addItem(item);
        } else{
            system(qPrintable(QString("sed -i '%1d' 99-usb.rules").arg(lwRules->count()+1)));
        }
        //qDebug() << "rules in" << lwRules->findItems(parameters[1],Qt::MatchContains).count();
    }
    rules.close();
    installedRules.open(QIODevice::ReadOnly);
    QTextStream tsInstalledRules(&installedRules);
    while (!tsInstalledRules.atEnd()){
        QStringList parameters = tsInstalledRules.readLine().split("\"");
        if (parameters[0] == "ENV{ID_USB_DRIVER}=="){
            QString parameter = QString("Серийный номер - \"Любой\" - %1").arg((parameters[3]) == "1" ? "Запрещен" : "Разрешен");
            QListWidgetItem *item = new QListWidgetItem;
            item->setText(parameter);
            lwInstalledRules->addItem(item);
            continue;
        }
        QString parameter = QString("Серийный номер - \"%1\" - %2").arg(parameters[1]).arg(parameters[3] == "1" ? "Запрещен" : "Разрешен");
        if (lwInstalledRules->findItems(parameters[1],Qt::MatchContains).count() == 0){
            QListWidgetItem *item = new QListWidgetItem;
            item->setText(parameter);
            lwInstalledRules->addItem(item);
        }
    }


    ui->pbRecreateRulesFile->setEnabled(installable);

    installedRules.close();
}

void MainWindow::updateConnectedUSBStorages(){
    lwConnectedUSBS->clear();

    QFile serials("connected-usb-serials.txt");
    if (serials.exists()){
        system("sudo rm ./connected-usb-serials.txt");
    }
    system(qPrintable(QString("sudo %1/scripts/checkusb.sh").arg(QCoreApplication::applicationDirPath())));
    serials.open(QIODevice::ReadOnly);
    while(!serials.atEnd()){
        QListWidgetItem *item = new QListWidgetItem;
        item->setText(serials.readLine());
        lwConnectedUSBS->addItem(item);
    }
    serials.close();
}

void MainWindow::deleteFlashFromRules()
{
    if (lwRules->count() == 0){
        return;
    }
    if (lwRules->currentItem() == nullptr){
        return;
    }
    qDebug() << "Флеш накопитель с серийным номером" << lwRules->item(lwRules->currentIndex().row())->text().split("\"").at(1) << "удален из правил";
    system(qPrintable(QString("sed -i '%1d' 99-usb.rules").arg(lwRules->currentIndex().row()+2)));
    lwRules->currentItem()->~QListWidgetItem();
    updateRules();
}
