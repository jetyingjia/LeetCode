#include "utils.h"

#ifdef TwoSum
/*
Given an array of integers, find two numbers such that they add up to a specific target number.
The function twoSum should return indices of the two numbers such that they add up to the target, 
where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <utility>

struct Node
{
	int value;
	int index;
	Node(int _value = 0, int _index = 0):value(_value), index(_index){};
	bool operator < (const Node &node) const
	{
		return value < node.value;
	}
};
std::vector<int> twoSum(std::vector<int> &numbers, int target) {
	std::vector<Node> numbersTemp(numbers.size());
	for(int i = 0; i < numbers.size(); i++)
	{
		numbersTemp[i].value = numbers[i];
		numbersTemp[i].index = i;
	}
	sort(numbersTemp.begin(), numbersTemp.end());
	int posLeft = 0;
	int posRight = numbersTemp.size() - 1;
	int sum;
	while(posLeft < posRight)
	{
		sum = numbersTemp[posLeft].value + numbersTemp[posRight].value;
		if(sum < target)
		{
			posLeft++;
		}
		else if(sum > target)
		{
			posRight--;
		}
		else
		{
			break;
		}
	}
	std::vector<int> Index;
	int i = numbersTemp[posLeft].index;
	int j = numbersTemp[posRight].index;
	if(i < j)
	{
		Index.push_back(i + 1);
		Index.push_back(j + 1);
	}
	else
	{
		Index.push_back(j + 1);
		Index.push_back(i + 1);
	}
	return Index;
}

std::vector<int> twoSumMap(std::vector<int> &numbers, int target)
{
	std::vector<int> Index;
	std::map<int, int> num;
	int start, end;
	for (int i = 0; i < numbers.size(); i++)
	{
		std::map<int, int>::const_iterator it = num.find(numbers[i]);
		if (it != num.end())
		{
			start = it->second + 1;
			end = i + 1;
			break;
		}
		else
		{
			num.insert(std::make_pair(target - numbers[i], i));
		}
	}
	if (start > end)
	{
		Index.push_back(end);
		Index.push_back(start);
	}
	else
	{
		Index.push_back(start);
		Index.push_back(end);
	}
	return Index;

}

int main()
{
	int N, target;
	std::vector<int> numbers;
	std::cout<<"Please input N and N numbers: ";
	std::cin>>N;
	for (int temp, i = 0; i < N; i++)
	{
		std::cin>>temp;
		numbers.push_back(temp);
	}
	std::cout<<"Please input the target: ";
	std::cin>>target;
	std::vector<int> result;
	//result = twoSum(numbers,target);
	result = twoSumMap(numbers,target);
	if (result.size() > 0)
	{
		std::cout<<result[0]<<"  "<<result[1];
	}	
	system("pause");
	return 0;
}

#endif