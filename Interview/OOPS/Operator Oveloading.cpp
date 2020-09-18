#include <bits/stdc++.h>
using namespace std;

class shape{
public:
	int a;
	shape(int x){
		a=x;
	}
	void operator+(shape);
	
};
void shape::operator+(shape s){
	int k=a+s.a;
	cout<<k<<endl;
}

int main() {
	shape a(5);
	shape b(10);
	a+b;
	return 0;
}
