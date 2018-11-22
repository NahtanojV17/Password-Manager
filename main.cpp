#include "Manager.h"
#include "Account.h"

using namespace std;

int main(){
    
    Manager user;
    const std::string loginPass {"WelcomePM"};
    
    cout << "Password Manager created by Jonathan Vazquez" << endl;
    
    std::string inputPass {nullptr};
    const unsigned short maxTries {3};
    unsigned short currTries {0};
   
    while(inputPass != loginPass && currTries < maxTries){
        cout << "Please enter password to access manager: " << endl;
        cin >> inputPass;
        currTries++;
        
        inputPass {nullptr};
    }
    
    unsigned int userInput{0};
    cout << "/tPlease choose an option" << endl;
    cout << "/t/t1 - View List of current saved accounts?" << endl;
    cout << "/t/t2 - Edit a saved accounts?" << endl;
    cout << "/t/t3 - Add a new Account?" << endl;
    cout << "/t/t4 - Delete a saved Account?" << endl;
    
    switch(userInput){
            case 1:
                // perform function
                user.displayList();
                break;
            case 2:
                // perform function
                break;
            case 3:
                std::string userName {nullptr};
                std::string userEmail {nullptr};
                std::string userPassword {nullptr};
                
                cout << "... Add New Account to Manager ..." << endl;
                cout << "Please enter User Name: ";
                cin >> userName;
                cout << "Please enter User Email: ";
                cin >> userEmail;
                cout << "Please enter User Password: ";
                cin >> userPassword;
                // Here is were we ask user if they want to generate a password or not
                
                
                Account *newAccount = new Account; // Creates a location in memory for object
                newAccount->setUserName(userName);
                newAccount->setUserEmail(userEmail);
                newAccount->setUserPassword(userPassword);
                
                // Now well pass the object to Manager, which will store it into a vector list
                addAccountToBank(&newAccount); // passing a reference, so that i can add the actual data to vector list
                
                newAccount {nullptr};
                delete newAccount;
                break;
            case 4:
                int inputChoice {0};
                std::string searchItem{nullptr};
                cout << "... Delete Account in Manager ..." << endl;
                cout << "Would you like to search by USERNAME or EMAIL?/n";
                cout << "USERNAME [1] or EMAIL [2]/n";
                cin >> inputChoice;
                if(inputChoice == 1){
                    cout << "Please enter the username: ";
                    cin >> searchItem;
                    user.deleteAccount(searchItem);
                
                }else{
                    if(inputChoice == 1){
                    cout << "Please enter the email: ";
                    cin >> searchItem;
                    user.deleteAccount(searchItem);
                }
                searchItem = nullptr;
                break;
            default:
                cout << "The option choosen isn't available, please try again...";
                break;
    }
    
}


/*
 *  NOTES: This is a categorie called 'NOTE' which will contain bits of information about certain stuff i learned
 *              regarding a specific topic. EX: More useful functions and behind the scenes compiler actions towards
 *              a vector. How it works behind the scenes, etc.
 * 
 * */