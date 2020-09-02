/*
Assignment Problem:
There are  persons and  tasks, each task is to be alloted to a single person. We are also given a matrix  of size N*N ,
where COST[I][J] denotes, how much person  is going to charge for task . Now we need to assign each task to a person in such a way
that the total cost is minimum. Note that each task is to be alloted to a single person, and each person will be alloted only one task.

*/
#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int arr[1005][1005];
int solve(int i,int n,int mask){
	if(i==n)return 0;
	if(dp[i][mask]!=-1)return dp[i][mask];
	
	int x=INT_MAX;
	//assigning the ith job to the jth person
	for(int j=0;j<n;j++){
		if(mask&(1<<j)){//if the jth person is available or not
			x=min(x,solve(i+1,n,mask^(1<<j))+arr[j][i]);
			//now next job is selected and will be assined to next available person
		}
	}
	return dp[i][mask]=x;
}
int main() {
	int n,m;
	cin>>n;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}
	memset(dp,-1,sizeof(dp));
	cout<<solve(0,n,(1<<n)-1);
	return 0;
}
