#include "classes.hpp"


string User::get_username(){
    return username;
}

string User::get_password(){
    return password;
}


bool User::is_logged_in(){
    return login_status;
}
void User::set_username(string usrname){
    username =usrname;
}
void User::set_password(string _password){
    password =_password;
}