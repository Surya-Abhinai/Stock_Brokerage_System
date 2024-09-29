#pragma once
#include<C:\Users\abhin\OneDrive\Desktop\Trade-bot\order.h>
using namespace std;

class BuyOrder : public Order{
public:
    BuyOrder(string order_id, Account* account, Stock* stock, int quantity, double price)
        : Order(order_id, account, stock, quantity, price){}

    void execute() override{
        double total_cost = quantity * price ; 
        Portfolio* P = account->get_portfolio() ; 
        unordered_map<string ,int> mp = P->get_holdings()  ;     
        if(account->get_balance() >= total_cost) {
            account->withdraw(total_cost) ;
            mp[stock->get_name()] += quantity ;  
            status = OrderStatus::EXECUTED ; 
        }else{
            status = OrderStatus::REJECTED;
            throw invalid_argument("Insufficient funds to execute the buy order.");
        }
    }
};