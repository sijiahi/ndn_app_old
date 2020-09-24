#ifndef NFD_MANEGEMENT_H
#define NFD_MANEGEMENT_H

#include <QDialog>

namespace Ui {
class Nfd_Manegement;
}

class Nfd_Manegement : public QDialog
{
    Q_OBJECT

public:
    explicit Nfd_Manegement(QWidget *parent = 0);
    ~Nfd_Manegement();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Nfd_Manegement *ui;
};

#endif // NFD_MANEGEMENT_H
