#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

int main(){
    ll n;
    ll flag=INT_MIN,sum=0,k,x;
    cin>>n>>k;
    ll arr[n+1];
    unordered_map<ll, ll > s;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sum=0;
    for(ll i=0;i<n;i++){
        sum+=arr[i];
        x=sum-k;
        if(sum==k){
            flag=max(flag,i+1);//if prefix sum becomes zero
        }
        if(s.find(x)!=s.end()){
            flag=max(flag, i-s[x]);
            //cout<<i<<" " <<x<<" "<<s[x]<<endl;
        }else if(s.find(sum)==s.end()){//only if it had not came earlier
        s[sum]=i;
        }
    }
    cout<<flag<<endl;
    
}