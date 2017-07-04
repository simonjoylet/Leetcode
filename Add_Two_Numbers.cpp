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



#include <iostream>
using namespace std;

//Definition for singly - linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/*
	方法一：递归
	注意递归结束条件即可。
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
		//使用指针前一定要判断是否为NULL
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
	方法二：非递归
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
				//因为之前已经new过了，所以第一次要跳过。
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

class AddTwoNumbers_3
{
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
	{
		int carry = 0;
		ListNode dummy(-1);
		ListNode * prev = &dummy;
		while (l1 || l2)
		{
			int v1 = l1 ? l1->val : 0;
			int v2 = l2 ? l2->val : 0;
			int val = (v1 + v2 + carry) % 10;
			carry = (v1 + v2 + carry) / 10;
			prev->next = new ListNode(val);


			prev = prev->next;
			l1 = l1 ? l1->next : NULL;
			l2 = l2 ? l2->next : NULL;
		}
		if (carry > 0)
		{
			prev->next = new ListNode(carry);
		}
		return dummy.next;
	}

};


void PrintList(ListNode * l)
{
	while (l)
	{
		printf("%d, ", l->val);
		l = l->next;
	}
}

int main()
{
	ListNode * l1 = new ListNode(2);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(3);

	ListNode * l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);

	AddTwoNumbers_3 s3;
	ListNode * r3 = s3.addTwoNumbers(l1, l2);

	PrintList(r3);

	getchar();
	return 0;
}