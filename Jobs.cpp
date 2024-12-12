//
// Created by Shira on 10/12/2024.
//
#include "Jobs.h"
#include <vector>

Jobs ::Jobs() {}


Jobs::Jobs(string location, string profession, string job_type, string jobUID, string experience)
{
    this->location = location;
    this->profession = profession;
    this->job_type = job_type;
    this->jobUID = jobUID;
    this->experience = experience;
}

void Jobs ::set_job(string location, string profession, string job_type, string jobUID, string experience) {
    this-> location = location;
    this-> profession = profession;
    this-> job_type = job_type;
    this->jobUID = jobUID;
    this->experience = experience;
}
void Jobs::update_job()
{
    int choice=0;
    bool run = true;
    while ( run ){
        cout << "What do tou want to update?:" << endl;
        cout << "1. Job location :" << endl;
        cout << "2. Job profession (job title):" << endl;
        cout << "3. Job type ( full time / part time):"<< endl;
        cout << "4.Exit."<< endl;
        cin >> choice;
        switch (choice) {
            case 1:{
                string  new_location;
                cout << "Enter the new location:" << endl;
                cin >> new_location;
                location = new_location;
                break;
            }
            case 2:{
                string new_profession;
                cout << "Enter the new profession:"<< endl;
                cin >> new_profession;
                profession=new_profession;
                break;
            }
            case 3:{
                string new_job_type;
                cout << "Enter the new job-type :" << endl;
                cin >> new_job_type;
                job_type=new_job_type;
                break;
            }
            case 4:{
                string new_experience;
                cout << "Enter the new required experience:" << endl;
                cin >> new_experience;
                experience= new_experience;
                break;
            }
            case 5 :{
                cout << "Updated successfully completed!"<< endl;
                break;
            }
            default:
                cout << "Invalid choice."<< endl;

        }
    }
}

Jobs Jobs::create_job() {
    string profession , location , job_type, jobUID, experience;
    cout << "Enter the location:" << endl;
    cin >> location;
    cout << "Enter the profession:" << endl;
    cin >> profession;
    cout << "Enter the job type:" << endl;
    cin >> job_type;
    cout << " Enter jobUID: "<< endl;
    cin >> jobUID;
    cout << " Enter required experience: " << endl;
    cin >> experience;
    return Jobs(location,profession,job_type,jobUID,experience);
}


void Jobs ::delete_job(Jobs *job, int &current_size, int index) {
    if ( index < 0 || index >= current_size){
        cout << "Invalid index . You can't delete the job."<< endl;
        return;
    }
    for (int i = 0; i < current_size; ++i) {
        job[i] = job[i+1];
        current_size--;
        cout << "The job was successfully deleted!"<< endl;
    }
}

void Jobs::display_jobs()const
{
    cout << "Job details: " << endl;
    cout << "Location: " << location << endl;
    cout << "Profession: " << profession << endl;
    cout << "Job type: " << job_type << endl;
    cout << "required experience: " << experience << endl;
    cout << "Job UID: " << jobUID << endl;
}

