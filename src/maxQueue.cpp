#include <queue>
using namespace std;

/*请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。

若队列为空，pop_front 和 max_value 需要返回 -1

示例 1：

输入: 
["MaxQueue","push_back","push_back","max_value","pop_front","max_value"]
[[],[1],[2],[],[],[]]
输出: [null,null,null,2,1,2]
示例 2：

输入: 
["MaxQueue","pop_front","max_value"]
[[],[],[]]
输出: [null,-1,-1]
*/

class MaxQueue {
public:
	MaxQueue() {
	}

	int max_value() {
		if (d.empty()) return -1;
		return q.front();
	}

	void push_back(int value) {
		d.push_back(value);
		while (!q.empty() && q.back() < value) {
			q.pop_back();
		}
		q.push_back(value);
	}

	int pop_front() {
		if (d.empty()) return -1;
		int value = d.front();
		if (value == q.front()) {
			q.pop_front();
		}
		d.pop_front();
		return value;
	}

private:
	deque<int> d;
	deque<int> q;
};

