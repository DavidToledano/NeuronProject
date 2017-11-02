#ifndef NETWORK_HPP
#define NETWORK_HPP
#include "neuron.h" 
#include "random"
using namespace std;

class Network {
	
public :
	Network();
	vector<Neuron> getNeurons() const;
	void update();

private :
	vector<Neuron> neurons_;
	vector<int> ExcitatoryConnections_;
	vector<int> InhibitoryConnections_;
	random_device rd;
	mt19937 generator;
	poisson_distribution<> pois_dis_;
};

#endif	
