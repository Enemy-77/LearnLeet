/*

给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

 

示例 1：

输入：nums = [2,0,2,1,1,0]
输出：[0,0,1,1,2,2]
示例 2：

输入：nums = [2,0,1]
输出：[0,1,2]
示例 3：

输入：nums = [0]
输出：[0]
示例 4：

输入：nums = [1]
输出：[1]
 

提示：

n == nums.length
1 <= n <= 300
nums[i] 为 0、1 或 2

*/

#include <vector>

using namespace std;

// 暴力解法，统计0，1，2的个数，然后重新生成
void sortColors(vector<int>& nums) {
    int zero_count = 0;
    int one_count = 0;
    int two_count = 0;
    for (auto & i : nums) {
        i == 0 ? zero_count++ : (i == 1 ? one_count++ : two_count++);
    }
    for (int j = 0; j < zero_count; ++j) {
        nums[j] = 0;
    }
    for (int j = zero_count; j < one_count + zero_count; ++j) {
        nums[j] = 1;
    }
    for (int j = zero_count + one_count; j < two_count + one_count +zero_count; ++j) {
        nums[j] = 2;
    }
}

//单指针
void sortColors(vector<int>& nums) {
	if (nums.size()< 2) {
		return;
	}
	int front = 0;
	for (int i = 0; i < nums.size(); ++i) {
		if (nums[i] == 0) {
			swap(nums[i], nums[front]);
            front++;
		}
	}
	for (int i = front; i < nums.size(); ++i) {
        if (nums[i] == 1) {
            swap(nums[i], nums[front]);
			++front;
        }
    }
}


// 双指针，只需扫描一遍
void sortColors(vector<int>& nums) {
	if (nums.size() < 2) {
		return;
	}
	int ptr_0 = 0;
	int ptr_1 = 0;
	for (int i = 0; i < nums.size(); ++i) {
		if (nums[i] == 1) {
			swap(nums[i], nums[ptr_1]);
			ptr_1++;
		}
		else if (nums[i] == 0) {
			swap(nums[i], nums[ptr_0]);
			if (ptr_0 < ptr_1) {
				swap(nums[i], nums[ptr_1]);
			}
			ptr_0++;
			ptr_1++;
		}
	}
}


