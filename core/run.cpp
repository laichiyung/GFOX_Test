//
// Created by admin on 1/23/21.
//

#include "run.h"

core::run::run(vector<string> symbols, shared_ptr<notification> n){
    this->_workers = make_shared<map<string, shared_ptr<thread>>>();
    this->_workersObject = make_shared<map<shared_ptr<thread>, shared_ptr<processor>>>();
    for(int i = 0; i < symbols.size();i++){
        order o("","",11,22,microsec_clock::local_time(), "");
        shared_ptr<processor> ob(new processor(n));
        shared_ptr<thread> thd(new thread(&processor::matchOrder, ob));
        this->_workers->insert({symbols[i], thd});
//        this->_workersObject->insert({thd, shared_ptr<processor>(new processor())});
        this->_workersObject->insert({thd, ob});
    }
};

//insert orders to books of different stocks
void core::run::insert(order& o) {
//    map<string, shared_ptr<thread> &obj = *this->_workers;
    shared_ptr<thread> thd = (*this->_workers)[o.symbol];
    shared_ptr<processor> ob = (*this->_workersObject)[thd];
    ob->insert(o);
}