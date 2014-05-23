#include "utils.h"
#ifdef RemoveDuplicatesfromSortedArray

#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <algorithm>

int removeDuplicates(int A[], int n)
{
	int i, j;
	for (i = j = 1; i < n; i++)
	{
		if (A[i] != A[i - 1])
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

	int length = removeDuplicates(a, N);
	std::cout<<length<<std::endl;
	for (int i = 0; i < length; i++)
	{
		std::cout<<a[i]<<" ";
	}
	system("pause");
	return 0;

}

#endif