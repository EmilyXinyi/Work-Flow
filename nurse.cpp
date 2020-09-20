#include "nurse.h"

Nurse::Nurse(std::string name) : Worker(name) {
}

bool Nurse::isCorrectAppointment(AppointmentTypes type) {
    AppointmentTypes validTypes[2] = { Flu, Bloodwork };
    for (auto& t : validTypes) {
        if (t == type) {
            return true;
        }
    }
    return false;
}