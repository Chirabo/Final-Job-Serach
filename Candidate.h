//
// Created by Shira on 10/12/2024.
//

#ifndef USERSTORY_CANDIDATE_H
#define USERSTORY_CANDIDATE_H
#include "User.h"
#include "Jobs.h"

class Candidate : public User
{
private:
    string resume;
    string phone_number;
    string job_type;
    Jobs *favorites;
    int favorites_size;
    int history_size;
    Jobs *app_history;
public:
    Candidate();
    Candidate(string first_name, string last_name, string id, string password, string email, string resume, string phone_number, string job_type, int favorites_size ,int history_size, Jobs *fav, Jobs *history);
    ~Candidate();
    Candidate &operator = (const Candidate &candidate);
    void add_favorite_job (string location , string profession , string job_type);
    void view_favorites () const;
    void add_application (const Jobs &job);
    void view_application_history ();
    void upload_resume (const string& file_resume);
    void manage_profile ( Candidate &candidate);
    void set_first_name ( const string& new_first_name){first_name=new_first_name;}
    void set_last_name ( const string& new_last_name){last_name=new_last_name;}
    void set_email ( const string& new_email){email= new_email;}
    void set_phone_number ( const string& new_phone_number){phone_number=new_phone_number;}
    void delete_candidate(Candidate &c , );
    virtual void display_details ()const ;
};


#endif //USERSTORY_CANDIDATE_H
