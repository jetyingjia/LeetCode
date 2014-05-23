#include "utils.h"

#ifdef RomantoInteger

#include <iostream>
#include <vector>
#include <string>

int roman[128];
int romanToInt(std::string s) 
{
	roman['I'] = 1;
	roman['V'] = 5;
	roman['X'] = 10;
	roman['L'] = 50;
	roman['C'] = 100;
	roman['D'] = 500;
	roman['M'] = 1000;
	int ans = 0;
	int pre;
	//大数后面是小数，则减；
	//大数前面是小数，则加；
	for(int i = s.size() - 1; i >= 0; i--)
	{
		if(ans == 0) 
		{
			ans = roman[s[i]];
		}
		else
		{
			if(pre > roman[s[i]]) 
			{
				ans -= roman[s[i]];
			}
			else 
			{
				ans += roman[s[i]];
			}
		}
		pre = roman[s[i]];
	}
	return ans;
}



int main()
{
	std::string str("DCXXI");
	//std::cin>>str;
	int ans = romanToInt(str);
	std::cout<<ans;
	system("pause");
	return 0;

}










#endif