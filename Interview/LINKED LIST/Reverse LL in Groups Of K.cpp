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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* p=head;
        if(head==NULL)return head;
        int x;
        for(int i=0;i<k;i++){
            if(!p) {    x=i;break;}//return head;
            p=p->next;//finally p is reaching to the node where next segment will start
        }
        ListNode* Last=head;//storing it so that the start of next segment can easily be called
        ListNode* temp;//for keeping the track of next node while reversing the segment list
        
        for(int i=0;i<x;i++){
            temp=head->next;//store tract of next element
            head->next=p;// making reverse pointing
            p=head;//prev element 
            head=temp;//moving ahead
        }
  
       Last->next=reverseKGroup(Last->next,k);
        
        return p;//returning p coz at the end p is holding start of segment
    }
};

//also reverse the remaining incomplte segement
