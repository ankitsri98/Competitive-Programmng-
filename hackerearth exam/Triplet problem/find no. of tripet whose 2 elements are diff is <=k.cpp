#include <bits/stdc++.h>
#define ll long long
using namespace std;



void solve() {




    int n;
    cin >> n;
    int k;
    cin >> k;
    int ar[n];

    for (int i = 0; i < n; i++)
        cin >> ar[i];


    sort(ar, ar + n);

    ll ans = 0;


    for (int i = 0; i < n; i++) {
        int ind = upper_bound(ar, ar + n, ar[i] + k) - ar;
        ind--;

        ll num = ind - i + 1;
        num--;//FIX ONE

        if (num >= 2)
            ans += ((num * (num - 1)) / 2);//SELECT ANY 2

    }



    cout << ans << endl;

}



int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);


    int t;
    cin >> t;
    // scanf("%d", &t);
    while (t--)
        solve();


    return 0;
}
