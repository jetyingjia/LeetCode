#include "utils.h"

#ifdef ContainerWithMostWater

#include <iostream>
#include <vector>
#include <windows.h>

int maxArea(std::vector<int> &height) 
{
	int ans = 0;
	int leftPos, rightPos;
	leftPos = rightPos = height.size();
	while(leftPos < rightPos)
	{
		ans = max(ans, min(height[leftPos], height[rightPos]) * (rightPos - leftPos));
		if (height[leftPos] < height[rightPos])
		{
			leftPos++;
		}
		else
		{
			rightPos++;
		}
	}
	return ans;
}

int main()
{
	std::vector<int> height;
	int temp = 0;
	while ((std::cin>>temp) && temp != -1)
	{
		height.push_back(temp);
	}
	int ans = maxArea(height);
	std::cout<<ans;
	system("pause");
	return 0;
}



#endif