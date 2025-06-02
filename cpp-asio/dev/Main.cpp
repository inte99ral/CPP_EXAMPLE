#include <bits/stdc++.h>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

using namespace std;
using namespace boost::asio;
using namespace boost::posix_time;

int main(int argc, char* argv[]) {
    // 코드 내용
    cout << "5 sec Timer" << endl;

    io_context io;
    deadline_timer t(io, seconds(5));

    t.wait();
    cout << "5 sec time over" << endl;

    return 0;
}

