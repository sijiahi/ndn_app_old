#ifndef MESSAGER_H
#define MESSAGER_H

#include <QDialog>

namespace Ui {
class Messager;
}

class Messager : public QDialog
{
    Q_OBJECT

public:
    explicit Messager(QWidget *parent = 0);
    ~Messager();

private:
    Ui::Messager *ui;
};

#endif // MESSAGER_H
