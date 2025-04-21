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
ListNode * reverselink(ListNode* head){
    ListNode*prev=nullptr;
    ListNode*curr=head;
    while(curr!=nullptr){
        ListNode* forward =curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
return prev;
}
    bool isPalindrome(ListNode* head) {

        if(head==NULL || head->next==NULL){
            return true;
        }

        ListNode * slow=head;
        ListNode * fast=head;

        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;

        }

        ListNode * newhead= reverselink(slow->next);
        
        ListNode * first=head;
        ListNode * sec= newhead;
    
        while(sec!=NULL){

            if(first->val!=sec->val){
                reverselink(newhead);

                return false;
            }
            first=first->next;
            sec=sec->next;
        }

        reverselink(newhead);
        return true;
    }
};