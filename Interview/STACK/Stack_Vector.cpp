#include <bits/stdc++.h>
using namespace std;
#define ll long long int
//LIFO
class Stack{
private:
    vector<int  >v;
public:
    void push(int data){
    v.push_back(data);
    }
    int top(){
    return v[v.size()-1];
    }
    void pop(){
        if(!v.empty()){
            v.pop_back();
        }
    }
    bool empty(){
    return v.size()==0;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //STACK USING VECTOR
    //METHODS:- PUSH(), POP(), TOP(), EMPTY()
    Stack s;
    for(int i=1;i<=5;i++){
        s.push(i*i);
    }
    //printing elements
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
	return 0;
}
