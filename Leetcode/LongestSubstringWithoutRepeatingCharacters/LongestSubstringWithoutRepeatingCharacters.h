// Author : Jianyun Sun
// Email  : youyouransjy@gmail.com
// Date   : 2015-04-02


/*
	Leetcode : Longest Substring Without Repeating Characters
	Source   : https://leetcode.com/problems/longest-substring-without-repeating-characters/
	Given a string, find the length of the longest substring without repeating characters.
	For example, the longest substring without repeating letters for "abcabcbb" is "abc",
	which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/

#ifndef LongestSubstringWithoutRepeatingCharacters_h
#define LongestSubstringWithoutRepeatingCharacters_h

#include <vector>
#include <map>
#include <string>
#include <stdio.h>
using namespace std;

/*
	方法一：用map保存字符位置。
	使用子串搜索，当发现重复字符时，根据map中的位置重新截取子串。
	核心想法是字符指针不能回溯。
*/
class LongestSubstringWithoutRepeatingCharacters_1
{
public:
	int lengthOfLongestSubstring(string s) 
	{
		int rst = 0;
		int count = 0;
		map<char, int> m;
		string subString;
		for (int i = 0; i < s.size(); ++i)
		{
			if (subString.find(s[i]) == subString.npos)
			{
				char tmpChar = s[i];
				subString.append(&tmpChar);
				++count;
			}
			else
			{
				rst = (count > rst ? count : rst);

				int tmp = m[s[i]];
				count = i - tmp;
				subString = s.substr(tmp + 1, count);
			}

			m[s[i]] = i;
		}

		//注意，循环结束时也要判断是否最后一次count比较大。
		rst = (count > rst ? count : rst);

		return rst;
	}
};

/*
	方法二：应该可以借鉴KMP的思想解题。
	不过KMP算法有点忘了，回头再研究一下。
*/

#endif//LongestSubstringWithoutRepeatingCharacters