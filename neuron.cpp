#include "neuron.h"
#include "random"
#include <cmath>

Neuron::Neuron() 
	: pot_ (0.0), clock_(0), n_spikes_(0), spike_(false), e_(true)
	{
		spikes_.clear();
		buffer_.clear();
		received_connections_.clear();
		sent_connections_.clear();
		for(size_t i=0; i < bufferSize; i++) {
		buffer_.push_back(0.0);
		}
	}
	
double Neuron::getPot() const {
	return pot_; 
}

void Neuron::setPot(double pot) {
	pot_ = pot;
}

bool Neuron::getSpike() const {
	return spike_; 
}

vector<int> Neuron::getSpikes() const {
	return spikes_; 
}

double Neuron::getSpikeTime(size_t a) const {
	return spikes_[a];
}	
	
int Neuron::getSpikesN() const {
	return n_spikes_; 
}

bool Neuron::update (double noise) {
	updateClock();
	updatePot(getBuffer(),noise);    //Ce J doit être le J émis il y a "Delay" h 
	if(pot_ > V_thr) {
		spikes_.push_back(clock_);
		spike_ = true;
		n_spikes_++;
	}
	else {
		spike_ = false;
	}
		
	if(!spikes_.empty()) {
		if(spikes_.back() <= clock_ and clock_ < (spikes_.back()+ t_refra )) {
			pot_ = V_reset;
		}
	}
	
	return spike_;	
}

void Neuron::updatePot (double J, double noise) {
	pot_ = exp(-h/tau)*pot_ + J + noise;        //mV
}

void Neuron::updateClock() {
	clock_+=h;
}

int Neuron::getClock() {
	return clock_;
}

void Neuron::setBuffer(bool e) {
	if(e) {
		buffer_[clock_%(D+1)] += J_e;
	}
	else {
		buffer_[clock_%(D+1)] += J_i;
	}
}

double Neuron::getBuffer() {
	int J(buffer_[clock_%(D+1)]);
	buffer_[clock_%(D+1)] = 0;
	return J;
}

bool Neuron::getE() {
	return e_;
}

void Neuron::setE(bool b) {
	e_ = b;
}

vector<int> Neuron::getReceivedConnections() {
	return received_connections_;
}

vector<int> Neuron::getSentConnections() {
	return sent_connections_;
}

void Neuron::addReceivedConnection(int c) {
	received_connections_.push_back(c);
}

void Neuron::addSentConnection(int c) {
	sent_connections_.push_back(c);
}
	

	 
		
	

	
	
	
	
