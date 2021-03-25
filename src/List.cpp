
struct ListNode {
	int val_;
	ListNode* next_;
	ListNode() : val_{ 0 }, next_{ nullptr }  {}
	ListNode(int value) : val_{value}, next_ {nullptr} {}
	ListNode(int value, ListNode* next) : val_{value}, next_{next} {}
};

// 反转链表
// 必须要申请一块新的内存，不能在原内存上操作
ListNode* reverseList(ListNode* head) {
	ListNode* newHead = new ListNode(head->val_);
	while (head->next_) {
		ListNode* next = head->next_;
		newHead = new ListNode(next->val_, newHead);
		head = head->next_;
	}
	return newHead;
}

