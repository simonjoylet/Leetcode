// Author : Jianyun Sun
// Email  : youyouransjy@gmail.com
// Date	  : 2015-04-01


/*
	Leetcode : Add Two Numbers
	Source   : https://leetcode.com/problems/add-two-numbers/
	You are given two linked lists representing two non-negative numbers. 
	The digits are stored in reverse order and each of their nodes contain a single digit. 
	Add the two numbers and return it as a linked list.

	Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
	Output: 7 -> 0 -> 8
*/


#ifndef ADDTWONUMBERS_H
#define ADDTWONUMBERS_H

#include <iostream>
using namespace std;

//Definition for singly - linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/*
	����һ���ݹ�
	ע��ݹ�����������ɡ�
*/
class AddTwoNumbers_1 
{
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) 
	{
		ListNode * node = new ListNode(0);

		int value1 = (l1 ? l1->val : 0);
		int value2 = (l2 ? l2->val : 0);
		int sum = value1 + value2;
		int shang = sum / 10;
		int yu = sum % 10;
		node->val = yu;
		//ʹ��ָ��ǰһ��Ҫ�ж��Ƿ�ΪNULL
		if (l1 && l1->next)
		{
			l1 = l1->next;
			l1->val += shang;
			l2 = (l2 ? l2->next : NULL);
			node->next = addTwoNumbers(l1, l2);
		}
		else if (l2 && l2->next)
		{
			l2 = l2->next;
			l2->val += shang;
			l1 = (l1 ? l1->next : NULL);
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
		
		return node;
	}
};

/*
	���������ǵݹ�
*/
class AddTwoNumbers_2
{
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
	{
		ListNode * itNode = new ListNode(0);
		ListNode * rstNode = itNode;
		int jinwei = 0;
		bool firstFlag = true;
		while (l1 || l2 || jinwei)
		{
			if (firstFlag)
			{
				//��Ϊ֮ǰ�Ѿ�new���ˣ����Ե�һ��Ҫ������
				firstFlag = false;
			}
			else
			{
				itNode->next = new ListNode(0);
				itNode = itNode->next;
			}
			
			int val1 = (l1 ? l1->val : 0);
			int val2 = (l2 ? l2->val : 0);
			int shang = (val1 + val2 + jinwei) / 10;
			int yu = (val1 + val2 + jinwei) % 10;
			itNode->val = yu;
			jinwei = shang;
			l1 = (l1 ? l1->next : NULL);
			l2 = (l2 ? l2->next : NULL);
		}
		
		return rstNode;
	}
};
#endif//ADDTWONUMBERS_H