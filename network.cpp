#include "network.h"

Network::Network(int n) {
	n_neurons=n;
	for(size_t i=0; i < n_neurons; i++) {
		neurons_.push_back(Neuron());
	}
}

vector<Neuron> Network::getNeurons() {
	return neurons_;
}

void Network::update(double Icurrent) {
	for(size_t i=0; i < n_neurons; i++) {
		if (i == 0) {                       //For the moment, only the first neuron has a Icurrent 
			neurons_[i].update(Icurrent);
		}
		else {
			neurons_[i].update(Inull);
		}
			
		if(neurons_[i].getSpike()) {
			for(size_t j=0; j < n_neurons; j++) {
				if(j!=i) {
					neurons_[j].setBuffer(Jconst);
				}
			}	
		}			
	}
}
			
		
		


		 
	
	
