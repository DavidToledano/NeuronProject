#include "network.h"
#include <iostream>
#include <cmath>
using namespace std;

int main()
{	
	Network network(2);
	int t(t_start), t_a(0), t_b(0);
	double Icurrent(0.0);
	
	do {
		cout<<"Enter the External Current"<<endl;
		cin>>Icurrent;
	} while(Icurrent==0.0);
	
	do {
		cout<<"Enter the External Time a (10-4s)"<<endl;
		cin>>t_a;
	} while(t_a <= t_start);
	
	do {
		cout<<"Enter the External Time b (10-4s)"<<endl;
		cin>>t_b;
	} while(t_b <= t_start or t_b <= t_a);
    
    
	cout<<" -------- POTENTIALS --------"<<endl;
	while(t<t_stop) {
		if(t_a <= t and t <= t_b) {
			network.update(Icurrent);
		}
		else {
			network.update(Inull);
		}
		
		t+=h;
		
		cout<<"Potential(neuron1) = "<<network.getNeurons()[0].getPot()<< "mV    at t = "<<t/10<<"ms      "<<"Potential(neuron2) = "<<network.getNeurons()[1].getPot()<< "mV    at t = "<<t/10<<"ms"<<endl;	
	}
	
	cout<<" -------- SPIKES --------"<<endl;
	for(size_t i=0; i<network.getNeurons()[0].getSpikesN(); i++) {
		cout<<network.getNeurons()[0].getSpikeTime(i)/10<<"ms    ";
	}
	
	
	return 0;
} 
