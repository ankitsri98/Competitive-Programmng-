// C++ program to count number of binary strings 
// with k times appearing consecutive 1's. 
//http://shuklas664.blogspot.com/2015/01/gnyr09f-solution.html
#include <bits/stdc++.h> 
using namespace std; 
#define ll long long int 
#define M 1000000007

int count(int n, int k) 
{ 
	// dp[i][j][0] stores count of binary 
	// strings of length i with j consecutive 
	// 1's and ending at 0. 
	// dp[i][j][1] stores count of binary 
	// strings of length i with j consecutive 
	// 1's and ending at 1. 
	int dp[n + 1][k + 1][2]; 
	memset(dp, 0, sizeof(dp)); 

	// If n = 1 and k = 0. 
	dp[1][0][0] = 1; 
	dp[1][0][1] = 1; 

	for (int i = 2; i <= n; i++) { 
		// number of adjacent 1's can not exceed i-1 
		for (int j = 0; j <=k; j++) { 
			dp[i][j][0] = ((dp[i - 1][j][0]%M) + (dp[i - 1][j][1]%M))%M; 
			dp[i][j][1] = (dp[i - 1][j][0])%M; 

			if (j - 1 >= 0) 
				dp[i][j][1] += (dp[i - 1][j - 1][1])%M; 
		} 
	} 

	return ((dp[n][k][0]%M) + (dp[n][k][1]%M))%M; 
} 

// Driver code 
int main() 
{ 
	ll n,m,k,i,j,x,z,t;
    cin>>t;
    while(t--)
    {
        cin>>i>>j>>k;
        cout<<i<<" "<<count(j,k)<<endl;
    }
	return 0; 
}
