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
ListNode* mid(ListNode* head){
    ListNode* slow=head;
    ListNode* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
ListNode* rev(ListNode* head){
    if(head->next==NULL){
        return head;
    }
    ListNode* smallans=rev(head->next);
    ListNode* c=head;
    c->next->next=c;
    c->next=NULL;
    return smallans;
}
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head){
            return true;;
        }
        ListNode* m=mid(head);
        ListNode* r=rev(m);
        while(r!=NULL){
            if(r->val!=head->val){
                return false;
            }
            r=r->next;
            head=head->next;
        }
        return true;
    }
};





