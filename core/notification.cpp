//
// Created by admin on 1/23/21.
//

#include "notification.h"
void core::notification::notify(notifyTrader& obj) {
    lock_guard<mutex> lock(m_lock_notification);
    cout << "=================" << endl;
    cout << "Notify Sucess!" << endl;
    cout << "side:"<< obj.side << " symbol:" <<obj.symbol << " traderID:" << obj.traderID<< " quantity:" << obj.totalQuantity<< " price:" << obj.price << endl;
    cout << "=================" << endl;
}