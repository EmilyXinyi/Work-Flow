#ifndef SCHEDULE_TABLE_H
#define SCHEDULE_TABLE_H

#include <QWidget>
#include <QTableWidget>
#include <QStringList>
#include <vector>
#include <worker.h>

namespace Ui {
class ScheduleTable;
}

class ScheduleTable : public QWidget
{
    Q_OBJECT

public:
    explicit ScheduleTable(QWidget *parent = nullptr);
    ~ScheduleTable();
    void setData(std::vector<Worker*> workers);

private:
    Ui::ScheduleTable *ui;
    QTableWidget* tableWidget;
    QStringList labels;
};

#endif // SCHEDULE_TABLE_H
