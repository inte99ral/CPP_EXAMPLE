#include "testTimer/testTimer.hpp"

TestTimerObject::TestTimerObject() {
    std::cout << "* TEST TIMER OBJ CONSTRUCT" << std::endl;
}

TestTimerObject::~TestTimerObject() {
    std::cout << "* TEST TIMER OBJ ~DESTRUCT" << std::endl;
}

void TestTimerObject::Timer5Sec() {
    std::cout << "\n5 sec Timer" << std::endl;

    boost::asio::io_context io;
    boost::asio::deadline_timer t(io, boost::posix_time::seconds(5));

    t.wait();
    std::cout << "5 sec time over\n" << std::endl;
}