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

    ListNode* findmidNode(ListNode* &head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL){
            fast=fast->next;
            if(fast->next!=NULL){
                fast=fast->next;
                slow=slow->next;
            }
        }
        return slow;
    }

    ListNode* reverseLL(ListNode* prev , ListNode* &curr){
        ListNode* head=curr;
        ListNode* temp=head;
        ListNode* nextNode=head;

        while(curr!=NULL){

            nextNode=nextNode->next;
            temp->next=prev;
            prev=curr;
            curr=nextNode;
            temp=nextNode;
            
        }
        return prev;
    }
    bool check(ListNode* head1, ListNode* head2){
        while(head1!=NULL && head2!=NULL){
            if(head1->val!=head2->val){
                return false;
            }
            else{
                head1=head1->next;
                head2=head2->next;
            }
            
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        //find the mid node;
        ListNode* midNode=findmidNode(head);
        ListNode* head2 = midNode->next;
        midNode->next=NULL;
        ListNode* prev=NULL;
        ListNode* curr=head2;
        head2=reverseLL(prev,curr);

        bool ans=check(head,head2);
        return ans;
        
    }
};