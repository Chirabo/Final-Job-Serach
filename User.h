#ifndef USERSTORY_USER_H
#define USERSTORY_USER_H
#include <string>
using namespace std;

class User
{
protected:
    string first_name;
    string last_name;
    string id;
    string password;
    string email;
public:
    User();
    User(string first_name, string last_name, string id, string password, string email);
    string get_first_name() {return first_name;}
    string get_last_name() {return last_name;}
    string get_id() {return id;}
    string get_password() {return password;}
    string get_email() {return email;}
    virtual bool login (string id, const string password)=0;
    virtual void regist()=0;
    virtual void display_details() const;
    virtual ~User();
};


#endif //USERSTORY_USER_H
