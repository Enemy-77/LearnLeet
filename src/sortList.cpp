/*
给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。

进阶：

你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？


示例 1：


输入：head = [4, 2, 1, 3]
输出：[1, 2, 3, 4]
示例 2：


输入：head = [-1, 5, 3, 4, 0]
输出：[-1, 0, 3, 4, 5]
示例 3：

输入：head = []
输出：[]

*/


ListNode* merge(ListNode* head1, ListNode* head2) {
    ListNode* head = new ListNode(0);
    ListNode* tmp = head;
    while (head1 != nullptr && head2 != nullptr) {
        if (head1->val < head2->val) {
            tmp->next = head1;
            head1 = head1->next;
        }
        else {
            tmp->next = head2;
            head2 = head2->next;
        }
        tmp = tmp->next;
    }
    if (head1 != nullptr) {
        tmp->next = head1;
    }
    if (head2 != nullptr) {
        tmp->next = head2;
    }
    return head->next;
}

ListNode* sortList(ListNode* head, ListNode* tail) {
    if (head == nullptr) {
        return head;
    }
    if (head->next == tail) {
        head->next = nullptr;
        return head;
    }
    ListNode* slow = head, * fast = head;
    while (fast != tail) {
        slow = slow->next;
        fast = fast->next;
        if (fast != tail) {
            fast = fast->next;
        }
    }
    ListNode* mid = slow;
    return merge(sortList(head, mid), sortList(mid, tail));
}

ListNode* sortList(ListNode* head) {
    return sortList(head, nullptr);
}