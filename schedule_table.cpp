#include "schedule_table.h"
#include "ui_schedule_table.h"
#include <QTableWidgetItem>
#include <QColor>
#include <utility>
#include "appointment.h"

ScheduleTable::ScheduleTable(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ScheduleTable)
{
    ui->setupUi(this);
    tableWidget = ui->tableWidget;
}

ScheduleTable::~ScheduleTable()
{
    delete ui;
}

void ScheduleTable::setData(const std::vector<Worker*>& workers) {
    tableWidget->setColumnCount(workers.size());

    bool shades[rows][workers.size()];

    std::cout << workers.size() << std::endl;

    for (int i = 0; i < rows; i++) {
//        std::vector<bool> temp;
        for (int j = 0; j < workers.size(); j++) {
//            temp.push_back(false);
            shades[i][j] = false;
        }
//        shades.push_back(temp);
    }

    for (int i = 0; i < workers.size(); i++) {
        labels << workers[i]->getName().c_str();

        for (auto& appointment : workers[i]->getSchedule()) {
            auto start = appointment.getTimeOfDayStart();
            auto end   = appointment.getTimeOfDayEnd();

            auto startSec = (start - shiftStart).total_seconds();
            auto endSec   = (end - shiftStart).total_seconds();

            int startIdx = floorf(startSec / (mins_f * 60));
            int endIdx   = ceilf(endSec / (mins_f * 60));

            std::cout << startIdx << "," << endIdx << std::endl;

            for (int j = startIdx; j < endIdx; j++) {
                shades[j][i] = true;
            }
        }
    }

    tableWidget->setHorizontalHeaderLabels(labels);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < workers.size(); j++) {
            QTableWidgetItem* qtwi = new QTableWidgetItem("");

            if (shades[i][j]) {
                qtwi->setBackground(QColor(34, 49, 63));
                std::cout << i << "," << j << std::endl;
            }

            tableWidget->setItem(i, j, qtwi);
        }
    }
}
