#include "worker.h"

Worker::Worker(std::string name) : name(name) {
}

std::string Worker::getName() const {
    return name;
}

std::vector<Appointment> Worker::getSchedule() const {
    return schedule;
}

boost::posix_time::time_duration Worker::getShiftStart() {
    return SHIFT_START;
}

boost::posix_time::time_duration Worker::getAvailableTime() {
    if (schedule.empty()) {
        return SHIFT_START;
    }
    return schedule.back().getTimeOfDayEnd() + BREAK;
}


void Worker::addAppointment(Appointment appointment) {
    schedule.push_back(appointment);
}

int Worker::getWorkingMinutes() const {
    int mins = 0;
    for (auto& appointment : schedule) {
        mins += appointment.getLength().minutes();
    }
    return mins;
}

std::ostream& operator<<(std::ostream& os, const Worker& worker) {
    os << worker.name << std::endl;
    for (auto& appointment : worker.schedule) {
        os << appointment;
    }
    return os;
}

bool Worker::operator<(const Worker& rhs) {
    return this->getWorkingMinutes() < rhs.getWorkingMinutes();
}

