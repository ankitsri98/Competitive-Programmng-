#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

int  check(vector<int > &arr, int n, int s){
    

    unordered_map<ll , ll > m;
    ll sum=0,x,nm=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        x=sum-s;
        //cout<<sum<<"  "<<x<<endl;
        if(sum==s){
            //cout<<"ppp   "<<i<<endl;
            nm++;
        }
        
        if(m.find(x)!=m.end()){
            //cout<<"qqqq   "<<m[x]<<" " <<i<<endl;
            nm+=m[x];//HERE ILL ADD ALL NO. OF TIMES THE GIVEN SUM CAME IN THE ARRAY
        }
        m[sum]++;//INCREASING THE COUNTER NO. OF TIMES THE PARTICULAR SUM CAME IN THE ARRAY
        
    }
    //cout<<sum<<endl;
    m.clear();
    return nm;

}
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        return check(nums,nums.size(),k);
    }
};
