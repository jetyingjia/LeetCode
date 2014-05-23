#include "utils.h"

#ifdef RegularExpressionMatching

#include <iostream>


bool isMatch(const char *s, const char *p) 
{
	if(*p == 0) 
	{
		return *s == 0;
	}
	//不等于'*'的情况
	if(*(p + 1) != '*')
	{
		//若此时*s和*p相等，则进行isMatch(s+1, p+1)的判断
		if(*s && (*s == *p || *p == '.'))
		{
			return isMatch(s + 1, p + 1);
		}
		return false;
	}
	else
	{
		for(; *s && (*s == *p || *p == '.'); s++)
		{
			//不带'*'进行比较
			if(isMatch(s, p + 2))
			{
				return true;   
			}
		}
		//*代表的值和s+1不匹配，则跳过2个点，比较s和p+2
		return isMatch(s, p + 2);	
	}

}


int main()
{
//  const char s[]= {'a','a','a','b','a','a','a','a','b','a','b','c','b','c','c','b','a','a','b', '\0'};
// 	const char p[]= {'c','*','c','*','.','*','c','*','a','*','.','.','*','c','*','\0'};
	const char s[] = {'a','b','\0'};
	const char p[] = {'.','*','c','c','c','\0'};


	bool ans = isMatch(s, p);
	system("pause");
	return 0;

	
}








#endif