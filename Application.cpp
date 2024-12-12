//
// Created by Shira on 11/12/2024.
//

#include "Application.h"
#include "Jobs.h"
using namespace std;

Application::Application(Jobs *jobs1, Candidate *candidate1, Employer *employer1, string &status1) {
    this->candidate = candidate1;
    this->job = jobs1;
    this->employer = employer1;
    status = status1;
}
void Application::update_status(const string &new_status) {
    status = new_status;
}

string Application::get_status() {
    return status;
}

void Application::display_application() const {
    cout << "Application Display: " << endl;
    candidate->display_details();
    cout << endl;
    job-> display_jobs();
    cout << endl;
    cout << "Status: " << status << endl;
}

