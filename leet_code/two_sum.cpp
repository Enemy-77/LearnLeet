

#include "stdafx.h"
#include "two_sum.h"

std::vector<int> twoSum(std::vector<int>& nums, int target) {
	int size = nums.size();
	std::vector<int> vec;
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

std::vector<int> other_twoSum(std::vector<int>& nums, int target) {
	std::unordered_map<int, int> map;
	std::vector<int> answer;
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

