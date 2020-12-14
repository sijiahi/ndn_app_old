/********************************************************************************
** Form generated from reading UI file 'add-contact-panel.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_2D_CONTACT_2D_PANEL_H
#define UI_ADD_2D_CONTACT_2D_PANEL_H

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
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddContactPanel
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *addContactPanelLayout;
    QHBoxLayout *contactSearchLayout;
    QLabel *contactLabel;
    QLineEdit *contactInput;
    QPushButton *searchButton;
    QTableWidget *infoView;
    QHBoxLayout *buttonLayout;
    QPushButton *cancelButton;
    QPushButton *addButton;

    void setupUi(QDialog *AddContactPanel)
    {
        if (AddContactPanel->objectName().isEmpty())
            AddContactPanel->setObjectName(QStringLiteral("AddContactPanel"));
        AddContactPanel->resize(400, 500);
        verticalLayout = new QVBoxLayout(AddContactPanel);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        addContactPanelLayout = new QVBoxLayout();
        addContactPanelLayout->setSpacing(10);
        addContactPanelLayout->setObjectName(QStringLiteral("addContactPanelLayout"));
        contactSearchLayout = new QHBoxLayout();
        contactSearchLayout->setObjectName(QStringLiteral("contactSearchLayout"));
        contactLabel = new QLabel(AddContactPanel);
        contactLabel->setObjectName(QStringLiteral("contactLabel"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        contactLabel->setFont(font);
        contactLabel->setTextFormat(Qt::AutoText);

        contactSearchLayout->addWidget(contactLabel);

        contactInput = new QLineEdit(AddContactPanel);
        contactInput->setObjectName(QStringLiteral("contactInput"));

        contactSearchLayout->addWidget(contactInput);

        searchButton = new QPushButton(AddContactPanel);
        searchButton->setObjectName(QStringLiteral("searchButton"));
        searchButton->setAutoDefault(false);

        contactSearchLayout->addWidget(searchButton);

        contactSearchLayout->setStretch(0, 3);
        contactSearchLayout->setStretch(1, 5);
        contactSearchLayout->setStretch(2, 2);

        addContactPanelLayout->addLayout(contactSearchLayout);

        infoView = new QTableWidget(AddContactPanel);
        infoView->setObjectName(QStringLiteral("infoView"));
        infoView->horizontalHeader()->setStretchLastSection(true);

        addContactPanelLayout->addWidget(infoView);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName(QStringLiteral("buttonLayout"));
        cancelButton = new QPushButton(AddContactPanel);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setAutoDefault(false);

        buttonLayout->addWidget(cancelButton);

        addButton = new QPushButton(AddContactPanel);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setAutoDefault(false);

        buttonLayout->addWidget(addButton);


        addContactPanelLayout->addLayout(buttonLayout);

        addContactPanelLayout->setStretch(0, 1);
        addContactPanelLayout->setStretch(1, 30);
        addContactPanelLayout->setStretch(2, 1);

        verticalLayout->addLayout(addContactPanelLayout);


        retranslateUi(AddContactPanel);

        QMetaObject::connectSlotsByName(AddContactPanel);
    } // setupUi

    void retranslateUi(QDialog *AddContactPanel)
    {
        AddContactPanel->setWindowTitle(QApplication::translate("AddContactPanel", "Add Contact", Q_NULLPTR));
        contactLabel->setText(QApplication::translate("AddContactPanel", "Contact identity:", Q_NULLPTR));
        searchButton->setText(QApplication::translate("AddContactPanel", "Fetch", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("AddContactPanel", "Cancel", Q_NULLPTR));
        addButton->setText(QApplication::translate("AddContactPanel", "Add", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AddContactPanel: public Ui_AddContactPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_2D_CONTACT_2D_PANEL_H
