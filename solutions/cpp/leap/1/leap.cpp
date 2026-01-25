#include "leap.h"

namespace leap
{
	bool is_leap_year(int year)
	{
		bool res;

		res = false;
		if ((year % 4) == 0)
		{
			res = true;
			if ((year % 100) == 0)
				res = false;
			if ((year % 400) == 0)
				res = false;
		}
		return res;
	}

} // namespace leap
