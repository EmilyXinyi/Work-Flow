#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QLabel>
#include <QHBoxLayout>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "appointment.h"
#include "worker.h"
#include "doctor.h"
#include "nurse.h"
#include "schedule.h"
#include "schedule_table.h"
#include "update.h"
#include "update_form.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_demoButton_clicked() {
    QString file_name = QFileDialog::getOpenFileName(this, "Open", "C://", "JSON (*.json)");
    if (file_name.size() > 0) {
        workers.clear();
        appointments.clear();

        filename = file_name.toStdString();

        std::ifstream jsonFile(filename);
        boost::property_tree::ptree pt;
        boost::property_tree::read_json(jsonFile, pt);

        const auto& jsonWorkers = pt.get_child("workers");
        const auto& jsonAppointments = pt.get_child("appointments");

        for (const auto& worker : jsonWorkers) {
            auto& child = worker.second;
            std::string role = child.get<std::string>("role");
            if (role == "Nurse") {
                workers.push_back(new Nurse(child.get<std::string>("name") ));
            } else if (role == "Doctor") {
                workers.push_back(new Doctor(child.get<std::string>("name") ));
            }
        }

        for (const auto& appointment : jsonAppointments) {
            auto& child = appointment.second;
            appointments.emplace_back(Appointment(
                stringToType(child.get<std::string>("type")),
                child.get<std::string>("time"),
                child.get<std::string>("patientName")
                )
            );
        }

        schedule(workers, appointments);
    }
}

void MainWindow::on_closeButton_clicked()
{
    close();
}

void MainWindow::on_timetableButton_clicked()
{
    if (appointments.size() !=0 && workers.size() != 0) {
        QDialog* scheduleDialog = new QDialog(this);
        QHBoxLayout* layout = new QHBoxLayout();
        ScheduleTable* table = new ScheduleTable(scheduleDialog);
        table->setData(workers);
        scheduleDialog->setLayout(layout);
        scheduleDialog->setMinimumSize(700, 500);
        layout->setStretch(1, 1);
        layout->addWidget(table);
        scheduleDialog->setModal(true);
        scheduleDialog->exec();
    }
}

void MainWindow::on_newAppointmentButton_clicked()
{
    if (filename.size() > 0) {
        UpdateForm* form = new UpdateForm(this);
        form->setFilename(filename);
        form->setModal(true);
        form->exec();
    }
}
