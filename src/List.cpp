
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val{ 0 }, next{ nullptr }  {}
	ListNode(int value) : val{value}, next{nullptr} {}
	ListNode(int value, ListNode* next) : val{value}, next{next} {}
};

// 我的版本
// 反转链表
// 必须要申请一块新的内存，不能在原内存上操作
ListNode* reverseList(ListNode* head) {
	ListNode* newHead = new ListNode(head->val);
	while (head->next) {
		ListNode* next = head->next;
		newHead = new ListNode(next->val, newHead);
		head = head->next;
	}
	return newHead;
}

// 更好的版本（更整体）
ListNode* reverseList(ListNode* head) {
	ListNode* prev = nullptr;
	ListNode* cur = head;
	while (cur) {
		ListNode* next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	return prev;
}

// 两数相加
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* head = nullptr, *tail = nullptr;
	int carry = 0;
	while (l1 || l2) {
		int v1 = l1 ? l1->val : 0;
		int v2 = l2 ? l2->val : 0;
		int value = v1 + v2 + carry;
		if (!head) {
			head = tail = new ListNode(value % 10);
		}
		else {
			tail->next = new ListNode(value % 10);
			tail = tail->next;
		}
		carry = value / 10;
		if (l1) {
			l1 = l1->next;
		}
		if (l2){
			l2 = l2->next;
		}
	}
	if (carry > 0) {
		tail->next = new ListNode(carry);
	}
	return head;
}
