#include "neuron.h"
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{	
	Neuron neuron1;
	Neuron neuron2;
	double t(t_start), Icurrent(0.0), Inull(0.0), t_a(0.0), t_b(0.0);
	
	do {
		cout<<"Enter the External Current"<<endl;
		cin>>Icurrent;
	} while(Icurrent==0.0);
	
	do {
		cout<<"Enter the External Time a"<<endl;
		cin>>t_a;
	} while(t_a <= t_start);
	
	do {
		cout<<"Enter the External Time b"<<endl;
		cin>>t_b;
	} while(t_b <= t_start or t_b <= t_a);
	
	
	ofstream cVar;
    cVar.open("variable.txt");
    if(cVar.fail()) {
        cout << "Error while opening the file" << endl;
    }
    else {   
        cout << "Your file could be opened" << endl;
    }
    
    
	cVar<<" -------- POTENTIALS --------"<<endl;
	while(t<t_stop) {
		if(t_a <= t and t <= t_b) {
			neuron1.update(t,dt,Icurrent, Jnull);
			neuron2.update(t,dt,Inull, Jnull);	
			if (neuron1.getSpike() == true) {
				neuron2.update(t,dt,Inull,Jconst);	
			}
		}
		else {
			neuron1.update(t,dt,Inull, Jnull);
			neuron2.update(t,dt,Inull, Jnull);
		}
		t+=dt;    // "t" is incremeted here because "update" (with "updatePot") calculates the pot_ at t+dt (cf equation) 
		cVar<<"Potential(neuron1) = "<<neuron1.getPot()<< "mV    at t = "<<t<<"ms      "<<"Potential(neuron2) = "<<neuron2.getPot()<< "mV    at t = "<<t<<"ms"<<endl;	
	}
	
	cVar<<" -------- SPIKES --------"<<endl;
	for(size_t i=0; i<neuron1.getSpikesN(); i++) {
		cVar<<neuron1.getSpikeTime(i)<<"    ";
	}
	
	
		
	cVar.close();
	
	return 0;
} 
