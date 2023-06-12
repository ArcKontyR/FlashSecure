/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *aHelp;
    QAction *aAbout;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *glButtonMenu;
    QCheckBox *cbDevRulesInstalled;
    QListWidget *lwConnectedUSBS;
    QPushButton *pbClearFlashes;
    QPushButton *pbDeleteFlash;
    QPushButton *pbAddFlash;
    QPushButton *pbDevCopyRules;
    QLabel *label_2;
    QCheckBox *cbDevTools;
    QPushButton *pbDevDeleteTmpRules;
    QPushButton *pbRecreateRulesFile;
    QLabel *label;
    QLabel *label_3;
    QListWidget *lwInstalledRules;
    QListWidget *lwRules;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(867, 350);
        aHelp = new QAction(MainWindow);
        aHelp->setObjectName(QStringLiteral("aHelp"));
        aAbout = new QAction(MainWindow);
        aAbout->setObjectName(QStringLiteral("aAbout"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setAutoFillBackground(true);
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        glButtonMenu = new QGridLayout();
        glButtonMenu->setSpacing(6);
        glButtonMenu->setObjectName(QStringLiteral("glButtonMenu"));
        cbDevRulesInstalled = new QCheckBox(centralWidget);
        cbDevRulesInstalled->setObjectName(QStringLiteral("cbDevRulesInstalled"));
        cbDevRulesInstalled->setEnabled(false);
        cbDevRulesInstalled->setCheckable(true);

        glButtonMenu->addWidget(cbDevRulesInstalled, 5, 2, 1, 1);

        lwConnectedUSBS = new QListWidget(centralWidget);
        lwConnectedUSBS->setObjectName(QStringLiteral("lwConnectedUSBS"));
        lwConnectedUSBS->setEnabled(false);
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lwConnectedUSBS->sizePolicy().hasHeightForWidth());
        lwConnectedUSBS->setSizePolicy(sizePolicy1);

        glButtonMenu->addWidget(lwConnectedUSBS, 1, 2, 1, 1);

        pbClearFlashes = new QPushButton(centralWidget);
        pbClearFlashes->setObjectName(QStringLiteral("pbClearFlashes"));

        glButtonMenu->addWidget(pbClearFlashes, 4, 1, 1, 1);

        pbDeleteFlash = new QPushButton(centralWidget);
        pbDeleteFlash->setObjectName(QStringLiteral("pbDeleteFlash"));

        glButtonMenu->addWidget(pbDeleteFlash, 5, 0, 1, 1);

        pbAddFlash = new QPushButton(centralWidget);
        pbAddFlash->setObjectName(QStringLiteral("pbAddFlash"));

        glButtonMenu->addWidget(pbAddFlash, 4, 0, 1, 1);

        pbDevCopyRules = new QPushButton(centralWidget);
        pbDevCopyRules->setObjectName(QStringLiteral("pbDevCopyRules"));

        glButtonMenu->addWidget(pbDevCopyRules, 6, 1, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        glButtonMenu->addWidget(label_2, 0, 2, 1, 1);

        cbDevTools = new QCheckBox(centralWidget);
        cbDevTools->setObjectName(QStringLiteral("cbDevTools"));
        cbDevTools->setChecked(true);

        glButtonMenu->addWidget(cbDevTools, 4, 2, 1, 1);

        pbDevDeleteTmpRules = new QPushButton(centralWidget);
        pbDevDeleteTmpRules->setObjectName(QStringLiteral("pbDevDeleteTmpRules"));

        glButtonMenu->addWidget(pbDevDeleteTmpRules, 6, 0, 1, 1);

        pbRecreateRulesFile = new QPushButton(centralWidget);
        pbRecreateRulesFile->setObjectName(QStringLiteral("pbRecreateRulesFile"));
        pbRecreateRulesFile->setEnabled(true);

        glButtonMenu->addWidget(pbRecreateRulesFile, 5, 1, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        glButtonMenu->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        glButtonMenu->addWidget(label_3, 0, 1, 1, 1);

        lwInstalledRules = new QListWidget(centralWidget);
        lwInstalledRules->setObjectName(QStringLiteral("lwInstalledRules"));
        lwInstalledRules->setEnabled(false);

        glButtonMenu->addWidget(lwInstalledRules, 1, 0, 1, 1);

        lwRules = new QListWidget(centralWidget);
        lwRules->setObjectName(QStringLiteral("lwRules"));
        lwRules->setEnabled(true);

        glButtonMenu->addWidget(lwRules, 1, 1, 1, 1);


        gridLayout_2->addLayout(glButtonMenu, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "FlashSecure", nullptr));
        aHelp->setText(QApplication::translate("MainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", nullptr));
        aAbout->setText(QApplication::translate("MainWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", nullptr));
        cbDevRulesInstalled->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\260\320\262\320\270\320\273\320\260 \321\203\321\201\321\202\320\260\320\275\320\276\320\262\320\273\320\265\320\275\321\213", nullptr));
        pbClearFlashes->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \320\277\321\200\320\260\320\262\320\270\320\273\320\260 \320\264\320\273\321\217 \320\237\320\232", nullptr));
        pbDeleteFlash->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\244\320\273\321\215\321\210-\320\275\320\260\320\272\320\276\320\277\320\270\321\202\320\265\320\273\321\214", nullptr));
        pbAddFlash->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\244\320\273\321\215\321\210-\320\275\320\260\320\272\320\276\320\277\320\270\321\202\320\265\320\273\321\214", nullptr));
        pbDevCopyRules->setText(QApplication::translate("MainWindow", "\320\241\320\272\320\276\320\277\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\277\321\200\320\260\320\262\320\270\320\273\320\260", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\265\320\275\320\275\321\213\320\265 \320\244\320\273\321\215\321\210-\321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\260:", nullptr));
        cbDevTools->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\277\320\276\320\273\320\275\320\270\321\202\320\265\320\273\321\214\320\275\321\213\320\265 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
        pbDevDeleteTmpRules->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\204\320\260\320\271\320\273 \320\275\320\260\321\201\321\202\321\200\320\276\320\265\320\272", nullptr));
        pbRecreateRulesFile->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214 \320\277\321\200\320\260\320\262\320\270\320\273\320\260", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\273\320\265\320\275\320\275\321\213\320\265 \320\277\321\200\320\260\320\262\320\270\320\273\320\260:", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\270\321\202\321\214 \320\277\321\200\320\260\320\262\320\270\320\273\320\260:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
