#include "utils.h"


#ifdef LetterCombinationsofaPhoneNumber

#include <iostream>
#include <vector>
#include <string>

void DFS(int pos, std::string digits, std::string &temp, std::vector<std::string> map, std::vector<std::string> &ans)
{
	if (pos == digits.length())
	{
		ans.push_back(temp);
		return ;
	}
	for (int i = 0; i < map[digits[pos] - '0'].length(); i++)
	{
		temp[pos] = map[digits[pos] - '0'][i];
		DFS(pos + 1, digits, temp, map, ans);
	}
}



std::vector<std::string> letterCombinations(std::string digits)
{
	std::string temp;
	std::vector<std::string> ans;
	temp.resize(digits.length());
	std::string m[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	std::vector<std::string> map;
	for (int i = 0; i < 10; i++)
	{
		map.push_back(m[i]);
	}
	DFS(0, digits, temp, map, ans);
	return ans;
}


//²ÉÓÃBFS
void BFS(int pos, std::string digits, std::vector<std::string> map, std::vector<std::string> &ans)
{
	if (pos == digits.size())
	{
		return ;
	}
	std::vector<std::string> ansTemp = ans;
	ans.clear();
	if (ansTemp.size() == 0)
	{
		for (int j = 0; j < map[digits[pos] - '0'].length(); j++)
		{
			std::string temp;
			temp.resize(1);
			temp[0] = map[digits[pos] - '0'][j];
			ans.push_back(temp);
		}
	}
	else
	{
		for (int i = 0; i < ansTemp.size(); i++)
		{
			for (int j = 0; j < map[digits[pos] - '0'].length(); j++)
			{
				std::string temp  = ansTemp[i] + map[digits[pos] - '0'][j];
				ans.push_back(temp);
			}
		}
	}	
	BFS(pos + 1, digits, map, ans);
}

std::vector<std::string> letterCombinationsBFS(std::string digits)
{
	std::string temp;
	std::vector<std::string> ans;
	temp.resize(digits.length());
	std::string m[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	std::vector<std::string> map;
	for (int i = 0; i < 10; i++)
	{
		map.push_back(m[i]);
	}
	if(digits.size() == 0)
	{
		ans.push_back("");
		return ans;
	}
	BFS(0, digits, map, ans);

	return ans;
}



int main()
{
	std::string str;
	std::string temp;
	for (int i = 0; i < 3; i++)
	{
		std::cin>>temp;
		str = str + temp;
	}
	std::vector<std::string> ans = letterCombinations(str);
	int i = 0;
	system("pause");
	return 0;
}













#endif