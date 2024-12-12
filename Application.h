//
// Created by Shira on 10/12/2024.
//

#ifndef USERSTORY_APPLICATION_H
#define USERSTORY_APPLICATION_H
#include "Jobs.h;
#include "Candidate.h"

class Application {
private:
    Jobs* job;
    Candidate* candidate;
    string status;
//status...
public:
    void update_status(const string& new_status);
    string get_status();
    void display_application() const;
};


#endif //USERSTORY_APPLICATION_H
