#include <string>
#include <stdexcept>

using namespace std;

#if !defined(PHONE_NUMBER_H)
#define PHONE_NUMBER_H

namespace phone_number
{
    class phone_number
    {
    private:
        string number_inserted;
        string number_value;
        string clear_number(const string str);

    public:
        phone_number(const string str);
        string area_code() const;
        string number() const;
        operator std::string() const;
    };
}

#endif