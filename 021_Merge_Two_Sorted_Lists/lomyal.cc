
// 1、14ms
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (!l1) {
            return l2;
        }
        if (!l2) {
            return l1;
        }

        ListNode *head = NULL;

        // 初始化新list的头指针
        if (l1->val < l2->val) {
            head = l1;
            l1 = l1->next;
        } else {
            head = l2;
            l2 = l2->next;
        }

        ListNode *p = head;  // p指向新list的尾部

        // 把两list头部较小的节点接到新list的尾部
        while (l1 && l2) {  // l1 l2 分别指向旧list剩余部分的头部
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;

            } else {
                p->next = l2;
                l2 = l2->next;
            }

            p = p->next;
        }

        // 把剩余的一个旧list（如果有的话）直接全部接到新list的尾部
        if (l1) {
            p->next = l1;
        }
        if (l2) {
            p->next = l2;
        }

        return head;
    }
};