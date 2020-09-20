#include "appointment.h"
#include <iostream>

using boost::gregorian::from_simple_string;
using boost::posix_time::time_from_string;
using boost::posix_time::time_period;

AppointmentTypes stringToType(std::string str) {
    if (str == "General") {
        return General;
    } else if (str == "Flu") {
        return Flu;
    } else if (str == "Bloodwork") {
        return Bloodwork;
    }
    return General;
}

Appointment::Appointment(AppointmentTypes type, std::string timeString, std::string name) :
    type(type),
    patientName(name) {
    int t = 0;
    if (type == General) {
        t = 20;
    } else if (type == Flu) {
        t = 30;
    } else if (type == Bloodwork) {
        t = 10;
    }
    this->period = time_period(time_from_string(timeString), boost::posix_time::minutes(t));
}

AppointmentTypes Appointment::getType() {
    return this->type;
}

std::string Appointment::getTypeString() {
    return AppointmentTypesString[this->type];
}

boost::posix_time::ptime Appointment::getTimeStart() {
    return this->period.begin();
}

boost::posix_time::ptime Appointment::getTimeEnd() {
    return this->period.end();
}

boost::gregorian::date Appointment::getDateBegin() {
    return this->period.begin().date();
}

boost::gregorian::date Appointment::getDateEnd() {
    return this->period.end().date();
}

boost::posix_time::time_duration Appointment::getTimeOfDayStart() {
    return this->period.begin().time_of_day();
}

boost::posix_time::time_duration Appointment::getTimeOfDayEnd() {
    return this->period.end().time_of_day();
}

boost::posix_time::time_duration Appointment::getLength() const {
    return this->period.length();
}

std::string Appointment::getPatientName() {
    return this->patientName;
}

std::ostream& operator<<(std::ostream& os, const Appointment& appointment) {
    os << appointment.period.begin() << "-" << appointment.period.end().time_of_day() << std::endl;
    os << "\tAppointment Type: " << AppointmentTypesString[appointment.type] << std::endl;
    os << "\tPatient: " << appointment.patientName << std::endl;
    return os;
}
