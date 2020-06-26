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
    while(temp!=NULL){
        temp=temp->next;
    }
    temp->next=new node(d);
    return;
}
void insert_at_middle(node* &head,int pos,int d){
    if(head==NULL || pos==0){
        insert_at_head(head,d);
        return ;
    }
    else if(leng(head)<pos){
        insert_at_tail(head,d);
        return ;
    }
    else{
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
int main() {
    node* head=NULL;
    insert_at_head(head,1);
    insert_at_head(head,2);
    insert_at_head(head,3);
    insert_at_middle(head,1,9);
    insert_at_middle(head,2,7);
    print(head);
    insert_at_middle(head,8,5);
    print(head);
}
