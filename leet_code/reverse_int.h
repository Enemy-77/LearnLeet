#pragma once

#include <utility>
#include <vector>

int reverse(int x) {
	std::vector<std::pair<int, int>> pair_vec;
	int e = 0;
	while (x != 0) {
		int mod = x % 10;
		std::pair<int, int> pair = std::make_pair(mod, e);
		pair_vec.push_back(pair);
		e++;
		x /= 10;
	}
	int minus = pair_vec.back().second - pair_vec.front().second;
	int sum = 0;
	for (auto & i : pair_vec) {
		
		sum += i.first *(std::pow(10, minus));
		minus--;
	}
	sum = x < 0 ? -sum : sum;
	return sum;
}
