#include<bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long int lli;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<pll> vop;
typedef vector<ll> vl;
typedef vector<vl> vvl;
#define REP(i,a,b) for(long long int i=a;i<b;i++)
#define REPR(i,a,b) for(long long int i=a;i>=b;i--)
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define all(x) (x).begin(),(x).end()
#define endl "\n"
#define mem(a,b) memset(a,b,sizeof(a))
#define mod 1000000007
#define MAX LLONG_MAX
const int mxn=2e5+5;
#define INF 1e18
ll power(ll a,ll b,ll m) { ll ans=1; while(b) { if(b&1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return (ans+m)%m; }
 
ll lcm(ll a, ll b) { return (a*b)/__gcd(a, b); }
 
ll modInverse(ll a, ll m) { ll g = __gcd(a, m); return power(a, m-2, m); } 
 
//there is one more method of counting the +ve od _ve subarrays and 
//subtracting it from n*(n+1)/2;
void solve(){
    ll n,k,m;
    cin>>n;
    ll arr[n+3];
    REP(i,1,n+1)cin>>arr[i];
    ll dp[n+2][3]={0};
    if(arr[1]>0){
    	dp[1][0]=1;
    }
    else{
    	dp[1][1]=1;
    }
    //0->positive 1->negative
    REP(i,2,n+1){
    	if(arr[i]>0){
    		//+ve number just increase the +ve count and -ve count remains the same
    		dp[i][0]=dp[i-1][0]+1;
    		dp[i][1]=dp[i-1][1];
    	}
    	else{
    		//in case of -ve number all +ve seq. till now becomes -ve and this -ve adds 1
    		//and incase of +ve = -ve sequences becomes +ve 
    		//remeber states
    		dp[i][0]=dp[i-1][1];
    		dp[i][1]=dp[i-1][0]+1;
    	}
    }
    /*REP(i,1,n+1){
    	cout<< arr[i]<<"  ->   ";
    	REP(j,0,2){
    		cout<<dp[i][j]<<"   ";
    	}
    	cout<<endl;
    }*/
    ll a=0,b=0;
    REP(i,1,n+1){
    	a+=dp[i][0];
    	b+=dp[i][1];
    }
    cout<<b<<" "<<a<<endl;
}
int main()
{
    fastIO;
    ll t=1;
    //cin >> t;
    while(t--)
    {
        solve();

    }
    return 0;
}
 
