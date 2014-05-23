#include "utils.h"

#ifdef RemoveElement

#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <list>

int removeElement(int A[], int n, int elem)
{
	int i, j;
	for (i = 0, j = 0; i < n; i++)
	{
		if (elem != A[i])
		{
			A[j++] = A[i];
		}
	}
	return n ? j : 0;
}


int main()
{
	srand(clock());
	int N;
	std::cin>>N;
	int *a = new int[N];
	for (int i = 0; i < N; i++)
	{
		a[i] = rand() % 5;
	}
	for (int i = 0; i < N; i++)
	{
		std::cout<<a[i]<<" ";
	}
	int elem;
	std::cin>>elem;
	int length = removeElement(a, N, elem);
	std::cout<<"length:"<<length;
	for (int i = 0; i < length; i++)
	{
		std::cout<<a[i]<<" ";
	}
	system("pause");
	return 0;
}



#endif