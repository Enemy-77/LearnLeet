// leet_code.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <unordered_map>

/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
Example:
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return[0, 1].
*/

using  namespace std;

vector<int> twoSum(vector<int>& nums, int target);
vector<int> other_twoSum(vector<int>& nums, int target);

int _tmain(int argc, _TCHAR* argv[]) {
	vector<int> vec = { 3, 2, 4 };
	int target = 6;
	vector<int> a = other_twoSum(vec, target);

	return 0;
}

vector<int> twoSum(std::vector<int>& nums, int target) {
	int size = nums.size();
	vector<int> vec;
	for (int i = 0; i < size; ++i) {
		for (int j = i + 1; j < size; ++j) {
			if (nums[i] + nums[j] == target) {
				vec.push_back(i);
				vec.push_back(j);
				break;
			}
		}
	}
	return vec;
}

vector<int> other_twoSum(vector<int>& nums, int target) {
	unordered_map<int, int> map;
	vector<int> answer;
	int size = nums.size();

	for (int i = 0; i < size; ++i) {
		if (map.find(target - nums[i]) != map.end()) {
			answer.push_back(i);
			answer.push_back(map[target - nums[i]]);
		}
		map[nums[i]] = i;
	}
	return answer;
}

