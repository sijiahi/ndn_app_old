/********************************************************************************
** Form generated from reading UI file 'start-chat-dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_START_2D_CHAT_2D_DIALOG_H
#define UI_START_2D_CHAT_2D_DIALOG_H

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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartChatDialog
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *chatroomLineLayout;
    QLabel *introLabel;
    QLineEdit *chatroomInput;
    QWidget *layoutWidget1;
    QHBoxLayout *buttonLayout;
    QPushButton *cancelButton;
    QPushButton *okButton;

    void setupUi(QDialog *StartChatDialog)
    {
        if (StartChatDialog->objectName().isEmpty())
            StartChatDialog->setObjectName(QStringLiteral("StartChatDialog"));
        StartChatDialog->resize(300, 100);
        layoutWidget = new QWidget(StartChatDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 281, 23));
        chatroomLineLayout = new QHBoxLayout(layoutWidget);
        chatroomLineLayout->setObjectName(QStringLiteral("chatroomLineLayout"));
        chatroomLineLayout->setContentsMargins(0, 0, 0, 0);
        introLabel = new QLabel(layoutWidget);
        introLabel->setObjectName(QStringLiteral("introLabel"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        introLabel->setFont(font);

        chatroomLineLayout->addWidget(introLabel);

        chatroomInput = new QLineEdit(layoutWidget);
        chatroomInput->setObjectName(QStringLiteral("chatroomInput"));

        chatroomLineLayout->addWidget(chatroomInput);

        layoutWidget1 = new QWidget(StartChatDialog);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 60, 281, 32));
        buttonLayout = new QHBoxLayout(layoutWidget1);
#ifndef Q_OS_MAC
        buttonLayout->setSpacing(-1);
#endif
        buttonLayout->setObjectName(QStringLiteral("buttonLayout"));
        buttonLayout->setContentsMargins(0, 0, 0, 0);
        cancelButton = new QPushButton(layoutWidget1);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setAutoDefault(false);

        buttonLayout->addWidget(cancelButton);

        okButton = new QPushButton(layoutWidget1);
        okButton->setObjectName(QStringLiteral("okButton"));

        buttonLayout->addWidget(okButton);

        buttonLayout->setStretch(0, 1);
        buttonLayout->setStretch(1, 1);

        retranslateUi(StartChatDialog);

        QMetaObject::connectSlotsByName(StartChatDialog);
    } // setupUi

    void retranslateUi(QDialog *StartChatDialog)
    {
        StartChatDialog->setWindowTitle(QApplication::translate("StartChatDialog", "Dialog", Q_NULLPTR));
        introLabel->setText(QApplication::translate("StartChatDialog", "Chatroom Name:", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("StartChatDialog", "Cancel", Q_NULLPTR));
        okButton->setText(QApplication::translate("StartChatDialog", "OK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class StartChatDialog: public Ui_StartChatDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_START_2D_CHAT_2D_DIALOG_H
