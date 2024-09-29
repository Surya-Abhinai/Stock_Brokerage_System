#include<C:\Users\abhin\OneDrive\Desktop\Trade-bot\order.h>
using namespace std;

class StockBroker{
private :
    static StockBroker* instance ; 
    queue<Order*> order_queue ;
    unordered_map<int , Account*> accounts ; 
    unordered_map<string , Stock*> stocks ;
    static mutex _lock;
    int account_id_counter ;
public :
    StockBroker() : account_id_counter(0) {}

    static StockBroker* getInstance() {
        if (instance == nullptr) {
            std::lock_guard<std::mutex> guard(_lock);  // Lock for thread safety
            if (instance == nullptr) {
                instance = new StockBroker();
            }
        }
        return instance;
    }
    void create_account(User* user , double balance){
        int acc_id = generate_acc_id() ;
        Account* acc = new Account(acc_id , user , balance) ; 
        accounts[acc_id] = acc ;
    }
    Account* get_account(int acc_id){
        return accounts[acc_id] ;
    }
    void add_stock(Stock* stock){
        stocks[stock->get_symbol()] = stock ;
    }
    Stock* get_stock(string id){
        return stocks[id] ;
    }
    void place_order(Order* order){
        order_queue.push(order) ; 
        process_orders() ; 
    }
    void process_orders(){
        while(!order_queue.empty()){
            Order* order = order_queue.front() ; 
            order_queue.pop() ; 
            try {
                order->execute();
            }
            catch (const invalid_argument& e) {
                cout << "Order failed: " << e.what() << std::endl;
            }
        }
    }
    int generate_acc_id(){
        account_id_counter++ ; 
        return account_id_counter ;
    }
};
