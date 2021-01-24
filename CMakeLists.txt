cmake_minimum_required(VERSION 3.16)
project(GFOX_Test)

set(CMAKE_CXX_STANDARD 14)

set(PROJECT_HEADERS)
set(PROJECT_SOURCES main.cpp core/notification.cpp core/notification.h model/notifyTrader.cpp model/notifyTrader.h model/order.cpp model/order.h core/run.cpp core/run.h core/placeorder.cpp core/placeorder.h core/processor.cpp core/processor.h utility/compare.cpp utility/compare.h)

SET (BOOST_ROOT "/usr/include/boost")
SET (BOOST_INCLUDEDIR "/usr/include")

find_package(Boost 1.66.0 COMPONENTS
        date_time thread iostreams REQUIRED) # <-- here

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(GFOX_Test ${PROJECT_SOURCES} ${PROJECT_HEADERS})
    target_link_libraries(GFOX_Test
            ${Boost_LIBRARIES}
            )
endif()