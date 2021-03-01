#include<bits/stdc++.h>
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
    if(head==NULL){
        head=new node(d);
        return ;
    }
    node* n=new node(d);
    n->next=head;
    head=n;
}
void insert_at_tail(node* &head,int d){
    if(head==NULL){
        head=new node(d);return ;
    }
    node * t=head;
    while(t->next!=NULL){
        t=t->next;
    }
    t->next=new node(d);

}
void del_head(node* &head){
    if(head==NULL)return ;
    node* t=head;
    head=head->next;
    delete t;
}
void del_tail(node* &head){
    if(head==NULL)return ;
    node* t=head;
    node* prev;
    while(t->next!=NULL){
        prev=t;
        t=t->next;
    }
    delete t;
    prev->next=NULL;
}
void print(node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
int leng(node* head){
    int x=0;
    while(head!=NULL){
        x++;
        head=head->next;
    }
    return x;
}
void find_cycle(node* head){
    node* s=head;
    node* f=head;
    int x=0;
    while(f!=NULL && f->next!=NULL){
        s=s->next;
        f=f->next->next;
        if(f==s){
            x=1;break;
        }
    }
    if(x==0)cout<<"NO cycle fount"<<endl;
    else cout<<"cycle found"<<endl;
}
void form_cycle(node* &head){
    node* x=NULL;
    node* t=head;
    while(t->data!=2){
        t=t->next;
    }
    x=t;
    t=head;
    while(t->next!=NULL){
        t=t->next;
    }
    t->next=x;
}
void start_of_cycle(node* head){
    node* s=head;
    node* f=head;
    int x=0;
    while(f!=NULL && f->next!=NULL){
        s=s->next;
        x++;
        f=f->next->next;
        if(f==s){
            break;
        }
    }
    cout<<x<<endl;
    s=head;
    while(s!=f){
        s=s->next;
        f=f->next;
    }
    cout<<f->data<<endl;
}
void removal_of_cycle(node* &head){
    node* s=head;
    node* f=head;
    int x=0;
    while(f!=NULL && f->next!=NULL){
        s=s->next;
        x++;
        f=f->next->next;
        if(f==s){
            break;
        }
    }
    s=head;
    node* prev;
    while(s!=f){
        prev=f;
        s=s->next;
        f=f->next;

    }
    prev->next=NULL;
}
node* Rev_LL(node* head){
    if(head==NULL || head->next==NULL)return head;
    node* sm=Rev_LL(head->next);
    node* c=head;
    c->next->next=c;
    c->next=NULL;
    return sm;
}
int main(){
    node* head=NULL;
    insert_at_head(head,2);
    insert_at_head(head,3);
    insert_at_head(head,4);
    insert_at_tail(head,5);
    insert_at_tail(head,6);
    insert_at_tail(head,7);
    insert_at_tail(head,2);
    print(head);
    form_cycle(head);
    find_cycle(head);
    start_of_cycle(head);
    removal_of_cycle(head);
    find_cycle(head);
    print(head);
    node* x=Rev_LL(head);
    print(x);
    //del_head(head);
    //del_tail(head);
    //print(head);
    //cout<<leng(head)<<endl;
    //del_head(head);
    //del_tail(head);

}
