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
    ListNode* findMiddleOfList(ListNode* head) {
        ListNode* fast = head;
        ListNode* prev = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        prev->next = NULL;
        return slow;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* current = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
    ListNode* mergeLists(ListNode* head1, ListNode* head2) {
        ListNode* newHead = new ListNode(0);
        ListNode* newTail = newHead;
        while (head1 && head2) {
            newTail->next = head1;
            newTail = head1;
            head1 = head1->next;
            newTail->next = head2;
            newTail = head2;
            head2 = head2->next;
        }
        return newHead->next;
    }
    void reorderList(ListNode* head) {
        // base case
        if (!head || !head->next) return;
        // find mid
        ListNode* mid = findMiddleOfList(head);
        // reverse the second part of the list
        ListNode* head2 = reverseList(mid);
        // merge the two lists.
        ListNode* head1 = head;
        ListNode* newHead = mergeLists(head1, head2);
        head = newHead;
    }
};
