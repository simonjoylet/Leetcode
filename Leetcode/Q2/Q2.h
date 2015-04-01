#ifndef Q2_H
#define Q2_H

#include <iostream>
using namespace std;
/*
You are given two linked lists representing two non-negative numbers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/


//Definition for singly - linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/******************************************************/
/*
解题思路：
就是简单的链表操作，加上递归用法，注意递归结束条件即可。
*/
class Q2 
{
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) 
	{
		ListNode * node = new ListNode(0);

		//这里要注意，如果有一个ListNode是NULL的话，要构造一个0节点来进行计算。
		if (l1 == NULL)
		{
			l1 = new ListNode(0);
		}
		else if (l2 == NULL)
		{
			l2 = new ListNode(0);
		}
		int tmp = l1->val + l2->val;
		int shang = tmp / 10;
		int yu = tmp % 10;
		node->val = yu;

		if (l1->next != NULL)
		{
			l1 = l1->next;
			l1->val += shang;
			l2 = l2->next;
			node->next = addTwoNumbers(l1, l2);
		}
		else if (l2->next != NULL)
		{
			l2 = l2->next;
			l2->val += shang;
			l1 = l1->next;
			node->next = addTwoNumbers(l1, l2);
		}
		else
		{
			if (shang == 1)
			{
				node->next = new ListNode(1);
			}
			else
			{
				node->next = NULL;
			}
		}
		
	}
};

#endif//Q2_H