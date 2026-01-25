#include <string>
#include <iostream>
#include <sstream>

#if !defined(BEER_SONG_H)
#define BEER_SONG_H

using namespace std;

namespace beer_song
{
   
    string sing(int init, int end);
    string verse(int num);
    string sing(int num);
}

#endif