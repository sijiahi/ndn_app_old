/********************************************************************************
** Form generated from reading UI file 'ndn_app.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NDN_APP_H
#define UI_NDN_APP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ndn_app
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ndn_app)
    {
        if (ndn_app->objectName().isEmpty())
            ndn_app->setObjectName(QStringLiteral("ndn_app"));
        ndn_app->resize(400, 300);
        menuBar = new QMenuBar(ndn_app);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        ndn_app->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ndn_app);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ndn_app->addToolBar(mainToolBar);
        centralWidget = new QWidget(ndn_app);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ndn_app->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ndn_app);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ndn_app->setStatusBar(statusBar);

        retranslateUi(ndn_app);

        QMetaObject::connectSlotsByName(ndn_app);
    } // setupUi

    void retranslateUi(QMainWindow *ndn_app)
    {
        ndn_app->setWindowTitle(QApplication::translate("ndn_app", "ndn_app", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ndn_app: public Ui_ndn_app {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NDN_APP_H
