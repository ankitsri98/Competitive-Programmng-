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
 
 ll primes[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

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
    cin>>n;
    ll arr[n+2];
    REP(i,1,n+1){
        cin>>arr[i];
    }
    //in order to buy max ele. i have to multiply by 2 make smallest divisible
    //why would i divide every number by 2 create problem in case of odd
    // i will * by 2 and mark from which positions j is reachable
    ll ans=1;
    ll dp[n+2];
    REP(i,1,n+1)dp[i]=1;
    REP(i,1,n+1){
        int j=i*2;
        //cout<<j<<" ";
        //j basically vo hai ki mai ith index se kon kon se j ko contribute kasakta hoon
        while(j<=n){
            if(arr[j]>arr[i]){
                dp[j]=max(dp[j],dp[i]+1);
            }
            j+=i;
            //cout<<j<<" ";
        }
        //cout<<endl;
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;
}
int main()
{
    fastIO;
    //precompute();
    ll t=1;
    cin >> t;
    while(t--)
    {
        solve();

    }
    return 0;
}
