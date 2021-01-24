//
// Created by admin on 1/23/21.
//

#include "processor.h"

core::processor::processor(shared_ptr<notification> n) {
    this->placeBuyOrder = make_unique<placeorder<utility::comparebuyorder>>();
    this->placeSellOrder = make_unique<placeorder<utility::comparesellorder>>();
    this->n = n;
}

//insert order to order books using template
void core::processor::insert(order& o) {
    lock_guard<mutex> lock(m_lock);
    if(o.side == "buy"){
        this->placeBuyOrder->insert(this->buyOrderBook, o);
    }else if(o.side == "sell"){
        this->placeSellOrder->insert(this->sellOrderBook, o);
    }
}

//match orders.If orders matched, send notification to traders.
void core::processor::matchOrder(){
    while(true){
        lock_guard<mutex> lock(m_lock);
        if(!this->buyOrderBook.empty() && !this->sellOrderBook.empty()){
            order buyOrder = this->buyOrderBook.top();
            order sellOrder = this->sellOrderBook.top();
            if(buyOrder.price >= sellOrder.price){
                if(buyOrder.quantity == sellOrder.quantity){
                    notifyTrader notifyMessage(buyOrder.traderID, buyOrder.symbol, buyOrder.totalQuantity, buyOrder.price, buyOrder.orderDateTime, buyOrder.side);
                    this->n->notify(notifyMessage);
                    notifyTrader notifyMessage2(sellOrder.traderID, sellOrder.symbol, sellOrder.totalQuantity, sellOrder.price, sellOrder.orderDateTime, sellOrder.side);
                    this->n->notify(notifyMessage2);
                    this->buyOrderBook.pop();
                    this->sellOrderBook.pop();
                }else if(buyOrder.quantity > sellOrder.quantity){
                    notifyTrader notifyMessage(sellOrder.traderID, sellOrder.symbol, sellOrder.totalQuantity, sellOrder.price, sellOrder.orderDateTime, sellOrder.side);
                    this->n->notify(notifyMessage);
                    buyOrder.quantity = buyOrder.quantity - sellOrder.quantity;
                    this->buyOrderBook.pop();
                    this->sellOrderBook.pop();
                    this->placeBuyOrder->insert(this->buyOrderBook, buyOrder);
                }else if(buyOrder.quantity < sellOrder.quantity){
                    notifyTrader notifyMessage(buyOrder.traderID, buyOrder.symbol, buyOrder.totalQuantity, buyOrder.price, buyOrder.orderDateTime, buyOrder.side);
                    this->n->notify(notifyMessage);
                    sellOrder.quantity = sellOrder.quantity - buyOrder.quantity;
                    this->buyOrderBook.pop();
                    this->sellOrderBook.pop();
                    this->placeSellOrder->insert(this->sellOrderBook, sellOrder);
                }
            }
        }
    }
}