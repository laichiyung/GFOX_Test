//
// Created by admin on 1/23/21.
//

#include "order.h"

model::order::order(string traderID, string symbol, long quantity, long price, ptime orderDateTime, string side) {
    this->traderID = traderID;
    this->symbol = symbol;
    this->quantity = quantity;
    this->totalQuantity = quantity;
    this->price = price;
    this->orderDateTime = orderDateTime;
    this->side = side;
};