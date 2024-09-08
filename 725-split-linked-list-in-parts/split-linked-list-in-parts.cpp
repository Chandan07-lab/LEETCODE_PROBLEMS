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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* curr=head;
        int L=0;
        while(curr){
            L++;
            curr=curr->next;
        }

        int eachbucketnodes=L/k;
        int remainingnodes=L%k;
        vector<ListNode*>re(k,NULL);
        curr= head;
        ListNode* prev=NULL;
        for(int i=0;curr&&i<k;i++){
            re[i]=curr;
            for(int count=1;count<=eachbucketnodes+(remainingnodes>0)?1:0;count++){
                prev=curr;
                curr=curr->next;
            }
            prev->next=NULL;
            remainingnodes--;

        }

        return re;
    }
};