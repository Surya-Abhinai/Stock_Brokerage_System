#pragma once
#include<C:\Users\abhin\OneDrive\Desktop\Trade-bot\stock.h>
using namespace std ; 

class Portfolio{
public:
    unordered_map<string , int> holdings ;

    void add_stock(Stock s , int quantity){
        string symbol = s.get_symbol() ; 
        holdings[symbol] += quantity ;
    }

    void remove_stock(Stock s , int quantity){
        string symbol = s.get_symbol() ; 
        if(holdings.find(symbol) != holdings.end()){
            int val = holdings[symbol] ; 
            if(val > quantity){
                holdings[symbol] -= quantity ;
            }else if(val == quantity){
                holdings.erase(symbol) ;
            }else{
                throw invalid_argument("Insufficient stock quantity in the portfolio.") ;
            }
        }else{
            throw invalid_argument("Stock not found in the portfolio.") ;
        }
    }
    
    unordered_map<string ,int> get_holdings(){
        return holdings ;
    }
};
