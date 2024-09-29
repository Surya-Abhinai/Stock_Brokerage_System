#include<C:\Users\abhin\OneDrive\Desktop\Trade-bot\order.h>
using namespace std;

class SellOrder : public Order{
public:
    SellOrder(string order_id, Account* account, Stock* stock, int quantity, double price)
        : Order(order_id, account, stock, quantity, price){}

    void execute() override {
        Portfolio* p = account->get_portfolio() ;
        unordered_map<string , int> mp = p->get_holdings() ;
        string sym = stock->get_symbol() ;
        if(mp.find(sym) == mp.end()){
            cout << "Hi" << endl ;
            throw invalid_argument("Stock not found in the portfolio.") ;
        }else if(mp[sym] < quantity){
            throw invalid_argument("Insufficinet number of stocks to sell.") ;
        }else{
            double cost = quantity * price ; 
            account->deposit(cost) ;
            mp[stock->get_name()] -= quantity ; 
            status = OrderStatus::EXECUTED ; 
        }
    }
};