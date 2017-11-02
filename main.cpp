#include "network.h"
#include "constant.h"
#include <iostream>
#include <cmath>
using namespace std;

int main()
{	
	Network network;
	double t(t_start);
	while(t<t_stop) {
		network.update();
		t+=h;
		cout<<t<<endl;
	}
	return 0;
} 
