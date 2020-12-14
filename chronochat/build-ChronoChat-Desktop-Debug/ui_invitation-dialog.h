/********************************************************************************
** Form generated from reading UI file 'invitation-dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INVITATION_2D_DIALOG_H
#define UI_INVITATION_2D_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_InvitationDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *msgLabel;
    QHBoxLayout *buttonLayout;
    QPushButton *cancelButton;
    QPushButton *okButton;

    void setupUi(QDialog *InvitationDialog)
    {
        if (InvitationDialog->objectName().isEmpty())
            InvitationDialog->setObjectName(QStringLiteral("InvitationDialog"));
        InvitationDialog->resize(300, 150);
        verticalLayout_2 = new QVBoxLayout(InvitationDialog);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(10, 10, 10, -1);
        msgLabel = new QLabel(InvitationDialog);
        msgLabel->setObjectName(QStringLiteral("msgLabel"));
        msgLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        msgLabel->setWordWrap(true);

        verticalLayout->addWidget(msgLabel);

        buttonLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
        buttonLayout->setSpacing(-1);
#endif
        buttonLayout->setObjectName(QStringLiteral("buttonLayout"));
        buttonLayout->setContentsMargins(0, -1, -1, -1);
        cancelButton = new QPushButton(InvitationDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        buttonLayout->addWidget(cancelButton);

        okButton = new QPushButton(InvitationDialog);
        okButton->setObjectName(QStringLiteral("okButton"));

        buttonLayout->addWidget(okButton);

        buttonLayout->setStretch(0, 1);
        buttonLayout->setStretch(1, 1);

        verticalLayout->addLayout(buttonLayout);

        verticalLayout->setStretch(0, 5);
        verticalLayout->setStretch(1, 1);

        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(InvitationDialog);

        QMetaObject::connectSlotsByName(InvitationDialog);
    } // setupUi

    void retranslateUi(QDialog *InvitationDialog)
    {
        InvitationDialog->setWindowTitle(QApplication::translate("InvitationDialog", "Dialog", Q_NULLPTR));
        msgLabel->setText(QApplication::translate("InvitationDialog", "TextLabel", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("InvitationDialog", "Reject", Q_NULLPTR));
        okButton->setText(QApplication::translate("InvitationDialog", "Accept", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class InvitationDialog: public Ui_InvitationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVITATION_2D_DIALOG_H
