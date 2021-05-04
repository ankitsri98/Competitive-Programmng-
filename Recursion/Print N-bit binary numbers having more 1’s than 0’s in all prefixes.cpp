#include<bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long int lli;
typedef long long  int ll;
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

vector<string > ans;
void func(int a, int b, string s ,int n,int i){
    if(i==n){ans.PB(s);return ;}

    if(a==b){
        func(a,b+1,s+"1",n,i+1);
    }
    else if(b>a){
        func(a+1,b,s+"0",n,i+1);
        func(a,b+1,s+"1",n,i+1);
    }
}
void solve(){
    ll n,k,m=0;
    cin>>n;
    string s="";
    func(0,0,s,n,0);
    for(auto i : ans)cout<<i<<endl;
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
