/********************************************************************************
** Form generated from reading UI file 'qferrers.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QFERRERS_H
#define UI_QFERRERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QFerrers
{
public:

    void setupUi(QWidget *QFerrers)
    {
        if (QFerrers->objectName().isEmpty())
            QFerrers->setObjectName(QString::fromUtf8("QFerrers"));
        QFerrers->resize(400, 300);

        retranslateUi(QFerrers);

        QMetaObject::connectSlotsByName(QFerrers);
    } // setupUi

    void retranslateUi(QWidget *QFerrers)
    {
        QFerrers->setWindowTitle(QApplication::translate("QFerrers", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QFerrers: public Ui_QFerrers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QFERRERS_H
