#ifndef NETWORK_HPP
#define NETWORK_HPP
#include "neuron.h" 
using namespace std;

class Network {
	
public :
	Network(int n);
	vector<Neuron> getNeurons();
	void update(double Icurrent);

private :
	vector<Neuron> neurons_;
	int n_neurons;

};

#endif	
