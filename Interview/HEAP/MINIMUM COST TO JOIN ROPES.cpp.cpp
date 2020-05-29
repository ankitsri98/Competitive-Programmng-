#include <bits/stdc++.h>
using namespace std;

int Connecting_Ropes(int* ropes, int n){
    //TAKE THE 2 MIN. ELEMENTS ADD THE THEN PUSH THEN PQ ....REPEAT THIS UNTIL IT BECOMES ONE.
    priority_queue<int , vector<int > , greater<int > > pq(ropes, ropes+n);
    int cost=0;
    while(pq.size()>1){
        int a=pq.top();
        pq.pop();
        int b=pq.top();
        pq.pop();
        cost+=a+b;
        pq.push(a+b);
    }
    return cost;
}
int main() {
    int n,x,idx;
    cin>>n;
    int* heap =new int[n+2]();
    for(int i=0;i<n;i++){
        cin>>x;
        heap[i]=x;
    }
    cout<<Connecting_Ropes(heap,n);
}
