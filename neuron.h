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
	vector<int> getSpikes() const;    //To get the the vector of spikes 
	double getSpikeTime(size_t a) const;    //To get the time of a given spike 
	size_t getSpikesN() const;    //The number of spikes     
	void update (double I);    //To update the potential of the neuron each h
	void updatePot (double h, double I, double J);    //to calculate the potential of the neuron at t+h  
	void updateClock();   
	int getClock();    //to get the clock of the neuron in 10-4ms
	void setBuffer(double J);
	double getBuffer();
	
private : 
	double pot_;    //Membrane potential
	int clock_;    //Internal clock of the neuron 
	vector<int> spikes_;    //The times (in 10-4s) when spikes occured
	vector<int> buffer_;
	bool spike_;
	void initializeBuffer();
};

#endif	           

