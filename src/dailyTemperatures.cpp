#include <vector>
#include <stack>

using namespace std;

vector<int> dailyTemperatures(vector<int>& T) {
	int size = T.size();
	vector<int> result(size, 0);
	stack<int> index;
	for (int i = 0; i < size; ++i) {
		while (!index.empty() && T[i] > T[index.top()]) {
			result[index.top()] = i - index.top();
			index.pop();
		}
		index.push(i);
	}
	return result;
}
