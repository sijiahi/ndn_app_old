/********************************************************************************
** Form generated from reading UI file 'setting-dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTING_2D_DIALOG_H
#define UI_SETTING_2D_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingDialog
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *identityLayout;
    QLabel *identityLabel;
    QLineEdit *identityLine;
    QHBoxLayout *nickLayout;
    QLabel *nickLabel;
    QLineEdit *nickLine;
    QHBoxLayout *prefixLayout;
    QLabel *prefixLabel;
    QLineEdit *prefixLine;
    QHBoxLayout *buttonLayout;
    QPushButton *cancelButton;
    QPushButton *saveButton;

    void setupUi(QDialog *SettingDialog)
    {
        if (SettingDialog->objectName().isEmpty())
            SettingDialog->setObjectName(QStringLiteral("SettingDialog"));
        SettingDialog->resize(400, 150);
        widget = new QWidget(SettingDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 13, 381, 133));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        identityLayout = new QHBoxLayout();
        identityLayout->setObjectName(QStringLiteral("identityLayout"));
        identityLabel = new QLabel(widget);
        identityLabel->setObjectName(QStringLiteral("identityLabel"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        identityLabel->setFont(font);

        identityLayout->addWidget(identityLabel);

        identityLine = new QLineEdit(widget);
        identityLine->setObjectName(QStringLiteral("identityLine"));

        identityLayout->addWidget(identityLine);

        identityLayout->setStretch(0, 3);
        identityLayout->setStretch(1, 7);

        verticalLayout->addLayout(identityLayout);

        nickLayout = new QHBoxLayout();
        nickLayout->setObjectName(QStringLiteral("nickLayout"));
        nickLabel = new QLabel(widget);
        nickLabel->setObjectName(QStringLiteral("nickLabel"));
        nickLabel->setFont(font);

        nickLayout->addWidget(nickLabel);

        nickLine = new QLineEdit(widget);
        nickLine->setObjectName(QStringLiteral("nickLine"));

        nickLayout->addWidget(nickLine);

        nickLayout->setStretch(0, 3);
        nickLayout->setStretch(1, 7);

        verticalLayout->addLayout(nickLayout);

        prefixLayout = new QHBoxLayout();
        prefixLayout->setObjectName(QStringLiteral("prefixLayout"));
        prefixLabel = new QLabel(widget);
        prefixLabel->setObjectName(QStringLiteral("prefixLabel"));
        prefixLabel->setFont(font);

        prefixLayout->addWidget(prefixLabel);

        prefixLine = new QLineEdit(widget);
        prefixLine->setObjectName(QStringLiteral("prefixLine"));

        prefixLayout->addWidget(prefixLine);

        prefixLayout->setStretch(0, 3);
        prefixLayout->setStretch(1, 7);

        verticalLayout->addLayout(prefixLayout);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName(QStringLiteral("buttonLayout"));
        cancelButton = new QPushButton(widget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setAutoDefault(false);

        buttonLayout->addWidget(cancelButton);

        saveButton = new QPushButton(widget);
        saveButton->setObjectName(QStringLiteral("saveButton"));

        buttonLayout->addWidget(saveButton);


        verticalLayout->addLayout(buttonLayout);


        retranslateUi(SettingDialog);

        QMetaObject::connectSlotsByName(SettingDialog);
    } // setupUi

    void retranslateUi(QDialog *SettingDialog)
    {
        SettingDialog->setWindowTitle(QApplication::translate("SettingDialog", "Dialog", Q_NULLPTR));
        identityLabel->setText(QApplication::translate("SettingDialog", "Identity:", Q_NULLPTR));
        nickLabel->setText(QApplication::translate("SettingDialog", "nick:", Q_NULLPTR));
        prefixLabel->setText(QApplication::translate("SettingDialog", "routable prefix:", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("SettingDialog", "Cancel", Q_NULLPTR));
        saveButton->setText(QApplication::translate("SettingDialog", "Save", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SettingDialog: public Ui_SettingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTING_2D_DIALOG_H
