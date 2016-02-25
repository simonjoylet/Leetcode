// Author : Jianyun Sun
// Email  : youyouransjy@gmail.com
// Date   : 2015-03-31


/*
	Leetcode : Two Sum
	Source   : https://oj.leetcode.com/problems/two-sum/
	Given an array of integers, find two numbers such that they add up to a specific target number.

	The function twoSum should return indices of the two numbers such that they add up to the target,
	where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

	You may assume that each input would have exactly one solution.

	Input: numbers={2, 7, 11, 15}, target=9
	Output: index1=1, index2=2
*/


#ifndef TWOSUM_H
#define TWOSUM_H
#include <vector>
#include <map>
#include <algorithm>

/*
	����һ����������
	ʱ�临�Ӷ���O(n2)
*/
class TwoSum_1 
{
public:
	vector<int> twoSum(vector<int> &numbers, int target) 
	{
		vector<int> rst;
		for (int i = 0; i < numbers.size(); ++i)
		{
			int tmp = target - numbers[i];
			for (int j = i + 1; j < numbers.size(); ++j)
			{
				if (numbers[j] == tmp)
				{
					rst.push_back(i + 1);
					rst.push_back(j + 1);
					break;
				}
			}
		}

		return rst;
	}
}

/*
	�������������������߱ƽ�������
	����ʱҪע�Ᵽ��ԭʼ�±ꡣ
	ʱ�临�Ӷȣ�O(nLogn)
*/
struct ss
{
	int index;
	int number;
};
bool ssCmp(ss & a, ss & b)
{
	return a.number < b.number;
}

class TwoSum_2
{
public:
	vector<int> twoSum(vector<int> &numbers, int target)
	{
		ss * sArray = new ss[numbers.size()];
		for (int i = 0; i < numbers.size(); ++i)
		{
			ss tmpS;
			tmpS.index = i;
			tmpS.number = numbers[i];
			sArray[i] = tmpS;
		}

		//sort��ǰ�����������ǵ�������begin�͵�������end
		//���ܴ���sArray[0]��sArray[numbers.size() - 1]
		sort(sArray, sArray + numbers.size(), ssCmp);

		vector<int> rst;
		for (int i = 0, j = numbers.size() - 1; i != j;)
		{
			if (sArray[i].number + sArray[j].number < target)
			{
				++i;
			}
			else if (sArray[i].number + sArray[j].number > target)
			{
				--j;
			}
			else
			{
				//�����и��ӣ���Ϊ�Ź����ˣ���������Ҫ�ж����index�Ĵ�С��ϵ��
				int r1 = sArray[i].index + 1;
				int r2 = sArray[j].index + 1;
				if (r1 < r2)
				{
					rst.push_back(r1);
					rst.push_back(r2);
				}
				else
				{
					rst.push_back(r2);
					rst.push_back(r1);
				}
				
				break;
			}
		}

		return rst;
	}
}
/*
	��������ʹ�ù�ϣ��map������������
	���ѵ��ڲ�ѭ��ʵ���Ͼ�ֻ������������
	���ǿ�����map�����ѭ���ĸ��Ӷȴ�O(n)��ΪO(1)
*/
class TwoSum_3
{
public:
	vector<int> twoSum(vector<int> &numbers, int target)
	{
		vector<int> rst;
		map<int, int> m;
		for (int i = 0; i < numbers.size(); ++i)
		{
			//������ʵӦ�ÿ�����ֵ�ظ��������������Ŀ˵ֻ��һ��⣬�����ʱ���Ժ��ԡ�
			m[numbers[i]] = i;
		}
		for (int i = 0; i < numbers.size(); ++i)
		{
			int tmp = target - numbers[i];
			//�����и�����Ҫ���������±겻����ȣ�������һ�����������顣
			if (m.find(tmp) != m.end() && m[tmp] != i)
			{
				rst.push_back(i + 1);
				rst.push_back(m[tmp] + 1);
				break;
			}
		}

		return rst;
	}
}
#endif//TWOSUM_H