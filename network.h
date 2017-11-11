#ifndef NETWORK_HPP
#define NETWORK_HPP
#include "neuron.h" 
#include "random"
#include <fstream>

using namespace std;

/**
 * ... The Network Class ...
 */
 


class Network {

	
private :

	/**
	 * ... General Attributes ...
	 */
	
	/**< all the neurons of the network are stored into this vector */
	vector<Neuron> neurons_;
	
	/**< general attributes for random generation */
	random_device rd;
	mt19937 generator;
	
	/**< attribute for poisson distribution */
	poisson_distribution<> pois_dis_;

		
public :

	/**
	 * ... The Constructors of the Network ...
	 */
	/** The constructor for the final network of 12500 neurons */ 
	Network();
	
	/**The constructor for the TEST 4 */
	/** @param n : the number of neuron in the network (2 for the TEST 4) */
	Network(size_t n);

	/** @return neurons_ */
	vector<Neuron> getNeurons() const;
	
	/** to update all the neurons */
	void update();
	
	/** The updtate for the TEST 4 
	 * Only the first neuron (of neurons_) receives an external current 
	 * the other neurons can receive spikes from the first neuron after the delay 
	 * thanks to the buffer that we want to test in the TEST 4 */
	/** @param Iext : the external current received by the first neuron */
	void update(double Iext);
	
	/** to simulate the network between two times */
	/** @param t_start : the begining of the simulation of the network
	 *  @param t_stop : the end of the simulation of the network */
	void simulation(int t_start, int t_stop);
	
	/** to put the spikes' data (time of each spikes of each neurons)
	 * into an external .txt file */
	void file();

};

#endif	
