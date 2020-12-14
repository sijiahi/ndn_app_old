/********************************************************************************
** Form generated from reading UI file 'chat-dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAT_2D_DIALOG_H
#define UI_CHAT_2D_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ChatDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *firstLayout;
    QVBoxLayout *infoLayout;
    QLabel *infoLabel;
    QHBoxLayout *prefixLayout;
    QLabel *prefixLabel;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *treeButtonLayout;
    QPushButton *trustTreeButton;
    QPushButton *syncTreeButton;
    QHBoxLayout *secondLayout;
    QListView *listView;
    QVBoxLayout *viewerLayout;
    QHBoxLayout *treeViewLayout;
    QGraphicsView *syncTreeViewer;
    QGraphicsView *trustTreeViewer;
    QTextEdit *textEdit;
    QHBoxLayout *thirdLayout;
    QPushButton *inviteButton;
    QHBoxLayout *inputLayout;
    QLabel *label;
    QLineEdit *lineEdit;

    void setupUi(QDialog *ChatDialog)
    {
        if (ChatDialog->objectName().isEmpty())
            ChatDialog->setObjectName(QStringLiteral("ChatDialog"));
        ChatDialog->resize(838, 600);
        verticalLayout_2 = new QVBoxLayout(ChatDialog);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        firstLayout = new QHBoxLayout();
        firstLayout->setObjectName(QStringLiteral("firstLayout"));
        infoLayout = new QVBoxLayout();
        infoLayout->setObjectName(QStringLiteral("infoLayout"));
        infoLabel = new QLabel(ChatDialog);
        infoLabel->setObjectName(QStringLiteral("infoLabel"));
        infoLabel->setFocusPolicy(Qt::NoFocus);

        infoLayout->addWidget(infoLabel);

        prefixLayout = new QHBoxLayout();
        prefixLayout->setObjectName(QStringLiteral("prefixLayout"));
        prefixLabel = new QLabel(ChatDialog);
        prefixLabel->setObjectName(QStringLiteral("prefixLabel"));
        prefixLabel->setFocusPolicy(Qt::NoFocus);

        prefixLayout->addWidget(prefixLabel);


        infoLayout->addLayout(prefixLayout);


        firstLayout->addLayout(infoLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        firstLayout->addItem(horizontalSpacer);

        treeButtonLayout = new QVBoxLayout();
        treeButtonLayout->setObjectName(QStringLiteral("treeButtonLayout"));
        trustTreeButton = new QPushButton(ChatDialog);
        trustTreeButton->setObjectName(QStringLiteral("trustTreeButton"));
        trustTreeButton->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(trustTreeButton->sizePolicy().hasHeightForWidth());
        trustTreeButton->setSizePolicy(sizePolicy);
        trustTreeButton->setMinimumSize(QSize(0, 0));
        trustTreeButton->setMaximumSize(QSize(200, 16777215));
        trustTreeButton->setAutoDefault(false);

        treeButtonLayout->addWidget(trustTreeButton);

        syncTreeButton = new QPushButton(ChatDialog);
        syncTreeButton->setObjectName(QStringLiteral("syncTreeButton"));
        syncTreeButton->setEnabled(false);
        sizePolicy.setHeightForWidth(syncTreeButton->sizePolicy().hasHeightForWidth());
        syncTreeButton->setSizePolicy(sizePolicy);
        syncTreeButton->setMinimumSize(QSize(0, 0));
        syncTreeButton->setMaximumSize(QSize(200, 16777215));
        syncTreeButton->setFocusPolicy(Qt::NoFocus);
        syncTreeButton->setAutoDefault(false);

        treeButtonLayout->addWidget(syncTreeButton);


        firstLayout->addLayout(treeButtonLayout);


        verticalLayout_2->addLayout(firstLayout);

        secondLayout = new QHBoxLayout();
        secondLayout->setObjectName(QStringLiteral("secondLayout"));
        secondLayout->setContentsMargins(5, -1, -1, -1);
        listView = new QListView(ChatDialog);
        listView->setObjectName(QStringLiteral("listView"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(listView->sizePolicy().hasHeightForWidth());
        listView->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        listView->setFont(font);
        listView->setFocusPolicy(Qt::NoFocus);
        listView->setStyleSheet(QLatin1String("color: darkGreen;\n"
"background: #F0F0F0;"));
        listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listView->setProperty("showDropIndicator", QVariant(false));
        listView->setSelectionMode(QAbstractItemView::NoSelection);

        secondLayout->addWidget(listView);

        viewerLayout = new QVBoxLayout();
        viewerLayout->setObjectName(QStringLiteral("viewerLayout"));
        treeViewLayout = new QHBoxLayout();
        treeViewLayout->setObjectName(QStringLiteral("treeViewLayout"));
        syncTreeViewer = new QGraphicsView(ChatDialog);
        syncTreeViewer->setObjectName(QStringLiteral("syncTreeViewer"));
        syncTreeViewer->setFocusPolicy(Qt::NoFocus);

        treeViewLayout->addWidget(syncTreeViewer);

        trustTreeViewer = new QGraphicsView(ChatDialog);
        trustTreeViewer->setObjectName(QStringLiteral("trustTreeViewer"));
        trustTreeViewer->setFocusPolicy(Qt::NoFocus);

        treeViewLayout->addWidget(trustTreeViewer);


        viewerLayout->addLayout(treeViewLayout);

        textEdit = new QTextEdit(ChatDialog);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setFocusPolicy(Qt::ClickFocus);
        textEdit->setReadOnly(true);

        viewerLayout->addWidget(textEdit);


        secondLayout->addLayout(viewerLayout);

        secondLayout->setStretch(0, 1);
        secondLayout->setStretch(1, 6);

        verticalLayout_2->addLayout(secondLayout);

        thirdLayout = new QHBoxLayout();
        thirdLayout->setSpacing(10);
        thirdLayout->setObjectName(QStringLiteral("thirdLayout"));
        thirdLayout->setContentsMargins(0, -1, -1, -1);
        inviteButton = new QPushButton(ChatDialog);
        inviteButton->setObjectName(QStringLiteral("inviteButton"));
        inviteButton->setEnabled(false);
        sizePolicy.setHeightForWidth(inviteButton->sizePolicy().hasHeightForWidth());
        inviteButton->setSizePolicy(sizePolicy);
        inviteButton->setMinimumSize(QSize(0, 0));
        inviteButton->setAutoDefault(false);

        thirdLayout->addWidget(inviteButton);

        inputLayout = new QHBoxLayout();
        inputLayout->setObjectName(QStringLiteral("inputLayout"));
        label = new QLabel(ChatDialog);
        label->setObjectName(QStringLiteral("label"));

        inputLayout->addWidget(label);

        lineEdit = new QLineEdit(ChatDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        inputLayout->addWidget(lineEdit);


        thirdLayout->addLayout(inputLayout);

        thirdLayout->setStretch(0, 1);
        thirdLayout->setStretch(1, 6);

        verticalLayout_2->addLayout(thirdLayout);


        retranslateUi(ChatDialog);

        QMetaObject::connectSlotsByName(ChatDialog);
    } // setupUi

    void retranslateUi(QDialog *ChatDialog)
    {
        ChatDialog->setWindowTitle(QApplication::translate("ChatDialog", "ChronoChat -- Powered By ChronoSync", Q_NULLPTR));
        trustTreeButton->setText(QApplication::translate("ChatDialog", "Show Trust Tree", Q_NULLPTR));
        syncTreeButton->setText(QApplication::translate("ChatDialog", "Show ChronoSync Tree", Q_NULLPTR));
        inviteButton->setText(QApplication::translate("ChatDialog", "Invite", Q_NULLPTR));
        label->setText(QApplication::translate("ChatDialog", "Message:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ChatDialog: public Ui_ChatDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_2D_DIALOG_H
