#include "secret_handshake.h"

namespace secret_handshake
{
    map<int, string> localcode = {{0, "wink"}, {1, "double blink"}, {2, "close your eyes"}, {3, "jump"}};

    vector<string> commands(int num)
    {
        vector<string> res;
        string bin;

        res = {};
        while (num != 0)
        {
            bin += (num % 2 == 0 ? "0" : "1");
            num /= 2;
        }
        for (int i = 0; i < (int)bin.length(); i++)
        {
            if (i == 4)
                reverse(res.begin(), res.end());
            else if (bin[i] == '1')
                res.push_back(localcode[i]);
        }
        return res;
    }
}
