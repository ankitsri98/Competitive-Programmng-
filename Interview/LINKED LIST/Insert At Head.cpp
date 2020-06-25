
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
int main() {
    node* head=NULL;
    insert_at_head(head,1);
    insert_at_head(head,2);
    insert_at_head(head,3);
    print(head);
}
