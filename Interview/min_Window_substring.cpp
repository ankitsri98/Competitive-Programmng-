#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long int

string find_min_window_pat(string str,string pat){
    if(str.size()<pat.size()){
        return "not possible";
    }
    ll freq_pat[256]={0},freq_str[256]={0};
	for(int i=0;i<pat.size();i++){
	    freq_pat[pat[i]]++;
	}
	ll start=0,start_index=-1,min_len=INT_MAX,count=0,len;
	for(int i=0;i<str.size();i++){
	    freq_str[str[i]]++;
	    if(freq_pat[str[i]]!=0  && freq_str[str[i]]<=freq_pat[str[i]]){
	        count++;
	    }
	    //shrinking
	    if(count==pat.size()){
    	    while(freq_str[str[start]]>freq_pat[str[start]] || freq_pat[str[start]]==0){
    	        if(freq_str[str[start]]>freq_pat[str[start]]){
    	            freq_str[str[start]]--;
    	        }
    	        start++;
    	    }
    	    len=i-start+1;
    	    if(min_len>len){
    	        min_len=len;
    	        start_index=start;
    	    }
    	}
	}
	if(start_index==-1){
	    cout<<"NO_Window";
	    return "";
	}
	cout<<min_len<<endl;
	return str.substr(start_index,min_len);
}
int main()
{
	string str,pat;
	cin>>str>>pat;

	cout<<find_min_window_pat(str,pat)<<endl;
	return 0;
}
