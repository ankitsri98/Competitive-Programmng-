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
    int getDecimalValue(ListNode* head) {
        int len=0;
        ListNode * cur=head;
        while(cur!=NULL){
            cur=cur->next;
            len++;
        }
        long int n=0;
        while(head!=NULL){
            n+= (head->val) *(1<<len-1);
            //cout<<n<<endl;
            head=head->next;
            len--;
        }
        return n;
    }
};
