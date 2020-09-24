/********************************************************************************
** Form generated from reading UI file 'nfd_manegement.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NFD_MANEGEMENT_H
#define UI_NFD_MANEGEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Nfd_Manegement
{
public:
    QPushButton *pushButton;

    void setupUi(QDialog *Nfd_Manegement)
    {
        if (Nfd_Manegement->objectName().isEmpty())
            Nfd_Manegement->setObjectName(QStringLiteral("Nfd_Manegement"));
        Nfd_Manegement->resize(400, 300);
        pushButton = new QPushButton(Nfd_Manegement);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(70, 30, 89, 25));

        retranslateUi(Nfd_Manegement);

        QMetaObject::connectSlotsByName(Nfd_Manegement);
    } // setupUi

    void retranslateUi(QDialog *Nfd_Manegement)
    {
        Nfd_Manegement->setWindowTitle(QApplication::translate("Nfd_Manegement", "Dialog", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Nfd_Manegement", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Nfd_Manegement: public Ui_Nfd_Manegement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NFD_MANEGEMENT_H
