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
 

 
void solve(){
    ll n,m,y,x2=0,y2,z1,z2,l,r,ans;
    ll upto,len;
    cin>>upto>>len;
    ll arr[len+2][upto+2]={0};
    //we only form base case for the state in which we move backward
    //base case: for length 1 for every element 1 sequence will be form
    //for filling further new elements we add this number to the sequence of len-1 and prev. elemnt is a factor
    
    REP(i,1,upto+1){
        arr[1][i]=1;//1 LENGTH KI SEQUENCE JAB HAR TYPE KA 1 ELEMENT HOGA :- MEANS FOR 1 LEN 3 ELEMENTS :- ANS=3 [1],[2],[3]  SO AT[1][1]=1 AT[1][2]=1 AT[1][3]=1 
     //TO FIND ALL U HAVE TO TAKE SUM OF ALL LIKE TOTAL=AT[1][1] + AT[1][2] + AT[1][3]; I.E =3
    }
    REP(i,2,len+1){
        REP(j,1,upto+1){
            int x=j;
            for(int k=1;k*k<=x;k++){
                if(x%k==0){
                    //cout<<"for : "<<x<<" factor: "<<k<<endl;
                    //factors
                    arr[i][j]+=arr[i-1][k]+ (x/k!=k ? arr[i-1][x/k] : 0);
                    
                }
            }
        }
    }
   /* REP(i,1,len+1){
        REP(j,1,upto+1){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }*/
    int tot=0;
    REP(i,1,upto+1){// TAKE TOTAL OF LEN JAB 1 ELE. THA JAB 2 THE JAB 3 ..4..5..6 THE 
        tot+=arr[len][i];
    }
    //summing up for all elements
    cout<<tot<<endl;
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
