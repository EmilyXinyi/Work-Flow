#ifndef WORKER_H
#define WORKER_H

#include <string>
#include <vector>
#include <iostream>
#include <boost/date_time/posix_time/posix_time.hpp>
#include "appointment.h"

class Worker {
private:
    const boost::posix_time::time_duration SHIFT_START = boost::posix_time::hours(6); // 6 AM
    const boost::posix_time::time_duration SHIFT_END   = boost::posix_time::hours(18); // 6 PM
    const boost::posix_time::time_duration BREAK       = boost::posix_time::minutes(15); // 15 minutes between appointments
    std::string name;
    std::vector<Appointment> schedule;
public:
    explicit Worker(std::string name);
    std::string getName();
    std::vector<Appointment> getSchedule();
    boost::posix_time::time_duration getAvailableTime();
    int getWorkingMinutes();
    void addAppointment(Appointment appointment);
    friend std::ostream& operator<<(std::ostream& os, const Worker& worker);
};

#endif //WORKER_H
