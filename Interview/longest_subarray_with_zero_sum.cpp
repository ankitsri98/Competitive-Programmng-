#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

int main(){
    ll n;
    ll flag=INT_MIN,sum=0;
    cin>>n;
    ll arr[n+1];
    unordered_map<ll, ll > s;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sum=0;
    for(ll i=0;i<n;i++){
        sum+=arr[i];
        if(arr[i]==0 && flag==0){//if any array element is zero 
            flag=1;
        }
        if(sum==0){
            flag=max(flag,i+1);//if prefix sum becomes zero
        }
        if(s.find(sum)!=s.end()){
            flag=max(flag, i-s[sum]);
            //cout<<flag<<endl;
        }else{
        s[sum]=i;
        }
    }
    cout<<flag<<endl;
    
}