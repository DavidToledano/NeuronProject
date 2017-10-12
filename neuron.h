#ifndef NEURON_HPP
#define NEURON_HPP
#include "constant.h"
#include <vector> 
using namespace std;

class Neuron {
	
public :
	Neuron();    //Default Constructor
	double getPot() const;    //To get the potential's value (mV)
	void setPot(double pot);    //To set the potential value 
	bool getSpike() const; 
	vector<double> getSpikes() const;    //To get the the vector of spikes 
	double getSpikeTime(size_t a) const;    //To get the time of a given spike 
	size_t getSpikesN() const;    //The number of spikes     
	void update (double I, double J);    //To update the potential of the neuron each dt
	void updatePot (double dt, double I, double J);    //to calculate the potential of the neuron at t+dt  
	void updateTime();
	//void updateBuffer(double J);
	
private : 
	double pot_;    //Membrane potential
	vector<double> spikes_;    //The times when spikes occured
	bool spike_;
	double t_;
	vector<double> buffer_;
};

#endif	           

