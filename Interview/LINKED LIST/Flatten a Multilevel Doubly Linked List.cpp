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
        Node* temp=head;
        stack<Node* > s;
        while(head!=NULL){
            if(head->child!=NULL){// agar child hai toh bas ye dekhlo ki next hai ki nhi agar hai toh 
                //bas uska address stack me daal lo
                if(head->next!=NULL){
                    s.push(head->next);
                }
                //ab bas head ke next ko adjust karlo child se and child ko NULL
                head->next=head->child;
                head->next->prev=head;
                head->child=NULL;
            }
            // normally traversing hori hai toh agar child NULL hai toh bas list end hogi 
            //in that case humko last node ko bache hui stack se link kardo bas
            else if(head->next==NULL && s.empty()==0){
                    head->next=s.top();
                    head->next->prev=head;
                    s.pop();
            }
            //head toh humesha chalega hi
            head=head->next;
        }
        return temp;
    }
};
