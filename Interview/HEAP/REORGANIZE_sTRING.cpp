typedef pair<int ,char > cp;
class Solution {
public:
    string reorganizeString(string S) {
        //question is to make a string such that no 2 consecutive char are same
        map<char,int > mp;
        for(auto i: S){
            mp[i]++;
        }
        priority_queue<cp> pq;
        for(auto i: mp){
            pq.push({i.second,i.first});
        }
        //logic is to make map of frequency then built a max heap of pair of char and frequency
        string ans,ans1="";
        cp a,b;
        //BELOW LOGIC IS TO TAKE 2 MOST FREQUENT CHARACTERS AND APPEND TO THE STRING .
        //AND AFTER REDUCING THERE FREQ BY 1 IF ANY OF THE ONE HAVE FREQ MORE THAN 0 THEN PUSH IT BACK AGAIN.
        //BASICALLY FORMING STRINGS OF DIFF. CONSECUTIVE CHARS.
        while(!pq.empty()){
            a=pq.top();
            pq.pop();
            cout<<"A  "<<a.second<<" " <<a.first<<endl;
            ans+=a.second;
            if(!pq.empty()){
                b=pq.top();
                pq.pop();
                cout<<"B  "<<b.second<<" " <<b.first<<endl;
                ans+=b.second;
                if(b.first>1){
                    pq.push({b.first-1,b.second});
                }
            }
            if(a.first>1){
                pq.push({a.first-1,a.second});
            }
        }
        cout<<ans<<endl;
        //AT LAST CHECK IF THE 2 CONSECU. CHARS ARE SAME OR NOT.
        for (int i = 1; i < ans.size(); i++)
            if (ans[i] == ans[i - 1]) return "";
        return ans;
    }
};