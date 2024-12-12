//
// Created by Shira on 10/12/2024.
//

#ifndef USERSTORY_CANDIDATE_H
#define USERSTORY_CANDIDATE_H
#include "User.h"

#include <vector>
class Application;
class Jobs;
class Candidate : public User
{
private:
    string resume;
    string phone_number;
    string job_type;
    vector <Jobs> favorites;
    vector <Application> app_history;

public:
    Candidate();
    Candidate(string first_name, string last_name, string id, string password, string email, string resume, string phone_number, string job_type);
    ~Candidate();
    bool login (string id, string password);
    Candidate &operator = (const Candidate& cand);
    void candidate_menu();
    void add_favorite_job (const Jobs& jobs);
    void view_favorites () const;
    void add_application (const Jobs &job);
    void view_application_history ();
    void upload_resume (const string& file_resume);
    void edit_profile (Candidate &candidate);
    void set_first_name ( const string& new_first_name);
    void set_last_name ( const string& new_last_name);
    void set_email ( const string& new_email);
    void set_phone_number ( const string& new_phone_number);
    //void delete_candidate(Candidate &c );
    void display_details ()const ;
};


#endif //USERSTORY_CANDIDATE_H
