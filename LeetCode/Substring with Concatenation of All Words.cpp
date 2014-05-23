#include "utils.h"

#ifdef SubstringwithConcatenationofAllWords

#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
std::vector<int> findSubstring(std::string S, std::vector<std::string> &L) 
{
// 	std::vector<int> ans;
// 	if (L.size() == 0)
// 	{
// 		return ans;
// 	}
// 	int count = L.size();
// 	int length = L[0].size();
// 	if (S.length() < length);
// 	{
// 		return ans;
// 	}
// 	std::map<std::string, int> words;
// 	for (int i = 0; i < count; i++)
// 	{
// 		if (words.count(L[i]))
// 		{
// 			words.find(L[i])->second++;
// 		}
// 		else
// 		{
// 			//words.insert(std::make_pair(L[i], 1));
// 			words[L[i]] = 1;
// 		}
// 	}
	//for (int i = 0; i < S.length(); i++)
// 	{
// 		int countTemp = L.size();
// 		int pos = i;
// 		std::map<std::string, int> tempMap = words;
// 		int m = i;
// 		while(m + length * countTemp <= S.length())
// 		{
// 			std::string temp; 
// 			temp.resize(length);
// 			for (int k =0, j = m; j < m + length; j++, k++)
// 			{
// 				temp[k] = S[j];
// 			}
// 			if(tempMap.count(temp))
// 			{
// 				tempMap.find(temp)->second--;
// 				if (tempMap.find(temp)->second == 0)
// 				{
// 					tempMap.erase(temp);
// 				}
// 				m = m + length;
// 				countTemp--;
// 				if (countTemp == 0)
// 				{
// 					ans.push_back(pos);
// 					i = pos + length - 1;
// 					break;
// 				}	
// 			}
// 			else
// 			{
// 				//i = pos + length - 1;
// 				break;
// 			}
// 		}
// 	}
// 	return an}
	vector<int> ans;
	if(L.size() == 0) return ans;
	map<string, int> mp, sum;
	int llen = L[0].length(), i, front, rear;
	for(int i = 0; i < L.size(); i ++)
	{
		if(!mp.count(L[i]))
		{
			mp[L[i]] = 1;
		}
		else
		{
			mp[L[i]] ++;
		}
	}
	for(i = 0; i < llen; i ++)
	{
		int m = i;
		sum = mp;
		int cnt = 0;
		for(front = rear = i; front + llen <= S.length(); front += llen)
		{
			string tmp = S.substr(front, llen);
			if(sum.count(tmp))
			{
				if(sum[tmp] > 0)
				{
					sum[tmp] --;
					cnt ++;
					if(cnt == L.size())
					{
						ans.push_back(rear);
					}
				}
				else
				{
					while(sum[tmp] == 0)
					{
						string ntmp = S.substr(rear, llen);
						sum[ntmp] ++;
						cnt --;
						rear += llen;
					}
					sum[tmp] --;
					cnt ++;
					if(cnt == L.size())
					{
						ans.push_back(rear);
					}
				}
			}
			else
			{
				while(rear < front)
				{
					string ntmp = S.substr(rear, llen);
					sum[ntmp] ++;
					cnt --;
					rear += llen;
				}
				rear += llen;
				cnt = 0;
			}
		}
	}
	return ans;
}

int main()
{
	std::string s("lingmindraboofooowingdingbarrwingmonkeypoundcake");
	std::vector<std::string> L;
// 	for (int i = 0; i < 2; i++)
// 	{
// 		std::string temp;
// 		std::cin>>temp;
// 		L.push_back(temp);
// 	}
	L.push_back("fooo");
	L.push_back("barr");
	L.push_back("wing");
	L.push_back("ding");
	L.push_back("wing");
	std::vector<int> ans = findSubstring(s, L);
	std::cout<<std::endl;
	system("pause");
	return 0;
}













#endif