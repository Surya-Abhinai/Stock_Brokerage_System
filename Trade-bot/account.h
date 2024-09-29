#include<C:\Users\abhin\OneDrive\Desktop\Trade-bot\portfolio.h>
#include<C:\Users\abhin\OneDrive\Desktop\Trade-bot\User.h>

using namespace std ; 

class Account{
public:
    int account_id ;
    User* user ; 
    double balance ; 
    Portfolio* P ;
    Account(int account_id , User* user , double balance) : account_id(account_id) , user(user) , balance(balance) {}
    void deposit(int amount){
        balance += amount ;
    }

    void withdraw(int amount){
        if(balance >= amount){
            balance -= amount ;
        }else{
            throw invalid_argument("Insufficient funds in the account") ;
        }
    }

    int get_account_id(){
        return account_id ;
    }
    User* get_user(){
        return user ;
    }
    double get_balance(){
        return balance ;
    }
    Portfolio* get_portfolio(){
        return P ;
    } 

};

