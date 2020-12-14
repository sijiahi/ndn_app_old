/********************************************************************************
** Form generated from reading UI file 'contact-panel.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTACT_2D_PANEL_H
#define UI_CONTACT_2D_PANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ContactPanel
{
public:
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *ContactPanelLayout;
    QListView *ContactList;
    QTabWidget *ContactInfo;
    QWidget *General;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_2;
    QGraphicsView *Avatar;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *NameSpaceLabel;
    QLineEdit *NameSpaceData;
    QHBoxLayout *horizontalLayout_2;
    QLabel *NameLabel;
    QLineEdit *NameData;
    QHBoxLayout *horizontalLayout_3;
    QLabel *InstitutionLabel;
    QLineEdit *InstitutionData;
    QSpacerItem *verticalSpacer;
    QWidget *TrustScope;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *isIntroducer;
    QTableView *trustScopeList;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *addScope;
    QPushButton *deleteScope;
    QPushButton *saveButton;
    QWidget *Endorse;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QTableView *endorseList;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer;
    QPushButton *endorseButton;

    void setupUi(QDialog *ContactPanel)
    {
        if (ContactPanel->objectName().isEmpty())
            ContactPanel->setObjectName(QStringLiteral("ContactPanel"));
        ContactPanel->setEnabled(true);
        ContactPanel->resize(600, 480);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ContactPanel->sizePolicy().hasHeightForWidth());
        ContactPanel->setSizePolicy(sizePolicy);
        horizontalLayout_5 = new QHBoxLayout(ContactPanel);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        ContactPanelLayout = new QHBoxLayout();
        ContactPanelLayout->setSpacing(10);
        ContactPanelLayout->setObjectName(QStringLiteral("ContactPanelLayout"));
        ContactPanelLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        ContactList = new QListView(ContactPanel);
        ContactList->setObjectName(QStringLiteral("ContactList"));
        ContactList->setContextMenuPolicy(Qt::CustomContextMenu);
        ContactList->setAcceptDrops(false);
        ContactList->setEditTriggers(QAbstractItemView::NoEditTriggers);

        ContactPanelLayout->addWidget(ContactList);

        ContactInfo = new QTabWidget(ContactPanel);
        ContactInfo->setObjectName(QStringLiteral("ContactInfo"));
        General = new QWidget();
        General->setObjectName(QStringLiteral("General"));
        verticalLayout_7 = new QVBoxLayout(General);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);

        Avatar = new QGraphicsView(General);
        Avatar->setObjectName(QStringLiteral("Avatar"));

        horizontalLayout_7->addWidget(Avatar);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_3);

        horizontalLayout_7->setStretch(0, 2);
        horizontalLayout_7->setStretch(1, 3);
        horizontalLayout_7->setStretch(2, 2);

        verticalLayout_6->addLayout(horizontalLayout_7);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
#ifndef Q_OS_MAC
        horizontalLayout->setSpacing(-1);
#endif
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        NameSpaceLabel = new QLabel(General);
        NameSpaceLabel->setObjectName(QStringLiteral("NameSpaceLabel"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        NameSpaceLabel->setFont(font);

        horizontalLayout->addWidget(NameSpaceLabel);

        NameSpaceData = new QLineEdit(General);
        NameSpaceData->setObjectName(QStringLiteral("NameSpaceData"));
        QFont font1;
        font1.setFamily(QStringLiteral("Lucida Grande"));
        NameSpaceData->setFont(font1);
        NameSpaceData->setReadOnly(true);

        horizontalLayout->addWidget(NameSpaceData);

        horizontalLayout->setStretch(0, 35);
        horizontalLayout->setStretch(1, 100);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        NameLabel = new QLabel(General);
        NameLabel->setObjectName(QStringLiteral("NameLabel"));
        NameLabel->setFont(font);

        horizontalLayout_2->addWidget(NameLabel);

        NameData = new QLineEdit(General);
        NameData->setObjectName(QStringLiteral("NameData"));
        NameData->setFont(font1);
        NameData->setReadOnly(true);

        horizontalLayout_2->addWidget(NameData);

        horizontalLayout_2->setStretch(0, 35);
        horizontalLayout_2->setStretch(1, 100);

        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        InstitutionLabel = new QLabel(General);
        InstitutionLabel->setObjectName(QStringLiteral("InstitutionLabel"));
        InstitutionLabel->setFont(font);

        horizontalLayout_3->addWidget(InstitutionLabel);

        InstitutionData = new QLineEdit(General);
        InstitutionData->setObjectName(QStringLiteral("InstitutionData"));
        InstitutionData->setFont(font1);
        InstitutionData->setReadOnly(true);

        horizontalLayout_3->addWidget(InstitutionData);

        horizontalLayout_3->setStretch(0, 35);
        horizontalLayout_3->setStretch(1, 100);

        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_6->addLayout(verticalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer);

        verticalLayout_6->setStretch(0, 2);
        verticalLayout_6->setStretch(1, 2);
        verticalLayout_6->setStretch(2, 1);

        verticalLayout_7->addLayout(verticalLayout_6);

        ContactInfo->addTab(General, QString());
        TrustScope = new QWidget();
        TrustScope->setObjectName(QStringLiteral("TrustScope"));
        verticalLayout_2 = new QVBoxLayout(TrustScope);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        isIntroducer = new QCheckBox(TrustScope);
        isIntroducer->setObjectName(QStringLiteral("isIntroducer"));

        verticalLayout_3->addWidget(isIntroducer);

        trustScopeList = new QTableView(TrustScope);
        trustScopeList->setObjectName(QStringLiteral("trustScopeList"));
        trustScopeList->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_3->addWidget(trustScopeList);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        addScope = new QPushButton(TrustScope);
        addScope->setObjectName(QStringLiteral("addScope"));
        addScope->setAutoDefault(false);

        horizontalLayout_4->addWidget(addScope);

        deleteScope = new QPushButton(TrustScope);
        deleteScope->setObjectName(QStringLiteral("deleteScope"));
        deleteScope->setAutoDefault(false);

        horizontalLayout_4->addWidget(deleteScope);

        saveButton = new QPushButton(TrustScope);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setAutoDefault(false);

        horizontalLayout_4->addWidget(saveButton);


        verticalLayout_3->addLayout(horizontalLayout_4);


        verticalLayout_2->addLayout(verticalLayout_3);

        ContactInfo->addTab(TrustScope, QString());
        Endorse = new QWidget();
        Endorse->setObjectName(QStringLiteral("Endorse"));
        verticalLayout_5 = new QVBoxLayout(Endorse);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        endorseList = new QTableView(Endorse);
        endorseList->setObjectName(QStringLiteral("endorseList"));
        endorseList->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_4->addWidget(endorseList);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        endorseButton = new QPushButton(Endorse);
        endorseButton->setObjectName(QStringLiteral("endorseButton"));
        endorseButton->setAutoDefault(false);

        horizontalLayout_6->addWidget(endorseButton);

        horizontalLayout_6->setStretch(0, 3);
        horizontalLayout_6->setStretch(1, 1);

        verticalLayout_4->addLayout(horizontalLayout_6);


        verticalLayout_5->addLayout(verticalLayout_4);

        ContactInfo->addTab(Endorse, QString());

        ContactPanelLayout->addWidget(ContactInfo);

        ContactPanelLayout->setStretch(0, 3);
        ContactPanelLayout->setStretch(1, 7);

        horizontalLayout_5->addLayout(ContactPanelLayout);


        retranslateUi(ContactPanel);

        ContactInfo->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ContactPanel);
    } // setupUi

    void retranslateUi(QDialog *ContactPanel)
    {
        ContactPanel->setWindowTitle(QApplication::translate("ContactPanel", "ChronoChat Contacts", Q_NULLPTR));
        NameSpaceLabel->setText(QApplication::translate("ContactPanel", "Name space", Q_NULLPTR));
        NameLabel->setText(QApplication::translate("ContactPanel", "Name", Q_NULLPTR));
        InstitutionLabel->setText(QApplication::translate("ContactPanel", "Institution   ", Q_NULLPTR));
        ContactInfo->setTabText(ContactInfo->indexOf(General), QApplication::translate("ContactPanel", "General", Q_NULLPTR));
        isIntroducer->setText(QApplication::translate("ContactPanel", "Set as introducer", Q_NULLPTR));
        addScope->setText(QApplication::translate("ContactPanel", "Add Scope", Q_NULLPTR));
        deleteScope->setText(QApplication::translate("ContactPanel", "Delete Scope", Q_NULLPTR));
        saveButton->setText(QApplication::translate("ContactPanel", "Save", Q_NULLPTR));
        ContactInfo->setTabText(ContactInfo->indexOf(TrustScope), QApplication::translate("ContactPanel", "Trust Scope", Q_NULLPTR));
        endorseButton->setText(QApplication::translate("ContactPanel", "Endorse", Q_NULLPTR));
        ContactInfo->setTabText(ContactInfo->indexOf(Endorse), QApplication::translate("ContactPanel", "Endorse", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ContactPanel: public Ui_ContactPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTACT_2D_PANEL_H
