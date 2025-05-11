class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // Step 1: Find the length of the list and the  node
        int length = 1;
        ListNode* temp = head;
        
        while (temp->next) {
            length++;
            temp = temp->next;
        }

        // Step 2: Handle cases where k >= length
        k = k % length;
        if (k == 0) return head;

        // Step 3: Find the breaking point
        int breakPoint = length - k;
        ListNode* current = head;
        for (int i = 1; i < breakPoint; i++) {
            current = current->next;
        }

        // Step 4: Rotate the list
        ListNode* newHead = current->next;
        current->next = nullptr;
        temp->next = head;

        return newHead;
    }
};