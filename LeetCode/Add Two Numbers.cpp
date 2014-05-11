#include "utils.h"

#ifdef AddTwoNumbers

#include <iostream>
#include <vector>
/**
 * Definition for singly-linked list.
 **/
 struct ListNode 
 {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
 ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) 
 {
	ListNode *result = new ListNode(0); 
	ListNode *p = result;
	int add = 0;
	while(l1 != NULL || l2 != NULL || add)
	{
		p->val = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + add;
		add = p->val/10;
		p->val = p->val % 10;
		if (l1 != NULL)
		{
			l1 = l1->next;
		}
		if (l2 != NULL)
		{
			l2 = l2->next;
		}
		if (l1 != NULL || l2 != NULL || add)
		{
			p->next = new ListNode(0);
		}
		p = p->next;
	}
	return result;
 }


int main()
{
	struct ListNode *l1 = new ListNode(0);
	struct ListNode *l2 = new ListNode(0);
	ListNode *p = l1, *q = l2;
	int len1, len2;
	std::cin>>len1>>len2;
	for (int i = 0; i < len1; i++)
	{
		std::cin>>p->val;
		p->next = new ListNode(0);
		p = p->next;
	}
	p = NULL;

	for (int i = 0; i < len2; i++)
	{
		std::cin>>q->val;
		q->next = new ListNode(0);
		q = q->next;
	}
	q = NULL;
	ListNode *ans = addTwoNumbers(l1, l2);
	
	while(ans != NULL)
	{
		std::cout<<ans->val<<"  ";
		ans = ans->next;

	}


	system("pause");
	return 0;
}




#endif