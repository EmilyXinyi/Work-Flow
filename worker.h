#ifndef WORKER_H
#define WORKER_H

#include <string>
#include <vector>
#include <iostream>
#include <boost/date_time/posix_time/posix_time.hpp>
#include "appointment.h"

class Worker {
protected:
    const boost::posix_time::time_duration SHIFT_START = boost::posix_time::hours(8); // 8 AM
    const boost::posix_time::time_duration SHIFT_END   = boost::posix_time::hours(18) + boost::posix_time::minutes(30); // 5:30 PM
    const boost::posix_time::time_duration BREAK       = boost::posix_time::minutes(5); // 5 minutes between appointments
    std::string name;
    std::vector<Appointment> schedule;
public:
    explicit Worker(std::string name);
    std::string getName() const;
    std::vector<Appointment> getSchedule() const;
    boost::posix_time::time_duration getShiftStart() const;
    boost::posix_time::time_duration getAvailableTime() const;
    int getWorkingMinutes() const;
    void addAppointment(Appointment appointment);
    virtual bool isCorrectAppointment(AppointmentTypes type) = 0;
    bool operator<(const Worker& rhs);
    friend std::ostream& operator<<(std::ostream& os, const Worker& worker);
};

#endif //WORKER_H
