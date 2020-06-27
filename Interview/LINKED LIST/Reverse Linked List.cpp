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
//reversing  the linked list
void reverse(node* &head){
    node* p=NULL;
    node*c=head;
    node* n;
    while(c!=NULL){
        n=c->next;
        c->next=p;
        p=c;
        c=n;
    }
    head=p;
}
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
void insert_at_tail(node* head,int d){
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
void delete_head(node* &head){
    if(head==NULL){
        return ;
    }
    node* temp=head;
    head=head->next;
    delete temp;
}
void delete_tail(node* head){
    node* temp=head;
    node* prev;
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    delete temp;
    prev->next=NULL;
}
void insert_at_middle(node* &head,int pos,int d){
    if(head==NULL || pos==0){
    	cout<<"A"<<endl;
        insert_at_head(head,d);
        return ;
    }
    else if(leng(head)<pos){
    	cout<<"B"<<endl;
        insert_at_tail(head,d);
        return ;
    }
    else{
    	cout<<"C"<<endl;
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
bool search(node* head,int d){
    if(head==NULL){
        return false;
    }
    if(head->data==d){
        return true;
    }
    else{
        return search(head->next,d);
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
    insert_at_middle(head,8,6);
    delete_tail(head);
    delete_head(head);
    print(head);
    cout<<search(head,12)<<endl;
    reverse(head);
    print(head);
}
