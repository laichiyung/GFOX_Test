//
// Created by admin on 1/23/21.
//

#ifndef GFOX_TEST_RUN_H
#define GFOX_TEST_RUN_H

#include <iostream>
#include <map>
#include <bits/unique_ptr.h>
#include <thread>
#include "processor.h"
#include "notification.h"
using namespace std;
namespace core {
    class run {
    public:
        run(vector<string> symbols, shared_ptr<notification> n);
        //key = symbol, value = thread object
        shared_ptr<map<string, shared_ptr<thread>>> _workers;
        shared_ptr<map<shared_ptr<thread>, shared_ptr<processor>>> _workersObject;
        void insert(order& o);
    };
}


#endif //GFOX_TEST_RUN_H
