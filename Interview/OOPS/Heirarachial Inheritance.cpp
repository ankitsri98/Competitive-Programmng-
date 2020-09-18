#include <bits/stdc++.h>
using namespace std;

class shape{
public:
	int a,b;
	void A(int a,int b){
		this->a=a;
		this->b=b;
	}	
};
class tri:public shape{
public:
	void B(){
		cout<<(a*b)/2<<endl;
	}	
};
class rect:public shape{
public:
	void C(){
		cout<<a*b<<endl;
	}	
};

int main() {
	rect obj;
	tri ob;
	obj.A(10,5);
	obj.C();
	ob.A(10,5);
	ob.B();
	return 0;
}
