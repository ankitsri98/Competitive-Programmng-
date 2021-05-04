#include <bits/stdc++.h>
#include <limits.h>
#include <math.h>
#define mod 1000000007
#define pi 3.14159265
//  sin((deg*pi)/180.0);

using namespace std;

long long int ceil2(long long int a, long long int b) 
{
    return (a + b - 1) / b;
}

int hcf(int n1, int n2)
{
    if (n2 != 0)
       return hcf(n2, n1 % n2);
    else 
       return n1;
}

int n;
string s;

void rec(int i,bool space,string x)
{
    if(i==n)
    {
        cout<<x<<endl;
        return ;
    }
    
    if(space)
    {
    	//agar last space use hui hai toh ab number hi lesakte hain
        rec(i+1,false,x + to_string(s[i]-'0'));
    }
    else
    {
    	//last number hai toh ab is number ko pichle set me daal den ya phir ek naa set bana den using space
        rec(i,true,x + " ");
        rec(i+1,false,x + to_string(s[i]-'0'));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>s;
    n = s.length();
    string x = "" + to_string(s[0]-'0');
    rec(1,false,x);
    
    return 0;
}
