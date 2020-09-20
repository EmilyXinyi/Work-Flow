#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <string>
#include <chrono>
#include <boost/date_time/posix_time/posix_time.hpp>

enum AppointmentTypes {
    General,
    Flu,
    Bloodwork
};

const std::string AppointmentTypesString[] = {
        "General Appointment",
        "Flu Shot",
        "Blood Work"
};

AppointmentTypes stringToType(std::string str);

class Appointment {
private:
    AppointmentTypes type;
    boost::posix_time::time_period period = boost::posix_time::time_period(boost::posix_time::ptime(), boost::posix_time::ptime());
    std::string patientName;
public:
    Appointment(AppointmentTypes type, std::string time, std::string name);
    AppointmentTypes getType();
    std::string getTypeString();
    boost::posix_time::ptime getTimeStart();
    boost::posix_time::ptime getTimeEnd();
    boost::gregorian::date getDateBegin();
    boost::gregorian::date getDateEnd();
    boost::posix_time::time_duration getTimeOfDayStart();
    boost::posix_time::time_duration getTimeOfDayEnd();
    boost::posix_time::time_duration getLength() const;
    friend std::ostream& operator<<(std::ostream& os, const Appointment& appointment);
};

#endif //APPOINTMENT_H
