#include <bits/stdc++.h>
using namespace std;
#define ll long long int
//LIFO
int arr[1000005];
int ans[1000005];
int n;
//stack contains indices because it can be used to
// compare array elements
void findvalue(stack<int > &s){
    s.push(0);ans[0]=0;
    for(int i=1;i<n;i++){//day loop
        int currprice=arr[i];
        while(!s.empty() && arr[s.top()]<currprice){
            s.pop();
        }
        int betterday= s.empty()==true ? 0 : s.top();
        int span=i-betterday;
        ans[i]=span;
        s.push(i);
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
}
int main()
{
    stack<int  > s;

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    findvalue(s);

   /* while(!s.empty()){
        cout<<s.top().first<<" ";
        s.pop();
    }*/
    return 0;
}
