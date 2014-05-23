#include "utils.h"
#ifdef LongestPalindromicSubstring

/*
Given a string S, find the longest palindromic substring in S. 
	You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/



#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <map>
#include "time.h"
#include <Windows.h>


// std::string longestPalindrome(std::string s)
// {
// 	int len = 0;
// 	int start = 0, end = 0;
// 	std::string ans("");
// 	std::map< char,std::vector<int> > a;
// 	std::vector<int> temp;
// 	clock_t starttime, endtime;
// 	for (int i = 0; i < s.size(); i++)
// 	{
// 		
// 		 starttime = clock();
// 	
// 		//若已经存在s[i]
// 		//int exist = a.count(s[i]);
// 		std::map<char, std::vector<int> >::iterator it = a.find(s[i]);
// 		if (it != a.end())
// 		{
// 			it->second.push_back(i);
// 		}
// 		else
// 		{
// 			//clock_t start = clock();
// 			temp.push_back(i);
// 			a.insert(std::make_pair(s[i], temp));
// 			temp.clear();
// 			it = a.find(s[i]);
// 		}
// 		
// 		int count = 0;
// 		for (int l = 0; l < it->second.size(); l++)
// 		{
// 			int k = it->second[l];
// 			int m = i;
// 			while(m >= k && s[m] == s[k])
// 			{
// 				if (m <= k)
// 				{
// 					break;
// 				}
// 				m--;
// 				k++;
// 			}
// 			if (i - it->second[l] < len)
// 			{
// 				l = it->second.size();
// 				continue;
// 			}
// 			if (m >= 0 && (m == k || k - m == 1))
// 			{
// 				count = i - it->second[l] + 1;
// 				if (count > len)
// 				{
// 					len = count;
// 					start = it->second[l];
// 					end = i;
// 				}
// 				l = it->second.size();
// 			}
// 			
// 		}
// 		endtime = clock();
// 		if (i == 900)
// 		{
// 			std::cout<<"time: "<<endtime - starttime<<std::endl;
// 		}
// 		
// 	}
// 	ans = s.substr(start, end);
// 	return ans;
// }

// std::string findPal(std::string &s, int left, int right)
// {
// 	if (left < 0)
// 		return s.substr(left+1, 1);
// 
// 	if (right >= s.size())
// 		return s.substr(right-1, 1);
// 
// 	while(0 <= left && right < s.size())
// 	{
// 		if (s[left] != s[right])
// 			break;
// 		left--;
// 		right++;
// 	}
// 
// 	left++;
// 	right--;
// 
// 	return s.substr(left, right - left + 1);        
// }

std::string findStr(std::string s, int left, int right)
{
	if (left < 0)
	{
		return s.substr(left+1, 1);
	}
	if (right > s.size() - 1)
	{
		return s.substr(right-1, 1);
	}

	while(left >= 0 && right <= s.size() - 1)
	{
		if (s[left] == s[right])
		{
			left --;
			right ++;
		}
		else
		{
			break;
		}
		
	}
	left ++;
	right --;
	return s.substr(left, right - left + 1);
}

std::string longestPalindrome(std::string s)
{
	if (s.size() <= 1)
	{
		return "";
	}
	std::string ans;
	for (int i = 0; i < s.size(); i++)
	{
		//s[i]位于回文数的中间
		std::string rct = findStr(s, i - 1, i + 1);
		if (rct.size() > ans.size())
		{
			ans = rct;
		}
		rct = findStr(s, i, i + 1);
		if (rct.size() > ans.size())
		{
			ans = rct;
		}
	}
	return ans;
}

int main()
{
//	std::string str;
// 	int N;
// 	std::cout<<"please int N and N characters: ";
// 	std::cin>>N;
// 	std::cin>>str;
	std::string str(500,'a');
	
	clock_t start = clock();
	std::string ans = longestPalindrome(str);
	clock_t end = clock();
	std::cout <<"total: "<< end - start;

	system("pause");
	return 0;



}



#endif