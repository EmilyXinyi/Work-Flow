#include "update_form.h"
#include "ui_update_form.h"
#include "update.h"
#include "appointment.h"
#include <boost/date_time/posix_time/posix_time.hpp>

UpdateForm::UpdateForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdateForm)
{
    ui->setupUi(this);
}

UpdateForm::~UpdateForm()
{
    delete ui;
}

void UpdateForm::setFilename(std::string filename) {
    this->filename = filename;
}

void UpdateForm::on_okButton_clicked()
{
    std::string name = ui->nameEdit->text().toStdString();
    std::string sType = ui->typeComboBox->currentText().toStdString();
    AppointmentTypes type = stringToType(sType);
    std::string time = ui->timeEdit->dateTime().toString("yyyy-MM-dd hh:mm").toStdString();
    Appointment apt = Appointment(type, time, name);
    updateJson(apt, filename);
    close();
}

void UpdateForm::on_cancelButton_clicked()
{
    close();
}
