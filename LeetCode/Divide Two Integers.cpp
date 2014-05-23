#include "utils.h"
#ifdef DivideTwoIntegers

#include <iostream>
#include <vector>

int divide(int dividend, int divisor)
{
	bool flag = false;
	if(divisor > 0) 
	{
		divisor = -divisor;
		flag ^= true;
	}
	if(dividend > 0)
	{
		dividend = -dividend;
		flag ^= true;
	}
	int ans = 0, res = divisor, ex = 1;
	if(divisor < dividend)
	{
		return 0;
	}
	while(res >= dividend - res)
	{
		res += res;
		ex += ex;
	}
	while(res <= divisor && dividend)
	{
		if(res >= dividend)
		{
			dividend -= res;
			ans += ex;
		}
		res >>= 1;
		ex >>= 1;
	}
	return flag ? -ans : ans;
}

int main()
{
	int dividend, divisor;
	std::cin>>dividend>>divisor;
	int ans = divide(dividend, divisor);
	system("pause");
	return 0;
}

#endif