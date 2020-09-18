#include <bits/stdc++.h>
using namespace std;

class shape{
public:
	void A(){
		cout<<"A"<<endl;
	}	
};
class tri:public shape{//single level
public:
	void B(){
		cout<<"A1"<<endl;
	}	
};
class rect{
public:
	void C(){
		cout<<"A12"<<endl;
	}	
};
class circle: public tri,public rect{//multiple
public:
	void D(){
		A();
		B();
		C();
	}	
};
int main() {
	circle obj;
	obj.D();
	return 0;
}
