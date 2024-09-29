#pragma once
#include<C:\Users\abhin\OneDrive\Desktop\Trade-bot\account.h>
using namespace std;

enum class OrderStatus {
    PENDING = 0,
    EXECUTED = 1,
    REJECTED = 2
};

class Order {
public:
    string order_id;
    Account* account;
    Stock* stock;
    int quantity;
    double price;
    OrderStatus status;

    Order(string order_id, Account* account, Stock* stock, int quantity, double price)
        : order_id(order_id), account(account), stock(stock), quantity(quantity), price(price), status(OrderStatus::PENDING) {}

    virtual void execute() {
        
    }

    void printOrder() const {
        cout << "Order ID: " << order_id << endl;
        cout << "Account: " << account << endl;
        cout << "Stock: " << stock << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Price: $" << price << endl;
        cout << "Status: " << getStatusString() << endl;
    }

private:
    string getStatusString() const {
        switch (status) {
            case OrderStatus::PENDING: return "Pending";
            case OrderStatus::EXECUTED: return "Executed";
            case OrderStatus::REJECTED: return "Rejected";
            default: return "Unknown";
        }
    }
};
