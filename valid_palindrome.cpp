/*
---------------
Leetcode 125
---------------

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.


*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool isPalindrome(string s);
	bool isPalindrome_stl(string s);
};

bool isAlpha(char c)
{
	if ((c>='A' && c <='Z') || (c >='a' && c <= 'z') )
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isNumber(char c)
{
	if (c >= '0' && c <= '9')
	{
		return true;
	}
	else
	{
		return false;
	}
}

char beLower(char c)
{
	if ((c >= 'A' && c <= 'Z'))
	{
		return c + 'a' - 'A';
	}
	else
	{
		return c;
	}
}

bool Solution::isPalindrome(string s)
{
	if (s.empty()) return true;
	int i = 0;
	int j = s.size() - 1; // 最后一个字符是size-1。
	while (i < j)
	{
		while (!isAlpha(s[i]) && !isNumber(s[i]) && i < s.size()) i++;
		while (!isAlpha(s[j]) && !isNumber(s[j]) && j > 0) j--;
		if (i >= j) break; // 注意不能少了等号，例如" "
		if (beLower(s[i]) == beLower(s[j]))
		{
			++i;
			--j;
		}
		else
		{
			return false;
		}
	}

	return true;

}

bool Solution::isPalindrome_stl(string s)
{
	if (s.size() <= 1) return true;
	int i = 0;
	int j = s.size() - 1;
	// 使用stl中的transform方法将所有字符变为小写。
	transform(s.begin(), s.end(), s.begin(), tolower);
	while (i < j)
	{
		// 直接使用判断是否是字母或数字的函数。
		while (!::isalnum(s[i]) && i < s.size()) ++i;
		while (!::isalnum(s[j]) && j > 0) --j;
		if (i >= j) break;

		if (s[i] == s[j])
		{
			++i;
			--j;
		}
		else
		{
			return false;
		}
	}
	return true;
}

int main()
{
	string s1, s2, s3;
	s1 = "A man, a plan, a canal: Panama";
	s2 = "race a car";
	s3 = ".,";

	Solution sol;
	cout << sol.isPalindrome(s1) << endl;
	cout << sol.isPalindrome(s2) << endl;
	cout << sol.isPalindrome_stl(s3) << endl;

	getchar();
	return 0;
}