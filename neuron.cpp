#include "neuron.h"
#include <cmath>

Neuron::Neuron() 
	: pot_ (0.0)
	{
		spikes_.clear();
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
	
size_t Neuron::getSpikesN() const {
	return spikes_.size(); 
}

void Neuron::update (double I) {
	updateClock();
	updatePot(h,I,getBuffer());    //Ce J doit être le J émis il y a "Delay" h 
	if(pot_ > V_thr) {
		spikes_.push_back(clock_);
		spike_ = true;
	}
	else {
		spike_ = false;
	}
		
	if(!spikes_.empty()) {
		if(spikes_.back() <= clock_ and clock_ < (spikes_.back()+ t_refra )) {
			pot_ = V_reset;
		}
	}		
}

void Neuron::updatePot (double h, double I, double J) {
	double const1 (exp(-h/tau));
	double const2 (R*(1-const1));
	pot_ = ((const1*pot_) + (I*const2) + (J));        //mV
}

void Neuron::updateClock() {
	clock_+=h;
}

int Neuron::getClock() {
	return clock_;
}

void Neuron::setBuffer(double J) {
 	buffer_[clock_%(D+1)] += J;
}

double Neuron::getBuffer() {
	int J(buffer_[clock_%(D+1)]);
	buffer_[clock_%(D+1)] = 0;
	return J;
}




	 
		
	

	
	
	
	
