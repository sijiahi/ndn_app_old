/********************************************************************************
** Form generated from reading UI file 'browse-contact-dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BROWSE_2D_CONTACT_2D_DIALOG_H
#define UI_BROWSE_2D_CONTACT_2D_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BrowseContactDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QListView *ContactList;
    QTableWidget *InfoTable;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *AddButton;
    QPushButton *DirectAddButton;

    void setupUi(QDialog *BrowseContactDialog)
    {
        if (BrowseContactDialog->objectName().isEmpty())
            BrowseContactDialog->setObjectName(QStringLiteral("BrowseContactDialog"));
        BrowseContactDialog->resize(600, 480);
        verticalLayout_2 = new QVBoxLayout(BrowseContactDialog);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        ContactList = new QListView(BrowseContactDialog);
        ContactList->setObjectName(QStringLiteral("ContactList"));
        ContactList->setContextMenuPolicy(Qt::CustomContextMenu);
        ContactList->setAcceptDrops(false);
        ContactList->setEditTriggers(QAbstractItemView::NoEditTriggers);

        horizontalLayout->addWidget(ContactList);

        InfoTable = new QTableWidget(BrowseContactDialog);
        InfoTable->setObjectName(QStringLiteral("InfoTable"));
        InfoTable->horizontalHeader()->setStretchLastSection(true);

        horizontalLayout->addWidget(InfoTable);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 3);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        AddButton = new QPushButton(BrowseContactDialog);
        AddButton->setObjectName(QStringLiteral("AddButton"));
        AddButton->setAutoDefault(false);

        horizontalLayout_2->addWidget(AddButton);

        DirectAddButton = new QPushButton(BrowseContactDialog);
        DirectAddButton->setObjectName(QStringLiteral("DirectAddButton"));
        DirectAddButton->setAutoDefault(false);

        horizontalLayout_2->addWidget(DirectAddButton);

        horizontalLayout_2->setStretch(0, 1);

        verticalLayout->addLayout(horizontalLayout_2);

        verticalLayout->setStretch(0, 20);
        verticalLayout->setStretch(1, 1);

        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(BrowseContactDialog);

        QMetaObject::connectSlotsByName(BrowseContactDialog);
    } // setupUi

    void retranslateUi(QDialog *BrowseContactDialog)
    {
        BrowseContactDialog->setWindowTitle(QApplication::translate("BrowseContactDialog", "BrowseContacts", Q_NULLPTR));
        AddButton->setText(QApplication::translate("BrowseContactDialog", "Add ", Q_NULLPTR));
        DirectAddButton->setText(QApplication::translate("BrowseContactDialog", "Direct Add", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BrowseContactDialog: public Ui_BrowseContactDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BROWSE_2D_CONTACT_2D_DIALOG_H
