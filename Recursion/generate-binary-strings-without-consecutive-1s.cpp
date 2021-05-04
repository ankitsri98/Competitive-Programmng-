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


void func(int i,int n,vector<int> a, vector<vector<int > > &b){
    if(i==n-1){
        b.PB(a);
        return ;
        /*for(auto it: a){
            cout<<it<<" ";
        }
        cout<<endl;*/
    }
    if(a.back()==1){
        a.PB(0);
        func(i+1,n,a,b);
        a.pop_back();
    }
    else {
        a.PB(1);
        func(i+1,n,a,b);
        a.pop_back();
        a.PB(0);
        func(i+1,n,a,b);
        a.pop_back();
    }
}
void solve(){
    ll n,k,m=0;
    cin>>n;
    cout<<n<<endl;
    vector<int > y;
    y.PB(1);
    vector<vector<int > > x;
    func(0,n,y,x);
    y.pop_back();
    y.PB(0);
    func(0,n,y,x);
    y.pop_back();
    /*for(auto i:x){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }*/
    cout<<x.size()<<endl;
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
