#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

int main()
{
    ll n,x,y;    //n=nodes e=edges
    cin>>n;    //entering no. of node and edges
    int a[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }

    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]> (a[i][k]+a[k][j]))
                    a[i][j]=a[i][k]+a[k][j];
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j];
        }
        cout<<endl;
    }
    return 0;
}
