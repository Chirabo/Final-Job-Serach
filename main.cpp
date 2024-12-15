

#include <iostream>
#include <vector>
#include "Employer.h"
#include "Jobs.h"
#include "Candidate.h"
#include "Application.h"
using namespace std;


int main() {
    // Create an Employer instance with sample data
    int choice = 0;
    string input_id, input_password;
    cout <<"Are you an employer or a candidate:\n1.Employer\n2.Candidate";
    cin >> choice;
    if (choice == 1) {
        Employer employer("joe", "bensi","340854371","ashdod","gujgig" );

        // Try logging in with correct credentials
        cout << "Enter ID: ";
        cin >> input_id;
        cout << "Enter Password: ";
        cin >> input_password;

        if (employer.login(input_id, input_password)) {
            // After successful login, display the employer's menu
            employer.employer_menu();
        } else {
            do {
                cout << "Login failed. Try again:" << endl;
                cout << "Enter ID: ";
                cin >> input_id;
                cout << "Enter Password: ";
                cin >> input_password;
            }while (!employer.login(input_id, input_password));
            employer.employer_menu();
        }
    }
    else if (choice == 2) {
        Candidate candidate("ilay","levi","12345","box","hggg","hello world","0553697854","fulltime");
        cout << "Enter ID: ";
        cin >> input_id;
        cout << "Enter Password: ";
        cin >> input_password;

        if (candidate.login(input_id, input_password)) {
            // After successful login, display the employer's menu
            candidate.candidate_menu();
        } else {
            do {
                cout << "Login failed. Try again:" << endl;
                cout << "Enter ID: ";
                cin >> input_id;
                cout << "Enter Password: ";
                cin >> input_password;
            }while (!candidate.login(input_id, input_password));
            candidate.candidate_menu();

        }
    }
    return 0;
}