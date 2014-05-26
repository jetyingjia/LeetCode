#include "utils.h"

#ifdef NextPermutation

#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>
#include <string>


void nextPermutation(std::vector<int> &num)
{
	int i, j;
	i = num.size() - 2;
	j = num.size() - 1;
	//�Ӻ���ǰ�ң����ҵ�������ǽ���ĵ�һ������
	while(i >= 0 && num[i] >= num[i + 1])
	{
		i--;
	}
	//�Ӻ���ǰ�ң��ҵ����������ҵ��ķǽ���ĵ�һ����
	while(j >= 0 && num[j] <= num[i])
	{
		j--;
	}
	if(i < j)
	{
		int temp;
		temp = num[j];
		num[j] = num[i];
		num[i] = temp;
		//swap(num[i], num[j]);
		sort(num.begin() + i + 1, num.end());
	}
	else
	{
		reverse(num.begin(), num.end());
	}
		
}


int main ()
{
	srand(clock());
	std::vector<int> num;
	for (int i = 0 ; i < 10; i++)
	{
		int temp;
		temp = rand() % 10;
		num.push_back(temp);
	}
	for (int i = 0; i < num.size(); i++)
	{
		std::cout<<num[i];
	}

	std::cout<<std::endl;

	nextPermutation(num);
	for (int i = 0; i < num.size(); i++)
	{
		std::cout<<num[i];
	}
	system("pause");
	return 0;

}

#endif