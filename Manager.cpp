#include "Manager.h"

Manager::Manager(): collection{nullptr}{
    // Constructor begins under here, above is simply initialization list...
    srand(time(NULL));
}

Manager::~Manager(){
}

bool Manager::addAccountToBank(Account* &acc){
    collection.push_back(acc);  // vector:push_back() does not have a return type (std=c++11) 
    // call upon a func that check to make sure data was added, returns a bool
    return true;
}

std::string Manager::createPassword(int passwordLength){
    const std::vector <char> alphabet {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};    
    const std::vector <char> specialChar {'&','%','@','^','?','!','#'};
    const std::vector <char> intChar {'0','1','2','3','4','5','6','7','8','9'}; //Convert them ahead of time into char
    
    /*
     * NOTE: Random Number generator - rand(), generate a number, which will pull the element at that index
     *      IMPORTANT: rand() is considered harmful - https://channel9.msdn.com/Events/GoingNative/2013/rand-Considered-Harmful 
     * LIBRARY: #include <cstdlib>
     *      function - int rand(), takes no parameter, returns an integer from 0 to RAND_MAX{2147483647}
     *          Each call to rand(), will output a value that seems random, but the probability of getting a number over another is the same
     *          There is no chance that the same number will rise, each has the same equal opportunity to appear.
     *          The function is following a sequence, each call will move onto the next sequence to output [NOT RANDOM AT ALL]
     * 
     *      We can achieve a smaller range by using & (modulus) operator.
     *          EX: (rand() % 10) // will give me a remainder between 0-9
     *              If we add +1, we can get the remainder to range between 1-10
     * 
     *  TRUE RANDOMIZING: SEEDING
     *  #include <ctime> - void srand(int seed);
     *  IMPORTANT: The below call should only ever be called once
     *  srand(time(NULL)); - time(NULL) = returns number of sec elapsed in computer time
     *  (srand() % 10) + 1 - will output a range from 1-10 but this time it is truly random
     * 
     * */
    int randomAlpha {(srand() % alphabet.size())};      // Range between 
    int randomSC {(srand() % specialChar.size())};  // Range between 0-9, i need multiple random numbers from 
    int randomInt{(srand() % intChar.size())};
    int randomOrder{0};
    
    std::string userNewPassword {nullptr};
    while(userNewPassword.size() <= passwordLength){    
        randomOrder {(srand() % 3) +1}; // 1 = alphabetLower, 2 = alphabetUpper, 3 = specialChar
        switch (randomOrder){
            case 1:
                userNewPassword.push_back(alphabet.at(randomAlpha));
                break;
            case 2:
                // i have to convert lower to upper
                //userNewPassword.push_back((alphabet.at(randomAlpha)).toUpper()); //
                break;
            case 3:
                userNewPassword.push_back(intChar.at(randomInt));
                break;
            default: 
                break;
        }
    }
    return userNewPassword;
}

void Manager::deleteAccount(std::string){ // i might need seperate function to find either email or username
    // loops through the collection of Account until it matches the string
}

void Manager::displayList(){
    for(int i = 0; i < alphabetLower.size();i++)
        std::cout << alphabetLower.at(i) << std::endl;
}