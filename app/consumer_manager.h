#ifndef CONSUMER_MANAGER_H
#define CONSUMER_MANAGER_H

#include <QWidget>

namespace Ui {
class Consumer_manager;
}

class Consumer_manager : public QWidget
{
    Q_OBJECT

public:
    explicit Consumer_manager(QWidget *parent = 0);
    ~Consumer_manager();

private:
    Ui::Consumer_manager *ui;
};

#endif // CONSUMER_MANAGER_H
