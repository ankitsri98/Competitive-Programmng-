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
//for this make product and compare no need to divide by factor always start from start 
//to make forward answer
void func(string s ,int n,int p,int start){
    if(start==n)return ;
    if(p==n){
        cout<<"sfdfsfsdsf  "<<s<<endl;
        return;
    }
   // cout<<s<<" "<<n<<endl;
    for(int i=start;i<=n;i++){
        if(i*p>n)break;
        if(n%i==0){
            func(s+to_string(i),n,p*i,i);
        }
    }
}
void solve(){
    ll n,k,m=0;
    cin>>n;
    string s="";
    func(s,n,1,2);
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
