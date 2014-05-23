#include "utils.h"

#ifdef SwapNodesinPairs

#include <iostream>
#include <vector>
#include <string>
#include <time.h>


struct ListNode
{
	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {} 
};


ListNode *swapPairs(ListNode *head)
{
   if (head == NULL)
   {
	   return head;
   }
   int count = 1;
   ListNode *p = head;
   int temp;
   while(p != NULL)
   {
	   if (count % 2 == 1)
	   {
		  if (p->next != NULL)
		  {
			  temp = p->val;
			  p->val = p->next->val;
			  p->next->val = temp;
		  }  
	   }
	   p = p->next;
	   count++;
   }
   return head;
}



int main()
{
	srand(clock());
	ListNode *head = new ListNode(0);
	ListNode *p = head;
	int N;
	std::cin>>N;
	for (int i = 0; i < N; i++)
	{
		p->val = rand()%25;
		if (i + 1 < N)
		{
			p->next = new ListNode(0);
			p = p->next;
		}
	}
	p = head;
	while(p != NULL)
	{
		std::cout<<p->val<<" ";
		p = p->next;
	}
	swapPairs(head);
	std::cout<<"swap: "<<std::endl;
	while(head != NULL)
	{
		std::cout<<head->val<<" ";
		head = head->next;
	}
	system("pause");
	return 0;
}
#endif