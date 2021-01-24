//
// Created by admin on 1/23/21.
//



#ifndef GFOX_TEST_PLACEORDER_H
#define GFOX_TEST_PLACEORDER_H
#include <iostream>
#include <queue>
#include "../model/order.h"
//#include "processor.h"
using namespace std;
using namespace model;

namespace core {
    template<typename p>
    class placeorder {
    public:
        void insert(priority_queue<order, vector<order>, p>& q, order o) {
            q.push(o);
        }

    };
}


#endif //GFOX_TEST_PLACEORDER_H
