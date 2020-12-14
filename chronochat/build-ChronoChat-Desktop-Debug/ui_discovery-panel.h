/********************************************************************************
** Form generated from reading UI file 'discovery-panel.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISCOVERY_2D_PANEL_H
#define UI_DISCOVERY_2D_PANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DiscoveryPanel
{
public:
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *DiscoveryPanelLayout;
    QListView *ChatroomList;
    QTabWidget *ChatroomInfo;
    QWidget *General;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *NameSpaceLabel;
    QLineEdit *NameSpaceData;
    QHBoxLayout *horizontalLayout_2;
    QLabel *NameLabel;
    QLineEdit *NameData;
    QHBoxLayout *horizontalLayout_3;
    QLabel *TrustModel;
    QLineEdit *TrustModelData;
    QVBoxLayout *verticalLayout;
    QListView *RosterList;
    QLabel *InChatroomWarning;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *join;
    QPushButton *requestInvitation;

    void setupUi(QDialog *DiscoveryPanel)
    {
        if (DiscoveryPanel->objectName().isEmpty())
            DiscoveryPanel->setObjectName(QStringLiteral("DiscoveryPanel"));
        DiscoveryPanel->setEnabled(true);
        DiscoveryPanel->resize(600, 480);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DiscoveryPanel->sizePolicy().hasHeightForWidth());
        DiscoveryPanel->setSizePolicy(sizePolicy);
        horizontalLayout_5 = new QHBoxLayout(DiscoveryPanel);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        DiscoveryPanelLayout = new QHBoxLayout();
        DiscoveryPanelLayout->setSpacing(10);
        DiscoveryPanelLayout->setObjectName(QStringLiteral("DiscoveryPanelLayout"));
        DiscoveryPanelLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        ChatroomList = new QListView(DiscoveryPanel);
        ChatroomList->setObjectName(QStringLiteral("ChatroomList"));
        ChatroomList->setMaximumSize(QSize(180, 16777215));
        ChatroomList->setContextMenuPolicy(Qt::PreventContextMenu);
        ChatroomList->setAcceptDrops(false);
        ChatroomList->setEditTriggers(QAbstractItemView::NoEditTriggers);

        DiscoveryPanelLayout->addWidget(ChatroomList);

        ChatroomInfo = new QTabWidget(DiscoveryPanel);
        ChatroomInfo->setObjectName(QStringLiteral("ChatroomInfo"));
        General = new QWidget();
        General->setObjectName(QStringLiteral("General"));
        horizontalLayout_6 = new QHBoxLayout(General);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
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

        verticalLayout_2->addLayout(horizontalLayout);

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

        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        TrustModel = new QLabel(General);
        TrustModel->setObjectName(QStringLiteral("TrustModel"));
        TrustModel->setFont(font);

        horizontalLayout_3->addWidget(TrustModel);

        TrustModelData = new QLineEdit(General);
        TrustModelData->setObjectName(QStringLiteral("TrustModelData"));
        TrustModelData->setFont(font1);
        TrustModelData->setReadOnly(true);

        horizontalLayout_3->addWidget(TrustModelData);

        horizontalLayout_3->setStretch(0, 35);
        horizontalLayout_3->setStretch(1, 100);

        verticalLayout_2->addLayout(horizontalLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        RosterList = new QListView(General);
        RosterList->setObjectName(QStringLiteral("RosterList"));
        RosterList->setContextMenuPolicy(Qt::PreventContextMenu);
        RosterList->setAcceptDrops(false);
        RosterList->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout->addWidget(RosterList);

        InChatroomWarning = new QLabel(General);
        InChatroomWarning->setObjectName(QStringLiteral("InChatroomWarning"));
        InChatroomWarning->setEnabled(true);

        verticalLayout->addWidget(InChatroomWarning);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        join = new QPushButton(General);
        join->setObjectName(QStringLiteral("join"));
        join->setAutoDefault(false);

        horizontalLayout_4->addWidget(join);

        requestInvitation = new QPushButton(General);
        requestInvitation->setObjectName(QStringLiteral("requestInvitation"));
        requestInvitation->setAutoDefault(false);

        horizontalLayout_4->addWidget(requestInvitation);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_2->addLayout(verticalLayout);


        horizontalLayout_6->addLayout(verticalLayout_2);

        ChatroomInfo->addTab(General, QString());

        DiscoveryPanelLayout->addWidget(ChatroomInfo);

        DiscoveryPanelLayout->setStretch(0, 3);

        horizontalLayout_5->addLayout(DiscoveryPanelLayout);


        retranslateUi(DiscoveryPanel);

        ChatroomInfo->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DiscoveryPanel);
    } // setupUi

    void retranslateUi(QDialog *DiscoveryPanel)
    {
        DiscoveryPanel->setWindowTitle(QApplication::translate("DiscoveryPanel", "ChronoChat Discovery", Q_NULLPTR));
        NameSpaceLabel->setText(QApplication::translate("DiscoveryPanel", "Sync Prefix", Q_NULLPTR));
        NameLabel->setText(QApplication::translate("DiscoveryPanel", "Name", Q_NULLPTR));
        TrustModel->setText(QApplication::translate("DiscoveryPanel", "Trust Model", Q_NULLPTR));
        InChatroomWarning->setText(QString());
        join->setText(QApplication::translate("DiscoveryPanel", "Join", Q_NULLPTR));
        requestInvitation->setText(QApplication::translate("DiscoveryPanel", "Request Invitation", Q_NULLPTR));
        ChatroomInfo->setTabText(ChatroomInfo->indexOf(General), QApplication::translate("DiscoveryPanel", "General", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DiscoveryPanel: public Ui_DiscoveryPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISCOVERY_2D_PANEL_H
