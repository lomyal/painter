
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


// 1、9ms
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        // 用二级指针可以解决没有头节点的链表“删除第一节点操作与删除其他节点操作不一致”的问题
        ListNode** t1 = &head, *t2 = head;

        for (int i = 1; i < n; ++i) {
            t2 = t2->next;
        }

        while (t2->next) {
            t1 = &((*t1)->next);  // @@ 遍历时是修改 t1 的值
            t2 = t2->next;
        }

        // 删除节点
        // 如何释放节点内存与该节点的内存分配方式有关，这里略过
        *t1 = (*t1)->next;  // @@ 删除节点时是修改 *t1 的值

        return head;
    }
};

// http://coolshell.cn/articles/8990.html
// Linus: 利用二级指针删除单向链表

// 2、10ms
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {

        // 空表
        if (!head) return NULL;

        int count = n;
        ListNode *p = head;
        ListNode *q = head;  // q 跟踪要删除节点的前一节点的位置，所以晚于 p 指针 n 轮再出发
        ListNode *newHead = NULL;

        while (p->next) {
            if (count != 0) {
                count--;
            } else {
                q = q->next;
            }
            p = p->next;
        }

        // 删除节点
        if (count != 0) {  // 需要删除的点是第一个节点（count 不为 0，说明 q 指针就没向后移动过）
            newHead = head->next;
            delete head;
        } else {
            newHead = head;
            ListNode *tmp = q->next;
            q->next = q->next->next;
            delete tmp;
        }

        return newHead;
    }
};