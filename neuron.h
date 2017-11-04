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
	int getSpikesN() const;    //The number of spikes     
	bool update (double noise);    //To update the potential of the neuron each h
	void updatePot (double J, double noise);    //to calculate the potential of the neuron at t+h  
	void updateClock();   
	int getClock();    //to get the clock of the neuron in 10-4ms
	void setBuffer(bool e);
	double bufferAfterDelay();
	bool getE();
	void setE(bool b);
	vector<int> getReceivedConnections();
	vector<int> getSentConnections();
	void addReceivedConnection(int c);
	void addSentConnection(int c);
	vector<int> getReceivedSpikes();
	void addReceivedSpike(int t);
	
private : 
	double pot_;    //Membrane potential
	int clock_;    //Internal clock of the neuron 
	vector<int> spikes_;    //The times (in 10-4s) when spikes occured
	int n_spikes_;
	vector<int> buffer_;
	bool spike_;
	bool e_;    //true if the neuron is exitatory, false if he is inhibitory
	vector<int> received_connections_;    //The values this vector are the number of the neurons (where they are in neurons_) that are connected to the current neurons : in the following way the current neuron receives potential from them
	vector<int> sent_connections_;    //The values this vector are the number of the neurons (where they are in neurons_) that are connected to the current neurons in the following way : the current neuron sends potential to them
	vector<int> received_spikes_;   //for a Gtest
};

#endif	           

