/********************************************************************************
** Form generated from reading UI file 'invite-list-dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INVITE_2D_LIST_2D_DIALOG_H
#define UI_INVITE_2D_LIST_2D_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_InviteListDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *inviteLabel;
    QListView *contactListView;
    QHBoxLayout *horizontalLayout;
    QPushButton *cancelButton;
    QPushButton *inviteButton;

    void setupUi(QDialog *InviteListDialog)
    {
        if (InviteListDialog->objectName().isEmpty())
            InviteListDialog->setObjectName(QStringLiteral("InviteListDialog"));
        InviteListDialog->resize(300, 400);
        verticalLayout_2 = new QVBoxLayout(InviteListDialog);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        inviteLabel = new QLabel(InviteListDialog);
        inviteLabel->setObjectName(QStringLiteral("inviteLabel"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        inviteLabel->setFont(font);
        inviteLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout->addWidget(inviteLabel);

        contactListView = new QListView(InviteListDialog);
        contactListView->setObjectName(QStringLiteral("contactListView"));

        verticalLayout->addWidget(contactListView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        cancelButton = new QPushButton(InviteListDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setAutoDefault(false);

        horizontalLayout->addWidget(cancelButton);

        inviteButton = new QPushButton(InviteListDialog);
        inviteButton->setObjectName(QStringLiteral("inviteButton"));
        inviteButton->setAutoDefault(false);

        horizontalLayout->addWidget(inviteButton);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 4);
        verticalLayout->setStretch(1, 20);
        verticalLayout->setStretch(2, 2);

        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(InviteListDialog);

        QMetaObject::connectSlotsByName(InviteListDialog);
    } // setupUi

    void retranslateUi(QDialog *InviteListDialog)
    {
        InviteListDialog->setWindowTitle(QApplication::translate("InviteListDialog", "Dialog", Q_NULLPTR));
        inviteLabel->setText(QApplication::translate("InviteListDialog", "TextLabel", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("InviteListDialog", "Cancel", Q_NULLPTR));
        inviteButton->setText(QApplication::translate("InviteListDialog", "Invite", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class InviteListDialog: public Ui_InviteListDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVITE_2D_LIST_2D_DIALOG_H
