#include "utils.h"

#ifdef ReverseInteger

#include <iostream>
#include <vector>

int reverse(int x) 
{
	int ans = 0;
	bool postive = true ;
	if (x < 0)
	{
		postive = false;
		x = -x;
	}
	while(x > 0)
	{
		ans = 10 * ans + x % 10;
		x = x/10;
	}
	if (postive == false)
	{
		return -ans;
	}
	return ans;
}



int main()
{
	int value;
	std::cin>>value;
	int ans = reverse(value);
	system("pause");
	return 0;
}







#endif