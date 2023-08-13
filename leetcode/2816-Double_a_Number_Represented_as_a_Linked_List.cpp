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
    /*
       I'd like to say easy question. I looked at it and it
       since it was a singly-linked list, it was pretty
       clear we just had to use recursion to return the 
       remainders along the chain.
    */
public:
    int recurse(ListNode* head) {
        if (head == NULL) return 0;
        int rem = recurse(head->next);
        
        int tmp = head->val;
        tmp *= 2;
        tmp += rem;
        
        head->val = tmp % 10;
        int ans = 0;
        if (tmp >= 10) {
            tmp /= 10;
            ans = tmp;
        }
        return ans;
    }
    ListNode* doubleIt(ListNode* head) {
        ListNode* ret = head;
        int node = recurse(head);
        if (node > 0) {
            ret = new ListNode(node, head);
        }
        return ret;
    }
};
