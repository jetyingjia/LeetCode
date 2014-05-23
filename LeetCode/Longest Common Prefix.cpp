#include "utils.h"

#ifdef LongestCommonPrefix


#include <iostream>
#include <vector>
#include <string>


std::string longestCommonPrefix(std::vector<std::string> &strs) 
{
	std::string ans("");
	//字符串数组为空
	if(strs.size()==0)
	{
		return ans;
	}
	//字符串数组大小为1
	if(strs.size() == 1)
	{
		return strs[0];
	}
	//字符串数组大小大于1
	int count = 0;
	//j用来表示列,i用来表示第几个字符串
	for (int j = 0; j < INT_MAX; j++)
	{
		std::vector<char> result;
		for (int i = 0; i < strs.size(); i++)
		{
			if(j < strs[i].size() && strs[i].size() != 0)
			{
				//各个字符串的j列都和第0个字符串的j列比较
				if (strs[i][j]==strs[0][j]&&strs[i][j] != '\0')
				{
					result.push_back(strs[i][j]);	
				}  
				else
				{
					break;
				}
			}
		}
		//若j列都相同，则count++;有一个不同，则停止比较
		if (result.size() == strs.size())
		{
			count++;
		}
		else
		{
			j = INT_MAX - 1;
			break;
		}
	}

	if (count >= 0)
	{
		for (int i = 0; i < count; i++)
		{
			ans = ans + strs[0][i];			
		}	
	}
	return ans;

	
}



int main()
{
	std::vector<std::string> strs;
	strs.push_back("c");
	strs.push_back("c");
// 	std::string temp;
// 	int N;
// 	std::cout<<"Please input N strings: ";
// 	std::cin>>N;
// 	for (int i = 0; i < N; i++)
// 	{
// 		std::cin>>temp;
// 		strs.push_back(temp);
// 	}
	std::string ans = longestCommonPrefix(strs);
	std::cout<<ans;
	system("pause");
	return 0;

}












#endif