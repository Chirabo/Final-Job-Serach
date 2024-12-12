

//
// Created by Shira on 10/12/2024.
//
#include <iostream>
#include <vector>
using namespace std;

#include "Jobs.h"
#include "Employer.h"

bool Employer::login(string input_id, const string input_password) {
    if (id == input_id && password == input_password) {
        cout << "Login successfully!" << endl;
        return true;
    } else {
        cout << "Invalid ID or password." << endl;
        return false;
    }
}

void Employer::employer_menu() {
    int choice;
    do {
        cout << "\nEmployer Menu: \n";
        cout << "1) Post jobs " << endl;
        cout << "2) View Published jobs " << endl;
        cout << "3) Manage jobs " << endl;
        cout << "Enter your choice: ";
        cout << "Back to Main Menu";
        cin >> choice;

        switch (choice) {
            case 1:
                Jobs newJob = Jobs().create_job();
                jobs.push_back(newJob);
                cout << "Job posted successfully!";
                break;
            case 2:
                view_published_jobs();
                break;
            case 3:
                manage_jobs();
            case 4:
                return;
            default:
                cout << "Invalid choice. try again. \n";
        }
    } while (choice != 4);
}

/*void Employer::post_jobs() {
    string location, profession, job_type, job_id;
    job_count++;
    cout << "Enter location: ";
    cin >> location;
    cout << "\nEnter profession: ";
    cin >> profession;
    cout << "\n Enter job type: " << endl;
    cin >> job_type;


    Jobs new_job(location, profession, job_type);
    Jobs *new_jobs_array = new Jobs[job_count];
    for (int i = 0; i < job_count - 1; ++i) {
        new_jobs_array[i] = published_jobs[i];
        new_jobs_array[job_count - 1] = new_job;
    }
    delete[] published_jobs;
    published_jobs = new_jobs_array;
}*/

void Employer::view_published_jobs() const {
    if (job_count == 0) {
        cout << "You have not posted any jobs yet! " << endl;
        return;
    }

    cout << "\nJobs Posted by you:\n";
    for (int i = 0; i < job_count; ++i) {
        published_jobs[i].display_jobs();
        cout << endl;
    }
}

void Employer::manage_jobs() {
    int choice = 0;
    bool run = true;
    while (run) {
        cout << "Choose an option: " << endl;
        cout << "1) Update job: " << endl;
        cout << "2) Delete job: " << endl;
        cin >> choice;

        switch ( choice) {
            case 1 :
                int index;
                cout << "Choose the index of the job that you want to update:"<< endl;
                cin>> index ;

                if (index < 1 || index > jobs.size()) {
                    cout << "Invalid index " << endl;
                    break;
                }

                jobs[index - 1].update_job();
                break;

            case 2:
                int job_index;
                cout << "Choose the index ";
                cin >> job_index;
                if (job_index < 1 || job_index > jobs.size()) {
                    cout << "Invalid index " << endl;
                    break;
                }

                jobs.erase(jobs.begin() + job_index - 1);
                cout << "Job deleted successfully" << endl;
                break;

    }

    void Employer::view_applications() const {
        if (job_count == 0) {
            cout << "There is no job applications! " << endl;
            return;
        }

        cout << "\n Jobs Applications: \n";
        for (int i = 0; i < application_count; ++i) {
            application_array[i].display_application();
        }
    }
    