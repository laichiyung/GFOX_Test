#include <iostream>
#include <queue>
#include "core/placeorder.h"
#include "core/run.h"
#include "core/notification.h"
#include "model/order.h"

using namespace std;
using namespace core;
double price = 1000;
int main() {
    //notification pointer
    shared_ptr<notification> n(new notification());
    run obj({"S", "G", "H"}, n);
    ptime dt = microsec_clock::local_time();

    //test cases
    order buyOrder1("A", "S", 200, price, microsec_clock::local_time(), "buy");
    order buyOrder2("B", "S", 200, price, microsec_clock::local_time(), "sell");

    order buyOrder3("C", "G", 300, price, microsec_clock::local_time(), "sell");
    order buyOrder4("D", "G", 200, price, microsec_clock::local_time(), "buy");
    order buyOrder5("E", "G", 200, price, microsec_clock::local_time(), "buy");

    order buyOrder6("W", "H", 200, price, microsec_clock::local_time(), "sell");
    order buyOrder7("X", "H", 200, price, microsec_clock::local_time(), "sell");
    order buyOrder8("Y", "H", 200, price, microsec_clock::local_time(), "sell");
    order buyOrder9("Z", "H", 600, price, microsec_clock::local_time(), "buy");
    obj.insert(buyOrder1);
    obj.insert(buyOrder2);
    obj.insert(buyOrder3);
    obj.insert(buyOrder4);
    obj.insert(buyOrder5);
    obj.insert(buyOrder6);
    obj.insert(buyOrder7);
    obj.insert(buyOrder8);
    obj.insert(buyOrder9);

    for(auto const& item : *obj._workers){
        item.second->join();
    }
    return 0;
}
