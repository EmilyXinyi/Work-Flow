#include "schedule_tabs.h"
#include "ui_schedule_tabs.h"
#include <QLabel>
#include <string>
#include <sstream>
#include "appointment.h"

ScheduleTabs::ScheduleTabs(QWidget *parent) :
    QDialog (parent),
    ui(new Ui::ScheduleTabs)
{
    ui->setupUi(this);
}

ScheduleTabs::~ScheduleTabs()
{
    delete ui;
}

void ScheduleTabs::setData(std::vector<Worker*> workers) {
    for (auto worker : workers) {
        WorkerTab* tab = new WorkerTab(worker, this);
        ui->tabWidget->addTab(tab, tab->getName().c_str());
    }
}

void ScheduleTabs::on_pushButton_clicked()
{
    close();
}

WorkerTab::WorkerTab(const Worker* worker, QWidget *parent) : QWidget(parent) {
    workerName = worker->getName();

    QVBoxLayout* mainLayout = new QVBoxLayout;

    for (auto& appointment : worker->getSchedule()) {
        QLabel* patientNameLabel = new QLabel(tr("Patient Name"));
        QLabel* patientName      = new QLabel(appointment.getPatientName().c_str());
        patientName->setFrameStyle(QFrame::Panel | QFrame::Sunken);
        mainLayout->addWidget(patientNameLabel);
        mainLayout->addWidget(patientName);

        QLabel* typeLabel = new QLabel("Appointment Type");
        QLabel* type      = new QLabel(AppointmentTypesString[appointment.getType()].c_str());
        type->setFrameStyle(QFrame::Panel | QFrame::Sunken);
        mainLayout->addWidget(typeLabel);
        mainLayout->addWidget(type);

        std::stringstream ss;
        ss << appointment.getTimeStart() << "-" << appointment.getTimeOfDayEnd();
        QLabel* timeLabel = new QLabel(tr("Time"));
        QLabel* time      = new QLabel(ss.str().c_str());
        time->setFrameStyle(QFrame::Panel | QFrame::Sunken);
        mainLayout->addWidget(timeLabel);
        mainLayout->addWidget(time);
    }

    mainLayout->addStretch(1);
    setLayout(mainLayout);
}

std::string WorkerTab::getName() {
    return workerName;
}
