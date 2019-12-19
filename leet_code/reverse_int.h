#pragma once

#include <utility>
#include <vector>

int reverse(int x) {
	if (x == INT_MAX || x == INT_MIN) return 0;
	std::vector<int> vec;
	int e = 0;
	while (x != 0) {
		int mod = x % 10;
		vec.push_back(mod);
		e++;
		x /= 10;
	}
	int sum = 0;
	for (auto & i : vec) {
		sum += i *(std::pow(10, e-1));
		e--;
	}
	sum = x < 0 ? -sum : sum;
	return sum;
}

// 看看别人的代码……
int reverse_(int x) {
	long num = abs((long)x);
	long new_num = 0;
	while (num) {
		new_num = new_num * 10 + num % 10;
		num /= 10;
	}

	if (new_num > INT_MAX) {
		return 0;
	}
	return (x < 0 ? -1 * new_num : new_num);
}