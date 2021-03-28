#include <stack>
#include <vector>
#include <cassert>
#include <string>

using namespace std;

void calc(stack<int>& operands, stack<int>& opors) {
	int b = operands.top();
	operands.pop();
	int a = operands.top();
	operands.pop();
	int op = opors.top();
	opors.pop();
	int c;
	switch (op) {
	case '+':c = a + b; break;
	case '-':c = a - b; break;
	case '*':c = a * b; break;
	case '/':c = a / b; break;
	default: assert(0);
	}
	operands.push(c);
}

bool priority(int a, int b) {
	if (a == '+' || a == '-') {
		return false;
	}
	else if (a == '*' || a == '/') {
		return (b == '+' || b == '-');
	}
	assert(0);
	return false;
}

int calculate(string s) {
	stack<int> num;
	stack<int> operand;
	int size = s.size();
	int i = 0;
	while (i < size) {
		if (isspace(s[i])) {
			++i;
			continue;
		}
		else if (isdigit(s[i])) {
			int d = 0;
			while (isdigit(s[i])) {
				d = (10 * d) + (s[i] - '0');
				++i;
			}
			num.push(d);
		}
		else {
			while (operand.size() && !priority(s[i], operand.top())) {
				calc(num, operand);
			}
			operand.push(s[i]);
			++i;
		}
	}
	while (operand.size()) {
		calc(num, operand);
	}
	return num.top();
}