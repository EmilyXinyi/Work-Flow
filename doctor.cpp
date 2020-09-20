#include "doctor.h"

Doctor::Doctor(std::string name) : Worker(name) {

}

bool Doctor::isCorrectAppointment(AppointmentTypes type) {
    AppointmentTypes validTypes[1] = { General };
    for (auto& t : validTypes) {
        if (t == type) {
            return true;
        }
    }
    return false;
}
