#ifndef REPO_PUTFILE_H
#define REPO_PUTFILE_H

#include <QObject>

class repo_putfile : public QObject
{
    Q_OBJECT
public:
    explicit repo_putfile(QObject *parent = nullptr);

signals:

public slots:
};

#endif // REPO_PUTFILE_H