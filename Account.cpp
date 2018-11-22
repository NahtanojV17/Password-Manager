#include "Account.h"

Account::Account(): username{nullptr}, 
                    email{nullptr}, 
                    password{nullptr}{}

Account::Account(std::string username, std::string email, std::string password){
        this.username = username;
        this.email = email;
        this.password = password;
}

Account::~Account(){
    // Destructor 
}

void Account::setUserName(std::string newUsername){
    username {newUsername};
}
void Account::setUserEmail(std::string newEmail){
    email {newEmail};
}
void Account::setUserPassword(std::string newPassword){
    password {newPassword};
}

void Account::displayAccount(){
    // Display The information at this current account
}
/*
 * NOTE: Research - Data compromise?
 *  I'm having a bit of a concern. Can an class like this which contain properties of Account, present a console output command?
 *  or
 *  Should this class stay away from communication with the user?
 *      It will end up communicating since the user has the opportunity of adding data to account down the road.
 * 
 * */