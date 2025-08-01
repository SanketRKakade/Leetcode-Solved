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
    ListNode* swapPairs(ListNode* head) {
    // Dummy node to handle edge cases
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        
        while (prev->next && prev->next->next) {
            ListNode* first = prev->next;
            ListNode* second = prev->next->next;
            
            // Swapping
            first->next = second->next; // 1 points to 3
            second->next = first;       // 2 points to 1
            prev->next = second;        // prev points to 2
            
            // Move prev pointer two nodes ahead
            prev = first;
        }
        return dummy.next;
    }

};