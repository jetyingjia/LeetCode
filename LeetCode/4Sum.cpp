#include "utils.h"

#ifdef Sum4

#include <iostream>
#include <vector>
#include <algorithm>

std::vector< std::vector<int> > fourSum(std::vector<int> &num, int target)
{
	std::vector< std::vector<int> > ans;
	if (num.size() < 4)
	{
		return ans;
	}
	sort(num.begin(), num.end());

	//排序后,从左到右扫描;中间两个数一个从left+1,一个从right-1开始
	for (int left = 0; left < num.size() - 3;)
	{
		for (int right = num.size() - 1; right > left + 2;)
		{
			int ml = left + 1; 
			int mr = right - 1;
			while (mr > ml)
			{
				int temp = num[left] + num[ml] + num[mr] + num[right];
				if (temp > target)
				{
					mr--;
					while(num[mr] == num[mr + 1])
					{
						mr--;
					}
				}
				else if (temp < target)
				{
					ml++;
					while(num[ml] == num[ml - 1])
					{
						ml++;
					}
				}
				else
				{
					std::vector<int> temp;
					temp.push_back(num[left]);
					temp.push_back(num[ml]);
					temp.push_back(num[mr]);
					temp.push_back(num[right]);
					ans.push_back(temp);

					mr--;
					ml++;
					while(ml < mr && num[mr] == num[mr + 1])
					{
						mr--;
					}
					while(ml < mr && num[ml] == num[ml - 1])
					{
						ml++;
					}

				}
			}
			right --;
			while(left < right && num[right] == num[right + 1])
			{
				right--;
			}
		}
		left++;
		while(num[left] == num[left - 1])
		{
			left++;
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
	std::vector< std::vector<int> > ans = fourSum(num, target);

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