#include "isogram.h"
#include "stdio.h"

bool	is_isogram(const char phrase[])
{
	char		aux1;
	char		aux2;
	const char	*iter;
	bool		res;

	res = (phrase != 0) ? true : false;
	while (res && *phrase != '\0')
	{
		aux1 = (*phrase <= 'Z') ? (*phrase) + 32 : *phrase;
		if (aux1 >= 'a' && aux1 <= 'z')
		{
			iter = phrase + 1;
			while (*iter != '\0' && res)
			{
				aux2 = (*iter <= 'Z') ? (*iter) + 32 : *iter;
				if (aux1 != aux2)
					iter++;
				else
					res = false;
			}
		}
		phrase++;
	}
	return (res);
}
