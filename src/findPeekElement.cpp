/*

峰值元素是指其值大于左右相邻值的元素。

给你一个输入数组 nums，找到峰值元素并返回其索引。数组可能包含多个峰值，在这种情况下，返回 任何一个峰值 所在位置即可。

你可以假设 nums[-1] = nums[n] = -∞ 。

 

示例 1：

输入：nums = [1,2,3,1]
输出：2
解释：3 是峰值元素，你的函数应该返回其索引 2。
示例 2：

输入：nums = [1,2,1,3,5,6,4]
输出：1 或 5 
解释：你的函数可以返回索引 1，其峰值元素为 2；
     或者返回索引 5， 其峰值元素为 6。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-peak-element
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

#include <vector>
using namespace std;

// 一开始的版本，简单直接
int findPeakElement(vector<int>& nums) {
	if (nums.size() == 1) {
		return 0;
	}
	if (nums.size() == 2) {
		return nums[0] > nums[1] ? 0 : 1;
	}
	if (nums[0] > nums[1]) {
		return 0;
	}
	if (nums[nums.size() - 1] > nums[nums.size() - 2]) {
		return nums.size() - 1;
	}
	int i = 1;
	while (i != nums.size() - 1) {
		if (nums[i] > nums [i - 1] && nums[i] > nums[i + 1]) {
			return i;
		}
		i++;
	}
	return 0;
}

// 思维层级更高的版本  
// 递归二分

int find(vector<int>& num, int left, int right) {
	if (left == right) {
		return left;
	}
	int mid = (left + right) / 2;
	if (num[mid] > num[mid + 1]) {
		return find(num, left, mid);
	} else {
		return find(num, mid + 1, right);
	}
}

int findPeakElement(vector<int>& nums) {
	return find(nums, 0, nums.size() - 1);
}
