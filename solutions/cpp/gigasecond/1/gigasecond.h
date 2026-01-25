#include "boost/date_time/posix_time/posix_time.hpp"

#if !defined(GIGASECOND_H)
#define GIGASECOND_H

using namespace boost::posix_time;

namespace gigasecond
{
    ptime advance(ptime dat);
}

#endif