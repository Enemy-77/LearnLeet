#include <vector>
#include <deque>

/*给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。

示例:

输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
输出: [3,3,5,5,6,7] 
解释: 

  滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
*/

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	vector<int> result;
	deque<int> increment;
	deque<int> origin;
	int size = nums.size();
	for (int i = 0; i < size; ++i) {
		int popFront;
		bool pop = false;
		if (origin.size() < k) {
			origin.push_back(nums[i]);
		} else {
			pop = true;
			popFront = origin.front();
			origin.pop_front();
			origin.push_back(nums[i]);
		}
		while (!increment.empty() && nums[i] > increment.back())	{
			increment.pop_back();
		}
		increment.push_back(nums[i]);
		if (i < k - 1) {
			continue;
		}
		if (pop && popFront == increment.front()) {
			increment.pop_front();
		}
		result.push_back(increment.front());
	}
	return result;
}

// 完全可以使用一个队列就可以实现，内存占用更少，解耦。

class MaxQueue {
private:
	deque<int> q;

public:
	int front() {
		if (!q.empty()) {
			return q.front();
		}
	}

	void pop(int value) {
		if (!q.empty() && q.front() == value) {
			q.pop_front();
		}
	}

	void push(int value) {
		while (!q.empty() && value > q.back()) {
			q.pop_back();
		}
		q.push_back(value);
	}
};

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	vector<int> result;
	if (nums.empty()) {
		return result;
	}
	MaxQueue queue;
	for (int i = 0; i < k; ++i) {
		queue.push(nums[i]);
	}
	result.push_back(queue.front());
	for (int i = k; i < nums.size(); ++i) {
		queue.push(nums[i]);
		queue.pop(nums[i - k]);
		result.push_back(queue.front());
	}
	return result;
}

