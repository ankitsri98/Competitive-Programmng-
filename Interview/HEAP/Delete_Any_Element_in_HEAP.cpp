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
void downheapify(vector<int > &heap, int idx){
    int left=2*idx+1;
    int right=2*idx+2;
    //checking if its not the leaf node
    if(left>=heap.size() && right>=heap.size()){
        return ;
    }
    //calc. index of largest priority
    int parent_idx=idx;
    if(left<heap.size() && heap[left]>heap[parent_idx]){
        parent_idx=left;
    }
    if(right<heap.size() && heap[right]>heap[parent_idx]){
        parent_idx=right;
    }
    if(parent_idx==idx)return;//means its already a max heap
    swap(heap[idx],heap[parent_idx]);
    downheapify(heap,parent_idx);
}
void deletepeek(vector<int > &heap){
    swap(heap[0],heap[heap.size()-1]);//send peek to last position
    heap.pop_back();//delete last element 
    downheapify(heap,0);
}
//code for deleting any node from heap
void deleteany(vector<int > &heap ,int idx ){
    heap[idx]=INT_MAX;
    upheapify(heap,idx);
    deletepeek(heap);
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
    cout<<endl;
}
int main() {
    int n,x,idx;
    cin>>n;
    vector<int > heap;
    for(int i=0;i<n;i++){
        cin>>x;
        insert(heap,x);
    }
    cin>>idx;
    display(heap);
    deleteany(heap,idx);
    display(heap);
}
