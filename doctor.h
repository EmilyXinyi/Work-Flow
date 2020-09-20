#ifndef DOCTOR_H
#define DOCTOR_H

#include "worker.h"
#include <string>

class Doctor : public Worker {
public:
    Doctor(std::string name);
    bool isCorrectAppointment(AppointmentTypes type) override;
};


#endif //DOCTOR_H
