#include <bits/stdc++.h>
using namespace std;
//Building max heap
void upheapify(vector<int > &heap, int idx){
    if(idx==0){
        return ;
    }
    int parent_idx=(idx-1)/2;
    if(heap[parent_idx]<heap[idx]){
        swap(heap[parent_idx],heap[idx]);
        upheapify(heap,parent_idx);
    }
    else{
        return ;
    }
}
//FIRSTLY INSERT THE VALUE AT THE END 
void insert(vector<int > &heap, int val){
    heap.push_back(val);
    upheapify(heap,heap.size()-1);//CALL UPHEAPIFY FROM THE LAST INDEX
}

void display(vector<int > &heap ){
    for(auto i: heap){
        cout<<i<<" ";
    }
}
int main() {
    int n,x;
    cin>>n;
    vector<int > heap;
    for(int i=0;i<n;i++){
        cin>>x;
        insert(heap,x);
    }
    display(heap);
}
