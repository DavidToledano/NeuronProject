#include "network.h"
#include <iostream>
#include <time.h>

Network::Network() {
	
	mt19937 generator(rd());
	
	poisson_distribution<> pois_dis_(lambda);
	
	uniform_int_distribution<> ExcitatoryReceivedConnectionsGenerator(0,(n_e-1));
	uniform_int_distribution<> InhibitoryReceivedConnectionsGenerator(n_e,n_e+n_i-1);
		
	int c(0);
	
	for(size_t i=0; i < n_e; ++i) {    //First of all, let's create the excitatory neurons
		neurons_.push_back(Neuron());
		neurons_[i].setE(true);
	}
	/* Here, the main difficulty is that we dont't know the precise number of connexions sent by a neuron, and we need this value
	 * but we do know the precise number of connexions received by a neuron (given in the course). 
	 * Before arriving to this code, I was dealing only with the number of connexions received, and in the updateNetwork, 
	 * I had to iterate among all the connexions of all my neurons. 
	 * It was to complexe. Then, I decide to determine the number of sent connexions of each neurons, 
	 * so that I will have to iterate only among the connexions of neurons which spikes.
	 */
	
	for(size_t i=0; i < n_e; ++i) {    
		for(size_t j=0; j < C_e; j++) {    //among all the excitataory neurons, we chose C_e that will be connected to the current neuron
			c=ExcitatoryReceivedConnectionsGenerator(generator);
			neurons_[i].addReceivedConnection(c);
			neurons_[c].addSentConnection(i);
		}
		for(size_t j=0; j < C_i; ++j) {    //among all the Inhibitory neurons, we chose C_i that will be connected to the current neuron
			c=InhibitoryReceivedConnectionsGenerator(generator);
			neurons_[i].addReceivedConnection(c);
			neurons_[c].addSentConnection(i);
		}
	}
	
	for(size_t i=0; i < n_i; ++i) {    ////Let's create the inhibitory neurons
		neurons_.push_back(Neuron());
		neurons_[n_e+i].setE(false);
	}
	for(size_t i=0; i < n_i; ++i) {
		for(size_t j=0; j < C_e; ++j) {    //among all the excitataory neurons, we chose C_e that will be connected to the current neuron
			c=ExcitatoryReceivedConnectionsGenerator(generator);
			neurons_[n_e+i].addReceivedConnection(c);
			neurons_[c].addSentConnection(n_e+i);
		}
		for(size_t j=0; j < C_i; ++j) {    //among all the Inhibitory neurons, we chose C_i that will be connected to the current neuron
			c=InhibitoryReceivedConnectionsGenerator(generator);
			neurons_[n_e+i].addReceivedConnection(c);
			neurons_[c].addSentConnection(n_e+i);
		}
	}
}

vector<Neuron> Network::getNeurons() const{
	return neurons_;
}

void Network::update() {
	for(size_t i=0; i < n_neurons; ++i) {
		if(neurons_[i].update(J_e*pois_dis_(generator))) {    //update return true if the neuron spike_ 
			for(auto con : neurons_[i].getSentConnections()){
				neurons_[con].setBuffer(neurons_[i].getE());
				//neurons_[con].addReceivedSpike(neurons_[con].getClock());    // decomment for the gtest
			}		
		}
	}
}

void Network::simulation(int t_start, int t_stop) {
	int t(t_start);
	while(t<t_stop) {
		update();
		t+=h;
		cout<<t<<endl;
	}
}

void Network::file() {
	ofstream neuron_graph;
	neuron_graph.open("NeuronGraph.txt");
	for(size_t i=0; i < n_neurons; ++i) {
		for(size_t j=0; j<neurons_[i].getSpikes().size(); ++j) {
			neuron_graph << neurons_[i].getSpikes()[j] << "\t" << i+1 << endl;
		}
	}
	neuron_graph.close();
}
	
			
	
	
	
	
				
















/*
		for(size_t j=0; j < C_tot; j++) {    //we iterate on each connection of each neuron
			if(neurons_[neurons_[i].getConnections()[j]].getSpike()) {    //if the neuron at the jth case of the vector connections_ is spiking (in each case of connections_, we have the number (in neurons_) of the neuron that is connected to the current neuron)
				neurons_[i].setBuffer();    // à revoir : prendre en compte l'état (excitateur ou pas) du neuronne qui envoi le spike
			}
		}
	}
}
*/
			
		
		


		 
	
	
