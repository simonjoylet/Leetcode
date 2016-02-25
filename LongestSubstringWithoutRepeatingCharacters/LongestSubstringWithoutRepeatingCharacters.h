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
	����һ����map�����ַ�λ�á�
	ʹ���Ӵ��������������ظ��ַ�ʱ������map�е�λ�����½�ȡ�Ӵ���
	�����뷨���ַ�ָ�벻�ܻ��ݡ�
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

		//ע�⣬ѭ������ʱҲҪ�ж��Ƿ����һ��count�Ƚϴ�
		rst = (count > rst ? count : rst);

		return rst;
	}
};

/*
	��������Ӧ�ÿ��Խ��KMP��˼����⡣
	����KMP�㷨�е����ˣ���ͷ���о�һ�¡�
*/

#endif//LongestSubstringWithoutRepeatingCharacters