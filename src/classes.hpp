#include "header.hpp"

class Resturant {
    public:
        Resturant(string name,string district,string foods,string oppening,string closing,string number_of_tables);
        
    private:
        string name;
        string district;
        string foods;
        string oppening;
        string closing;
        string number_of_tables;
};

class User {
    public:
    string get_username();
    string get_password();
    bool is_logged_in();
    void set_username(string usrname);
    void set_password(string password);
    private:
        string username;
        string password;
        bool login_status = 0;
        bool is_auser = 0;
};

class System{
    public:
        System(){
            
        }
        void add_resturant(Resturant resturant);
        void add_district(string districts,string neighber);
        void add_user(User user);
        vector<Resturant> get_resturants(); 
        bool repeated_username(string username);
        User * loggin(string username , string password);
        User * get_last_user();
        User * get_lost_login(string username);

    private:
        vector<Resturant> resturants;
        vector<User> users;
        map<string,string> districts;

};


