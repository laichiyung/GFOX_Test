//
// Created by admin on 1/23/21.
//

#ifndef GFOX_TEST_NOTIFYTRADER_H
#define GFOX_TEST_NOTIFYTRADER_H
#include <iostream>
#include <boost/date_time/posix_time/posix_time.hpp>
using namespace std;
using namespace boost::posix_time;

namespace model{
    //notify trader message structure
    class notifyTrader {
    public:
        notifyTrader(string traderID, string symbol, long quantity, long price, ptime orderDateTime, string side);
        string traderID;
        string symbol;
        long quantity;
        long totalQuantity;
        long price;
        ptime orderDateTime;
        string side;
    };
};


#endif //GFOX_TEST_NOTIFYTRADER_H
