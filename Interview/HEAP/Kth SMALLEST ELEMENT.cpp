#include<bits/stdc++.h>
using namespace std;
int main() {
    int t,n;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>t;
    while(t--){
        cin>>n;
        int arr[n+5];
        priority_queue<int > pq;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int k;
        cin>>k;
        //always maintain heap of size k 
      for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }
    
    for(int i=k;i<n;i++){
        // no need to push for every iteration then check 
        //first check then push as push is log time operation
        if(pq.top()>arr[i]){
                pq.pop();
                pq.push(arr[i]);
        }
    }
        
        cout<<pq.top()<<endl;
    }
}