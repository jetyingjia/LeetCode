#include "utils.h"

#ifdef StringtoInteger

#include <iostream>
#include <vector>

int atoi1(const char *str)
{
	long long ans = 0;
	bool postive = true;
	while(*str == ' ')
	{
		str++;
	}
	if(*str == '+') 
	{	
		str ++;
	}
	else if(*str == '-')
	{
		postive = false;
		str ++;
	}
	while(*str >= '0' && *str <= '9')
	{
		ans = ans * 10 + *str - '0';
		if(postive && ans > INT_MAX)
		{
			return INT_MAX;
		}
		if(!postive && -ans < INT_MIN)
		{
			return INT_MIN;
		}
		str++;
	}
	return (int)(postive ? ans : -ans);
		
}

int main()
{
	char a[10] = {'2'};
	a[9] = '\0';
	const char *p = a;
	int ans = atoi1(p);
	system("pause");
	return 0;
}






#endif