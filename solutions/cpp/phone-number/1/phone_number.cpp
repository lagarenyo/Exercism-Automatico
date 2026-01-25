#include "phone_number.h"

string phone_number::phone_number::clear_number(const string str)
{
    string res;

    res = "";
    for (char c : str)
        if (isdigit(c))
            res += c;
    if (res.length() != 10)
        throw std::domain_error("");
    return res;
}

phone_number::phone_number::phone_number(const string str)
{
    int pos;

    pos = 0;
    if (str.substr(0, 2) == "+1")
        this->number_inserted = str.substr(2);
    else if (str[0] == '1')
        this->number_inserted = str.substr(1);
    else
        this->number_inserted = str;
    while (this->number_inserted[pos] == ' ')
        pos++;
    this->number_inserted = this->number_inserted.substr(pos);
    this->number_value = this->clear_number(this->number_inserted);
    if ((this->number_value[0] < '2') || (this->number_value[3] < '2'))
        throw std::domain_error("");
}

string phone_number::phone_number::area_code() const
{
    return this->number_value.substr(0, 3);
}

string phone_number::phone_number::number() const
{
    return this->number_value;
}

phone_number::phone_number::operator std::string() const
{
    return this->number_inserted;
}
