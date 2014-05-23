#include "utils.h"

#ifdef ImplementstrStr

#include <iostream>
#include <vector>
#include <string>


std::vector<int> getNext(char *needle)
{
	int nlen = (int) strlen(needle);
	std::vector<int> next;
	next.resize(nlen);
	next[0] = -1;
	int i = 0;
	int j = -1;
	while(i < nlen - 1)
	{
		if (j == -1 || needle[i] == needle[j])
		{
			++j;
			++i;
			if (needle[i] != needle[j])
			{
				next[i] = j;
			}
			else
			{
				next[i] = next[j]; 
			}
		}
		else
		{
			j = next[j];
		}
	}
	return next;
}


//KMP
char *strStr(char *haystack, char *needle)
{
	int nlen = (int)strlen(needle), hlen = (int)strlen(haystack);
	if (nlen > hlen || haystack == NULL || needle == NULL)
	{
		return NULL;
	}
	if (nlen == 0)
	{
		return haystack;
	}
	std::vector<int> next = getNext(needle);
	int i = 0, j = 0;
	while(i < hlen && j < nlen)
	{
		if (j == -1 || haystack[i] == needle[j])
		{
			++i;
			++j;
		}
		else
		{
			j = next[j];
		}
	}
	if (j >= nlen)
	{
		return haystack + i - nlen;
	}
	else
	{
		return NULL;
	}
}





int main()
{

	char haystack[10], needle[5];

	std::cout<<"haystack: 10";
	for (int i = 0; i < 9; i++)
	{
		char temp;
		std::cin>>temp;
		haystack[i] = temp;
	}
	haystack[9] = '\0';

	std::cout<<"needle: 8";
	for (int i = 0; i < 8; i++)
	{
		char temp;
		std::cin>>temp;
		needle[i] = temp;
	}
	needle[8] = '\0';

	char *ans = strStr(haystack,needle);

	while(ans != '\0')
	{
		std::cout<<*ans;
		ans++;
	}

	system("pause");
	return 0;



}











#endif