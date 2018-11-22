#ifndef MANAGER_H
#define MANAGER_H

#include <vector>
#include <string>
#include <iostream>
#include <ctime>
#include "Account.h"

class Manager
{
    private:
        const std::vector <char> specialChar;
        vector <Account> collection;
        /*  NOTE: Vectors - using as const 
         * 
         *      std::vector <const string> - Can no longer change the actual data value for each element. [Can fail for compile Pre-C++11]
         *      const std::vector <string> - Can not change anything about the vector itself
         *      const vector <const string> - Can not change anything, at all.
         * */
        
        
    public:
        Manager();
        ~Manager();
        
        bool addAccountToBank(Account* &acc);
        std::string createPassword(int);
        
        /*
         * 
         * NOTE: Vectors - how to use vectors of class rather than default data types
         *      I want to be able to create a class which will perform the account section 
         *          - Add username, generate password, add email, add note, save
         *      I can create class objects which i then add into a list of objects
         *          EX: vector <classObjectName> list;
         *              classObjectName *objectItem;
         *              // we then pass it as we use to like linked list
         * */
        
        void deleteAccount(std::string);
        void displayList();
};
#endif // MANAGER_H
