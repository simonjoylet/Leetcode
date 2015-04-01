#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "../Q2/Q2.h"

using namespace std;

int main()
{
	Q2 q;
	ListNode n1(9), n2(1), n3(6), n4(0);
	n1.next = &n2;
	n2.next = &n3;
	ListNode * rstNode = q.addTwoNumbers(&n1, &n4);
	while (rstNode)
	{
		cout << rstNode->val << " -> ";
		rstNode = rstNode->next;
	}
	getchar();
	return 0;

}