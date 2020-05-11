The stock span problem is a financial problem where we have a series of N daily price quotes for a stock and we need to calculate span of stock’s price for all N days. You are given an array of length N, where ith element of array denotes the price of a stock on ith. Find the span of stock's price on ith day, for every 1<=i<=N.
A span of a stock's price on a given day, i, is the maximum number of consecutive days before the (i+1)th day, for which stock's price on these days is less than or equal to that on the ith day.

Input Format
First line contains integer N denoting size of the array.
Next line contains N space separated integers denoting the elements of the array.

Constraints
1 <= N <= 10^6

Output Format
Display the array containing stock span values.

Sample Input
5
30 35 40 38 35
Sample Output
1 2 3 1 1 END
Explanation
For the given case
for day1 stock span =1
for day2 stock span =2 (as 35>30 so both days are included in it)
for day3 stock span =3 (as 40>35 so 2+1=3)
for day4 stock span =1 (as 38<40 so only that day is included)
for day5 stock span =1 (as 35<38 so only that day is included)
hence output is 1 2 3 1 1 END


#include <bits/stdc++.h>
using namespace std;
#define ll long long int
//LIFO
int arr[1000005];
int ans[1000005];
int n;
//stack contains indices because it can be used to
// compare array elements
void findvalue(stack<int > &s){
    s.push(0);ans[0]=0;
    for(int i=1;i<n;i++){//day loop
        int currprice=arr[i];
        while(!s.empty() && arr[s.top()]<currprice){
            s.pop();
        }
        int betterday= s.empty()==true ? 0 : s.top();
        int span=i-betterday;
        ans[i]=span;
        s.push(i);
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
}
int main()
{
    stack<int  > s;

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    findvalue(s);

   /* while(!s.empty()){
        cout<<s.top().first<<" ";
        s.pop();
    }*/
    return 0;
}
