#ifndef TEST_TIMER_HPP
#define TEST_TIMER_HPP

#include <iostream>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

class TestTimerObject {
  public:
    TestTimerObject();
    ~TestTimerObject();
    void Timer5Sec();
};

#endif