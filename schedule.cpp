//
//  schedule.cpp
//  HackRiceX2020
//
//  Created by Emily Chen on 2020/9/19.
//  Copyright © 2020年 HackRiceX2020. All rights reserved.
//
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include "schedule.h"

void schedule(std::vector<Worker*>& workers, std::vector<Appointment>& appointments) {
    std::sort(appointments.begin(), appointments.end(), [](auto& a, auto& b) { return a.getTimeEnd() < b.getTimeEnd(); });

    for (auto& appointment : appointments) {
        for (auto& worker : workers) {
//            std::cout << worker->getName() << "\t | " << worker->getWorkingMinutes() << "\t | " << worker->getAvailableTime() << "\t | " << appointment.getTimeOfDayEnd() << std::endl;

            if (worker->isCorrectAppointment(appointment.getType()) && worker->getAvailableTime() <= appointment.getTimeOfDayStart()) {
                worker->addAppointment(appointment);
                break;
            }
        }
        std::sort(workers.begin(), workers.end(), [](auto& a, auto& b) { return *a < *b; });
//        for (auto& worker: workers) {
//            std::cout << worker->getName();
//        }
//        std::cout << std::endl;
    }
}
