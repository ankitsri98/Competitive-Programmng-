#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int pre[n + 1][26];
    memset(pre, 0, sizeof(pre));
    // here i am calculating the count of all the characters till the ith characters

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 26; j++)
            pre[i][j] = pre[i - 1][j];
        pre[i][s[i - 1] - 'a']++;
    }
    /*for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 26; j++)
            cout<<pre[i][j]<<" ";
        cout<<endl;
    }*/
    // try to relate it it with subarray with sum 0 a little bit
    // at we have choice or cond' of each character to even keeping that in mind i decided
    // to form a mask of a type of string with no even characters as the will not create a problm in answer
    // and now when when this mask appears then i maintain acount of it and from these 
    // counts i will select 2 at a time that is indexes say i,j then from i+1 to j will hae
    // even no. of particular type of characters.
    // to visualize print things
    map<string, int> ma;
    for (int i = 0; i <= n; i++) {
        string temp;
        for (int j = 0; j < 26; j++)
            if ((pre[i][j]) & 1)
                temp += '1';//odd case
            else
                temp += '0';//even case
        //cout<<temp<<endl;
        ma[temp]++;
    }
    long long ans = 0;
    for (auto it : ma) {
        long long num = it.second;

        ans += (num * (num - 1)) / 2;//formula to select any 2 at a time 
       //cout<<it.first<<" "<<num<<" "<<ans<<endl;
        ans %= M;
    }
    cout << ans << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();


    return 0;
}
