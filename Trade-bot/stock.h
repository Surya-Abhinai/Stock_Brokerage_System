#pragma once
#include<bits/stdc++.h>
using namespace std ; 

struct Stock{
    string symbol ; 
    string name ; 
    int price ; 
    Stock(string symbol , string name , int price) : symbol(symbol) , name(name), price(price){}
    void update_price(int new_price){
        price = new_price ; 
    } 
    string get_symbol(){
        return symbol ;
    }
    string get_name(){
        return name ; 
    }
    int get_price(){
        return price ;
    }
};