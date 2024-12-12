//
// Created by Shira on 10/12/2024.
//

#ifndef USERSTORY_JOBS_H
#define USERSTORY_JOBS_H
using namespace std;
#include <string>
#include <iostream>


class Jobs
{
protected:
    string location;
    string profession;
    string job_type;
    string experience;string jobUID;
public:
    Jobs();
    Jobs(string location, string profession, string job_type, string jobUID, string experience);
    void set_job(string location , string profession , string job_type, string jobUID, string experience);
    string get_location(){return location;}
    string get_profession() {return profession;}
    string get_job_type(){return job_type;}
    string get_jobUID() {return jobUID;}
    string get_experience(){return experience;}
    void display_jobs()const;
    void update_job();
    Jobs create_job();
    static void delete_job ( Jobs *job , int &current_size , int index);
    friend ostream &operator << (ostream &os , const Jobs &j){
        os << "Location:" << j.location << ", Profession: " << j.profession << ", Job Type : " << j.job_type;
        return os;}
};


#endif //USERSTORY_JOBS_H
