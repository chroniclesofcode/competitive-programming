/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void rev(ListNode* head, ListNode* ed, ListNode* prev) {
        if (head == ed) return;
        ListNode* tmp = head->next;
        head->next = prev;
        rev(tmp, ed, head);
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *st, *prev, *ret;
        st = head;
        int ct = 0;
        bool flag = true;
        ret = head;
        prev = nullptr;
        while (head != NULL) {
            if (ct == 0) {
                st = head;
            }
            if (ct == k-1) {
                ListNode *tmp = head->next;
                if (flag) {
                    flag = false;
                    ret = head;
                }
                rev(st, head->next, head->next);
                if (prev != nullptr) {
                    prev->next = head;
                }
                prev = st;
                head = tmp;
            } else {
                head = head->next;
            }
            
            ct = (ct + 1) % k;
        }
        return ret;
    }
};
