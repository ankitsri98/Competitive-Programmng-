#include <bits/stdc++.h>
using namespace std;
#define ll long int

//SQUARE ROOT DECOMPOSITION 
//RANGE SOME PROBLEM
int query(int * blocks,int* arr,int l,int r,int rn){
    int ans=0;
    //left part
    while(l<r  && l!=0 && l%rn!=0){
        ans+=arr[l];
        l++;
    }
    //middle part
    while(l+rn<=r){
        int block_id=l/rn;
        ans+=blocks[block_id];
        l+=rn;
    }
    //right part
    while(l<=r){
        ans+=arr[l];
        ++l;
    }
    return ans;
}
//update function

void update(int* blocks,int i,int val,int * arr,int rn){
    int block_id=i/rn;
    blocks[block_id]+=val-arr[i];
    arr[i]=val;
}
int main() {
	int t,n,m;
	int a[]={1,3,5,2,7,6,3,1,4,8};
	n=10;
	int rn=sqrt(n);
	int* blocks=new int[n+1];
	//build function take o(n) time
	int block_id=-1;
	for(int i=0;i<n;i++){
	    if(i%rn==0){
	        block_id++;
	    }
	    blocks[block_id]+=a[i];
	}
	//print the blocks array
	for(int i=0;i<=rn;i++){
	    cout<<blocks[i]<<" , "<<endl;
	}
	
	//queries
	int l,r;
	cin>>l>>r;
	update(blocks,2,15,a,rn);
	cout<<  query(blocks,a,l,r,rn)<<endl;
	return 0;
}
