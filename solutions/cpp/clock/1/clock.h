#include <string>
#include <utility>

using namespace std;

#if !defined(CLOCK_H)
#define CLOCK_H

namespace date_independent
{

    class clock
    {
    private:
        int hour;
        int minute;
        void calculus(int position, int offset);

    public:
        bool operator==(const clock &dat) const;
        bool operator!=(const clock &dat) const;
        operator std::string() const;
        static clock at(int hour, int minute);
        clock plus(int add);
    };
}
#endif // CLOCK_H