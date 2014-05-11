#include "utils.h"

#ifdef Longest

//Longest Substring Without Repeating Characters
#include <iostream>
#include <vector>
#include <string>
int lengthOfLongestSubstring(std::string s) 
{
	int slen = s.length();  
	if(slen <= 0) 
	{
		return 0;   
	}  
	if(slen == 1)
	{
		return 1;
	}
	//前一个字母对应的字串的长度（往前算：如bccbbc对应pre：121212）
	int pre = 1;
	int longest = 1;
	for(int i = 1; i < slen; ++i)  
	{  
		char tmp = s[i];  
		int j = i-1;  
		int count = 1;  
		while((j>=0) && (tmp != s[j]))  
		{
			j--;
			count++;
		}  
		if(count >= pre+1)
			count = pre+1;  
		if(count > longest) 
			longest = count;  
		pre = count;  
	}  
	return longest;  
}


int main()
{
	std::string str("bccbbc");
	int length = 0;
	length = lengthOfLongestSubstring(str);
	std::cout << length;
	system("pause");

}

#endif
