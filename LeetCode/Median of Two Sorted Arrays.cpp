#include "utils.h"

#ifdef Median
//There are two sorted arrays A and B of size m and n respectively. 
//Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

#include <iostream>
#include <vector>
#include <string>
//#include <algorithm>
#include <windows.h>


double findKth(int A[], int m, int B[], int n, int k)
{
	//always m<=n
	if(m > n)
	{
		return findKth(B, n, A, m, k);
	}

	if(m == 0)
	{
		return B[k -1];
	}
	if(k == 1)
	{
		return min(A[0], B[0]);
	}
	//if A[k/2-1] < B[k/2-1], that means all the elements from A[0] to A[k/2-1]
	//(i.e. the k/2 smallest elements in A) are in the range of k smallest elements in the union of A and B. 
	//Or, in the other word, A[k/2 - 1] can never be larger than the k-th smalleset element in the union of A and B.
	int posA = min(m, k/2);
	int posB = k - posA;
	if(A[posA - 1] < B[posB - 1])
	{
		return findKth(A + posA, m - posA, B, n, k - posA);
	}
	else if(A[posA -1] > B[posB - 1])
	{
		return findKth(A, m, B + posB, n - posB, k - posB);
	}
	else
	{
		return A[posA - 1];
	}
}

double findMedianSortedArrays(int A[], int m, int B[], int n) {
	if((m+n)&0x01)//odd
	{
		return findKth(A, m, B, n,(m + n)/2 + 1);
	}
	else //even
	{
		return (findKth(A, m, B, n, (m + n)/2) + findKth(A, m, B, n, (m + n)/2 + 1))/2;
	}


}

int main()
{
	int A[6] = {1,2,3,4,5,6};
	int B[5] = {2,4,6,8,9};
	double mid = findMedianSortedArrays(A, 6, B, 5);
	std::cout<<mid;
	system("pause");
	return 0;
}

#endif


