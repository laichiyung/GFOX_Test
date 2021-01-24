//
// Created by admin on 1/23/21.
//

#include "compare.h"
bool utility::comparebuyorder::operator()(order const &p1, order const &p2){
    if (p1.price != p2.price) {
        return p1.price < p2.price;
    }
    return p1.orderDateTime > p2.orderDateTime;
}

bool utility::comparesellorder::operator()(order const &p1, order const &p2){
    if (p1.price != p2.price) {
        return p1.price > p2.price;
    }
    return p1.orderDateTime > p2.orderDateTime;
}