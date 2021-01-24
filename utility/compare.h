//
// Created by admin on 1/23/21.
//

#ifndef GFOX_TEST_COMPARE_H
#define GFOX_TEST_COMPARE_H

#include "compare.h"
#include "../model/order.h"
#include "../utility/compare.h"
using namespace std;
using namespace model;
namespace utility {
    struct comparebuyorder {
        bool operator()(order const &p1, order const &p2);
    };
    struct comparesellorder {
        bool operator()(order const &p1, order const &p2);
    };
}


#endif //GFOX_TEST_COMPARE_H
