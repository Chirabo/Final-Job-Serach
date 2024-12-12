//
// Created by Shira on 10/12/2024.
//

#ifndef USERSTORY_EMPLOYER_H
#define USERSTORY_EMPLOYER_H
#include "User.h"
#include "Jobs.h"
#include "Application.h"
#include <string>
#include <vector>

class Employer : public User {
private:
    vector<Jobs> jobs;
    vector<Application> applications;
    Jobs* published_jobs;
    Application* application_array;
    int job_count;
    int application_count;

public:
    Employer(const string &id, const string &name, const string &password, const string &email);
    bool login (string input_id , const string input_password) ;
    void employer_menu();
    void post_jobs();
    void view_published_jobs() const;
    void manage_jobs();
    void view_applications();

};

#endif //USERSTORY_EMPLOYER_H
