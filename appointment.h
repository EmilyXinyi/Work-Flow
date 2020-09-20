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
    AppointmentTypes getType() const;
    std::string getTypeString() const;
    boost::posix_time::ptime getTimeStart() const;
    boost::posix_time::ptime getTimeEnd() const;
    boost::gregorian::date getDateBegin() const;
    boost::gregorian::date getDateEnd() const;
    boost::posix_time::time_duration getTimeOfDayStart() const;
    boost::posix_time::time_duration getTimeOfDayEnd() const;
    boost::posix_time::time_duration getLength() const;
    std::string getPatientName() const;
    friend std::ostream& operator<<(std::ostream& os, const Appointment& appointment);
};

#endif //APPOINTMENT_H
