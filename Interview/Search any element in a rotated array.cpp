#include<bits/stdc++.h>
using namespace std;

int search(int a[],int s, int e ,int key)
{
    //base case
    if(s>e)
    {
        return -1;
    }
    //rec case
    int mid=(s+e)/2;
    //cout<<mid<<endl;
    if(a[mid]==key){
        return mid;
    }
    if(a[s]<=a[mid])
    {
        if(key>=a[s] && key<=a[mid])
        {
            return search(a,s,mid-1,key);
        }
        else
        {
            return search(a,mid+1,e,key);
        }
    }
    else{

        if(key>=a[mid] && key<=a[e])
        {
            //cout<<mid<<"a:  "<<endl;
            return search(a,mid+1,e,key);
        }
        else
        {
            //cout<<mid<<"b:  "<<endl;
            return search(a,s,mid-1,key);
        }
    }
}
int main() {
	
	int a[]={5,6,7,1,2,3,4};
	int key;
	cin>>key;
	cout<<search(a,0,6,key)<<endl;
	return 0;
}