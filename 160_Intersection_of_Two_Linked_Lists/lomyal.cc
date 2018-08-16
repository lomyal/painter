/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 1、先将两表各走一遍，获取长度差，让长的先走，以使两表末端对齐


// 2、先分别从AB的头部同时出发，A走完后调到B头部，B走完后调到A头部。这样既能提早在AB长度相等时发现结合点，又能应对不等长的情况。
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        ListNode *p1 = headA;
        ListNode *p2 = headB;

        if (!p1 || !p2) return NULL;

        // 循环跳出的条件：p1为空，或p2为空，或p1和p2指向同一节点
        while (p1 && p2 && p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;

            if (p1 == p2) return p1;  // 发现公共节点，或无公共节点的情况最后 p1 p2 同时为 NULL 时

            if (!p1) p1 = headB;
            if (!p2) p2 = headA;
        }

        return p1;
    }
};
