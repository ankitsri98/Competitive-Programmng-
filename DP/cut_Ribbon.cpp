#include <bits/stdc++.h>
using namespace std;
#define ll long long int 


void solve(){
	ll n,m,k,a,b,c;
	cin>>n>>a>>b>>c;
	ll ac[]={a,b,c};
	ll dp[n+2]={0};
	//in this question we want to find max no. of parts that we need to make
	//array modification:- we do not pick position i-ac[j]>0 where dp value is 0
	//we take if i-ac[j]==0 so to avoid those places with 0 value put dp value
	//INT_MIN initially

	for(int i=1;i<=n;i++){
		dp[i]=INT_MIN;//main step
		for(int j=0;j<=2;j++){
			//cout<<i<<"  "<<ac[j]<<endl;
			if(i-ac[j]>=0 ){
				dp[i]=max(dp[i],dp[i-ac[j]]+1);
			}
		}
	}
	/*for(int i=0;i<=n;i++){
		cout<<dp[i]<<" ";
	}
	cout<<endl;*/
	cout<<dp[n]<<endl;
	
}
int main()
{
    //fastIO;
    ll t=1;
    //cin >> t;
    while(t--)
    {
        solve();

    }
    return 0;
}
