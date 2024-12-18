#include "header.hpp"
#include "classes.hpp"

bool POST_signup(vector<string> &commands,System &ss,User *user){
    string username = commands[4];
    string password = commands[6];

    if (ss.repeated_username(username))
    {
        cout << "Bad Request" << username<< endl;
        return 0;
    }
    if (user != 0)
    {
        cout << "Permission Denied" << endl;
        return 0;
    }
    
    User newuser;
    ss.add_user(newuser);
    user = ss.get_last_user();
    
    user->set_username(username);
    user->set_password(password);

    cout << "OK" << endl;
    return 1;
    
}

string POST_login(vector<string> &commands,System &ss,User *user){
        string username = commands[4];
        string password = commands[6];

        

    if(user != 0){
        cout << "Permission Denied";
        return "";
    }
    if (!ss.repeated_username(username))
    {
        cout << "Not Found" <<endl  ;
        return "";
    }
    
        User *x = ss.loggin(username,password);
        if(x == 0){
            cout << "Permission Denied" << endl;
            return "";
        }else{
            user = x;
            cout << "OK" << endl;
            return user->get_username();
        }
    


}

bool POST_logout(User *user){
    if(!user){
        cout << "Permission Denied";
        return 0;
    }else{
        user = 0;
        cout << "OK" << endl ;
        return 1;
    }
    
}





string POST(vector<string> &commands ,System &ss,User *user){
    if (commands.size() < 3){
        cout << "Bad Request" << endl;
        return "" ;
    }
    if (commands[1] == "signup" )
    {
        if(commands.size() >= 6){
            if (commands[2] == "?" & commands[3] == "username"  && commands[5] == "password")
            {
                if(POST_signup(commands,ss,user) == 1){
                    return "signup-1";
                }
                
            }else{
                  cout << "Bad Request" << endl;
                
            }
            
        }else{
                cout << "Bad Request" << endl;
            
        }
        return "";
    }else if(commands[1] == "login"){
        if(commands.size() >= 7){
            if (commands[2] == "?" & commands[3] == "username"  && commands[5] == "password")
            {
                string k = POST_login(commands,ss,user);
                if (k!="")
                {
                    return k;
                }
                

                
            }else{
                  cout << "Bad Request" << endl;
                
            }
            
        }else{
                cout << "Bad Request" << endl;
            
        }
        return "";
    }else if(commands[1] == "logout"){
        if (commands[2] == "?"){
            if (POST_logout(user) ==1)
            {
                return "logout-succsess";
            }
            
        }
        return "" ;
        
    }

    
    cout << "Not Found"<<endl;
    return "";
}