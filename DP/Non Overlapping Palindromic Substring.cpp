// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 
#define N 100 

// Pre-processing function 
void pre_process(bool dp[N][N], string s) 
{ 

    // Get the size of the string 
    int n = s.size(); 

    // Initially mark every 
    // position as false 
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) 
            dp[i][j] = false; 
    } 

    // For the length 
    for (int j = 1; j <= n; j++) { 

        // Iterate for every index with 
        // length j 
        for (int i = 0; i <= n - j; i++) { 

            // If the length is less than 2 
            if (j <= 2) { 

                // If characters are equal 
                if (s[i] == s[i + j - 1]) 
                    dp[i][i + j - 1] = true; 
            } 

            // Check for equal 
            else if (s[i] == s[i + j - 1]) 
                dp[i][i + j - 1] = dp[i + 1][i + j - 2]; 
        } 
    } 
} 

// Function to return the number of pairs 
int countPairs(string s) 
{ 

    // Create the dp table initially 
    bool dp[N][N]; 
    pre_process(dp, s); 
    int n = s.length(); 

    // Declare the left array 
    int left[n]; 
    memset(left, 0, sizeof left); 

    // Declare the right array 
    int right[n]; 
    memset(right, 0, sizeof right); 

    // Initially left[0] is 1 
    left[0] = 1; 

    // Count the number of palindrome 
    // pairs to the left 
    for (int i = 1; i < n; i++) { 

        for (int j = 0; j <= i; j++) { 

            if (dp[j][i] == 1)  //you will get indexing ince you see the table
                left[i]++; 
        } 
    } 

    // Initially right most as 1 
    right[n - 1] = 1; 

    // Count the number of palindrome 
    // pairs to the right 
    for (int i = n - 2; i >= 0; i--) { 

        right[i] = right[i + 1]; 

        for (int j = n - 1; j >= i; j--) { 

            if (dp[i][j] == 1) //you will get indexing ince you see the table
                right[i]++; 
        } 
    } 

    int ans = 0; 

    // Count the number of pairs 
    for (int i = 0; i < n - 1; i++) 
        ans += left[i] * right[i + 1]; 

    return ans; 
} 

// Driver code 
int main() 
{ 
    string s ;
    cin>>s; 
    cout << countPairs(s); 

    return 0; 
} 
