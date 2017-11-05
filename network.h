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
	
	vector<Neuron> neurons_;
	/**< all the neurons of the network are stored into this vector */
	
	random_device rd;
	mt19937 generator;
	/**< general attributes for random generation */
	
	poisson_distribution<> pois_dis_;
	/**< attribute for poisson distribution */

		
public :

	/**
	 * ... The Constructor of the Network ...
	 * */
	Network();
	
	/** ... The Only Getter ...
	 */
	vector<Neuron> getNeurons() const;
	/** @return neurons_ */
	
	void update();
	/** to update all the neurons */
	
	void simulation(int t_start, int t_stop);
	/** to simulate the network between two times */
	/** @param t_start : the begining of the simulation of the network
	 *  @param t_stop : the end of the simulation of the network
	 */
	 
	void file();
	/** to put the spikes' data (time of each spikes of each neurons)
	 * into an external .txt file */

};

#endif	
