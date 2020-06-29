#include <bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* next;
    node(int d){
        data=d;
        next=NULL;
    }
};

void insert_at_head(node* &head,int d){
    //form start node with data d
    node* n=new node(d);
    n->next=head;
    head=n;
}
void print(node * head){
    while(head!=NULL){
        cout<<head->data<<"  ->  ";
        head=head->next;
    }
    cout<<endl;
}
int leng(node* head){
    int l=0;
    while(head!=NULL){
        head=head->next;
        l++;
    }
    return l;
}
void insert_at_tail(node* &head,int d){
    if(head==NULL){
        head=new node(d);
        return ;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    node* n=new node(d);
    temp->next=n;
    return;
}

void insert_at_middle(node* &head,int pos,int d){
    if(head==NULL || pos==0){
    	//cout<<"A"<<endl;
        insert_at_head(head,d);
        return ;
    }
    else if(leng(head)<pos){
    	//cout<<"B"<<endl;
        insert_at_tail(head,d);
        return ;
    }
    else{
    	//cout<<"C"<<endl;
	    int jump=1;
	    node* temp=head;
	    while(jump<=pos-1){
	        temp=temp->next;
	        jump++;
	    }
	    node* n=new node(d);
	    n->next=temp->next;
	    temp->next=n;
        return ;
    }
}
void print_mid_point(node* head){
    if(head->next==NULL && head==NULL){
        cout<<head->data<<endl;;
    }
    node* slow=head;
    node* fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    cout<<slow->data<<endl;
}
void k_node_from_end(node* head,int k){
    node* fast=head;
    node* slow=head;
    int x=k;
    while(x--){
        fast=fast->next;
    }
    while(fast!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
    cout<<slow->data<<endl;

}
node* recur_Reverse(node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node* smallhead=recur_Reverse(head->next);//ponts to end
    node* c=head;
    c->next->next=c;
    c->next=NULL;
    return smallhead;
}
//BOTH LL SHOULD BE SORTED
node* merge_2_ll(node* a,node* b){
    if(a==NULL){
        return b;
    }
    else if(b==NULL){
        return a;
    }
    node* c;
    if(a->data < b->data){
        c=a;
        c->next=merge_2_ll(a->next,b);
    }
    else{
        c=b;
        c->next=merge_2_ll(a,b->next);
    }
    return c;
}
bool cycle_detection(node* head){
    node* fast=head;
    node* slow=head;
    int x=0;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            return true;
        }
    }
    return false;
}
void length_of_cycle(node* head){
    node* fast=head;
    node* slow=head;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            cout<<"Cycle Detected"<<endl;
            break;
        }
    }
    int c=0;
    while(slow->next!=fast){
        slow=slow->next;
        c++;
    }
    cout<<"Length of Cycle is "<<c<<endl;
}
void Starting_of_Cycle(node* head){
    node* fast=head;
    node* slow=head;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            cout<<"Cycle Detected"<<endl;
            break;
        }
    }
    slow=head;
    while(slow!=fast){
        fast=fast->next;
    }
    cout<<"starting of Cycle is "<<slow->data<<endl;
}
int main() {
    node* head=NULL;
    node* h=NULL;
    node* mod=NULL;
    insert_at_head(head,3);
    insert_at_head(head,2);
    insert_at_head(head,1);
    insert_at_head(h,13);
    insert_at_head(h,12);
    insert_at_head(h,11);
    print(head);
    print_mid_point(head);
    k_node_from_end(head,3);
    mod=merge_2_ll(head,h);
    print(mod);
    mod->next->next->next=head;//forming cycle
    cout<<cycle_detection(head)<<endl;
    length_of_cycle(mod);
    Starting_of_Cycle(mod);
}
