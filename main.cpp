#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "appointment.h"
#include "worker.h"
#include "doctor.h"
#include "nurse.h"
#include "schedule.h"

using namespace std;

int main() {
    vector<Worker*> workers;
    vector<Appointment> appointments;

    ifstream jsonFile("example.json");
    boost::property_tree::ptree pt;
    boost::property_tree::read_json(jsonFile, pt);

    const auto& jsonWorkers = pt.get_child("workers");
    const auto& jsonAppointments = pt.get_child("appointments");

    for (const auto& worker : jsonWorkers) {
        auto& child = worker.second;
        std::string role = child.get<std::string>("role");
        if (role == "Nurse") {
            workers.push_back(new Nurse(child.get<std::string>("name") ));
        } else if (role == "Doctor") {
            workers.push_back(new Doctor(child.get<std::string>("name") ));
        }
    }

    for (const auto& appointment : jsonAppointments) {
        auto& child = appointment.second;
        appointments.emplace_back(Appointment(
            stringToType(child.get<std::string>("type")),
            child.get<std::string>("time"),
            child.get<std::string>("patientName")
            )
        );
    }

//    for (auto& worker : workers) {
//        std::cout << worker << std::endl;
//    }
//
//    for (auto& apt : appointments) {
//        std::cout << apt << std::endl;
//    }

    std::sort(appointments.begin(), appointments.end(), [](auto& a, auto& b) { return a.getTimeEnd() < b.getTimeEnd(); });

    schedule(workers, appointments);

    for (auto& worker : workers) {
        std::cout << *worker;
        std::cout << worker->getWorkingMinutes() << " minutes" << std::endl << std::endl;
    }

    return 0;
}
