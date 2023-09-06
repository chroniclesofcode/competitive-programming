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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        #define arr array<int,2>
        priority_queue<arr, vector<arr>, greater<arr>> pq;

        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != NULL) pq.push({lists[i]->val, i});
        }
        if (pq.empty()) return NULL;
        int idx = pq.top()[1];
        ListNode* head = lists[idx];
        ListNode* back = head;
        lists[idx] = lists[idx]->next;
        pq.pop();
        if (lists[idx] != NULL) pq.push({lists[idx]->val, idx});
        while (!pq.empty()) {
            arr tp = pq.top();
            idx = tp[1];
            pq.pop();
            back->next = lists[idx];
            back = back->next;
            lists[idx] = lists[idx]->next;
            if (lists[idx] != NULL) {
                pq.push({lists[idx]->val, idx});
            }
        }
        back->next = NULL;
        return head;
    }
};
