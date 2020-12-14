/********************************************************************************
** Form generated from reading UI file 'set-alias-dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SET_2D_ALIAS_2D_DIALOG_H
#define UI_SET_2D_ALIAS_2D_DIALOG_H

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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SetAliasDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *introLabel;
    QLineEdit *aliasInput;
    QHBoxLayout *horizontalLayout;
    QPushButton *cancelButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *okButton;

    void setupUi(QDialog *SetAliasDialog)
    {
        if (SetAliasDialog->objectName().isEmpty())
            SetAliasDialog->setObjectName(QStringLiteral("SetAliasDialog"));
        SetAliasDialog->resize(300, 150);
        verticalLayout_2 = new QVBoxLayout(SetAliasDialog);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        introLabel = new QLabel(SetAliasDialog);
        introLabel->setObjectName(QStringLiteral("introLabel"));
        introLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        introLabel->setWordWrap(true);

        verticalLayout->addWidget(introLabel);

        aliasInput = new QLineEdit(SetAliasDialog);
        aliasInput->setObjectName(QStringLiteral("aliasInput"));

        verticalLayout->addWidget(aliasInput);

        horizontalLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
        horizontalLayout->setSpacing(-1);
#endif
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        cancelButton = new QPushButton(SetAliasDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout->addWidget(cancelButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okButton = new QPushButton(SetAliasDialog);
        okButton->setObjectName(QStringLiteral("okButton"));

        horizontalLayout->addWidget(okButton);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 2);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 1);

        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(SetAliasDialog);

        QMetaObject::connectSlotsByName(SetAliasDialog);
    } // setupUi

    void retranslateUi(QDialog *SetAliasDialog)
    {
        SetAliasDialog->setWindowTitle(QApplication::translate("SetAliasDialog", "Dialog", Q_NULLPTR));
        introLabel->setText(QApplication::translate("SetAliasDialog", "TextLabel", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("SetAliasDialog", "Cancel", Q_NULLPTR));
        okButton->setText(QApplication::translate("SetAliasDialog", "OK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SetAliasDialog: public Ui_SetAliasDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SET_2D_ALIAS_2D_DIALOG_H
