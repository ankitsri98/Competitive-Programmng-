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
//----------------------------------------------------------------------------------------
//lower_bound returns an iterator pointing to the first ele. which has a value not less than ‘val
#define LB(arr,n) ll c=0;it=lower_bound(arr.begin(),arr.end(),n);if(it==arr.end()){c=1;}
//define it and if c==1 means not found
#define LB1(arr,n) ll idx=it-arr.begin();if(arr[idx]==n){ idx=idx;}else{idx=idx-1;}
// here idx holds the index( 0 based) of found element
//-----------------------------------------------------------------------------------------
//upper_bound returns an iterator pointing to the first ele. which has a value greater than ‘val’.
#define UB(arr,n) ll c=0;it=upper_bound(arr.begin(),arr.end(),n);if(it==arr.end()){c=1;}
#define UB1(arr,n) ll idx=it-arr.begin();
//-----------------------------------------------------------------------------------------
 
ll power(ll a,ll b,ll m) { ll ans=1; while(b) { if(b&1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return (ans+m)%m; }
 
ll lcm(ll a, ll b) { return (a*b)/__gcd(a, b); }
 
ll modInverse(ll a, ll m) { ll g = __gcd(a, m); return power(a, m-2, m); } 
 
bool cmp(pair<int ,int > &a,pair<int ,int > & b){
    if(a.second!=b.second){
        return a.first<b.first;
    }
    else{
        return a.second<b.second;
    }
}
//prime factors of 10^18
vector<long long int> genfactors(long long int n){
    vector<long long int> res; 
    long long int val = 2;
    for(long long int i = 2; i*i <= n ; ++i){
        while(n%i == 0){
            res.push_back(i);
            n/=i;
        }
    }
    if(n > 1) res.push_back(n);
    return res;
}
//--------------------------------------------------------------------------------------------


void solve(){
    ll n,k,m;
    ll l,r;
    cin>>n>>l>>r;
    ll arr[4];
    l--;
    /*
    here goes the explanation of how to find the numbers in range L to R with remainder 0 or 1 or 2 when
    divide by 3.
    just think of the problem of how we count in sequence from 0 that is 
    for 0 remainder:- 0 to R ans will be R/3 say A and from 0 to L-1 its (L-1)/3 say B so we want from [L,R]
    so final answer will be (A-B);
    similarly for remainder 1 and 2 we can think og the iniquality like
    L<= 3*k - 1 <=R   and  L<= 3*k - 2 <=R respectively just find k remember that L will be L-1 fro above logic
    */
    arr[0]=((r/3)-(l)/3);
    arr[1]=((r+1)/3-(l+1)/3);
    arr[2]=((r+2)/3-(l+2)/3);

    //cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<endl;
    ll dp[n+2][4]={0};
    dp[1][0]=arr[0],dp[1][1]=arr[1],dp[1][2]=arr[2];
    /*
    Now how to fill the dp matrix dp[i][j]= i length sequence with j remainder
    how to fill dp[i][0]= what all elements i can add behind seq. of i-1 length such that sum is 0;
    so sum %3 can be zero if we add 
    no. of seq. (i-1) len. with remainder (combine with) total elements present with X remainder
    (0      dp[i-1][0]                                +             0 (already calc. before)) %3 =0
    (1      dp[i-1][1]                                +             2 (already calc. before)) %3 =0
    (2      dp[i-1][2]                                +             1 (already calc. before)) %3 =0

    similary for 1
    0+1
    1+0
    2+2
    similary for 2
    0+2
    2+0
    1+1
    */
    for(int i=2;i<=n;i++){
    	dp[i][1]=((dp[i-1][0]*arr[1])%mod + (dp[i-1][1]*arr[0])%mod + (dp[i-1][2]*arr[2])%mod)%mod;
    	dp[i][2]=((dp[i-1][1]*arr[1])%mod + (dp[i-1][2]*arr[0])%mod + (dp[i-1][0]*arr[2])%mod)%mod;
    	dp[i][0]=((dp[i-1][0]*arr[0])%mod + (dp[i-1][1]*arr[2])%mod + (dp[i-1][2]*arr[1])%mod)%mod;
    }
    cout<<dp[n][0]<<endl;

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
 
