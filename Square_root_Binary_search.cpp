#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,p;
    cin>>n>>p;
    int s,e;
    s=0,e=n;
    float ans;
    while(s<=e){
        int mid=(s+e)/2;
        if(mid*mid==n){
            ans=mid;
            break;
        }
        if(mid*mid>n){
            e=mid-1;
            
        }
        else {
                s=mid+1;
                ans=mid;
            }
        }
    cout<<ans<<endl;
    float inc=0.1;
    for(int i=0;i<p;i++){
        while(ans*ans<=n){
            ans+=inc;
        }
        ans-=inc;
        inc=inc/10;
    }
    cout<<ans<<endl;
}
