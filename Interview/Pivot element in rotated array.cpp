#include<bits/stdc++.h>
using namespace std;

int search(int a[],int s, int e )
{
    //base case
    if(s>e)
    {
        return -1;
    }
    //rec case
    int mid=(s+e)/2;
    //cout<<mid<<endl;
    if(a[mid]<a[mid-1]){
        return mid-1;
    }
    if(a[mid]>a[mid+1]){
        return mid;
    }
    if(a[s]<=a[mid])
    {
        return search(a,s,mid-1);
    }
    else{
        return search(a,mid+1,e);
    }
}
int main() {
	
	int a[]={5,6,7,9,2,3,4};
	cout<<search(a,0,6)<<endl;
	return 0;
}