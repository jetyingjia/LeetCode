#include "utils.h"

#ifdef MergekSortedLists

#include <iostream>
#include <vector>
#include <list>
#include <time.h>
#include <queue>

struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
struct comp
{
	//优先队列中默认是less(<),top为最大的元素
	//此处为greater(>),top为最小元素
	bool operator() (ListNode *a,ListNode *b)
	{
		return a->val > b->val;
	}
};

/*
ListNode *mergeKLists(std::vector<ListNode *> &lists) 
{
	if (lists.size() == 0)
	{
		return NULL;
	}
	if (lists.size() == 1)
	{
		return lists[0];
	}
	
	int pos = 0;
	int count = 0;

	for (int i = 0; i < lists.size(); i++)
	{
		ListNode* p = lists[i];
		while(p != NULL)
		{
			count++;
			p = p->next;
		}
	}
	if (count > 0)
	{
		ListNode* ans = new ListNode(0);
		ListNode* ansTemp= ans;
		while(count)
		{
			int min = INT_MAX;
			for (int i = 0; i < lists.size(); i++)
			{
				if (lists[i] != NULL)
				{
					if ( (*lists[i]).val < min)
					{
						min = (*lists[i]).val;
						pos = i;
					}
				}
			}
			ansTemp->val = (*lists[pos]).val;
			if (count > 1)
			{
				ansTemp->next = new ListNode(0);
				ansTemp = ansTemp->next;
			}
			lists[pos] = lists[pos]->next;
			count--;
		}
		return ans;
	}
	else
	{
		return lists[0];
	}
}
*/

ListNode *mergeKLists(std::vector<ListNode *> &lists) 
{
	ListNode *tmphead = new ListNode(0), *p = tmphead;
	std::priority_queue<ListNode*,  std::vector<ListNode*>,  comp> q;
	for(int i = 0; i < lists.size(); i ++)
	{
		if(lists[i] != NULL)
		{
			q.push(lists[i]);
		}
	}
	while(!q.empty())
	{
		p->next = q.top();
		p = p->next;
		q.pop();
		if(p ->next != NULL)
		{	
			q.push(p->next);
		}
	}
	return tmphead->next;
}
int main()
{
	srand(clock());
	std::vector<ListNode*> lists;
// 	lists.push_back(NULL);
// 	ListNode *p = new ListNode(0);
// 	p->val = 1;
// 	p->next = NULL;
// 	lists.push_back(p);
// 	ListNode *q = new ListNode(0);
// 	q->val = 0;
// 	q->next = NULL;
// 	lists.push_back(q);
	//lists.push_back()

	for (int i = 0; i < 5; i++)
	{
		ListNode *head = new ListNode(0);
		ListNode *p = head;
		for (int j = 0; j < 4; j++)
		{
			p->val = rand() % 25;
			//std::cin>>p->val;
			if ( j + 1 < 4)
			{
				p->next = new ListNode(0);
				p = p->next;
			}
		}
		p->next = NULL;
		lists.push_back(head);
	}
	ListNode* ans = mergeKLists(lists);
	int a = 0;
	system("pause");
	return 0;
	
	
}


#endif