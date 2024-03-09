/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return head;
        Node* current = head;
        Node* temp;
        while (current) {
            temp = current->next;
            current->next = new Node(current->val);
            current->next->next = temp;
            current = temp;
        }
        current = head;
        while (current) {
            if (current->next && current->random) {
                current->next->random = current->random->next;
            }
            current = current->next ? current->next->next : current->next;
        }
        Node* original = head;
        Node* copy = head->next;
        temp = copy;
        while (original && copy) {
            original->next = original->next ? original->next->next : original->next;
            copy->next = copy->next ? copy->next->next : copy->next;
            original = original->next;
            copy = copy->next;
        }
        return temp;
    }
};
