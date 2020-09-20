#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "appointment.h"
#include "worker.h"
#include "update.h"

using namespace std;

void updateJson(Appointment newAppointment)
{
    // Short alias for this namespace
    namespace pt = boost::property_tree;
    
    // Create a root
    pt::ptree root;
    
    //vector to store all appointments
    vector<Appointment> appointments;
    
    // Load the json file in this ptree
    pt::read_json("example.json", root);
    
    //read all appointments from json and put it into a vector
    const auto& jsonAppointments = root.get_child("appointments");
    for (const auto& appointment : jsonAppointments) {
        auto& child = appointment.second;
        appointments.emplace_back(Appointment(
                                              stringToType(child.get<std::string>("type")),
                                              child.get<std::string>("time"),
                                              child.get<std::string>("patientName")
                                              )
                                  );
    }
    
    //add new appointment to appointment vector
    appointments.emplace_back(newAppointment);
    
    //erasing the old appointments subtree
    auto child = root.get_child("appointments");
    child.clear();
    
    //write all appointments into the json file
    pt::ptree app_node;
    for (auto &appt: appointments)
    {
        //temp node containing the value
        pt::ptree temp_node;
        temp_node.put("",appt);
        
        //adding the node to the list
        app_node.push_back(std::make_pair("", temp_node));
    }
    root.add_child("appointments", app_node);
    
    cout<<"Update success"<<endl;
    

}
