/*
---------------
Leetcode 28
---------------


Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.



*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle);
	int strStr_sunday(string haystack, string needle);
};

// 直接暴力穷举
int Solution::strStr(string haystack, string needle)
{
	// 注意题目理解，如果needle时空，则题目认为一定包含，直接返回0
	if (needle.empty()) return 0;
	// 注意先判断needle是否为空，再判断haystack是否为空。
	if (haystack.empty()) return -1;

	for (int i = 0; i < haystack.size(); ++i)
	{
		int t = i;
		int count = 0;
		for (int j = 0; j < needle.size(); ++j)
		{
			if (haystack[t] == needle[j])
			{
				++t;
				++count;
			}
			else
			{
				break;
			}
		}
		if (count == needle.size())
		{
			return i;
		}
	}
	return -1;
}

int Solution::strStr_sunday(string haystack, string needle)
{
	if (needle.empty()) return 0;
	if (haystack.size() < needle.size()) return -1;
	const int char_range = 128;

	// 构建needle中字符和最后出现位置的映射
	int map[char_range];
	for (int i = 0; i < char_range; ++i)
	{
		map[i] = -1;
	}
	for (int i = 0; i < needle.size(); ++i)
	{
		map[needle[i]] = i;
	}

	int rst = 0;
	for (int i = 0; i < haystack.size() - needle.size();)
	{
		int j = 0;
		for (j = 0; j < needle.size();)
		{
			if (haystack[i] == needle[j])
			{
				++i;
				++j;
			}
			else
			{
				int next = rst + needle.size();
				if (next > haystack.size()) return -1;
				i = rst + needle.size() - map[haystack[next]];
				rst = i;
				break;
			}
		}
		if (j == needle.size())
		{
			return rst;
		}
	}
	return -1;

}
int main()
{

	Solution sol;
	cout << sol.strStr_sunday("mississippi", "sippj") << endl;
	cout << sol.strStr_sunday("mississippi", "issipi") << endl;
	cout << sol.strStr_sunday("abcabc", "cab") << endl;
	cout << sol.strStr_sunday("a", "a") << endl;
	cout << sol.strStr_sunday("abcabc", "t") << endl;
	cout << sol.strStr("bcabc", "") << endl;
	cout << sol.strStr("", "abc") << endl;

	getchar();
	return 0;
}