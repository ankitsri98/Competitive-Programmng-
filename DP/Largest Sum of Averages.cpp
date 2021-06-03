int pref[10005]={0};
double dp[105][105];
// i is the start of the array and c=1 initially is the segment the recur call is made like
// taking till jth item and considering that one segment and now the count of segment will increase by one
// and to it we will have to add the average of segment i->j and remember base cases
double recur(int i,int c,int k,int n){
    if(i>=n)return 0;
    if(dp[i][c]>0  )return dp[i][c];// dp[i][c]!=-1 is not used coz we dont use equality with decimal value
    
    double ans=INT_MIN;
    for(int j=i;j<n;j++){
        //HAR ITH POSITION PAR MAINE YE KIYA KI ITH ELEMENT KO ADD KIYA(YAANI PURAANE SET ME RAKHA) 
        // AUR DOOSRI CHOICE YE HAI KI MAINE USKE AAGE EK NAYA SET CHALU KARDIYA
        // YE MAINE POORI ARRA KE LIYE KIYA ISKO TERMINATE KARNE KI CONDITION LAGAI HUI HAI
        // AUR NUMBER OF SET AGAR K HOGAI TOH MAINE CONTINUE KIYA JISSE KI AB ISS SET ME SAARE ELEMENTS AAJAIN
        int x= (i==0)? pref[j]: pref[j]-pref[i-1];
        double y=x*1.0/(j-i+1);
        if(c==k){
            ans=y;
            continue;
        }
        ans=max(ans,y+recur(j+1,c+1,k,n));
    }
    return dp[i][c]=ans;
}
class Solution {
public:
    double largestSumOfAverages(vector<int>& arr, int k) {
        int n=arr.size();
        pref[0]=arr[0];
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]+arr[i];
        }
        double ans;
        //2 base case
        if(k==1){
            ans=pref[n-1]*1.0/n;
            return ans;
        }
        else if(k==n){
            ans=pref[n-1]*1.0;
            return ans;
        }
        memset(dp,-1,sizeof(dp));
        ans=recur(0,1,k,n);
        return ans;
    }
};
