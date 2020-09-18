#include <bits/stdc++.h>
using namespace std;

class shape{
public:
	virtual void draw(){
		cout<<"shapes"<<endl;
	}	
};
class tri:public shape{
public:
	void draw(){
		cout<<"triangle"<<endl;
	}	
};
class rect:public shape{
public:
	void draw(){
		cout<<"rect"<<endl;
	}	
};

int main() {
	shape*s;
	shape ss;
	tri t;
	rect r;
	s=&ss;
	s->draw();
	s=&t;
	s->draw();
	s=&r;
	s->draw();
	
	return 0;
}
