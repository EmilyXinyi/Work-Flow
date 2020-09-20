#ifndef SCHEDULE_TABLE_H
#define SCHEDULE_TABLE_H

#include <QDialog>
#include <QTableWidget>
#include <QStringList>
#include <vector>
#include <worker.h>
#include <boost/date_time/posix_time/posix_time.hpp>

namespace Ui {
class ScheduleTable;
}

class ScheduleTable : public QDialog
{
    Q_OBJECT

public:
    explicit ScheduleTable(QWidget *parent = nullptr);
    ~ScheduleTable();
    void setData(const std::vector<Worker*>& workers);

private:
    Ui::ScheduleTable *ui;
    QTableWidget* tableWidget;
    QStringList labels;
    const boost::posix_time::time_duration shiftStart = boost::posix_time::hours(8);

    const int rows = 126; // 10 hours + 30 mins per 5 mins
    const int mins = 5;
    const float mins_f = 5.0;
};

#endif // SCHEDULE_TABLE_H
