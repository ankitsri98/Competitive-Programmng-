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

void precompute(string pat,vector<ll > &lps){
    ll m=pat.size();
    lps[0]=0;
    ll j=0,i=1;
    while(i<m){
        if(pat[j]==pat[i]){
            lps[i]=j+1;
            i++,j++;
        }
        else{
            if(j==0)lps[i]=0,i++;
            else{
                j=lps[j-1];
            }
        }
    }
}
void kmp(string s,string pat){
    ll n=s.size(),m=pat.size();
    vector<ll > lps(m);
    precompute(pat,lps);
    /*REP(i,0,m)cout<<lps[i]<<" ";
    cout<<endl;*/
    ll j=0,i=0;
    while(i<n){
        if(s[i]==pat[j])i++,j++;
        if(j==m){
            cout<<"found at:- "<<i-j<<endl;
            j=lps[j-1];
        }
        if(s[i]!=pat[j]){
            if(j!=0)j=lps[j-1];
            else i++;
        }
    }
}
void solve(){
    ll n,k,m;
    string s,pat;
    cin>>s>>pat;
    kmp(s,pat);
    
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
