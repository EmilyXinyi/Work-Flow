#ifndef NURSE_H
#define NURSE_H

#include "worker.h"
#include <string>

class Nurse : public Worker {
public:
    Nurse(std::string name);
    bool isCorrectAppointment(AppointmentTypes type) override;
};


#endif //NURSE_H
