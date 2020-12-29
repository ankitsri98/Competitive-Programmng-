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
const int mxn=2e5;
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
ll arr[mxn],pro[mxn];
ll n;
ll check(ll x , ll &ans){
    ll cur,val1=0,val2=INT_MAX,val3=INT_MAX;
    cur=arr[x];
    REP(i,0,n){
        if(i!=x){
            val1+= abs(arr[i]-arr[x])*pro[i];
        }
    }
    if(x<n-1){
        cur=arr[x+1];
        val2=0;
        REP(i,0,n){
            if(i!=x+1){
                val2+= abs(arr[i]-arr[x+1])*pro[i];
            }
        }
    }
    if(x>0){
        cur=arr[x-1];
        val3=0;
        REP(i,0,n){
            if(i!=x-1){
                val3+= abs(arr[i]-arr[x-1])*pro[i];
            }
        }
    }
    //val3  val1  val2
    //cout<<val3<<"  "<<val1<<"  "<<val2<<endl;
    if(val1 < val3  && val1 <  val2){
        ans=val1;
        return 1;
    }
    else if(val1 < val3  && val1 >  val2){
        return 2;
    }
    else if(val1 > val3  && val1 <  val2){
        return 3;
    }
}
void solve(){
    ll m,x;
    cin>>n;
    
    REP(i,0,n)cin>>arr[i];
    REP(i,0,n)cin>>pro[i];
    ll l=0,r=n-1,ans;
    while(l<=r){
        ll mid =  l + (r-l)/2;
        //cout<<mid<<endl;
        x=check(mid,ans);
        if(x==1){
            cout<<ans<<endl;break;
        }
        else if(x==2){
            l++;
        }
        else{
            r--;
        }
    }
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




