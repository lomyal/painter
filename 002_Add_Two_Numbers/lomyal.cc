
// 1、头节点的运用 62ms
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (!l1 && !l2) {
            return NULL;
        }

        ListNode preHead(0);  // 使用头节点可简化程序的书写(不必区分尾插法的第一节点和其他节点)，且此头节点存储在栈中，会自动释放内存
        ListNode *p = &preHead;
        int carry = 0;

        while (l1 || l2 || carry) {
            int x, y;

            if (l1) {
                x = l1->val;
                l1 = l1->next;
            } else {
                x = 0;
            }
            if (l2) {
                y = l2->val;
                l2 = l2->next;
            } else {
                y = 0;
            }

            int sum = carry + x + y;
            carry = sum / 10;
            p->next = new ListNode(sum % 10);
            p = p->next;
        }

        return preHead.next;
    }
};

// 2、写法不够简洁 57ms
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (!l1 && !l2) {
            return NULL;
        }

        ListNode *head = NULL;
        ListNode *p = NULL;
        int carry = 0;

        while (l1 || l2) {
            int x, y;

            if (l1) {
                x = l1->val;
                l1 = l1->next;
            } else {
                x = 0;
            }
            if (l2) {
                y = l2->val;
                l2 = l2->next;
            } else {
                y = 0;
            }

            int sum = carry + x + y;
            carry = sum / 10;

            if (!p) {
                p = new ListNode(sum % 10);
                head = p;
            } else {
                p->next = new ListNode(sum % 10);
                p = p->next;
            }
        }

        if (carry) {
            p->next = new ListNode(1);
        }

        return head;
    }
};