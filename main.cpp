

#include <iostream>
#include <vector>
#include "Employer.h"
#include "Jobs.h"
#include <vector>

using namespace std;


int main() {
    // Create an Employer instance with sample data

    Employer employer("joe", "bensi","340854371","ashdod","gujgig" );

    // Try logging in with correct credentials
    string input_id, input_password;
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
    return 0;
}