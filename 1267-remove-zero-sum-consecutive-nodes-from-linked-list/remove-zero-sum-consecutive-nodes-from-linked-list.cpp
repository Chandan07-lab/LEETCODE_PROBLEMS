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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int,ListNode*>mp;
        int prefixsum=0;
        ListNode*dummy=new ListNode(0);
        dummy->next=head;

        for(ListNode*curr=dummy;curr!=nullptr;curr=curr->next){
            prefixsum+=curr->val;
            mp[prefixsum]=curr;
        }

        prefixsum=0;

        for(ListNode*curr=dummy;curr!=nullptr;curr=curr->next){
            prefixsum+=curr->val;
            curr->next=mp[prefixsum]->next;

        }

        return dummy->next;
    }
};