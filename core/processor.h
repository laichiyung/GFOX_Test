//
// Created by admin on 1/23/21.
//

#ifndef GFOX_TEST_PROCESSOR_H
#define GFOX_TEST_PROCESSOR_H

#include <iostream>
#include "../model/order.h"
#include <queue>
#include <mutex>
#include "../utility/compare.h"
#include "placeorder.h"
#include "notification.h"
using namespace std;
using namespace core;
namespace core {
    class processor {
    public:
        processor(shared_ptr<notification> n);
        mutex m_lock;
        priority_queue<order, vector<order>, utility::comparebuyorder> buyOrderBook;
        priority_queue<order, vector<order>, utility::comparesellorder> sellOrderBook;
        unique_ptr<placeorder<utility::comparebuyorder>> placeBuyOrder;
        unique_ptr<placeorder<utility::comparesellorder>> placeSellOrder;
        void insert(order& o);
        void matchOrder();
        shared_ptr<notification> n;

    };
}


#endif //GFOX_TEST_PROCESSOR_H
