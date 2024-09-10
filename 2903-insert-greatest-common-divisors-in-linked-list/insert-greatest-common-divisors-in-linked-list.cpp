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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head||!head->next){
            return head;
        }
        ListNode *curr=head;
        ListNode *nextn=head->next;

        while(nextn){
            ListNode* temp=new ListNode(__gcd(curr->val,nextn->val));
            curr->next=temp;
            temp->next=nextn;
            curr=nextn;
            nextn=nextn->next;

        }
        return head;
    }
};