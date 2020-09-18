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

int main() {
	tri obj;
	obj.A();
	obj.B();
	return 0;
}
