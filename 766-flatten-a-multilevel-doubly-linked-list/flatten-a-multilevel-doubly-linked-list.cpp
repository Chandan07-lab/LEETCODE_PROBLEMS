/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) return nullptr;
        stack<Node*>st;
        Node* temp= head;

        while(temp){
            if(temp->child){
                if(temp->next)st.push(temp->next);

                temp->next=temp->child;
                temp->next->prev=temp;

                temp->child=nullptr;
            }

            if(!temp->next && !st.empty()){
                temp->next=st.top();
                st.pop();
                temp->next->prev=temp;

            }
            
            temp=temp->next;
        }
     return head;
    }
};