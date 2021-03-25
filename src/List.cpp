
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
// 更好的版本
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
