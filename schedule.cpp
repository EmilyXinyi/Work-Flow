//
//  schedule.cpp
//  HackRiceX2020
//
//  Created by Emily Chen on 2020/9/19.
//  Copyright © 2020年 HackRiceX2020. All rights reserved.
//
#include <iostream>
#include <stdio.h>
#include "schedule.h"

void schedule(std::vector<Worker>& workers, std::vector<Appointment>& appointments) {
    for (int i = 0; i < appointments.size(); i++) {
        for (int j = 0; j < workers.size(); j++) {
            std::cout << workers[j].getName() << " | " << workers[j].getAvailableTime() << " | " << appointments[i].getTimeOfDayEnd() << std::endl;
            if (workers[j].getAvailableTime() <= appointments[i].getTimeOfDayStart()) {
                workers[j].addAppointment(appointments[i]);
                break;
            }
        }
    }
}