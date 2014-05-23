#include "utils.h"


#ifdef Sum3
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int> > threeSum(std::vector<int> &num)
{
	std::vector<std::vector<int> > ans;
	if(num.size() < 3) 
	{
		return ans;
	}
	sort(num.begin(), num.end());

	//从左向右扫描,后两个数一个在第一个数后边一个开始，一个从末尾开始
	for(int i = 0; i < num.size() - 2;)
	{
		for(int left = i + 1, right = num.size() - 1; left <right;)
		{
			int tmpsum = num[i] + num[left] + num[right];
			if(tmpsum < 0) 
			{
				left ++;
			}
			else if(tmpsum > 0) 
			{
				right --;
			}
			else
			{
				std::vector<int> tmp;
				tmp.push_back(num[i]);
				tmp.push_back(num[left]);
				tmp.push_back(num[right]);
				ans.push_back(tmp);
				left ++;
				right --;
			}
			while(left != i + 1 && left < right && num[left] == num[left - 1])
			{
				left++;
			}
			while(right != num.size() - 1 && left < right && num[right] == num[right + 1])
			{
				right--;
			}
		}
		i++;
		while(i < num.size() && num[i] == num[i - 1])
		{
			i++;
		}
	}
	return ans;
}

int main()
{
	int N;
	std::cin>>N;
	std::vector<int> num;
	for (int i = 0; i < N; i++)
	{
		int temp;
		std::cin>>temp;
		num.push_back(temp);
	}
	std::vector< std::vector<int> > ans = threeSum(num);
	for (int i = 0; i < ans.size(); i++)
	{
		for (int j = 0; j < ans[i].size(); j++)
		{
			std::cout<<ans[i][j];
		}
		std::cout<<std::endl;
	}
	system("pause");
	return 0;
}

#endif