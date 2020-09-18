#include <bits/stdc++.h>
using namespace std;

class shape{
public:
	void A(){
		cout<<"A"<<endl;
	}	
};
class tri{
public:
	void A(){
		cout<<"A1"<<endl;
	}	
};

class circle: public tri,public shape{
public:
	void B(){
		shape ::A();
		tri ::A();
	}	
};
int main() {
	circle obj;
	//obj.tri::A();
	//obj.shape::A();
	obj.B();
	return 0;
}
