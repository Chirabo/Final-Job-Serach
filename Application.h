//
// Created by Shira on 10/12/2024.
//

#include "Jobs.h"
#ifndef CANDIDATE_H
#define CANDIDATE_H
#include "Candidate.h"

class Candidate;
class Employer;

class Application {
private:
    Jobs *job;
    Candidate* candidate;
    Employer* employer;
    string status;
//status...
public:
    Application(Jobs *jobs1, Candidate *candidate1, Employer *employer1, string &status1);
    void update_status(const string& new_status);
    string get_status();
    void display_application() const;
};


#endif //USERSTORY_APPLICATION_H
