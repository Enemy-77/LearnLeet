/*
已知一个长度为 n 的数组，预先按照升序排列，经由 1 到 n 次 旋转 后，得到输入数组。例如，原数组 nums = [0,1,2,4,5,6,7] 在变化后可能得到：
若旋转 4 次，则可以得到 [4,5,6,7,0,1,2]
若旋转 7 次，则可以得到 [0,1,2,4,5,6,7]
注意，数组 [a[0], a[1], a[2], ..., a[n-1]] 旋转一次 的结果为数组 [a[n-1], a[0], a[1], a[2], ..., a[n-2]] 。

给你一个元素值 互不相同 的数组 nums ，它原来是一个升序排列的数组，并按上述情形进行了多次旋转。请你找出并返回数组中的 最小元素 。

 
示例 1：

输入：nums = [3,4,5,1,2]
输出：1
解释：原数组为 [1,2,3,4,5] ，旋转 3 次得到输入数组。
示例 2：

输入：nums = [4,5,6,7,0,1,2]
输出：0
解释：原数组为 [0,1,2,4,5,6,7] ，旋转 4 次得到输入数组。
示例 3：

输入：nums = [11,13,15,17]
输出：11
解释：原数组为 [11,13,15,17] ，旋转 4 次得到输入数组。
 

提示：

n == nums.length
1 <= n <= 5000
-5000 <= nums[i] <= 5000
nums 中的所有整数 互不相同
nums 原来是一个升序排序的数组，并进行了 1 至 n 次旋转

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

#include <vector>
using namespace std;

// 利用一开始是有序的数组的特性，出现有降序的地方就是最小的地方。
int findMin(vector<int>& nums) {
    for (int i = 0; i < nums.size() - 1; ++i) {
        if (nums[i] > nums[i + 1]) {
            return nums[i + 1];
        }
    }
    return *nums.begin();
}

// 二分递归实现
int find_min(vector<int>& nums, int left, int right) {
	if (left == right) {
		return nums[left];
	}
	int mid = (left + right) / 2;
	if (nums[mid] < nums[right]) {
		return find_min(nums, left, mid);
	}
	else {
		return find_min(nums, mid +1, right);
	}
}

int findMin(vector<int>& nums) {
	return find_min(nums, 0, nums.size() - 1);
}

//二分循环实现
int findMin(vector<int>& nums) {
	int left = 0;
	int right = nums.size() - 1;
	while (left < right) {
	    int mid = (left + right) / 2;
		if (nums[mid] < nums[right]) {
            right = mid;
		}
		else {
            left = mid + 1;
		}
	}
	return nums[left];
}