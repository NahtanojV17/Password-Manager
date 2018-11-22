#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account{
    private:
        std::string username, email, password;
        
    public:
        Account();  // Default constructor 
        Account(std::string username, std::string email, std::string password);  // Overloaded Constructor
        ~Account();

        // Manually adding the data, in case the user decided to take their time adding it bit by bit
        void setUserName(std::string newUsername);
        void setUserEmail(std::string newEmail);
        void setUserPassword(std::string newPassword);
        
        void displayAccount();
        
};

#endif // ACCOUNT_H
/*
 * This class is for object storing
 *  I plan to utilize this class a skeleton base for accounts which will contain information
 * 
 * */