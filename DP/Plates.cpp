/*
Problem
Dr. Patel has N stacks of plates. Each stack contains K plates. Each plate has a positive beauty value, describing how beautiful it looks.

Dr. Patel would like to take exactly P plates to use for dinner tonight. If he would like to take a plate in a stack, he must also take all of the plates above it in that stack as well.

Help Dr. Patel pick the P plates that would maximize the total sum of beauty values.

Input
The first line of the input gives the number of test cases, T. T test cases follow. Each test case begins with a line containing the three integers N, K and P. Then, N lines follow. The i-th line contains K integers, describing the beauty values of each stack of plates from top to bottom.

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the maximum total sum of beauty values that Dr. Patel could pick.

Limits
Time limit: 20 seconds per test set.

Memory limit: 1GB.

1 ≤ T ≤ 100.

1 ≤ K ≤ 30.

1 ≤ P ≤ N * K.

The beauty values are between 1 and 100, inclusive.

Test set 1
1 ≤ N ≤ 3.

Test set 2
1 ≤ N ≤ 50.

Sample
 

Input

 

 

Output

 

2
2 4 5
10 10 100 30
80 50 10 50
3 2 3
80 80
15 50
20 10

  
Case #1: 250
Case #2: 180

  
In Sample Case #1, Dr. Patel needs to pick P = 5 plates:

He can pick the top 3 plates from the first stack (10 + 10 + 100 = 120).
He can pick the top 2 plates from the second stack (80 + 50 = 130) .
In total, the sum of beauty values is 250.

In Sample Case #2, Dr. Patel needs to pick P = 3 plates:

He can pick the top 2 plates from the first stack (80 + 80 = 160).
He can pick no plates from the second stack.
He can pick the top plate from the third stack (20).
In total, the sum of beauty values is 180.

Note: Unlike previous editions, in Kick Start 2020, all test sets are visible verdict test sets, meaning you receive instant feedback upon submission.
*/

//dp solution

#include<bits/stdc++.h>
using namespace std;


int  x=1;
void solve(){
    int n,k,p;
    cin>>n>>k>>p;
    vector<vector<int > > vec(55,vector<int > (55,0));
    vector<vector<int > > dp(55,vector<int > (51*30,0));
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            cin>>vec[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            vec[i][j]+=vec[i][j-1];
        }
    }
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }*/
    for(int i=1;i<=n;i++){
        for(int j=1;j<=p;j++){
            dp[i][j]=0;
            //LOO AT THE NEXT LOOP AS KI KOI NAYA STACK AAYA SO 
            //HOW MANY ITEMS WE CAN TAKE IT FROM THIS STACK MIN(PAGES,STACK SIZE);
            for(int l=0;l<=min(j,k);l++){
                //loop starting from zero means thats we have not taken any elements from this stack
                //IF I TAKE FIRST L ELEMENTS FROM THIS STACK THEN 
                //REMAINING I CAN TAKE FROM PREVIOUS BUILT DP
                int sum=vec[i][l]+dp[i-1][j-l];//(j-l) is the remaining elements
                dp[i][j]=max(dp[i][j],sum);
            }
        }
    }
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=p;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/
    cout<<"Case #"<<x<<": "<<dp[n][p]<<endl;

    x++;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}


//Recursive Solution

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


vector<vector<ll> > vec(55,vector<ll>(50));
vector<vector<ll> > pref(55,vector<ll>(50));
ll n,k,m,c=1;
ll dp[55][51*30];
ll func(ll idx,ll taken){
    if(taken==m)return 0;//answer fulfilling condition
    if(idx>n ||taken>m)return -1e9;//false condition
    if(dp[idx][taken]!=-1)return dp[idx][taken];
    ll ans=-1e9;
    for(int i=0;i<=k;i++){
        ans=max(ans,pref[idx][i]+func(idx+1,taken+i));
    }
    //cout<<ans<<"  "<<idx<<"  "<<taken<<endl;
    return dp[idx][taken]=ans;
}
void solve(){
    
    cin>>n>>k>>m;
    vector<ll > t;
    REP(i,1,n+1){
        REP(j,1,k+1){
            cin>>vec[i][j];
        }
    }
    /*REP(i,0,n){
        REP(j,0,k){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }*/
    REP(i,1,n+1){
        REP(j,1,k+1){
            pref[i][j]=vec[i][j]+pref[i][j-1];
        }
    }
    /*REP(i,0,n){
        REP(j,0,k){
            cout<<pref[i][j]<<" ";
        }
        cout<<endl;
    }*/
    memset(dp,-1,sizeof(dp));
    ll ans=func(1,0);
    cout<<"Case #"<<c<<": "<<ans<<endl;
    c++;

}
int main()
{
    fastIO;
    ll t=1;
    cin >> t;
    while(t--)
    {
        solve();

    }
    return 0;
}

