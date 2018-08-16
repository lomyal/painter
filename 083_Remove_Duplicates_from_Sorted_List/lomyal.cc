
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head) {
            return head;
        }
        
        ListNode *p = head;
        
        while (p->next) {

            if (p->val == p->next->val) {  // 下一节点与当前节点内容相同
                p->next = p->next->next;  // 删除下一节点。节点空间不是分配在堆中的，因此不需要手工回收空间
                // 注意此时不后移指针p，仍需比较本节点和新的下一节点

            } else {  // 下一节点与当前节点内容不同
                p = p->next;
            }
        }
        
        return head;
    }
};