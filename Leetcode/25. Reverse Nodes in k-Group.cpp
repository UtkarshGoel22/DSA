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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* current = head;
        int count = 0;
        while (current && count != k) {
            current = current->next;
            count++;
        }
        if (count < k) return head;
        else {
            current = head;
            ListNode* prev = NULL;
            ListNode* next = NULL;
            count = 0;
            while (current && count < k) {
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
                count++;
            }
            if (head) head->next = reverseKGroup(next, k);
            return prev;
        }
    }
};
