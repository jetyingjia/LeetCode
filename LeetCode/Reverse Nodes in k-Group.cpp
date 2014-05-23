#include "utils.h"
#ifdef ReverseNodesinkGroup

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

ListNode *reverseKGroup(ListNode *head, int k) 
{
	if (head == NULL)
	{
		return head;
	}
	int count = 0;
	ListNode *newHead = new ListNode(0);
	newHead->next = head;
	ListNode *p = newHead;
	ListNode *q, *r1,*r2, *record1, *record2;
	while(p != NULL)
	{
		record1 = q = p;
		while(q->next != NULL && count != k)
		{
			q = q->next;
			count++;
		}
		
		if (count == k)
		{
			q = q->next;
			record2 = r2 = p->next;
			while(count != 0)
			{
				r1 = r2->next;
				r2->next = p;
				p = r2;
				r2 = r1;
				count--;
			}
			record1->next = p;
			record2->next = q;
			p = record2;
		}
		else
		{
			break;
		}
		
	}
	head = newHead->next;
	return head;
}

int main()
{
	srand(clock());
	ListNode *head = new ListNode(0);
	ListNode *p = head;
	int N, k;
	std::cin>>N>>k;
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
	
	head = reverseKGroup(head, k);
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