/*
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

输入：l1 = [1,2,4], l2 = [1,3,4]
输出：[1,1,2,3,4,4]
示例 2：

输入：l1 = [], l2 = []
输出：[]
示例 3：

输入：l1 = [], l2 = [0]
输出：[0]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-two-sorted-lists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};


ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode* result = new ListNode(-1);
	ListNode* tmp = result;
    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val < l2->val) {
			tmp->next = l1;
			l1 = l1->next;
		}
		else {
            tmp->next = l2;
			l2 = l2->next;
		}
		tmp = tmp->next;
    }
	tmp->next = l1 == nullptr ? l2 : l1;

	return result->next;
}