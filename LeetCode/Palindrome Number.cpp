#include "utils.h"

#ifdef PalindromeNumber

#include <iostream>

bool isPalindrome(int x)
{
	if (x < 0)
	{
		return false;
	}
	if (x >= 0 && x <= 9)
	{
		return true;
	}
	int a = 0, b = x;
	int cnt = 1;
	while(x /= 10)
	{
		cnt++;
	}
	for (; cnt >= 0 ;b = b / 10, cnt -= 2)
	{
		if (cnt == 1)
		{
			return a == (b / 10);
		}
		else if (cnt == 0)
		{
			return a==b;
		}
		a = a * 10 + b % 10;
	}
}




int main()
{
	int N;
	std::cin>>N;
	bool ans = isPalindrome(N);
	system("pause");
	return 0;

}







#endif