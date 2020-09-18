#include <bits/stdc++.h>
using namespace std;

class shape{
public:
	void A(){
		cout<<"A"<<endl;
	}	
};
class tri: public shape{
public:
	void B(){
		cout<<"B"<<endl;
	}	
};

class circle: public tri{
public:
	void C(){
		cout<<"C"<<endl;
	}	
};
int main() {
	circle obj;
	obj.A();
	obj.B();
	obj.C();
	return 0;
}
