#include "beer_song.h"

namespace beer_song
{
    string verse(int num)
    {
        stringstream res;

        switch (num)
        {
        case 0:
            res << "No more bottles of beer on the wall, no more bottles of beer.\n";
            res << "Go to the store and buy some more, 99 bottles of beer on the wall.\n";
            break;
        case 1:
            res << "1 bottle of beer on the wall, 1 bottle of beer.\n";
            res << "Take it down and pass it around, no more bottles of beer on the wall.\n";
            break;
        case 2:
            res << "2 bottles of beer on the wall, 2 bottles of beer.\n";
            res << "Take one down and pass it around, 1 bottle of beer on the wall.\n";
            break;
        default:
            res << num << " bottles of beer on the wall, " << num << " bottles of beer.\n"
                << "Take one down and pass it around, " << num - 1 << " bottles of beer on the wall.\n";
            break;
        }
        return res.str();
    }

    string sing(int init, int end)
    {
        string res;
        int iter;

        iter = init;
        while (iter >= end)
        {
            if (iter != init)
                res += "\n";
            res += verse(iter);
            iter--;
        }
        return res;
    }

    string sing(int num)
    {
        return sing(num, 0);
    }

} // namespace beer_song
