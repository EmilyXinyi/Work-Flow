#ifndef SCHEDULE_TABS_H
#define SCHEDULE_TABS_H

#include <QDialog>
#include "worker.h"

namespace Ui {
class ScheduleTabs;
}

class ScheduleTabs : public QDialog
{
    Q_OBJECT

public:
    explicit ScheduleTabs(QWidget *parent = nullptr);
    ~ScheduleTabs();
    void setData(std::vector<Worker*> workers);

private slots:
    void on_pushButton_clicked();

private:
    Ui::ScheduleTabs *ui;
};

class WorkerTab : public QWidget {
    Q_OBJECT

public:
    explicit WorkerTab(const Worker* worker, QWidget *parent = nullptr);
    std::string getName();
private:
    std::string workerName;
};

#endif // SCHEDULE_TABS_H
