//BUILDING A SEGMENT TREE
#include<bits/stdc++.h>
using namespace std;

void buildtree(int* arr,int* tree,int start,int en,int treenode)
{
    if(start==en)
    {
        tree[treenode]=arr[start];
        return ;
    }
    int mid=(start+en)/2;

    buildtree(arr,tree,start,mid,2*treenode);
    buildtree(arr,tree,mid+1,en,2*treenode+1);

    tree[treenode]= tree[2*treenode]+ tree[2*treenode+1];

}
int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9};
    int* tree = new int[18];
    buildtree(arr,tree,0,8,1);
    for(int i=1;i<18;i++)
    {
        cout<<tree[i]<<"  ";
    }
}
