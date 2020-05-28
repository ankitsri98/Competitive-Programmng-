#include<bits/stdc++.h>
using namespace std;
int main() {
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int arr[n+5];
        priority_queue<int > pq1;//max heap
        priority_queue<int , vector<int > , greater<int> > pq2;// min heap
        for(int i=0;i<n;i++){
            cin>>arr[i];
            //cout<<"aa  "<<arr[i]<<" ";
            if(i==0){
                pq1.push(arr[0]);
                cout<<arr[0]<<" ";
            }
            else{
                if(pq1.top()>arr[i]){
                    pq1.push(arr[i]);
                }else {
                    pq2.push(arr[i]);
                }
                int a=pq1.size(),b=pq2.size();
                //balanced
                if(abs(a-b)<=1){
                    //evaluating ans
                    if(a==b){
                        cout<<(pq1.top()+pq2.top())/2<<" ";
                    }
                    else if(a>b){
                        cout<<pq1.top()<<" ";
                    }
                    else if(a<b){
                        cout<<pq2.top()<<" ";
                    }
                }
                else{
                    //balancing 
                    if(a>b){
                        pq2.push(pq1.top());
                        pq1.pop();
                    }
                    else if(b>a){
                        pq1.push(pq2.top());
                        pq2.pop();
                    }
                    //evaluating ans
                    cout<<(pq1.top()+pq2.top())/2<<" ";
                }
            }
        }
        cout<<endl;
    }
}
