#include "gigasecond.h"

using namespace boost::posix_time;

namespace gigasecond
{
    ptime advance(ptime dat)
    {
        return dat + seconds(1000000000);
    }
}
