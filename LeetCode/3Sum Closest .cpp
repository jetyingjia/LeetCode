#include "utils.h"

#ifdef Sum3Closest



#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>

int threeSumClosest(std::vector<int> &num, int target)
{
	int ans;
	bool ansFind = false;
	sort(num.begin(), num.end());
	if (num.size() == 3)
	{
		return num[0] + num[1] + num[2];
	}
	for (int i = 0; i < num.size() - 2; i++)
	{
		for (int left = i + 1, right = num.size() - 1; left < right; )
		{
			int temp = num[i] + num[left] + num[right];
			if(temp < target)
			{
				left++;
				//遇到重复的数字，快速处理
				while (num[left] == num[left - 1]&& left < right)
				{
					left++;
				}
			}
			else if(temp > target)
			{
				right--;
				//遇到重复的数字，快速处理
				while(num[right] == num[right+1]&& left < right)
				{
					right--;
				}
			} 
			else
			{
				return target;
			}
			//ansFind用来判断ans是否已经被赋过值，用于第一次的初始化
			if (!ansFind || abs(target - temp) < abs(target - ans))
			{
				ans = temp;
				ansFind = true;
			}
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
	int target;
	std::cout<<"Please intput target: ";
	std::cin>>target;
	int ans = threeSumClosest(num, target);
	std::cout<< ans;
	system("pause");
	return 0;




}

#endif