#include<C:\Users\abhin\OneDrive\Desktop\Trade-bot\stock_broker.h>
#include<C:\Users\abhin\OneDrive\Desktop\Trade-bot\buy_order.h>
#include<C:\Users\abhin\OneDrive\Desktop\Trade-bot\sell_order.h>


using namespace std;

int main(){
    StockBroker* stock_broker = new StockBroker() ;
    User* user = new User("U001" , "Abhinai" , "abhinayj848430@gmail.com") ;
    stock_broker->create_account(user, 10000.0) ; 
    Account* account = stock_broker->get_account(1) ;

    Stock* stock1 = new Stock("AAPL", "Apple Inc.", 150.0) ;
    stock_broker->add_stock(stock1) ;
    Order* buy_order1 = new BuyOrder("O001", account, stock1, 10, 150.0) ;
    stock_broker->place_order(buy_order1) ;
    Order* sell_order1 = new SellOrder("O002", account, stock1, 5, 160.0) ;
    stock_broker->place_order(sell_order1) ;
    cout << account->get_balance() << endl ;
    return 0 ;
}