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
int leng(ListNode* head ){
    int c=0;
    while(head!=NULL){
        head=head->next;
        c++;
    }
    return c;
}
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(!head)return head;
        if(k==0){
            return head;
        }
        int len=leng(head);
        k=abs(len-(k%len));
        
        int c=1;
        ListNode* curr=head;
        while(c<k && curr!=NULL){
            curr=curr->next;
            c++;
        }
        
        //if k==length then after shifting it wont affect the list
        if(curr==NULL){
            return head;
        }
        
        ListNode* kth=curr;
        while(curr->next!=NULL){
            curr=curr->next;
        }
        
        curr->next=head;//linking end to beginning
        
        head=kth->next;//starting to kth next
        
        kth->next=NULL; //kth to null end
        
        return head;
        
    }
};
