#include "allergies.h"

namespace allergies
{
    allergy_test::allergy_test(unsigned int ind)
    {
        code = "";
        
        while ((ind > 0) && (code.length() < nomb.size()))
        {
            code += (ind % 2 == 0 ? "0" : "1");
            ind /= 2;
        }
    }

    bool allergy_test::is_allergic_to(string cad)
    {
        bool res;
        int iter;
        int leng;

        res = false;
        iter = 0;
        leng = code.size();
        while (!res && (iter < leng))
        {
            if (code[iter] == '1')
                res = nomb[iter] == cad;

            iter++;
        }
        return res;
    }

    unordered_set<std::string> allergy_test::get_allergies()
    {
        unordered_set<std::string> res;
        int leng;

        leng = code.size();
        for (int i = 0; i < leng; i++)
            if (code[i] == '1')
                res.insert(nomb[i]);
        return res;
    }
}
