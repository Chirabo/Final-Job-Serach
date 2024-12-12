//
// Created by Shira on 10/12/2024.
//

#include "Candidate.h"
#include "Jobs.h"

Candidate::Candidate() : User() {
    favorites = nullptr;
    app_history = nullptr;
    job_type = nullptr;
    phone_number = nullptr;
}

Candidate::Candidate(string first_name, string last_name, string id, string password, string email, string resume, string phone_number, string job_type, int favorites_size,int history_size , Jobs *fav, Jobs *history): User(first_name, last_name, id, password, email) {
    this->resume = resume;
    this-> favorites_size = favorites_size;
    this->phone_number = phone_number;
    this->job_type = job_type;
    favorites= new Jobs [favorites_size];
    for (int i = 0; i < favorites_size; ++i) {
        favorites[i] = fav[i];
    }
    app_history= new Jobs[history_size];
    for (int i = 0; i < history_size; ++i) {
        app_history[i] = history[i];
    }

}

Candidate &Candidate ::operator=(const Candidate &candidate){
    if ( this != &candidate){
        first_name = candidate.first_name;
        last_name = candidate.last_name;
        email = candidate.email;
        job_type= candidate.job_type;
        favorites = candidate.favorites;
        app_history = candidate.app_history;
    }
    return *this;
}

void Candidate :: add_favorite_job(string location , string profession , string job_type) {
    if (favorites_size ==0)
    {
        favorites = new Jobs[1];
        favorites[0].set_job(location , profession , job_type);
        ++favorites_size;
        return;
    }
    Jobs *tmp= new Jobs [favorites_size+1];
    for (int i = 0; i < favorites_size; ++i) {
        tmp[i] = favorites[i];
    }
    tmp[favorites_size++].set_job(location,profession, job_type);
    delete[]favorites;
    favorites=tmp;
}

void Candidate ::view_favorites() const{
    if (favorites_size == 0){
        cout << "No favorite jobs yet."<< endl;
        return;
    }
    cout << "Favorites jobs:" << endl;
    for (int i = 0; i < favorites_size; ++i) {
        cout << i+1 << ")";
        favorites[i].display_jobs();
        cout << endl;

    }
}

void Candidate ::add_application(const Jobs &job) {
    Jobs* tmp = new Jobs [history_size+1];
    for (int i = 0; i < history_size; ++i) {
        tmp[i]= app_history[i];
    }
    tmp[history_size]= job;
    delete[]app_history;
    app_history=tmp;
    ++history_size;
}

void Candidate ::view_application_history() {
    if ( history_size==0){
        cout << "No application history yet." << endl;
        return;
    }
    cout << "Application history:" << endl;
    for (int i = 0; i < history_size; ++i) {
        cout << i + 1 << ") ";
        app_history[i].display_jobs();
        cout << endl;
    }
}

void Candidate ::upload_resume(const string &file_resume) {
    resume = file_resume;
    cout << "Resume uploaded successfully." << endl;
}

void Candidate ::manage_profile(Candidate &candidate)
{
    int choice;
    bool run = true;
    while ( run ){
        cout << "Manage profile menu:" << endl;
        cout << "1. Change my first name:" << endl;
        cout << "2. Chamge my last name:" << endl;
        cout << "3. Change my email address:" << endl;
        cout << "4. Change my phone number:" << endl;
        cout << "5. Display my profile's details:" << endl;
        cout << "6.Exit." << endl;
        cout << "Please choose an option:" << endl;
        cin >> choice;
        switch ( choice ){
            case 1: {
                cout << "Enter the new first name :";
                string new_first_name;
                cin >> new_first_name;
                candidate.set_first_name(new_first_name);
                cout << "First name updated successfully!";
                break;
            }
            case 2: {
                cout << "Enter the new last name : ";
                string new_last_name;
                cin >> new_last_name;
                candidate.set_last_name(new_last_name);
                cout << "Last name updated successfully!";
                break;
            }
            case 3: {
                cout << "Enter the new email:";
                string new_email ;
                cin>> new_email;
                candidate.set_email(new_email);
                cout << "Email updated successfully!";
                break;
            }
            case 4: {
                cout << "Enter the new phone number:";
                string new_phone_number;
                cin >> new_phone_number;
                candidate.set_phone_number(new_phone_number);
                cout << "Phone number updated successfully!";
                break;
            }
            case 5:{
                candidate.display_details();
                break;
            }
            case 6:
                cout << "Goodbye!"<< endl;
                run = false;
                break;
            default:
                cout << "invalid option , please try again.";
        }
    }
}

void Candidate ::display_details() const {
    cout << "Candidate details: " << endl;
    User :: display_details();
    cout << "Resume:"<< resume << endl << "Phone number:" << phone_number << endl << "The job that I looking for :"<< job_type << endl;


}
Candidate::~Candidate(){

}
