#include "utils.h"


#ifdef RemoveNthNodeFromEndofList

#include <iostream>
#include <vector>
#include <string>

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int _val): val(_val), next(NULL){}; 
};
ListNode *removeNthFromEnd(ListNode *head, int n) 
{
	
	ListNode *slow, *quick, *pre;
	slow = quick = head;
	for (int i = 0; quick != NULL; i++)
	{
		pre = slow;
		if (i >= n)
		{
			slow = slow->next;
		}
		quick = quick->next;
	}
	if (slow == head)
	{
		head = head->next;
		return head;
	}
	pre->next = slow->next;
	free(slow);
	return head;
}

ListNode *removeNthFromEnd1(ListNode *head, int n) {
	ListNode *p = head;
	int count = 0;
	while (p != NULL)
	{
		p = p->next;
		count++;
	}
	p = head;
	for (int i = 1; i < count - n; i++)
	{
		p = p->next;
	}

	if (n == count)
	{
		head = head->next;
		return head;
	}
	ListNode *q = p;
	q = p->next;
	p->next = q->next;
	return head;
}

int main()
{
	ListNode *head = new ListNode(0);
	ListNode *p = head;
	for (int i = 0; i < 5; i++)
	{
		std::cin>>p->val;
		if ( i + 1 < 5)
		{
			p->next = new ListNode(0);
			p = p->next;
		}
		
	}
	
	std::cout<<"Please input n: ";
	int n;
	std::cin>>n;
	ListNode *ans = removeNthFromEnd(head, n);

	for (; ans != NULL; ans = ans->next)
	{
		std::cout<<ans->val<<"  ";
	}
	system("pause");
	return 0;
}




#endif