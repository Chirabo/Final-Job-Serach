//
// Created by Shira on 11/12/2024.
//

#include "Application.h"


void Application::update_status(const std::string &new_status) {
    status = new_status;
}

string Application::get_status() {
    return status;
}

void Application::display_application() const {
    cout << "Application Display: " << endl;
    candidate->display_details();
    cout << endl;
    job->display_jobs();
    cout << endl;
    cout << "Status: " << status << endl;
}