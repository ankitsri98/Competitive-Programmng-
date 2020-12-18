#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		int arr[n],brr[n];
		set<int > mt;
		mt.clear();
		int freq[n+2]={0};
		for(int i=0;i<n;i++){
			cin>>arr[i];
			
		}
		for(int i=0;i<n;i++){
			cin>>brr[i];
			mt.insert(brr[i]);
			freq[brr[i]]++;
		}
		int ans[n];
		for(int i=0;i<n;i++){
			int x=arr[i];
			//cout<<"smaller: "<<y<< "  larger: "<<z<<endl;
			if((mt.lower_bound(n-x))==mt.end()){
				int y=*mt.begin();
				int m1=(x+y)%n;
				ans[i]=m1;
				//cout<<y<< " jkjk  "<<freq[y]<<endl;
				if(freq[y]>1){
					freq[y]--;
				}
				else{
					mt.erase(y);
				}
				
			}
			else{
				int y=*(mt.lower_bound(n-x));
				int m1=(x+y)%n;
				//cout<<y<< " popop "<<freq[y]<<endl;
				ans[i]=m1;
				if(freq[y]>1){
					freq[y]--;
				}
				else{
					mt.erase(y);
				}
			}
		}
		for(int i=0;i<n;i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
}


