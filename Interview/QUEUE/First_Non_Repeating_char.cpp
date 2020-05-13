#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin>>s;
    queue<char > q;
    map<char , int > m;

    cout<<firstUniqChar(s)<<endl;
    for(int i=0;i<s.size();i++){
        q.push(s[i]);
        m[s[i]]++;
       while(!q.empty()){
           cout<<i<<" "<<q.front()<<endl;
            if(m[q.front()]>1){
                q.pop();
            
            }
            else{
                cout<<q.front()<<endl;break;
            }
        }
        if(q.empty()){
            cout<<-1<<endl;
        }
    }
}
