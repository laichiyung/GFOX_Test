//
// Created by admin on 1/23/21.
//

#ifndef GFOX_TEST_NOTIFICATION_H
#define GFOX_TEST_NOTIFICATION_H

#include <iostream>
#include "../model/notifyTrader.h"
#include <mutex>
using namespace std;
using namespace model;
namespace core {
    class notification {
    public:
        mutex m_lock_notification;
        void notify(notifyTrader& obj);
    };
}


#endif //GFOX_TEST_NOTIFICATION_H
