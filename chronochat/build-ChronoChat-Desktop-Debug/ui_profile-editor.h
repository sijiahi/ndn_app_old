/********************************************************************************
** Form generated from reading UI file 'profile-editor.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFILE_2D_EDITOR_H
#define UI_PROFILE_2D_EDITOR_H

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
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ProfileEditor
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *profileEditorLayout;
    QHBoxLayout *identityLayout;
    QLabel *identityLabel;
    QLineEdit *identityInput;
    QTableView *profileTable;
    QHBoxLayout *buttonLayout;
    QPushButton *addRowButton;
    QPushButton *deleteRowButton;
    QPushButton *okButton;

    void setupUi(QDialog *ProfileEditor)
    {
        if (ProfileEditor->objectName().isEmpty())
            ProfileEditor->setObjectName(QStringLiteral("ProfileEditor"));
        ProfileEditor->resize(400, 500);
        verticalLayout = new QVBoxLayout(ProfileEditor);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        profileEditorLayout = new QVBoxLayout();
        profileEditorLayout->setObjectName(QStringLiteral("profileEditorLayout"));
        identityLayout = new QHBoxLayout();
        identityLayout->setObjectName(QStringLiteral("identityLayout"));
        identityLabel = new QLabel(ProfileEditor);
        identityLabel->setObjectName(QStringLiteral("identityLabel"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        identityLabel->setFont(font);

        identityLayout->addWidget(identityLabel);

        identityInput = new QLineEdit(ProfileEditor);
        identityInput->setObjectName(QStringLiteral("identityInput"));
        identityInput->setReadOnly(true);

        identityLayout->addWidget(identityInput);

        identityLayout->setStretch(0, 2);
        identityLayout->setStretch(1, 4);

        profileEditorLayout->addLayout(identityLayout);

        profileTable = new QTableView(ProfileEditor);
        profileTable->setObjectName(QStringLiteral("profileTable"));
        profileTable->horizontalHeader()->setCascadingSectionResizes(false);
        profileTable->horizontalHeader()->setDefaultSectionSize(100);
        profileTable->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        profileTable->horizontalHeader()->setStretchLastSection(true);
        profileTable->verticalHeader()->setVisible(true);

        profileEditorLayout->addWidget(profileTable);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName(QStringLiteral("buttonLayout"));
        addRowButton = new QPushButton(ProfileEditor);
        addRowButton->setObjectName(QStringLiteral("addRowButton"));
        addRowButton->setAutoDefault(false);

        buttonLayout->addWidget(addRowButton);

        deleteRowButton = new QPushButton(ProfileEditor);
        deleteRowButton->setObjectName(QStringLiteral("deleteRowButton"));
        deleteRowButton->setAutoDefault(false);

        buttonLayout->addWidget(deleteRowButton);

        okButton = new QPushButton(ProfileEditor);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setAutoDefault(false);

        buttonLayout->addWidget(okButton);

        buttonLayout->setStretch(0, 1);
        buttonLayout->setStretch(1, 1);
        buttonLayout->setStretch(2, 1);

        profileEditorLayout->addLayout(buttonLayout);

        profileEditorLayout->setStretch(1, 20);
        profileEditorLayout->setStretch(2, 1);

        verticalLayout->addLayout(profileEditorLayout);


        retranslateUi(ProfileEditor);

        QMetaObject::connectSlotsByName(ProfileEditor);
    } // setupUi

    void retranslateUi(QDialog *ProfileEditor)
    {
        ProfileEditor->setWindowTitle(QApplication::translate("ProfileEditor", "Profile Editor", Q_NULLPTR));
        identityLabel->setText(QApplication::translate("ProfileEditor", "Current identity:", Q_NULLPTR));
        addRowButton->setText(QApplication::translate("ProfileEditor", "Add", Q_NULLPTR));
        deleteRowButton->setText(QApplication::translate("ProfileEditor", "Delete", Q_NULLPTR));
        okButton->setText(QApplication::translate("ProfileEditor", "OK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ProfileEditor: public Ui_ProfileEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFILE_2D_EDITOR_H
