#include "utils.h"

#ifdef RegularExpressionMatching

#include <iostream>


bool isMatch(const char *s, const char *p) 
{
	if(*p == 0) 
	{
		return *s == 0;
	}
	//������'*'�����
	if(*(p + 1) != '*')
	{
		//����ʱ*s��*p��ȣ������isMatch(s+1, p+1)���ж�
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
			//����'*'���бȽ�
			if(isMatch(s, p + 2))
			{
				return true;   
			}
		}
		//*�����ֵ��s+1��ƥ�䣬������2���㣬�Ƚ�s��p+2
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