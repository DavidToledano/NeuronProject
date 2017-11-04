#include "network.h"
#include "constant.h"
#include <iostream>
#include <cmath>

using namespace std;

int main()
{	
	Network network;
	network.simulation(0,5000);
	network.file();
	
	return 0;
} 
