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


//complexity is  O(N^K)
// another method is to run 2 loops chose 2 values and swap and capture max value
void func(string s ,int k,string &max,int curr,int n){
    if(k==0)return;
    char ma=s[curr];
    REP(i,curr,n){
        if(ma<s[i])ma=s[i]; //find max to swap curr with it 
    }
    //cout<<ma<<endl;
    if(ma!=s[curr]){
        k--;//means effective swap will take place ( GREEDY MOVE )
    }

    REP(i,curr,n){
        if(s[i]==ma){
            swap(s[i],s[curr]);
            //cout<<s<<endl;
            if(s.compare(max)>0){
                max=s;
            }
            func(s,k,max,curr+1,n);
            swap(s[i],s[curr]);
        }
    }

    
}
void solve(){
    ll n,k,m=0;
    string s,max;
    cin>>s>>k;
    max=s;
    func(s,k,max,0,s.size());
    cout<<max<<endl;
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
